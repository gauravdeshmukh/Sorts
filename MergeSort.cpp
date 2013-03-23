#include <iostream>

using namespace std;

int n;
int *t;

void merge(int *arr,int start,int mid,int end)
{
    for(int i=start;i<=end;i++) {t[i]=arr[i];}
    int l=start,h=mid+1,m=mid+1,i=start;
    while(l<m&&h<=end)
    {
        if(t[l]>t[h]) {arr[i++]=t[l++];}
        else {arr[i++]=t[h++];}
    }
    if(l<m)
    while(l<m) arr[i++]=t[l++];
    else if(h<=end)
    while(h<=end) arr[i++]=t[h++];
}

void sort(int *arr,int start,int end)
{
    t=new int[n];
    if(start==end) return;
    int mid=(start+end)/2;
    sort(arr,start,mid);
    sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main()
{
    cout<<"Enter number of elements:";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,0,n-1);
    cout<<"Sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
