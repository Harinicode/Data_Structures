#include<iostream>
using namespace std;
int main()                                          //Selection sort
{
    int n,a[10],i,j;                                //min
    int min;
    cout<<"Enter the size of the array: ";
     cin>>n;
    cout<<"Enter "<<n<<" elemenets: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
      min=i;
      for(j=i+1;j<n;j++)
        if(a[j]<a[min])
            min=j;
      if(min!=i)
        swap(a[i],a[min]);
      cout<<"After Pass:"<<i+1<<"\t";
        for(int k=0;k<n;k++)
        cout<<a[k]<<"\t";
        cout<<endl;
    }
    return 0;
}
