#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

typedef struct {
    int arr[SIZE];
    int front, rear, count;
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

int isFull(CircularQueue *q) {
    return q->count == SIZE;
}

void enqueue(CircularQueue *q, int element) {
    if(isFull(q)) {
        cout<<"Queue overflow";
        return;
    }
    
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = element;
    q->count++;
    cout<<"Enqueued..."<<element<<" "<<endl;
}

int dequeue(CircularQueue *q) {
    if(isEmpty(q)) {
        cout<<"Queue underflow";
        return -1;
    }

    int element = q->arr[q->rear];
    q->front = (q->front + 1) % SIZE;
    q->count--;
    cout<<"Dequeued..."<<element<<" "<<endl;
    return element;
}

void display(CircularQueue *q) {
    if(isEmpty(q)) {
        cout<<"Queue is empty";
        return;
    }

    cout<<"Queue: ";
    for(int i = 0; i < q->count; i++) {
        int index = (q->front + i) %  SIZE;
        cout<<q->arr[index]<<" ";
    }
    cout<<endl;
}

void reverseK(CircularQueue *q, int k) {
    if(k > q->count || k < 0) {
        cout<<"Invalid k value: "<<endl;
        return;
    }
    int stack[SIZE];
    int top = -1;
    for(int i = 0; i < k; i++) {
        int index = (q->front + i) % SIZE;
        stack[++top] = q->arr[index];
    }

    for(int i = 0; i < k; i++) {
        int index = (q->front + i) % SIZE;
        q->arr[index] = stack[top--];
    }

    cout<<k<<endl;
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value, k;

    while(1) {
        cout<<"----Circular Queue Menu-----"<<endl;
        cout<<"Select a choice"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Reverse first k elements"<<endl;
        cout<<"5. Check underflow"<<endl;
        cout<<"6. Exit"<<endl;
        
        cin>>choice;

        if(choice == 1) {
            cout<<"Enter the value: "<<endl;
            cin>>value;
            enqueue(&q, value);
        } else if (choice == 2) {
            dequeue(&q);
        } else if (choice == 3) {
            display(&q);
        } else if (choice == 4) {
            cout<<"Enter the value of k: ";
            cin>>k;
            reverseK(&q, k);
            display(&q);
        } else if (choice == 5) {
            if(isEmpty(&q)) {
                cout<<"Queue underflow"<<endl;
            } else {
                cout<<"Queue is not empty"<<endl;
            }
        } else if (choice == 6) {
            exit(0);
        } else {
            cout<<"Invalid choice is selected"<<endl;
        }
    }
}