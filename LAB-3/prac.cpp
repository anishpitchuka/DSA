#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

int main(){
    struct node *head, *first, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    head = first;
    cout<<first->data<<" "<<second->data<<" "<<third->data<<" ";
    cout<<endl;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 4;
    ptr->next = first;
    head = ptr;
    cout<<ptr->data<<" "<<first->data<<" "<<second->data<<" "<<third->data<<" ";
    cout<<endl;
    struct node *mid = (struct node *)malloc(sizeof(struct node));
    mid->data = 5;
    first->next = mid;
    mid->next = second;
    cout<<ptr->data<<" "<<first->data<<" "<<mid->data<<" "<<second->data<<" "<<third->data;
    cout<<endl;
    struct node *end = (struct node *)malloc(sizeof(struct node));
    end->data = 6;
    third->next = end;
    end->next = NULL;
    cout<<ptr->data<<" "<<first->data<<" "<<mid->data<<" "<<second->data<<" "<<third->data<<" "<<end->data;
    cout<<endl;
    mid->next = third;
    free(second);
    struct node *walker;
    walker = head;
    while(walker != NULL){
        cout<<walker->data<<" ";
        walker = walker->next;
    }
}

/* struct node *ptr;
ptr = (struct node *)malloc(sizeof(struct node));

*/
