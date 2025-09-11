#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* createCircularList(int n) {
    if(n <= 0) {
        cout<<"Invalid size"<<endl;
        return nullptr;
    }
    Node *head = nullptr, *temp = nullptr, *newNode = nullptr;
    int value;
    cout<<"Enter value for node 1: ";
    cin>>value;
    head = new Node{value, nullptr};
    head->next = head;
    temp = head;
    for(int i = 2; i <= n; i++) {
        cout<<"Enter value for node " << i << ": ";
        cin>>value;
        newNode = new Node{value, head}; 
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}
void printCircularList(Node* head) {
    if(head == nullptr) {
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp = head;
    cout<<"Circular Linked List: ";
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}
Node* addByKey(Node* head, int add, int pos) {
    if(head == nullptr) {
        cout<<"List is empty."<<endl;
        return nullptr;
    }
    Node* newNode = new Node{add, nullptr}; 
    if(pos == 1) {
        Node* last = head;
        while(last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        return newNode;
    }  
    Node* curr = head;
    for(int i = 1; i < pos-1 && curr->next != head; i++) {
        curr = curr->next;
    } 
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}
Node* deleteByKey(Node* head, int key) {
    if(head == nullptr) {
        cout<<"List is empty."<<endl;
        return nullptr;
    }
    Node *curr = head, *prev = nullptr; 
    if(head->next == head && head->data == key) {
        delete head;
        return nullptr;
    }
    if(head->data == key) {
        Node* last = head;
        while(last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    prev = head;
    curr = head->next;
    while(curr != head) {
        if(curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    cout<<"Key "<<key<<" not found in list."<<endl;
    return head;
}

Node* updateByKey(Node* head, int updt, int posi) {
    if(head == nullptr) {
        cout<<"List is empty."<<endl;
        return nullptr;
    }
    Node* current = head;
    int count = 1;
    if(posi == 1) {
        head->data = updt;
        return head;
    }
    while(current->next != head && count < posi) {
        current = current->next;
        count++;
    }
    if(count == posi) {
        current->data = updt;
    } else {
        cout<<"Position "<<posi<<" not found in list."<<endl;
    }
    return head;
}

int main() {
    Node* head = nullptr;
    int n, key,add,pos;
    cout<<"Enter number of nodes: ";
    cin>>n;
    head = createCircularList(n);
    cout<<"\nBefore deletion:\n";
    printCircularList(head);
    cout<<"\nEnter the value to be added:\n";
    cin>>add;
    cout<<"\nEnter the position to be added at:\n";
    cin>>pos;
    head = addByKey(head, add, pos);
    printCircularList(head);
    cout << "\nEnter key to delete: ";
    cin >> key;
    head = deleteByKey(head, key);
    cout<<"\nAfter deletion:\n";
    printCircularList(head);
    int updt, posi;
    cout<<"\nEnter the position to be updated:\n";
    cin>>posi;
    cout<<"\nEnter the value to be changed into:\n";
    cin>>updt;
    head = updateByKey(head, updt, posi);
    printCircularList(head);
}
