#include <iostream>
using namespace std;
#define sz 100000

bool func(int a[],int n,int i,int sum,int key){
    if(sum>key)return 0;
    if(i==n)return 0;
    if(sum==key)return 1;
    return func(a,n,i+1,sum,key)|func(a,n,i+1,sum+a[i],key);
}



int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[sz];
        for(int i=0;i<n;i++)cin>>a[i];
        int key;
        cin>>key;

        cout<<func(a,0,n,0,key);
    }
    
    return 0;
}