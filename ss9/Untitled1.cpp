#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteHead(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteTail(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

Node* search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) return head;
        head = head->next;
    }
    return NULL;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node** head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3. Xoa dau danh sach\n");
        printf("4. Xoa cuoi danh sach\n");
        printf("5. Tim kiem gia tri\n");
        printf("6. In danh sach\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertAtHead(&head, value);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insertAtTail(&head, value);
                break;
            case 3:
                deleteHead(&head);
                printf("Da xoa dau danh sach.\n");
                break;
            case 4:
                deleteTail(&head);
                printf("Da xoa cuoi danh sach.\n");
                break;
            case 5:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                Node* found = search(head, value);
                if (found != NULL) {
                    printf("Tim thay gia tri: %d\n", found->data);
                } else {
                    printf("Khong tim thay gia tri\n");
                }
                break;
            case 6:
                printf("Danh sach lien ket: ");
                printList(head);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    freeList(&head);
    return 0;
}

