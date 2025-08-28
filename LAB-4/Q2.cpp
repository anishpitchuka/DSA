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

void deleted(Node **head, int pos){
    if(*head == NULL) return;
    struct node *ptr = (*head);
    if(pos == 1){
        (*head) = ptr->next;
        free(ptr);
        return;
    }else{
        for(int j=1;j<pos-1;j++){
            ptr = ptr->next;
        }
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        return;
    }
}


void insertNode(Node **head, int val, int pos){
    if(*head == NULL) return;
    struct node *newNode = createNode(val);
    if(pos == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct node *ptr = *head;
    for(int i=1;i<pos-1;i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        cout<<"OUT OF RANGE"<<endl;
        free(newNode);
        return;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;

}

void gretearThanMean(Node **head){
    int sum = 0;
    int count = 0;
    struct node *temp = *head;
    while(temp != NULL){
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    if(count == 0) return;
    float mean = (float)sum / count;
    cout<<mean;
    cout<<endl;
    while(temp != NULL){
        if(temp->data > mean){
            cout<<temp->data;
            
        }
        temp = temp->next;
        
    }
    cout<<endl;

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
    int n;
    cout<<"enter size: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
       insertLatest(&head, x);
      
    }
    int value;
    cout<<"enter value";
    cin>>value;
    int pos;
    cout<<"enter position";
    cin>>pos;
    insertNode(&head, value, pos);
    printList(&head);
    int del_x;
    cout<<"enter a number to be deleted: ";
    cin>>del_x;
    deleted(&head, del_x);
    printList(&head);
    gretearThanMean(&head);
    
    
}