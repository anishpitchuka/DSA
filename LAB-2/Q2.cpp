#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int *ptr = v;

    // cout<<"a: addresses: "<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<ptr+i<<"-"<<*(ptr+i)<<endl;
    // }

    // cout<<"b: ";
    // int sum = 0;
    // for(int i=0;i<n;i++){
    //     sum = sum + *(ptr+i);
    // }
    // cout<<sum<<endl;
    
    cout<<"c: "<<endl;
    int m;
    cin>>m;
    int i;
    for( i=n-1; i>=0 && *(v+i) > m; i--){
        *(ptr + i + 1) = *(ptr + i);
    }
    *(v+i+1) = m;
    for(int i=0;i<n+1;i++){
        cout<<*(ptr+i)<<" ";
    }

    // cout<<"d: ";
    // int *l = v;
    // int *r = v + n -1;
    // while(l<=r){
    //     int temp = *l;
    //     *l = *r;
    //     *r = temp;
    //     l++;
    //     r--;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<v+i<<"-"<<*(v+i)<<endl;
    // }
    // cout<<"e: ";
    // int j,k;
    // cin>>j>>k;
    // int temp = *(v+j);
    // *(v+j) = *(v+k);
    // *(v+k) = temp;
    // for(int i=0;i<n;i++){
    //     cout<<v+i<<"-"<<*(v+i)<<endl;
    // }
}