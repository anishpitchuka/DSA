#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int copy1 = n;
    int copy2 = n;
    int sum = 0;
    int digit_count=0;
    while(copy2>0){
        copy2/=10;
        digit_count++;
        
    }
    while(n>0){
        int digit = n%10;
        int temp = digit;
        for(int i=1;i<digit_count;i++){
            temp = temp * digit;
        }
        sum+=temp;
        n/=10;
    }
    if(sum == copy1){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}