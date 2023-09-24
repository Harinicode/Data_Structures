#include<iostream>
using namespace std;
int main()
{
    int n,a[10],i,j;
    int hold;
    cout<<"Enter the size of the array: ";
     cin>>n;
    cout<<"Enter "<<n<<" elemenets: ";
    for(i=0;i<n;i++)
        cin>>a[i];                                                    //insertion sort
                                                                      //hold
    for(i=1;i<n;i++)
    {
        hold=a[i];
        for(j=i-1;(j>=0)&&(hold<a[j]);j--)
            a[j+1]=a[j];
        a[j+1]=hold;
        cout<<"After Pass: "<<i+1<<"\t";;
        for(int k=0;k<n;k++)
        cout<<a[k]<<"\t";
        cout<<endl;
    }
    
    return 0;
}
