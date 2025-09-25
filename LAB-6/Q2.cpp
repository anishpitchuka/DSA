// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct Node {
//     char data;
//     struct Node* next;
// } Node;

// Node* top = NULL;

// void push(char c) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = c;
//     newNode->next = top;
//     top = newNode;
// }

// char pop() {
//     if (top == NULL) return '\0';
//     Node* temp = top;
//     char c = temp->data;
//     top = top->next;
//     free(temp);
//     return c;
// }

// int isBalanced(char* exp) {
//     for (int i = 0; exp[i]; i++) {
//         if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);
//         else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
//             char c = pop();
//             if ((exp[i] == ')' && c != '(') ||
//                 (exp[i] == '}' && c != '{') ||
//                 (exp[i] == ']' && c != '[')) return 0;
//         }
//     }
//     return top == NULL;
// }

// int main() {
//     char exp[100];
//     printf("Enter Expression: ");
//     scanf("%s", exp);
//     if (isBalanced(exp)) printf("Balanced\n");
//     else printf("Not Balanced\n");
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if(top == NULL) return '\0';
    Node *temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}

int isBalanced(char *exp) {
    for(int i = 0; exp[i]; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char c = pop();
            if((exp[i] == ')' && c != '(') || 
               (exp[i] == '}' && c != '{') ||
               (exp[i] == ']' && c != '[')) return 0;
        }
    }
    return top == NULL;
}

int main() {
    char exp[100];
    cout<<"Enter the expression: ";
    cin>>exp;
    if(isBalanced(exp)) {
        cout<<"balanced";
    } else {
        cout<<"unbalanced";
    }
}