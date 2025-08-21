#include <bits/stdc++.h>
using namespace std;
struct EMPLOYEE{
    int Employee_Id;
    string Employee_name;
    int Basic_salary;

};
int main(){
    struct EMPLOYEE emp[5];
    for(int i=0;i<5;i++){
        cin>>(emp+i)->Employee_Id;
        cin>>(emp+i)->Employee_name;
        cin>>(emp+i)->Basic_salary;
    }
    for(int i=0;i<5;i++){
        cout<<(emp+i)->Employee_Id<<" ";
        cout<<(emp+i)->Employee_name<<" ";
        cout<<(emp+i)->Basic_salary<<" ";
        cout<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<"The size of "<<i<<" employee record is "<<sizeof(emp[i])<<endl;
    }
  
    for(int i=0;i<5;i++){
        cout<<"The address of the employee "<<i<<" is "<<&emp[i]<<endl;
        //51 52 53 54 55 56 57 58 59 5a 5b 5c 5d 5e 5f
        //60 61 62 63 64 65 66 67 68 69 6a 6b 6c 6d 6e 6f 70 
        //difference == 32
    }
    struct EMPLOYEE  *p = emp;
    cout<<p<<endl;
    cout<<++p<<endl;
    //diff between addresses is 32
    p=--p;
    for(int i=0;i<5;i++){
        cout<<(p+i)->Employee_Id<<" ";
        cout<<(p+i)->Employee_name<<" ";
        cout<<(p+i)->Basic_salary<<" ";
        cout<<endl;

    }
    for(int i=0;i<5;i++){
        cout<<&((p+i)->Employee_Id)<<" ";
        cout<<&((p+i)->Employee_name)<<" ";
        cout<<&((p+i)->Basic_salary)<<" ";
        cout<<endl;
    }

}

/*
1
a
100
2
b
200
3
c
300
4
d
400
5
e
500
*/