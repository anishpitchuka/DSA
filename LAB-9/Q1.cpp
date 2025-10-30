#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int searchInInorder(char inorder[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}


struct TreeNode* buildTree(char inorder[], char postorder[], int inStart, int inEnd, int* postIndex) {

    if (inStart > inEnd) {
        return NULL;
    }
    

    struct TreeNode* root = createNode(postorder[*postIndex]);
    (*postIndex)--;
    

    if (inStart == inEnd) {
        return root;
    }
    
  
    int inIndex = searchInInorder(inorder, inStart, inEnd, root->data);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    

    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    
    return root;
}


void printPreorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}


void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n = 0;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 0;
    }


    char* inorder = (char*)malloc(sizeof(char) * n);
    char* postorder = (char*)malloc(sizeof(char) * n);
    if (inorder == NULL || postorder == NULL) {
        printf("Memory allocation failed.\n");
        if (inorder) free(inorder);
        if (postorder) free(postorder);
        return 0;
    }

    printf("Enter %d nodes for Inorder (space-separated): ", n);
    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &inorder[i]) != 1) {
            printf("Invalid input.\n");
            free(inorder);
            free(postorder);
            return 0;
        }
    }

    printf("Enter %d nodes for Postorder (space-separated): ", n);
    for (int i = 0; i < n; i++) {
        if (scanf(" %c", &postorder[i]) != 1) {
            printf("Invalid input.\n");
            free(inorder);
            free(postorder);
            return 0;
        }
    }

    int postIndex = n - 1;
    struct TreeNode* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder: ");
    printPreorder(root);
    printf("\n");

    freeTree(root);
    free(inorder);
    free(postorder);
    return 0;
}

