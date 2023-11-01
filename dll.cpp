#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link,*back;

};
struct head
{
    int count;
    node *first;
    node *rear;
};

class dll
{
        head *list;
        node *ptr,*prec,*temp;
  public:
        dll()
        {
            list=new head;
            list->count=0;
            list->first=NULL;
            list->rear=NULL;

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
            {
                temp->back=NULL;                     //at the beginning
                temp->link=ptr;
                list->first=temp;
            }
            else
            {
                temp->link=ptr;
                temp->back=prec;                          //at middle or end
                prec->link=temp;

            }
            if(ptr==NULL)
                list->rear=temp;
            else
                ptr->back=temp;
            cout<<temp->data<<" inserted Sucessfully\n";
            list->count=list->count+1;
        }
        void displayfromhead()
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
        void displayfromrear()
        {
            if(list->count==0)
                cout<<"List is empty\n";
            else
            {
                temp=list->rear;
                while(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->back;
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
          
            if(!success)
            {
                    cout<<"Cannot delete as"<<y<<"not found in list\n";
                    return;
            }
                
            if(ptr->back==NULL)
                    list->first=ptr->link;
            else
                    prec->link=ptr->link;
            if(ptr->link!=NULL)
            {
                ptr->back=ptr->back;
            }
            else
                list->rear=ptr->back;
            delete ptr;
            cout<<y<<" deleted Successfully\n";
          list->count--;

        }
        int searchfromhead(int t)
        {
            int pos=1;
            ptr=list->first;
            while((ptr!=NULL)&&(ptr->data<t))  
            
            {
                pos=pos+1;
                ptr=ptr->link;
            }
            if(ptr==NULL)
                return -1;
            else
            if(ptr->data==t)
                return pos;
            else
                return -1;           //if greater
        }
        int searchfromrear(int target)
        {
            int pos=1;
            ptr=list->rear;
            while((ptr!=NULL)&&(ptr->data>target)) 
            {
                pos=pos+1;
                ptr=ptr->back;
            }
            if(ptr==NULL)
                return -1;
            else
            if(ptr->data==target)
                return pos;
            else
                return -1;           //if greater
        }

        int isempty()
        {
            if(list->count==0)
                return 1;
            else
                return 0;

        }
        void dllcount()
        {
                     cout<<"List count: "<<list->count;
        }
       ~dll()
        {
            temp= new node;
            temp=list->first;
            while(temp!=NULL)
            {
                temp=temp->link;
                delete temp;
            }
            list->first=NULL;
            list->rear=NULL;
            list->count=0;
            cout<<"List destroyed";
        }
};

int main()
{
    dll s;
    int ch,ele;
    cout<<"Enter choice 1.insert 2.searchfromhead 3.searchfromrear 4.delete 5.displayfromhead 6.displayfromrear 7.count 8.isempty \n";
    cin>>ch;
    do
    {

        switch(ch)
        {
            case 1:s.insert();
                   break;
            case 2:
                   cout<<"Enter the element to be searched from head\n";
                   cin>>ele;
                   if(s.searchfromhead(ele)>=0)
                    cout<<"Element found at pos: "<<s.searchfromhead(ele);
                   else
                    cout<<"Element not found\n";
                   break;
            case 3:
                   cout<<"Enter the element to be searched from rear\n";
                   cin>>ele;
                   cout<<s.searchfromrear(ele);
                   if(s.searchfromrear(ele)>=0)
                    cout<<"Element found at pos: "<<s.searchfromrear(ele);
                   else
                    cout<<"Element not found\n";
                   break;

            case 4:s.del();
                   break;
            case 5:s.displayfromhead();
                   break;
            case 6:s.displayfromrear();
                   break;
            case 7:s.dllcount();
                   break;
            case 8:if(s.isempty())
                     cout<<"List is Empty\n";
                    else
                     cout<<"List is not Empty\n";
                   break;
           default:cout<<"Invalid Choice\n";
                    break;
        }
        cout<<"Enter choice else enter no.>9 to exit\n";
        cin>>ch;
    }while(ch<=8);
    return 0;
}
