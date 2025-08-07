#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int rmax[m];
    int cmax[n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
       int max=0;
       for(int j=0;j<n;j++){
            if(max < a[i][j]){
                max=a[i][j];
            }
       }
       rmax[i] = max;
    }
    for(int j=0;j<n;j++){
        int max = 0;
        for(int i=0;i<m;i++){
            if(max < a[i][j]){
                max = a[i][j];
            }
        }
        cmax[j] = max;
    }
    for(int i=0;i<m;i++){
        cout<<rmax[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<n;j++){
        cout<<cmax[j]<<" ";
    }
}