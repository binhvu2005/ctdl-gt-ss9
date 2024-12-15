#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

QueueNode* createQueueNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue* q, int data) {
    QueueNode* newNode = createQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("%d da duoc them vao hang doi.
", data);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d da duoc them vao hang doi.
", data);
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Hang doi rong.
");
        return -1;
    }
    QueueNode* temp = q->front;
    int dequeued = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeued;
}

int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Hang doi rong.
");
        return -1;
    }
    return q->front->data;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void freeQueue(Queue* q) {
    while (q->front != NULL) {
        QueueNode* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

int main() {
    Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Them vao hang doi\n");
        printf("2. Xoa khoi hang doi\n");
        printf("3. Xem phan tu dau tien\n");
        printf("4. Kiem tra hang doi rong\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Gia tri da xoa: %d
", value);
                }
                break;
            case 3:
                value = peek(queue);
                if (value != -1) {
                    printf("Phan tu dau tien: %d
", value);
                }
                break;
            case 4:
                if (isEmpty(queue)) {
                    printf("Hang doi rong.
");
                } else {
                    printf("Hang doi khong rong.
");
                }
                break;
            case 5:
                printf("Thoat chuong trinh.
");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.
");
        }
    } while (choice != 5);

    freeQueue(queue);
    return 0;
}

