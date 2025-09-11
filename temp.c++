// #include <iostream> //5B-Q1 and 5A-Q1
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };
// Node* createCircularList(int n) {
//     if (n <= 0) {
//         cout << "Invalid size" << endl;
//         return nullptr;
//     }
//     Node *head = nullptr, *temp = nullptr, *newNode = nullptr;
//     int value;
//     cout << "Enter value for node 1: ";
//     cin >> value;
//     head = new Node{value, nullptr};
//     head->next = head;
//     temp = head;
//     for (int i = 2; i <= n; i++) {
//         cout << "Enter value for node " << i << ": ";
//         cin >> value;
//         newNode = new Node{value, head}; 
//         temp->next = newNode;
//         temp = newNode;
//     }

//     return head;
// }
// void printCircularList(Node* head) {
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return;
//     }
//     Node* temp = head;
//     cout << "Circular Linked List: ";
//     do {
//         cout << temp->data << " ";
//         temp = temp->next;
//     } while (temp != head);
//     cout << endl;
// }
// Node* deleteByKey(Node* head, int key) {
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return nullptr;
//     }
//     Node *curr = head, *prev = nullptr; 
//     if (head->next == head && head->data == key) {
//         delete head;
//         return nullptr;
//     }
//     if (head->data == key) {
//         Node* last = head;
//         while (last->next != head) {
//             last = last->next;
//         }
//         last->next = head->next;
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return head;
//     } 
//     prev = head;
//     curr = head->next;
//     while (curr != head) {
//         if (curr->data == key) {
//             prev->next = curr->next;
//             delete curr;
//             return head;
//         }
//         prev = curr;
//         curr = curr->next;
//     }
//     cout << "Key " << key << " not found in list." << endl;
//     return head;
// }

// int main() {
//     Node* head = nullptr;
//     int n, key;
//     cout << "Enter number of nodes: ";
//     cin >> n;
//     head = createCircularList(n);
//     cout << "\nBefore deletion:\n";
//     printCircularList(head);
//     cout << "\nEnter key to delete: ";
//     cin >> key;
//     head = deleteByKey(head, key);
//     cout << "\nAfter deletion:\n";
//     printCircularList(head);
// }

// =========================================================================//

// #include <iostream> //5B-Q2
// using namespace std;

// struct Node {
//     char data;
//     Node* prev;
//     Node* next;
// };
// Node* createDoublyLinkedList(int n) {
//     if (n <= 0) {
//         cout << "Invalid size" << endl;
//         return nullptr;
//     }
//     Node *head = nullptr, *tail = nullptr, *newNode = nullptr;
//     char value;
//     cout << "Enter character for node 1: ";
//     cin >> value;
//     head = new Node{value, nullptr, nullptr};
//     tail = head;
//     for (int i = 2; i <= n; i++) {
//         cout << "Enter character for node " << i << ": ";
//         cin >> value;
//         newNode = new Node{value, tail, nullptr};
//         tail->next = newNode;
//         tail = newNode;
//     }
//     return head;
// }
// void printList(Node* head) {
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return;
//     }
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
// Node* rotateList(Node* head, int k, int n) {
//     if (head == nullptr || k == 0 || k >= n) return head;

//     Node* current = head;
//     int count = 1;
//     while (count < k && current != nullptr) {
//         current = current->next;
//         count++;
//     }
//     Node* kthNode = current;
//     Node* tail = head;
//     while (tail->next != nullptr) {
//         tail = tail->next;
//     }
//     tail->next = head;    
//     head->prev = tail;

//     head = kthNode->next; 
//     head->prev = nullptr;

//     kthNode->next = nullptr; 

//     return head;
// }

// int main() {
//     int n, k;
//     Node* head = nullptr;
//     cout << "Enter number of nodes: ";
//     cin >> n;
//     head = createDoublyLinkedList(n);
//     cout << "\nOriginal List: ";
//     printList(head);
//     cout << "Enter K (rotation count): ";
//     cin >> k;
//     head = rotateList(head, k, n);
//     cout << "\nRotated List: ";
//     printList(head);
// }

//==================================================================//

// #include <iostream> //B-Q3 and A-Q3
// using namespace std;

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };
// Node* createDoublyLinkedList(int n) {
//     if (n <= 0) {
//         cout << "Invalid size" << endl;
//         return nullptr;
//     }
//     Node *head = nullptr, *tail = nullptr, *newNode = nullptr;
//     int value;
//     cout << "Enter value for node 1: ";
//     cin >> value;
//     head = new Node{value, nullptr, nullptr};
//     tail = head;
//     for (int i = 2; i <= n; i++) {
//         cout << "Enter value for node " << i << ": ";
//         cin >> value;
//         newNode = new Node{value, tail, nullptr};
//         tail->next = newNode;
//         tail = newNode;
//     }
//     return head;
// }

// void printList(Node* head) {
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return;
//     }
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
// Node* reverseList(Node* head) {
//     if (head == nullptr) return head;
//     Node* current = head;
//     Node* temp = nullptr;
//     while (current != nullptr) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev; 
//     }
//     if (temp != nullptr) {
//         head = temp->prev;
//     }
//     return head;
// }

// int main() {
//     int n;
//     Node* head = nullptr;
//     cout << "Enter number of nodes: ";
//     cin >> n;
//     head = createDoublyLinkedList(n);
//     cout << "\nOriginal List: ";
//     printList(head);
//     head = reverseList(head);
//     cout << "\nReversed List: ";
//     printList(head);
// }

//===============================================================//

// #include <iostream> //5A-Q2
// using namespace std;

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };


// Node* createDoublyLinkedList(int n) {
//     if (n <= 0) {
//         cout << "Invalid size" << endl;
//         return nullptr;
//     }

//     Node *head = nullptr, *tail = nullptr;
//     int value;

//     cout << "Enter value for node 1: ";
//     cin >> value;
//     head = new Node{value, nullptr, nullptr};
//     tail = head;

//     for (int i = 2; i <= n; i++) {
//         cout << "Enter value for node " << i << ": ";
//         cin >> value;
//         Node* newNode = new Node{value, tail, nullptr};
//         tail->next = newNode;
//         tail = newNode;
//     }

//     return head;
// }

// void printList(Node* head) {
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return;
//     }

//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// Node* removeDuplicates(Node* head) {
//     if (head == nullptr) return head;

//     Node* current = head;


//     while (current != nullptr) {
//         Node* runner = current->next;

//         // Inner loop to check duplicates ahead
//         while (runner != nullptr) {
//             if (runner->data == current->data) {
//                 // Duplicate found → remove it
//                 Node* duplicate = runner;
//                 runner = runner->next;

//                 if (duplicate->prev != nullptr)
//                     duplicate->prev->next = duplicate->next;
//                 if (duplicate->next != nullptr)
//                     duplicate->next->prev = duplicate->prev;

//                 delete duplicate;
//             } else {
//                 runner = runner->next;
//             }
//         }
//         current = current->next;
//     }

//     return head;
// }


// int main() {
//     int n;
//     Node* head = nullptr;

//     cout << "Enter number of nodes: ";
//     cin >> n;

//     head = createDoublyLinkedList(n);

//     cout << "\nOriginal List: ";
//     printList(head);

//     head = removeDuplicates(head);

//     cout << "\nList after removing duplicates: ";
//     printList(head);

//     return 0;
// }

//==============================================================//

// #include <iostream> //6B-Q1 and 6A-Q1
// #include <cctype>
// #include <string>
// #include <sstream>
// using namespace std;

// struct Stack {
//     int top;
//     int capacity;
//     char* arr;

//     Stack(int size) {
//         capacity = size;
//         top = -1;
//         arr = new char[capacity];
//     }

//     void push(char c) {
//         if (top == capacity - 1) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         arr[++top] = c;
//     }

//     char pop() {
//         if (top == -1) {
//             cout << "Stack Underflow\n";
//             return '\0';
//         }
//         return arr[top--];
//     }

//     char peek() {
//         if (top == -1) return '\0';
//         return arr[top];
//     }

//     bool isEmpty() {
//         return top == -1;
//     }
// };


// struct IntStack {
//     int top;
//     int capacity;
//     int* arr;

//     IntStack(int size) {
//         capacity = size;
//         top = -1;
//         arr = new int[capacity];
//     }

//     void push(int val) {
//         if (top == capacity - 1) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         arr[++top] = val;
//     }

//     int pop() {
//         if (top == -1) {
//             cout << "Stack Underflow\n";
//             return -1;
//         }
//         return arr[top--];
//     }

//     bool isEmpty() {
//         return top == -1;
//     }
// };


// int precedence(char op) {
//     if (op == '+' || op == '-') return 1;
//     if (op == '*' || op == '/') return 2;
//     if (op == '^') return 3;
//     return 0;
// }


// string infixToPostfix(string infix) {
//     Stack st(infix.size());
//     string postfix;

//     for (char ch : infix) {
//         if (isspace(ch)) continue;

//         if (isalnum(ch)) { // operand
//             postfix += ch;
//             postfix += ' ';
//         }
//         else if (ch == '(') {
//             st.push(ch);
//         }
//         else if (ch == ')') {
//             while (!st.isEmpty() && st.peek() != '(') {
//                 postfix += st.pop();
//                 postfix += ' ';
//             }
//             if (!st.isEmpty()) st.pop(); // remove '('
//         }
//         else { // operator
//             while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
//                 postfix += st.pop();
//                 postfix += ' ';
//             }
//             st.push(ch);
//         }
//     }

//     while (!st.isEmpty()) {
//         postfix += st.pop();
//         postfix += ' ';
//     }

//     return postfix;
// }


// int evaluatePostfix(string postfix) {
//     IntStack st(postfix.size());
//     stringstream ss(postfix);
//     string token;

//     while (ss >> token) {
//         if (isdigit(token[0])) {
//             st.push(stoi(token));
//         }
//         else {
//             int val2 = st.pop();
//             int val1 = st.pop();
//             switch (token[0]) {
//                 case '+': st.push(val1 + val2); break;
//                 case '-': st.push(val1 - val2); break;
//                 case '*': st.push(val1 * val2); break;
//                 case '/': st.push(val1 / val2); break;
//                 case '^': {
//                     int res = 1;
//                     for (int i = 0; i < val2; i++) res *= val1;
//                     st.push(res);
//                     break;
//                 }
//             }
//         }
//     }

//     return st.pop();
// }

// int main() {
//     string infix;
//     cout << "Enter infix expression: ";
//     getline(cin, infix);

//     string postfix = infixToPostfix(infix);
//     cout << "Postfix expression: " << postfix << endl;

//     int result = evaluatePostfix(postfix);
//     cout << "Evaluation result: " << result << endl;


// }

//===================================================================//

// #include <iostream> //6B-Q2
// #include <string>
// using namespace std;

// // ---------- STACK IMPLEMENTATION ----------
// struct Stack {
//     int top;
//     int capacity;
//     int* arr;

//     Stack(int size) {
//         capacity = size;
//         top = -1;
//         arr = new int[capacity];
//     }

//     void push(int val) {
//         if (top == capacity - 1) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         arr[++top] = val;
//     }

//     int pop() {
//         if (top == -1) {
//             return -1; // underflow
//         }
//         return arr[top--];
//     }

//     int peek() {
//         if (top == -1) return -1;
//         return arr[top];
//     }

//     bool isEmpty() {
//         return top == -1;
//     }
// };

// // ---------- FUNCTION TO CHECK BALANCED ----------
// void checkBalancedParentheses(const string& expr) {
//     Stack st(expr.size());
//     int lastBalancedIndex = -1;

//     for (int i = 0; i < (int)expr.size(); i++) {
//         char ch = expr[i];

//         if (ch == '(' || ch == '{' || ch == '[') {
//             st.push(i); // push index
//         } 
//         else if (ch == ')' || ch == '}' || ch == ']') {
//             if (!st.isEmpty()) {
//                 int openIndex = st.pop();
//                 char openChar = expr[openIndex];

//                 // Check matching pairs
//                 if ((openChar == '(' && ch != ')') ||
//                     (openChar == '{' && ch != '}') ||
//                     (openChar == '[' && ch != ']')) {
//                     cout << "Unbalanced at index " << i << endl;
//                     cout << "Longest balanced prefix: [0.." << lastBalancedIndex << "]" << endl;
//                     return;
//                 } else {
//                     // valid pair, update last balanced index
//                     lastBalancedIndex = i;
//                 }
//             } else {
//                 // No matching opening
//                 cout << "Unbalanced at index " << i << endl;
//                 cout << "Longest balanced prefix: [0.." << lastBalancedIndex << "]" << endl;
//                 return;
//             }
//         }
//     }

//     if (st.isEmpty()) {
//         cout << "Balanced Expression ✅" << endl;
//     } else {
//         cout << "Unbalanced: Extra opening bracket(s)" << endl;
//         cout << "Longest balanced prefix: [0.." << lastBalancedIndex << "]" << endl;
//     }
// }


// int main() {
//     string expr;
//     cout << "Enter expression: ";
//     getline(cin, expr);

//     checkBalancedParentheses(expr);

//     return 0;
// }

//====================================================================//

// #include <iostream> //6B-Q3
// using namespace std;

// // ---------- STACK IMPLEMENTATION ----------
// struct Stack {
//     int top;
//     int capacity;
//     int* arr;

//     Stack(int size) {
//         capacity = size;
//         top = -1;
//         arr = new int[capacity];
//     }

//     void push(int val) {
//         if (top == capacity - 1) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         arr[++top] = val;
//     }

//     int pop() {
//         if (top == -1) {
//             cout << "Stack Underflow\n";
//             return -1;
//         }
//         return arr[top--];
//     }

//     bool isEmpty() {
//         return top == -1;
//     }

//     int peek() {
//         if (top == -1) return -1;
//         return arr[top];
//     }
// };

// // ---------- QUEUE USING TWO STACKS ----------
// struct Queue {
//     Stack s1, s2;

//     Queue(int size) : s1(size), s2(size) {}

//     // Enqueue operation
//     void enqueue(int val) {
//         s1.push(val);
//         cout << val << " enqueued\n";
//     }

//     // Dequeue operation
//     int dequeue() {
//         if (s1.isEmpty() && s2.isEmpty()) {
//             cout << "Queue is empty\n";
//             return -1;
//         }

//         // If s2 is empty, transfer all from s1
//         if (s2.isEmpty()) {
//             while (!s1.isEmpty()) {
//                 s2.push(s1.pop());
//             }
//         }

//         int val = s2.pop();
//         cout << val << " dequeued\n";
//         return val;
//     }

//     // Display queue
//     void display() {
//         if (s1.isEmpty() && s2.isEmpty()) {
//             cout << "Queue is empty\n";
//             return;
//         }

//         // Print s2 (already reversed)
//         for (int i = s2.top; i >= 0; i--) {
//             cout << s2.arr[i] << " ";
//         }

//         // Print s1 (in correct order from bottom to top)
//         for (int i = 0; i <= s1.top; i++) {
//             cout << s1.arr[i] << " ";
//         }
//         cout << endl;
//     }
// };

// // ---------- DRIVER CODE ----------
// int main() {
//     int size, choice, value;
//     cout << "Enter queue size: ";
//     cin >> size;

//     Queue q(size);

//     do {
//         cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1:
//                 cout << "Enter value: ";
//                 cin >> value;
//                 q.enqueue(value);
//                 break;
//             case 2:
//                 q.dequeue();
//                 break;
//             case 3:
//                 q.display();
//                 break;
//             case 4:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice\n";
//         }
//     } while (choice != 4);

//     return 0;
// }

//==============================================================//