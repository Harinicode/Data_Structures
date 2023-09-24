#include<iostream>                                                          //bubble sort
using namespace std;
int main()                                                                  //sorted
{
    int n,a[10];
    bool sorted=false;
    cout<<"Enter the size of the array: ";
     cin>>n;
    cout<<"Enter "<<n<<" elemenets: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;((i<n)&&(sorted==false));i++)
    {
        sorted=true;
        for(int j=n-1;j>i;j--)
            if(a[j]<a[j-1])
            {
                sorted=false;
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;

            }
            
        cout<<"After pass:"<<i+1;
        for(int k=0;k<n;k++)
        cout<<a[k]<<"\t";
        cout<<endl;
        
    }
    return 0;
}
