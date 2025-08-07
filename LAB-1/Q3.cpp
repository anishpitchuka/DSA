#include <bits/stdc++.h>
using namespace std;
int main(){
    // int option;
    // cout<<"Enter an option: ";
    // cin>>option;
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"The array is as follows:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The required addresses are: "<<endl;
    for(int i=0;i<n;i++){
        cout<<&a[0][i]<<" "<<&a[m-1][i]<<endl;

    }
    cout<<"The kth smallest element in the principal diagonal"<<endl;
    int k;
    cin>>k;
    int min_arr[n];
    for(int i=0;i<m;i++){
        min_arr[i] = a[i][i];
    }
    cout<<"Accessing elements using base address"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(a+i)+j)<<" ";
        }
        cout<<endl;
    }
}
