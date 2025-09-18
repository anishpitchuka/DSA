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
    if (top == NULL) return '\0';
    Node* temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}

char peek() {
    if(top == NULL) return '\0';
    return top->data;
}

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return -1;
}

void infixToPostfix(char* exp, char* result) {
    int k = 0;
    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) result[k++] = exp[i];
        else if (exp[i] == '(') push(exp[i]);
        else if (exp[i] == ')') {
            while (top != NULL && peek() != '(') result[k++] = pop();
            pop();
        } else {
            while (top != NULL && precedence(peek()) >= precedence(exp[i]))
                result[k++] = pop();
            push(exp[i]);
        }
    }
    while (top != NULL) {
        result[k++] = pop();
    } 
    result[k] = '\0';
}

typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

IntNode* itop = NULL;

void ipush(int x) {
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    newNode->data = x;
    newNode->next = itop;
    itop = newNode;
}

int ipop() {
    if (itop == NULL) return -1;
    IntNode* temp = itop;
    int val = temp->data;
    itop = itop->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) ipush(exp[i] - '0');
        else {
            int val2 = ipop();
            int val1 = ipop();
            switch (exp[i]) {
                case '+': ipush(val1 + val2); break;
                case '-': ipush(val1 - val2); break;
                case '*': ipush(val1 * val2); break;
                case '/': ipush(val1 / val2); break;
            }
        }
    }
    return ipop();
}

int main(){
    char exp[100], postfix[100];
    printf("Enter Infix: ");
    scanf("%s", exp);
    infixToPostfix(exp, postfix);
    printf("Postfix: %s\n", postfix);
    printf("Evaluation: %d\n", evaluatePostfix(postfix));
    return 0;
}


