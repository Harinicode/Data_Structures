#include <iostream>
using namespace std;
int lr(int a[],int b,int end,int e,int & loc)
{
    
    if(b>e)
    {
        loc=-1;
        return 0;
    }
    else
    {
      int mid=int((b+e)/2);
      if(e<a[mid])
      {
          return lr(a,b,mid-1,e,loc);
      }
     else
        if(e>a[mid])
      {
          return lr(a,mid+1,end,e,loc);
      }
     else
        {
            loc=mid;
            return 1;
        }
    }
}
int main()
{
  int a[15],loc,ele,f=1,beg=0,end,mid,n;
  cout<<"Enter Size";
  cin>>n;
  cout<<"Enter Elements";
  for(int i=0;i<n;i++)
   cin>>a[i];
   cout<<"Enter the element to be searched";
   cin>>ele;
   end=n-1;
   f=lr(a,beg,end,ele,loc);
   if(f)
   cout<<"found at index: "<<loc;
  else
   cout<<"Not found";
  return 0;

}
