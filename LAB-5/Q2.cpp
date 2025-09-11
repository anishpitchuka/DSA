#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};
Node* createList(string str) {
    if(str.empty()) return nullptr;
    Node* head = new Node(str[0]);
    Node* current = head;
    for(int i=1;i<str.length();i++) {
        current->next = new Node(str[i]);
        current = current->next;
    }
    current->next = head;
    return head;
}
int compare(Node* s1, Node* s2) {
    if (s1 == nullptr && s2 == nullptr) return 0;
    if (s1 == nullptr) return -1;
    if (s2 == nullptr) return 1;
    Node* start1 = s1;
    Node* start2 = s2;
    do {
        if (s1->data < s2->data) return -1;
        if (s1->data > s2->data) return 1;
        
        s1 = s1->next;
        s2 = s2->next;
    } while (s1 != start1 && s2 != start2);

    if(s1 != start1 && s2 == start2) return 1;
    if(s1 == start1 && s2 != start2) return -1;
    return 0; 
}

int main() {
    string str1, str2;
    cout<<"Enter first string: ";
    cin>>str1;
    cout<<"Enter second string: ";
    cin>>str2;
    Node* list1 = createList(str1);
    Node* list2 = createList(str2); 
    int result = compare(list1, list2); 
    cout<<result<<endl;
}