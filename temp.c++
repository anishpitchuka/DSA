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


//------------Heapify-----------------//
// #include <stdio.h>

// // Function to heapify a subtree rooted at index i
// void heapify(int arr[], int n, int i) {
//     int largest = i;        // Initialize largest as root
//     int left = 2 * i + 1;   // Left child index
//     int right = 2 * i + 2;  // Right child index

//     // If left child exists and is greater than root
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child exists and is greater than current largest
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root, swap and recursively heapify
//     if (largest != i) {
//         int temp = arr[i];
//         arr[i] = arr[largest];
//         arr[largest] = temp;

//         // Recursively heapify the affected subtree
//         heapify(arr, n, largest);
//     }
// }

// // Function to build a max heap from the array
// void buildMaxHeap(int arr[], int n) {
//     for (int i = (n / 2) - 1; i >= 0; i--) {
//         heapify(arr, n, i);
//     }
// }

// // Function to remove and return the root (maximum element)
// int extractMax(int arr[], int *n) {
//     if (*n <= 0) {
//         printf("Heap is empty!\n");
//         return -1;
//     }

//     int root = arr[0];      // The maximum element (root)
//     arr[0] = arr[*n - 1];   // Move last element to root
//     (*n)--;                 // Reduce heap size
//     heapify(arr, *n, 0);    // Restore heap property

//     return root;
// }

// // Function to print the array
// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int n;

//     // Step 1: Take size input
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int arr[n]; // Declare array

//     // Step 2: Take array elements input
//     printf("Enter %d elements: ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Step 3: Display the original array
//     printf("\nOriginal array:\n");
//     printArray(arr, n);

//     // Step 4: Build the max heap using heapify
//     buildMaxHeap(arr, n);

//     printf("\nMax Heap after heapify:\n");
//     printArray(arr, n);

//     // Step 5: Remove root (maximum element)
//     int maxElement = extractMax(arr, &n);
//     printf("\nRemoved root (maximum element): %d\n", maxElement);

//     printf("\nHeap after removing root:\n");
//     printArray(arr, n);

//     return 0;
// }

//--------MAX HEAPS QUESTION----------------//
// #include <stdio.h>

// // Function to swap two integers
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Heapify a subtree rooted at index i
// void heapify(int arr[], int n, int i) {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left] > arr[largest])
//         largest = left;
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);
//         heapify(arr, n, largest);
//     }
// }

// // Build a max heap from array
// void buildMaxHeap(int arr[], int n) {
//     for (int i = (n / 2) - 1; i >= 0; i--)
//         heapify(arr, n, i);
// }

// // Print heap
// void printHeap(int arr[], int n) {
//     printf("ProcessID\tResources\n");
//     for (int i = 0; i < n; i++)
//         printf("%d\t\t%d\n", i + 1, arr[i]);
// }

// // (a) Print process with maximum resources
// void printMax(int arr[], int n) {
//     if (n <= 0) {
//         printf("Heap is empty.\n");
//         return;
//     }
//     printf("Process with maximum resources:\n");
//     printf("ProcessID: 1\tResources: %d\n", arr[0]);
// }

// // (b) Increase number of resources for a given process
// void increaseResources(int arr[], int n, int pid, int inc) {
//     if (pid < 1 || pid > n) {
//         printf("Invalid process ID!\n");
//         return;
//     }

//     int i = pid - 1;
//     arr[i] += inc;

//     // Fix heap upwards (bubble-up)
//     while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
//         swap(&arr[i], &arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }

//     printf("Resources increased successfully.\n");
// }

// // (c) Remove process with maximum resources
// int extractMax(int arr[], int *n) {
//     if (*n <= 0) {
//         printf("Heap is empty!\n");
//         return -1;
//     }

//     int max = arr[0];
//     arr[0] = arr[*n - 1];
//     (*n)--;

//     heapify(arr, *n, 0);

//     printf("Removed process with maximum resources (%d).\n", max);
//     return max;
// }

// // (d) Insert new process into heap
// void insertProcess(int arr[], int *n, int val) {
//     arr[*n] = val;
//     (*n)++;

//     int i = (*n) - 1;
//     while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
//         swap(&arr[i], &arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }

//     printf("Process inserted successfully.\n");
// }

// // (e) Sort processes in ascending order using heap sort
// void heapSort(int arr[], int n) {
//     buildMaxHeap(arr, n);
//     for (int i = n - 1; i > 0; i--) {
//         swap(&arr[0], &arr[i]);
//         heapify(arr, i, 0);
//     }
//     printf("Processes sorted in ascending order of resources.\n");
// }

// int main() {
//     int arr[50] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
//     int n = 11;
//     int choice, pid, val;

//     buildMaxHeap(arr, n);

//     do {
//         printf("\n========= PROCESS HEAP MENU =========\n");
//         printf("1. Display heap\n");
//         printf("2. Print process with maximum resources\n");
//         printf("3. Increase resources of a process\n");
//         printf("4. Remove process with maximum resources\n");
//         printf("5. Insert a new process\n");
//         printf("6. Sort processes (ascending order)\n");
//         printf("7. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printHeap(arr, n);
//                 break;
//             case 2:
//                 printMax(arr, n);
//                 break;
//             case 3:
//                 printf("Enter process ID to increase resources: ");
//                 scanf("%d", &pid);
//                 printf("Enter amount to increase: ");
//                 scanf("%d", &val);
//                 increaseResources(arr, n, pid, val);
//                 break;
//             case 4:
//                 extractMax(arr, &n);
//                 break;
//             case 5:
//                 printf("Enter resources required for new process: ");
//                 scanf("%d", &val);
//                 insertProcess(arr, &n, val);
//                 break;
//             case 6:
//                 heapSort(arr, n);
//                 printf("After sorting (ascending order):\n");
//                 for (int i = 0; i < n; i++)
//                     printf("%d ", arr[i]);
//                 printf("\n");
//                 break;
//             case 7:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice! Try again.\n");
//         }
//     } while (choice != 7);

//     return 0;
// }

//------------MAX HEAP-------------------------//
// #include <stdio.h>

// // Function to swap two integers
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Function to heapify a subtree rooted at index i (for Min Heap)
// void heapify(int arr[], int n, int i) {
//     int smallest = i;       
//     int left = 2 * i + 1;   
//     int right = 2 * i + 2;  

//     // If left child exists and is smaller than root
//     if (left < n && arr[left] < arr[smallest])
//         smallest = left;

//     // If right child exists and is smaller than current smallest
//     if (right < n && arr[right] < arr[smallest])
//         smallest = right;

//     // If smallest is not root, swap and recursively heapify
//     if (smallest != i) {
//         swap(&arr[i], &arr[smallest]);
//         heapify(arr, n, smallest);
//     }
// }

// // Function to build a Min Heap from the array
// void buildMinHeap(int arr[], int n) {
//     for (int i = (n / 2) - 1; i >= 0; i--)
//         heapify(arr, n, i);
// }

// // Function to print the heap
// void printHeap(int arr[], int n) {
//     printf("ProcessID\tExecutionTime\n");
//     for (int i = 0; i < n; i++)
//         printf("%d\t\t%d\n", i + 1, arr[i]);
// }

// // (a) Print process with minimum execution time
// void printMin(int arr[], int n) {
//     if (n <= 0) {
//         printf("Heap is empty.\n");
//         return;
//     }
//     printf("Process with minimum execution time:\n");
//     printf("ProcessID: 1\tExecutionTime: %d\n", arr[0]);
// }

// // (b) Decrease the execution time for a given process
// void decreaseExecutionTime(int arr[], int n, int pid, int dec) {
//     if (pid < 1 || pid > n) {
//         printf("Invalid process ID!\n");
//         return;
//     }

//     int i = pid - 1;
//     arr[i] -= dec;
//     if (arr[i] < 0)
//         arr[i] = 0; // no negative times allowed

//     // Fix heap upwards (bubble-up)
//     while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
//         swap(&arr[i], &arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }

//     printf("Execution time decreased successfully.\n");
// }

// // (c) Remove process with minimum execution time
// int extractMin(int arr[], int *n) {
//     if (*n <= 0) {
//         printf("Heap is empty!\n");
//         return -1;
//     }

//     int min = arr[0];
//     arr[0] = arr[*n - 1];
//     (*n)--;

//     heapify(arr, *n, 0);

//     printf("Removed process with minimum execution time (%d).\n", min);
//     return min;
// }

// // (d) Insert new process with execution time into the heap
// void insertProcess(int arr[], int *n, int val) {
//     arr[*n] = val;
//     (*n)++;

//     int i = (*n) - 1;
//     while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
//         swap(&arr[i], &arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }

//     printf("New process inserted successfully.\n");
// }

// // (e) Sort processes in descending order using heap sort (Min Heap)
// void heapSortDescending(int arr[], int n) {
//     buildMinHeap(arr, n);
//     for (int i = n - 1; i > 0; i--) {
//         swap(&arr[0], &arr[i]);
//         heapify(arr, i, 0);
//     }
//     printf("Processes sorted in descending order of execution time.\n");
// }

// int main() {
//     int arr[50];
//     int n, choice, pid, val;

//     printf("Enter number of processes: ");
//     scanf("%d", &n);

//     printf("Enter execution times for %d processes:\n", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     buildMinHeap(arr, n);

//     do {
//         printf("\n========= PROCESS MIN HEAP MENU =========\n");
//         printf("1. Display heap\n");
//         printf("2. Print process with minimum execution time\n");
//         printf("3. Decrease execution time of a process\n");
//         printf("4. Remove process with minimum execution time\n");
//         printf("5. Insert a new process\n");
//         printf("6. Sort processes in descending order of execution time\n");
//         printf("7. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printHeap(arr, n);
//                 break;
//             case 2:
//                 printMin(arr, n);
//                 break;
//             case 3:
//                 printf("Enter process ID to decrease execution time: ");
//                 scanf("%d", &pid);
//                 printf("Enter amount to decrease: ");
//                 scanf("%d", &val);
//                 decreaseExecutionTime(arr, n, pid, val);
//                 break;
//             case 4:
//                 extractMin(arr, &n);
//                 break;
//             case 5:
//                 printf("Enter execution time for new process: ");
//                 scanf("%d", &val);
//                 insertProcess(arr, &n, val);
//                 break;
//             case 6:
//                 heapSortDescending(arr, n);
//                 printf("After sorting (descending order):\n");
//                 for (int i = 0; i < n; i++)
//                     printf("%d ", arr[i]);
//                 printf("\n");
//                 break;
//             case 7:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice! Try again.\n");
//         }
//     } while (choice != 7);

//     return 0;
// }

//---------------PRIORITY QUEUE--------------------//
// #include <stdio.h>

// Swap helper function
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Heapify (Max Heap property)
// void heapify(int arr[], int n, int i) {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);
//         heapify(arr, n, largest);
//     }
// }

// Build a Max Heap from array
// void buildMaxHeap(int arr[], int n) {
//     for (int i = (n / 2) - 1; i >= 0; i--)
//         heapify(arr, n, i);
// }

// // (1) INSERT(S, x): inserts element x into the set
// void insert(int arr[], int *n, int key) {
//     arr[*n] = key;
//     (*n)++;

//     // Fix heap upwards (bubble up)
//     int i = (*n) - 1;
//     while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
//         swap(&arr[i], &arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }

//     printf("Element %d inserted successfully.\n", key);
// }

// // (2) MAXIMUM(S): returns the largest element
// void maximum(int arr[], int n) {
//     if (n == 0) {
//         printf("Priority Queue is empty.\n");
//         return;
//     }
//     printf("Maximum element: %d\n", arr[0]);
// }

// // (3) EXTRACT-MAX(S): removes and returns largest element
// int extractMax(int arr[], int *n) {
//     if (*n <= 0) {
//         printf("Priority Queue is empty!\n");
//         return -1;
//     }

//     int max = arr[0];
//     arr[0] = arr[*n - 1];
//     (*n)--;

//     heapify(arr, *n, 0);

//     printf("Extracted max element: %d\n", max);
//     return max;
// }

// // (4) INCREASE-KEY(S, x, k): increases value of element x’s key to k
// void increaseKey(int arr[], int n, int index, int newKey) {
//     if (index < 0 || index >= n) {
//         printf("Invalid index.\n");
//         return;
//     }

//     if (newKey < arr[index]) {
//         printf("New key is smaller than current key! Operation not allowed.\n");
//         return;
//     }

//     arr[index] = newKey;

//     // Move upwards if heap property is violated
//     while (index != 0 && arr[(index - 1) / 2] < arr[index]) {
//         swap(&arr[index], &arr[(index - 1) / 2]);
//         index = (index - 1) / 2;
//     }

//     printf("Key increased successfully.\n");
// }

// // Function to print the heap
// void printQueue(int arr[], int n) {
//     if (n == 0) {
//         printf("Priority Queue is empty.\n");
//         return;
//     }

//     printf("Current Priority Queue (as Max Heap):\n");
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// // Main function (menu-driven)
// int main() {
//     int arr[50];
//     int n = 0;
//     int choice, key, index;

//     printf("Enter number of initial elements: ");
//     scanf("%d", &n);

//     printf("Enter %d elements: ", n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     buildMaxHeap(arr, n);

//     do {
//         printf("\n========= MAX PRIORITY QUEUE MENU =========\n");
//         printf("1. Display Priority Queue\n");
//         printf("2. Insert an element (INSERT)\n");
//         printf("3. Get maximum element (MAXIMUM)\n");
//         printf("4. Extract maximum element (EXTRACT-MAX)\n");
//         printf("5. Increase key value (INCREASE-KEY)\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printQueue(arr, n);
//                 break;

//             case 2:
//                 printf("Enter element to insert: ");
//                 scanf("%d", &key);
//                 insert(arr, &n, key);
//                 break;

//             case 3:
//                 maximum(arr, n);
//                 break;

//             case 4:
//                 extractMax(arr, &n);
//                 break;

//             case 5:
//                 printf("Enter index of element to increase (0-based index): ");
//                 scanf("%d", &index);
//                 printf("Enter new key value: ");
//                 scanf("%d", &key);
//                 increaseKey(arr, n, index, key);
//                 break;

//             case 6:
//                 printf("Exiting...\n");
//                 break;

//             default:
//                 printf("Invalid choice! Try again.\n");
//         }
//     } while (choice != 6);

//     return 0;
// }

//---------------BST---------------//
// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #include <math.h>

// // Structure for a node
// struct Node {
//     int data;
//     struct Node *left, *right;
// };

// // Function to create a new node
// struct Node* createNode(int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = value;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// // Insert a node into BST
// struct Node* insert(struct Node* root, int value) {
//     if (root == NULL)
//         return createNode(value);

//     if (value < root->data)
//         root->left = insert(root->left, value);
//     else if (value > root->data)
//         root->right = insert(root->right, value);

//     return root;
// }

// // Find minimum value node (used for inorder successor)
// struct Node* findMin(struct Node* root) {
//     while (root && root->left != NULL)
//         root = root->left;
//     return root;
// }

// // Delete node using inorder successor
// struct Node* deleteNode(struct Node* root, int key) {
//     if (root == NULL) return root;

//     if (key < root->data)
//         root->left = deleteNode(root->left, key);
//     else if (key > root->data)
//         root->right = deleteNode(root->right, key);
//     else {
//         // Node found
//         if (root->left == NULL) {
//             struct Node* temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             struct Node* temp = root->left;
//             free(root);
//             return temp;
//         }

//         // Node with two children — use inorder successor
//         struct Node* temp = findMin(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data);
//     }

//     return root;
// }

// // Inorder traversal (Left → Root → Right)
// void inorder(struct Node* root) {
//     if (root == NULL) return;
//     inorder(root->left);
//     printf("%d ", root->data);
//     inorder(root->right);
// }

// // Postorder traversal (Left → Right → Root)
// void postorder(struct Node* root) {
//     if (root == NULL) return;
//     postorder(root->left);
//     postorder(root->right);
//     printf("%d ", root->data);
// }

// // Find the closest element to a given x
// int findClosest(struct Node* root, int x) {
//     int closest = INT_MAX;
//     int minDiff = INT_MAX;

//     while (root != NULL) {
//         int diff = abs(root->data - x);
//         if (diff < minDiff) {
//             minDiff = diff;
//             closest = root->data;
//         }
//         if (x < root->data)
//             root = root->left;
//         else if (x > root->data)
//             root = root->right;
//         else
//             break; // exact match
//     }
//     return closest;
// }

// // Main menu-driven program
// int main() {
//     struct Node* root = NULL;
//     int choice, value, x, result;

//     do {
//         printf("\n--- Binary Search Tree Operations ---\n");
//         printf("1. Insert\n");
//         printf("2. Delete (using inorder successor)\n");
//         printf("3. Inorder Traversal\n");
//         printf("4. Postorder Traversal\n");
//         printf("5. Find Closest Element\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//         case 1:
//             printf("Enter value to insert: ");
//             scanf("%d", &value);
//             root = insert(root, value);
//             break;

//         case 2:
//             printf("Enter node value to delete: ");
//             scanf("%d", &value);
//             root = deleteNode(root, value);
//             break;

//         case 3:
//             printf("Inorder Traversal: ");
//             inorder(root);
//             printf("\n");
//             break;

//         case 4:
//             printf("Postorder Traversal: ");
//             postorder(root);
//             printf("\n");
//             break;

//         case 5:
//             printf("Enter number to find closest element: ");
//             scanf("%d", &x);
//             result = findClosest(root, x);
//             printf("Closest element to %d is %d\n", x, result);
//             break;

//         case 6:
//             printf("Exiting...\n");
//             break;

//         default:
//             printf("Invalid choice! Try again.\n");
//         }
//     } while (choice != 6);

//     return 0;
// }

//-------------HEAPSORT-----------------------//
// #include <stdio.h>

// // Function to swap two elements
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Function to heapify a subtree rooted at index i (for Max Heap)
// void heapify(int arr[], int n, int i) {
//     int largest = i;         // Initialize largest as root
//     int left = 2 * i + 1;    // Left child index
//     int right = 2 * i + 2;   // Right child index

//     // If left child exists and is greater than root
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child exists and is greater than current largest
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);
//         // Recursively heapify the affected subtree
//         heapify(arr, n, largest);
//     }
// }

// // Function to perform Heap Sort
// void heapSort(int arr[], int n) {
//     // Step 1: Build a max heap
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i);

//     // Step 2: Extract elements from heap one by one
//     for (int i = n - 1; i > 0; i--) {
//         // Move current root (largest) to end
//         swap(&arr[0], &arr[i]);
//         // Call heapify on reduced heap
//         heapify(arr, i, 0);
//     }
// }

// // Function to print the array
// void printArray(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int n;

//     // Take number of elements as input
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int arr[n];

//     // Take array input from user
//     printf("Enter %d elements: ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     printf("\nOriginal array:\n");
//     printArray(arr, n);

//     // Perform Heap Sort
//     heapSort(arr, n);

//     printf("\nSorted array in ascending order:\n");
//     printArray(arr, n);

//     return 0;
// }


// – MAX-HEAPIFY O(lgn)
// – BUILD-MAX-HEAP O(n)
// – HEAP-SORT O(nlgn)
// – MAX-HEAP-INSERT O(lgn)
// – HEAP-EXTRACT-MAX O(lgn)
// – HEAP-INCREASE-KEY O(lgn)
// – HEAP-MAXIMUM O(1)

//-------------predecessor and successor--------------//
// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a BST node
// struct Node {
//     int key;
//     struct Node *left, *right;
// };

// // Function to create a new node
// struct Node* newNode(int key) {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->key = key;
//     temp->left = temp->right = NULL;
//     return temp;
// }

// // Function to insert a node in BST
// struct Node* insert(struct Node* node, int key) {
//     if (node == NULL)
//         return newNode(key);

//     if (key < node->key)
//         node->left = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);

//     return node;
// }

// // Helper function to find predecessor and successor
// void findPreSuc(struct Node* root, struct Node** pre, struct Node** suc, int key) {
//     if (root == NULL)
//         return;

//     // If key is found
//     if (root->key == key) {
//         // Find maximum in left subtree (Predecessor)
//         if (root->left != NULL) {
//             struct Node* temp = root->left;
//             while (temp->right)
//                 temp = temp->right;
//             *pre = temp;
//         }

//         // Find minimum in right subtree (Successor)
//         if (root->right != NULL) {
//             struct Node* temp = root->right;
//             while (temp->left)
//                 temp = temp->left;
//             *suc = temp;
//         }
//         return;
//     }

//     // If key is smaller than root, go left
//     if (key < root->key) {
//         *suc = root; // this node could be successor
//         findPreSuc(root->left, pre, suc, key);
//     }
//     // If key is greater than root, go right
//     else {
//         *pre = root; // this node could be predecessor
//         findPreSuc(root->right, pre, suc, key);
//     }
// }

// // Inorder traversal (for verification)
// void inorder(struct Node* root) {
//     if (root != NULL) {
//         inorder(root->left);
//         printf("%d ", root->key);
//         inorder(root->right);
//     }
// }

// int main() {
//     int n, key, val;
//     struct Node* root = NULL;

//     printf("Enter number of nodes in BST: ");
//     scanf("%d", &n);

//     printf("Enter %d node values: ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &val);
//         root = insert(root, val);
//     }

//     printf("Inorder traversal of BST:\n");
//     inorder(root);
//     printf("\n");

//     printf("Enter key to find predecessor and successor: ");
//     scanf("%d", &key);

//     struct Node* pre = NULL, *suc = NULL;
//     findPreSuc(root, &pre, &suc, key);

//     if (pre != NULL)
//         printf("Predecessor: %d\n", pre->key);
//     else
//         printf("Predecessor: None\n");

//     if (suc != NULL)
//         printf("Successor: %d\n", suc->key);
//     else
//         printf("Successor: None\n");

//     return 0;
// }


////----------------------AVL TREES------------------//
// ================= AVL NODE STRUCT =================

#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode {
    int data;
    struct avlNode *left;
    struct avlNode *right;
    int height;
} AVLNode;

// ================= FUNCTION 1: CREATE NODE =================
AVLNode* createNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0; // new node height = 0
    return node;
}

// ================= FUNCTION 2: HEIGHT =================
int height(AVLNode *node) {
    if (node == NULL)
        return -1;
    return node->height;
}

// ================= FUNCTION 3: BALANCE FACTOR =================
int balanceFactor(AVLNode *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// ================= FUNCTION 4: RIGHT ROTATION =================
AVLNode* rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    // Return new root
    return x;
}

// ================= FUNCTION 5: LEFT ROTATION =================
AVLNode* rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    // Return new root
    return y;
}

// ================= FUNCTION 6: INSERT WITH REBALANCING =================
AVLNode* insert(AVLNode *node, int key) {
    // 1. Normal BST insertion
    if (node == NULL)
        return createNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;  // Duplicate keys not allowed

    // 2. Update height
    node->height = 1 + (height(node->left) > height(node->right)
                        ? height(node->left)
                        : height(node->right));

    // 3. Get balance factor
    int bf = balanceFactor(node);

    // 4. Check for imbalance and fix it
    // Left Left Case
    if (bf > 1 && key < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (bf < -1 && key > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (bf > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Return unchanged node
    return node;
}

// ================= HELPER: INORDER TRAVERSAL =================
void inorder(AVLNode *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// ================= HELPER: PREORDER TRAVERSAL =================
void preorder(AVLNode *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// ================= HELPER: POSTORDER TRAVERSAL =================
void postorder(AVLNode *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Get minimum value node (used to find inorder successor)
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete node in AVL tree
AVLNode* deleteNode(AVLNode* root, int key) {
    // 1️⃣ Perform standard BST delete
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found — now delete it
        if (root->left == NULL || root->right == NULL) {
            AVLNode* temp = root->left ? root->left : root->right;
            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                // One child case
                *root = *temp;
            }
            free(temp);
        } else {
            // Two children: Get inorder successor
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If tree had only one node
    if (root == NULL)
        return root;

    // 2️⃣ Update height
    root->height = 1 + (height(root->left) > height(root->right)
                        ? height(root->left)
                        : height(root->right));

    // 3️⃣ Get balance factor
    int bf = balanceFactor(root);

    // 4️⃣ Balance it like a pro
    // Left Left Case
    if (bf > 1 && balanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (bf > 1 && balanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (bf < -1 && balanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (bf < -1 && balanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// ================= SEARCH FUNCTION =================
int search(AVLNode* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// ================= DISPLAY MENU =================
void displayMenu() {
    printf("\n========== AVL TREE OPERATIONS ==========\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Search for a node\n");
    printf("4. Display Inorder traversal\n");
    printf("5. Display Preorder traversal\n");
    printf("6. Display Postorder traversal\n");
    printf("7. Exit\n");
    printf("==========================================\n");
    printf("Enter your choice: ");
}

// ================= MAIN MENU-DRIVEN PROGRAM =================
int main() {
    AVLNode *root = NULL;
    int choice, value;
    
    printf("Welcome to AVL Tree Operations!\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted successfully!\n", value);
                break;
                
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    root = deleteNode(root, value);
                    printf("Value %d deleted successfully!\n", value);
                } else {
                    printf("Value %d not found in the tree!\n", value);
                }
                break;
                
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Value %d found in the tree!\n", value);
                } else {
                    printf("Value %d not found in the tree!\n", value);
                }
                break;
                
            case 4:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
                
            case 5:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
                
            case 6:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
                
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1-7.\n");
        }
    }
    
    return 0;
}

