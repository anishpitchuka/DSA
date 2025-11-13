#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
    int size;
};

int maxValue(int a, int b) { return (a > b) ? a : b; }

int height(struct Node *N) {
    return (N == NULL) ? 0 : N->height;
}

int getSize(struct Node *N) {
    return (N == NULL) ? 0 : N->size;
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    node->size = 1;
    return node;
}

int getBalance(struct Node* N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct Node* rightRotate(struct Node* y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxValue(height(y->left) , height(y->right));
    x->height = 1 + maxValue(height(x->left) , height(x->right));

    y->size = 1 + getSize(y->left) + getSize(y->right);
    x->size = 1 + getSize(x->left) + getSize(x->right);

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + maxValue(height(x->left), height(x->right));
    y->height = 1 + maxValue(height(y->left), height(y->right));

    x->size = 1 + getSize(x->left) + getSize(x->right);
    y->size = 1 + getSize(y->left) + getSize(y->right);

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + maxValue(height(node->left), height(node->right));
    node->size = 1 + getSize(node->left) + getSize(node->right);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node* node)  {
    struct Node* current = node;
    while(current->left != nullptr) {
        current = current->left;
    }
    return current;
}

void preorder(struct Node* root) {
    if(root != nullptr) {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if(root != nullptr) {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if(root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

struct Node* lowestCommonAncestor(struct Node* root, int n1, int n2) {
    struct Node* current = root;
    while(current != nullptr) {
        if(n1 < current->key && n2 < current->key) {
            current = current->left;
        } else if(n1 > current->key && n2 > current->key) {
            current = current->right;
        } else{
            return current;
        }
    }

    return NULL;
}


int main() {
    struct Node *root = NULL;
    int choice, value, k;
    int first, second;

    while (1) {
        printf("\n---- AVL Tree Menu ----\n");
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Lowest Common Ancestor\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;         
          

            case 2:
                preorder(root);
                printf("\n");
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }
                printf("Enter first value: ");
                scanf("%d", &first);
                printf("Enter second value: ");
                scanf("%d", &second);
              
                {
                    struct Node* lca = lowestCommonAncestor(root, first, second);
                    if (lca != NULL)
                        printf("LCA of %d and %d is %d\n", first, second, lca->key);
                    else
                        printf("LCA not found\n");
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}