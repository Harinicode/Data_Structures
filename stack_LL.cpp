#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};

struct head
{
    int count;
    node *top;
};

class stack
{       int y;
            head *list;
            node *temp;
    public: stack()
            {
                list=new head;
                list->count=0;
                list->top=NULL;
            }
            void push(int ele)
            {
                temp=new node;                  //creating a node
                if(temp!=NULL)
                {
                    temp->link=list->top;
                    temp->data=ele;
                    list->top=temp;
                    cout<<temp->data<<" is inserted successfully\n";
                    list->count++;
                }
            }
            void pop()
            {
                if(list->count==0)
                    cout<<"List is empty\n";
                else
                {
                temp=list->top;
                if(temp!=NULL)
                {
                    temp=list->top;
                    list->top=list->top->link;
                   y=temp->data;
                   cout<<y<<" is deleted successfully\n";
                   delete temp;
                   list->count--;
                }
                
                }
            }
            void display()
            {
                if(list->count==0)
                    cout<<"Stack is empty\n";
               else
                    {
                        temp=list->top;
                        while(temp!=NULL)
                        {
                            cout<<temp->data<<"\t";
                            temp=temp->link;
                        }
                    }

            }
            void isempty()
            {
                if(list->top==-1)
                    cout<<"List is empty\n";
                else
                    cout<<"List is not empty";
                
            }
            void stacktop()
            {
                if(list->top==-1)
                    cout<<"List is empty\n";
                else
                    cout<<"Stack top element:"<<list->top->data;
                
            }
            ~stack()
            {
                temp=list->top;
                while(temp!=NULL)
                {
                    list->top=temp;
                    delete temp;
                    temp=temp->link;
                }
                delete list;
            }




};
int main()
{
    stack s;
    int ch,x;
    cout<<"Enter choice\n 1.Push 2.Pop 3.Display 4.isempty 5.Stacktop\n";
    cin>>ch;
    do{
        switch(ch)
        {
        case 1:cout<<"ENTER THE ELEMENT TO BE INSERTED: ";
                cin>>x;
                s.push(x);
                break;
        case 2:s.pop();
               break;
        case 3:s.display();
                break;
        case 4:s.isempty();
               break;
        case 5:s.stacktop();
                break;                
        default:cout<<"Invalid choice";
        }
        cout<<"Enter choice 1.Push 2.Pop 3.Display 4.isempty 5.Stacktop else enter any other no.";
        cin>>ch;
    }while(ch<=5);
    return 0;
}
