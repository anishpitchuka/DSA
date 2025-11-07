#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct garden {
    char name[100];
    char color[100];
    int height;
    struct garden* left;
    struct garden* right;
} garden;


garden * newnode(char *name,char * color,int height){
    garden* newnode=(garden *)malloc(sizeof(garden));
strcpy(newnode->name,name);
strcpy(newnode->color,color);
newnode->height=height;
newnode->left=NULL;
newnode->right=NULL;
return newnode;}

garden* insert(garden* root, char* name, char *color, int height) {
    if (root == NULL) {
        return newnode(name, color, height);
    }
    
    if (height < root->height) {
        root->left = insert(root->left, name,color, height);
    } else {
        root->right = insert(root->right, name, color, height);
    }
    
    return root;
}
void listAllAscending(garden* root) {
    if (root != NULL) {
        listAllAscending(root->left);
        printf("%s, %s, %d\n", root->name, root->color, root->height);
        listAllAscending(root->right);
    }
}

garden* search(garden* root, int x) {
   garden * ceil=NULL;
   while(root){
if(root->height==x){
     ceil=root;
    return ceil;
}
 if(root->height > x){
    ceil=root;
    root=root->left;

 }
 else{
    root=root->right;
 }
   }
   return ceil;
}

garden* findMin(garden* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
garden* deletesapling(garden* root, int height, garden** deleted) {
    if (root == NULL) {
        *deleted = NULL;
        return NULL;
    }
    
    if (height < root->height) {
        root->left = deletesapling(root->left, height, deleted);
    } else if (height > root->height) {
        root->right = deletesapling(root->right, height, deleted);
    } else {
        
        *deleted = (garden*)malloc(sizeof(garden));
        strcpy((*deleted)->name, root->name);
         strcpy((*deleted)->color, root->color);
        (*deleted)->height = root->height;
       
        
        
        if (root->left == NULL) {
           garden* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            garden* temp = root->left;
            free(root);
            return temp;
        }
        
        
        garden* successor = findMin(root->right);
        strcpy(root->name, successor->name);
        strcpy(root->color, successor->color);
        root->height = successor->height;
        
        
        garden* dummy = NULL;
        root->right = deletesapling(root->right, successor->height, &dummy);
        if (dummy != NULL) free(dummy);
    }
    
    return root;
}


int main() {
    int n;
    scanf("%d", &n);
    
    garden* root = NULL;
    
   
    for (int i = 0; i < n; i++) {
        char name[100];
       char color[100];
        int height;
        printf("Enter name color height\n");
        scanf("%s", name);
        scanf("%s", color);
        scanf("%d", &height);
        root = insert(root, name, color, height);
    }
    
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        char query_type;
        scanf(" %c", &query_type);
        
        if (query_type == 'A') {
           
            listAllAscending(root);
        } else if (query_type == 'B') {
            garden *p=NULL;
            int x;
            printf("Enter the value that you want greater than that\n");
            scanf("%d",&x);
            p=search(root,  x);
            printf("%s",p->name);
            printf("%s",p->color);
            printf("%d",p->height);
        } else if (query_type == 'C') {int height;
            scanf("%d", &height);
            garden* deleted = NULL;
           root = deletesapling(root, height, &deleted);
        } else if (query_type == 'D') {
            
            }
        }
    
    
    return 0;
}