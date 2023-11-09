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

class cdll
{
        head *list;
        node *ptr,*prec,*temp;
        int n;
  public:
        cdll()
        {
            list=new head();
            list->count=0;
            list->first=NULL;
            list->rear=NULL;
            cout<<"Enter the size of linked list";
            cin>>n;

        }
        bool search(int target)
        {
            prec=NULL;
            if(ptr==NULL)
                return false;
            ptr=list->first;
          if(ptr->data==target)
            return true;
          if(target<ptr->data)
            return false;
          prec=ptr;
          ptr=ptr->link;
            while((ptr!=list->first)&&(ptr->data<target))
            {
                    prec=ptr;
                     ptr=ptr->link;
            }
            if(ptr==list->first)
                return false;
           else
           if(ptr->data==target)
                return true;
            else
                return false;
            
        }
       void insert()
    {
    int x;
    bool success;
    cout << "Enter the element to be inserted: ";
    cin >> x;
    temp = new node;
        temp->data = x;
    success = search(x);
        if (success)
        {
            cout << "Cannot insert as already present\n";
            return;
        }
        if (isFull())
        {
        cout << "List full cannot insert\n";
        return;
        }
        if (prec == NULL)
        {
            if (list->count == 0)
            {
                temp->back = temp;
                temp->link = temp;
                list->rear=temp;
                list->first=temp;
            }
            else
            {
                temp->back = list->rear;
                temp->link = list->first;
                list->first->back = temp;
                list->rear->link = temp;
                list->rear = temp;
            }
        }
        else
        {

            temp->back = prec;
            temp->link = ptr;
            prec->link = temp;
            if (ptr == list->first)
            {
                list->rear = temp;
            }
            ptr->back = temp;
        }
        cout << temp->data << " inserted Successfully\n";
        list->count++;
        //list->count = list->count + 1;

    }




        void displayfromhead()
        {
            if(list->count==0)
                cout<<"List is empty\n";
            else
            {
                temp=list->first;
                if(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->link;
                }
                while(temp!=list->first)
                {
                    cout<<temp->data;;
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
                if(temp!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->back;
                }
                while(temp!=list->rear)
                {
                    cout<<temp->data;;
                    temp=temp->back;
                }

                cout<<endl;
            }
        }
        void del()
        {
            if(isempty())
               return;
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
            if(list->count==1)
            {
                list->first=NULL;
                list->rear=NULL;
            }
            else
            {
                if(prec==NULL)
                {
                    list->first=ptr->link;
                    ptr->link->back=ptr->back;
                    list->rear->link=ptr->link;
                }
                else
                {
                    prec->link=ptr->link;
                    ptr->link->back=prec;
                    if(ptr==list->rear)
                        list->rear=prec;
                }
            }
            delete ptr;
            cout<<y<<" deleted Successfully\n";
            list->count--;

        }
        int searchfromhead(int target )
        {
            int pos=1;
            ptr=list->first;
            if(isempty())
                return -1;
             if(ptr->data==target)
                return pos;
            ptr=ptr->link;
            while((ptr!=list->first)&&(ptr->data<target))
            {
                    pos=pos+1;
                    ptr=ptr->link;
            }
            if(ptr->data==target)
                return pos;
            else
                return -1;
        }
        int searchfromrear(int target)
        {
            int pos=1;
            ptr=list->rear;
            if(isempty())
                return -1;
            ptr=ptr->back;
            while((ptr!=list->rear)&&(ptr->data<target))
            {
                    pos=pos+1;
                    ptr=ptr->back;
            }
            if(ptr->data==target)
                return pos;
            else
                return -1;
        }

        int isempty()
        {
            if(list->count==0)
                return 1;
            else
                return 0;

        }
        int isFull()
        {
            if(list->count==n)
                return 1;
            else
                return 0;

        }

        void cdllcount()
        {
                     cout<<"List count: "<<list->count;
        }
       ~cdll()
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
    cdll s;
    int ch,ele;
    cout<<"Enter choice 1.insert 2.searchfromhead 3.searchfromrear 4.delete 5.displayfromhead 6.displayfromrear 7.count  8.isempty 9.Isfull\n";
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
            case 7:s.cdllcount();
                   break;
            case 8:if(s.isempty())
                     cout<<"List is Empty\n";
                    else
                     cout<<"List is not Empty\n";
                   break;
            case 9:if(s.isFull())
                     cout<<"List is Full\n";
                    else
                     cout<<"List is not Full\n";
                   break;

           default:cout<<"Invalid Choice\n";
                    break;
        }
        cout<<"Enter choice else enter no.>9 to exit\n";
        cin>>ch;
    }while(ch<=8);
    return 0;
}
