#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[] = "abchjh";
    char* ptr1 = s;
    while (*ptr1 != '\0'){
        ptr1++;
    }
    int len1 = ptr1 - s;
    char t[] = "abc";
    char* ptr2 = t;
    while(*ptr2 != '\0'){
        ptr2++;
    }
    int len2 = ptr2 - t;
    cout<<len1<<","<<len2<<endl;
    if(len1 != len2){
        cout<<"Not Identical"<<endl;
        
        
    }else{
        bool flag = true;
        for(int i=0;i<len1;i++){
            if(s[i] != t[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"identical"<<endl;
        }else{
            cout<<"not identical"<<endl;
        }
    }
    
   
}
