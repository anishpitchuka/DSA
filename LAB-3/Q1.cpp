#include <bits/stdc++.h>
using namespace std;
struct vectorr{
    int x;
    int y;
    int z;

};
int main(){
    struct vectorr v1, v2;
    cout<<"Enter the data of v1: ";
    cin>>v1.x>>v1.y>>v1.z;
    cout<<endl<<"Enter the data of v2: ";
    cin>>v2.x>>v2.y>>v2.z;
    cout<<"The vector v1 is: "<<endl;
    cout<<v1.x<<" "<<v1.y<<" "<<v1.z;
    cout<<endl<<"The vector v2 is: "<<endl;
    cout<<v2.x<<" "<<v2.y<<" "<<v2.z;
    struct vectorr v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    cout<<endl<<"The resultant vector after adding is: ";
    cout<<v3.x<<" "<<v3.y<<" "<<v3.z;
    cout<<endl<<"After scaling: ";
    v1.x = v1.x * 10;
    v1.y = v1.y * 10;
    v1.z = v1.z * 10;
    v2.x = v2.x * 10;
    v2.y = v2.y * 10;
    v2.z = v2.z * 10;
    cout<<endl<<"Vector v1 is: ";
    cout<<v1.x<<" "<<v1.y<<" "<<v1.z;
    cout<<endl<<"Vector v2 is: ";
    cout<<v2.x<<" "<<v2.y<<" "<<v2.z;

}