include <iostream>
using namespace std;
int lr(int a[],int i,int n,int & loc,int e)
{
    if(i>n-1)
    {
     loc=-1;
     return 0;
     }
     if(e==a[i])
     {
       loc=i;
       return 1;
     }
    return lr(a,i+1,n,loc,e);
}
int main()
{
  int a[15],loc,ele,f=0,n;
  cin>>n;
  cout<<"Enter Elements";
  for(int i=0;i<n;i++)
   cin>>a[i];
   cin>>ele;
   f=lr(a,0,n,loc,ele);
   if(f)
   cout<<"found at location "<<loc;
  else
   cout<<"Not found";
  return 0;
  
}
