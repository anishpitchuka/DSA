#include <bits/stdc++.h>
using namespace std;

struct student {
    char name [20];
    int age;
    int marks;
    struct student *next;
};

int main(){
    struct student s1, s2, s3;
    cin>>s1.name>>s1.age>>s1.marks;
    cin>>s2.name>>s2.age>>s2.marks;
    cin>>s3.name>>s3.age>>s3.marks;
    
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;

    cout<<s1.name<<endl;
    cout<<s1.age<<endl;
    cout<<s1.marks<<endl;

    cout<<s1.next->name<<endl;
    cout<<s1.next->age<<endl;
    cout<<s1.next->marks<<endl;

    cout<<(s1.next)->next->name<<endl;
    cout<<(s1.next)->next->age<<endl;
    cout<<(s1.next)->next->marks<<endl;

    cout<<((s1.next)->next)->name<<endl;
    cout<<((s1.next)->next)->age<<endl;
    cout<<((s1.next)->next)->marks<<endl;

    struct student *ptr = s1.next;

    cout<<ptr->name<<endl;
    cout<<ptr->age<<endl;
    cout<<ptr->marks<<endl;

    cout<<(ptr->next)->name<<endl;
    cout<<(ptr->next)->age<<endl;
    cout<<(ptr->next)->marks<<endl;

    cout<<((ptr->next)->next)->name<<endl;
    cout<<((ptr->next)->next)->age<<endl;
    cout<<((ptr->next)->next)->marks<<endl;

}

/*
jack
5
10
jill
4
9
peter
6
8
*/
