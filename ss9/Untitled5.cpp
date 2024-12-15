#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao cay\n");
        printf("2. Duyet cay theo thu tu truoc (NLR)\n");
        printf("3. Duyet cay theo thu tu giua (LNR)\n");
        printf("4. Duyet cay theo thu tu sau (LRN)\n");
        printf("5. Tim kiem mot phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Duyet theo thu tu truoc: ");
                preOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Duyet theo thu tu giua: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Duyet theo thu tu sau: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                TreeNode* found = search(root, value);
                if (found != NULL) {
                    printf("Phan tu %d ton tai trong cay.\n", value);
                } else {
                    printf("Phan tu %d khong ton tai trong cay.\n", value);
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);

    freeTree(root);
    return 0;
}

