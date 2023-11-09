#include<iostream>
#include<cstring>
#include<ctype.h>
#include<string.h>
using namespace std;
class Hashsrch
{
	int address,R,n,i,count;
	bool avail[15];
	string table[15];
	public:
		Hashsrch()
		{
			cout<<"Enter the size";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				avail[i]=0;
			}
			count=1;
		}
		int hash(string name)
		{
			int sum=0;
			for(i=0;i<=name.length();i++)
				sum+=name[i];
			cout<<"Sum = "<<sum<<"\n";
			return (sum %n);
		}
        void add(string name)
        {
		address=hash(name);
		if(avail[address]==0)
		{
			table[address]=name;
			avail[address]=1;
			if(count==1)
			{
				R=address;
				count++;
			}
		}
		else
		{
			do
			{
				address=(address+1)%n;
				
			}while(avail[address]!=0&&address!=R);
			table[address]=name;
			avail[address]=1;
		   }
	}
	void retreival(string name)
	{
		address=hash(name);
	
		if(table[address]==name)
		    cout<<name<<" found at address "<<address<<"\n";
		else
		{
			do
			{
					address=(address+1)%n;
					if(table[address]==name)
					{
						cout<<"String "<<name<<" found at address "<<address<<"\n";
						return;
					}
			}while(avail[address]!=0&&address!=R);
			cout<<" Not found\n";
		}
	}
	void display()
	{

		for(int i=0;i<n;i++)
			cout<<table[i]<<" "<<"present at index: "<<i<<"\n";
	}
};
int main()
{
	Hashsrch h;
	int ch;
	string name;
	do{
		cout<<"Enter the choice\n1.Storage 2.Retrieval 3.Display\n";
		cin>>ch;
		switch(ch){
		case 1:
		 	cout<<"Enter the String\n";
			cin>>name;
			h.add(name);
			cout<<name<<" inserted into table";
			break;
		case 2:
			cout<<"Enter the name to be searched:\n";
			cin>>name;
			h.retreival(name);
			break;
		case 3:
			h.display();
			break;
		default:
			cout<<"Invalid choice\n";
			break;
		}
	}while(ch<=3);
	return 0;
}
/*Enter the size 3
3
Enter the choice
1.Storage 2.Retrieval 3.Display
1
Enter the String
ate
Sum = 314
ate inserted into tableEnter the choice
1.Storage 2.Retrieval 3.Display
1
Enter the String
dad
Sum = 297
dad inserted into tableEnter the choice
1.Storage 2.Retrieval 3.Display
1
Enter the String
eat
Sum = 314
eat inserted into tableEnter the choice
1.Storage 2.Retrieval 3.Display
3
dad present at index: 0
eat present at index: 1
ate present at index: 2
Enter the choice
1.Storage 2.Retrieval 3.Display
2
Enter the name to be searched:
eat
Sum = 314
String eat found at address 1Enter the choice
1.Storage 2.Retrieval 3.Display
*/
