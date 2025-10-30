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

// #include <stdio.h>
// #include <stdlib.h>

// #define SIZE 100

// typedef struct {
//     int arr[SIZE];
//     int front, rear, count;
// } CircularQueue;

// // Initialize queue
// void initQueue(CircularQueue *q) {
//     q->front = 0;
//     q->rear = -1;
//     q->count = 0;
// }

// // Check if empty (underflow)
// int isEmpty(CircularQueue *q) {
//     return q->count == 0;
// }

// // Check if full
// int isFull(CircularQueue *q) {
//     return q->count == SIZE;
// }

// // Enqueue
// void enqueue(CircularQueue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue Overflow! Cannot insert %d\n", value);
//         return;
//     }
//     q->rear = (q->rear + 1) % SIZE;
//     q->arr[q->rear] = value;
//     q->count++;
//     printf("%d enqueued.\n", value);
// }

// // Dequeue
// int dequeue(CircularQueue *q) {
//     if (isEmpty(q)) {
//         printf("Queue Underflow!\n");
//         return -1;
//     }
//     int value = q->arr[q->front];
//     q->front = (q->front + 1) % SIZE;
//     q->count--;
//     printf("%d dequeued.\n", value);
//     return value;
// }

// // Display
// void display(CircularQueue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty.\n");
//         return;
//     }
//     printf("Queue: ");
//     int i, index;
//     for (i = 0; i < q->count; i++) {
//         index = (q->front + i) % SIZE;
//         printf("%d ", q->arr[index]);
//     }
//     printf("\n");
// }

// // Reverse first k elements using stack
// void reverseK(CircularQueue *q, int k) {
//     if (k > q->count || k <= 0) {
//         printf("Invalid k value.\n");
//         return;
//     }

//     int stack[SIZE], top = -1;
//     int i, index;

//     // Push first k elements to stack
//     for (i = 0; i < k; i++) {
//         index = (q->front + i) % SIZE;
//         stack[++top] = q->arr[index];
//     }

//     // Pop from stack and put back in queue
//     for (i = 0; i < k; i++) {
//         index = (q->front + i) % SIZE;
//         q->arr[index] = stack[top--];
//     }

//     printf("First %d elements reversed.\n", k);
// }

// int main() {
//     CircularQueue q;
//     initQueue(&q);

//     int choice, value, k;

//     while (1) {
//         printf("\n--- Circular Queue Menu ---\n");
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display\n");
//         printf("4. Reverse first k elements\n");
//         printf("5. Check Underflow\n");
//         printf("6. Exit\n");
//         printf("Enter choice: ");
//         scanf("%d", &choice);

//         if (choice == 1) {
//             printf("Enter value: ");
//             scanf("%d", &value);
//             enqueue(&q, value);
//         }
//         else if (choice == 2) {
//             dequeue(&q);
//         }
//         else if (choice == 3) {
//             display(&q);
//         }
//         else if (choice == 4) {
//             printf("Enter k: ");
//             scanf("%d", &k);
//             reverseK(&q, k);
//         }
//         else if (choice == 5) {
//             if (isEmpty(&q))
//                 printf("Queue Underflow (Empty).\n");
//             else
//                 printf("Queue is not empty.\n");
//         }
//         else if (choice == 6) {
//             exit(0);
//         }
//         else {
//             printf("Invalid choice.\n");
//         }
//     }
//     return 0;
// }

// ==============INSERTION SORT========================//

// #include <bits/stdc++.h>
// using namespace std;

// void insertionSort(int arr [], int n) {
//     for(int j = 1; j < n; j++) {
//         int key = arr[j];
//         int i = j - 1;
//         while(i >= 0 && arr[i] > key) {
//             arr[i + 1] = arr[i];
//             i--;
//         }
//         arr[i + 1] = key;

//     }
//         for(int i = 0; i < n; i++) {
//         cout<<arr[i]<<" ";
//     }

// }

// int main() {
//     int arr[] = {5,3,1,4,2,8,9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     for(int i = 0; i < 7; i++) {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"after sorted"<<endl;

//     insertionSort(arr, 7);
// }


//====================SELECTION SORT=======================//


// #include <bits/stdc++.h>
// using namespace std;

// void printArray(int arr [], int n) {
//     for(int i = 0; i < n; i++) {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void selectionSort(int arr [], int n) {
//     for(int i = 0; i < n - 1; i++) {
//         int min = i;
//         for(int j = i + 1; j < n; j++) {
//             if(arr[min] > arr[j]){
//                 min =j;
//             }
//         }
//         int temp = arr[i];
//         arr[i] = arr[min];
//         arr[min] = temp;
//     }
// }


// int main() {
//     int arr[] = {5,3,1,4,2,8,9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(arr, n);

//     selectionSort(arr, n);

//     printArray(arr, n);
// }

//==============   MERGE SORT  =================================//

// #include <bits/stdc++.h>
// using namespace std;

// void printArray(int arr [], int n) {
//     for(int i = 0; i < n; i++) {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void mergeArray(int leftArr[], int rightArr [], int arr[], int leftSize, int rightSize) {


//     int i = 0, j = 0, k = 0;
//     while(i < leftSize && j < rightSize) {
//         if(leftArr[i] <= rightArr[j]) {
//             arr[k] = leftArr[i];
//             k++;
//             i++;
//         } else {
//             arr[k] = rightArr[j];
//             k++;
//             j++;
//         }
//     }
//     while(i < leftSize) {
//         arr[k] = leftArr[i];
//         i++;
//         k++;
//     }
//     while(j < rightSize) {
//         arr[k] = rightArr[j];
//         k++;
//         j++;
//     }

// }

// void mergeSort(int arr [], int n) {
//     int length = n;
//     if(length <= 1) return;

//     int mid = n / 2;
//     int leftArr[mid];
//     int rightArr[n - mid];

//     for(int i = 0; i < mid; i++) {
//         leftArr[i] = arr[i];
//     }
//     for(int i = mid; i < n; i++) {
//         rightArr[i - mid] = arr[i];
//     }

//     mergeSort(leftArr, mid);
//     mergeSort(rightArr, n - mid);
//     mergeArray(leftArr, rightArr, arr, mid, n - mid);
// }



// int main() {
//     int arr[] = {5,3,1,4,2,8,9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(arr, n);

//     mergeSort(arr, n);
//     printArray(arr, n);
// }


//=========================QUICK SORT=========================//

// #include <iostream>
// using namespace std;

// void printArray(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         cout<<arr[i] <<" ";
//     }
//     cout<<endl;
// }

// int partition(int arr[], int start, int end) {

//     int pivot = arr[end];
//     int i = start - 1;
    
//     for(int j = start; j < end; j++) {
//         if(arr[j] < pivot) {
//             i++;
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     i++;
//     int temp = arr[i] ;
//     arr[i] = arr[end];
//     arr[end] = temp;

//     return i;

// }

// void quickSort(int arr[], int start, int end)  {
//     if(end <= start) return;

//     int pivot = partition(arr, start, end);
//     quickSort(arr, start, pivot - 1);
//     quickSort(arr, pivot + 1, end);
// }


// int main() {
//     int arr [] = {5,3,1,4,2,8,9};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printArray(arr, n);
//     quickSort(arr, 0, n-1);
//     printArray(arr, n);
// }
