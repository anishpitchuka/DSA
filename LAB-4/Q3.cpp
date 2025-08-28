#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *createNode(int value){
    Node *newnode = (Node *)malloc(sizeof(newnode));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}



int main(){
    
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    // insertLatest(&head,1);
    // insertLatest(&head,2);
    // insertLatest(&head, 3);
    // insertLatest(&head, 4);
    // insertLatest(&head, 5);
    // printList(&head);
    int n1, n2;
    cin>>n1>>n2;
    int d1=0, d2=0;
    while(n1 > 0){
        int val = n1 % 10;
        d1++;
        n1 /= 10;
    }
    while(n2 > 0){
        int val = n2 % 10;
        d2++;
        n2 /= 10;
    }
    for(int i=0;i<n1;i++){
        insertLatest(&head, )
    }
    
}