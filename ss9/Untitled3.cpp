#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

Stack* createStackNode(int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack** top, int data) {
    Stack* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d da duoc them vao ngan xep.\n", data);
}

int pop(Stack** top) {
    if (*top == NULL) {
        printf("Ngan xep rong.\n");
        return -1;
    }
    Stack* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peek(Stack* top) {
    if (top == NULL) {
        printf("Ngan xep rong.\n");
        return -1;
    }
    return top->data;
}

int isEmpty(Stack* top) {
    return top == NULL;
}

void freeStack(Stack** top) {
    while (*top != NULL) {
        Stack* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    Stack* stack = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them vao ngan xep\n");
        printf("2. Xoa khoi ngan xep\n");
        printf("3. Xem phan tu dau ngan xep\n");
        printf("4. Kiem tra ngan xep rong\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Gia tri da xoa: %d\n", value);
                }
                break;
            case 3:
                value = peek(stack);
                if (value != -1) {
                    printf("Phan tu dau ngan xep: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(stack)) {
                    printf("Ngan xep rong.\n");
                } else {
                    printf("Ngan xep khong rong.\n");
                }
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 5);

    freeStack(&stack);
    return 0;
}

