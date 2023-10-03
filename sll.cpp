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
    node *first;

};

class sll
{
        head *list;
        node *ptr,*prec,*temp;
  public:
        sll()
        {
            list=new head;
            list->count=0;
            list->first=NULL;

        }
        bool search(int target)
        {
            prec=NULL;
            ptr=list->first;
            while((ptr!=NULL)&&(ptr->data<target))          //search
            {
                prec=ptr;
                ptr=ptr->link;
            }
            if(ptr==NULL)
                return false;
            else
            if(ptr->data==target)
                return true;
            else
                return false;           //if greater
        }
        void insert()
        {
            int x;
            bool success;
            cout<<"Enter the element to be inserted\n";
            cin>>x;
            success=search(x);
            if(success)
            {
                cout<<"Cannot insert as  already present\n";
                return;
            }
            temp=new node;
            temp->data=x;
            if(prec==NULL)
            {                                               //at the beginning
                temp->link=ptr;
                list->first=temp;
            }
            else
            {
                temp->link=ptr;                            //at middle or end
                prec->link=temp;

            }
            cout<<temp->data<<" inserted Sucessfully\n";
            list->count++;
        }
        void display()
        {
            if(list->count==0)
                cout<<"List is empty\n";
            else
            {
                temp=list->first;
                while(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->link;
                }

                cout<<endl;
            }
        }
        void del()
        {
            if(isempty())
                cout<<"List is empty\n";
                int y,x;
                bool success;
                cout<<"Enter the element to be deleted\n";
                cin>>y;
                success=search(y);
            if(success==0)
            {
                    cout<<"Cannot delete as"<<y<<"not found in list\n";
                    return;
            }
            if(prec==NULL)
                    list->first=ptr->link;
            else
                    prec->link=ptr->link;
            delete ptr;
            cout<<ptr->data<<" deleted Successfully\n";
            list->count--;

        }
        int isempty()
        {
            if(list->count=0)
                return 1;
            else
                return 0;

        }

        void retrieve()
        {
                    int ele;
                    cout<<"Enter element to be retrieved\n";
                    cin>>ele;
                    if(search(ele))
                        cout<<ptr->data<<" is retrieved\n";
                    else
                        cout<<"Element not found\n";
        }
        void count()
        {
            if(list->count==0)
                cout<<"List is empty\n";
            else
                cout<<"List count: "<<list->count;
        }
       ~sll()
        {
            temp= new node;
            temp=list->first;
            while(list->count!=0)
            {

                list->first=temp->link;
                delete temp;
                list->count--;

            }
            delete list;
            cout<<"List destroyed";
        }
};

int main()
{
    sll s;
    int ch,ele;
    cout<<"Enter choice\n";
    cin>>ch;
    do
    {

        switch(ch)
        {
            case 1:s.insert();
                   break;
            case 2:
                   cout<<"Enter the element to be searched\n";
                   cin>>ele;
                   if(s.search(ele))
                    cout<<"Element found\n";
                   else
                    cout<<"Element not found\n";
                   break;
            case 3:s.del();
                   break;
            case 4:s.display();
                   break;
            case 5:s.retrieve();
                   break;
            case 6:s.count();
                   break;
            case 7:if(s.isempty())
                     cout<<"List is Empty\n";
                    else
                     cout<<"List is not Empty\n";
                   break;
            case 8:s.~sll();
                    break;
           default:cout<<"Invalid Choice\n";
                    break;
        }
        cout<<"Enter choice else enter no.>8 to exit\n";
        cin>>ch;
    }while(ch<=8);
    return 0;
}
