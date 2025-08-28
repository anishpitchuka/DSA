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
void insertLatest(Node **head, int value){
    Node *newnode = createNode(value);
    if(*head == NULL){
        *head = newnode;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
       
    }
    temp->next = newnode;
    return;
}

void printList(Node **head){
    Node *temp = *head;
    cout<<"head: ";
    while(temp != NULL){
        cout<<temp->data<<" ";
         temp = temp->next;
    }
   cout<<endl;
}



int main(){
    
    Node *head = (Node *)malloc(sizeof(Node));
    head = NULL;
    insertLatest(&head,1);
    insertLatest(&head,2);
    insertLatest(&head, 3);
    insertLatest(&head, 4);
    insertLatest(&head, 5);
    printList(&head);
    
}