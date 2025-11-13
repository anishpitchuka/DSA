#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
    int size;   // subtree size for kth largest
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
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->size = 1;
    return node;
}

int getBalance(struct Node *N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxValue(height(y->left), height(y->right));
    x->height = 1 + maxValue(height(x->left), height(x->right));

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

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxValue(height(root->left), height(root->right));
    root->size = 1 + getSize(root->left) + getSize(root->right);

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// K-th Largest Element
int kthLargest(struct Node* root, int k) {
    if (root == NULL)
        return -1;

    int rightSize = getSize(root->right);

    if (k == rightSize + 1)
        return root->key;
    else if (k <= rightSize)
        return kthLargest(root->right, k);
    else
        return kthLargest(root->left, k - rightSize - 1);
}

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->key == key) return 1;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

struct Node* lowestCommonAncestor(struct Node* root, int n1, int n2) {
    struct Node* current = root;

    while (current != NULL) {
        if (n1 < current->key && n2 < current->key) {
            current = current->left;
        } else if (n1 > current->key && n2 > current->key) {
            current = current->right;
        } else {
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
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder\n");
        printf("5. Inorder\n");
        printf("6. Postorder\n");
        printf("7. K-th Largest\n");
        printf("8. Lowest Common Ancestor\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value)) printf("Found\n");
                else printf("Not Found\n");
                break;

            case 4:
                preorder(root);
                printf("\n");
                break;

            case 5:
                inorder(root);
                printf("\n");
                break;

            case 6:
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Enter k: ");
                scanf("%d", &k);
                value = kthLargest(root, k);
                if (value == -1) printf("Invalid k\n");
                else printf("%d-th largest = %d\n", k, value);
                break;

            case 8:
                if (root == NULL) {
                    printf("Tree is empty\n");
                    break;
                }
                printf("Enter first value: ");
                scanf("%d", &first);
                printf("Enter second value: ");
                scanf("%d", &second);
                if (!search(root, first) || !search(root, second)) {
                    printf("One or both values not found\n");
                    break;
                }
                {
                    struct Node* lca = lowestCommonAncestor(root, first, second);
                    if (lca != NULL)
                        printf("LCA of %d and %d is %d\n", first, second, lca->key);
                    else
                        printf("LCA not found\n");
                }
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
