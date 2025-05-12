#include <stdio.h>
#include <stdlib.h>

// Definicao do no
typedef struct node {
    int data;
    struct node* next;
} tNode;

// Lista Encadeada
typedef struct list {
    tNode* first_elem;
} tList;

// Pilha
typedef struct stack {
    tNode* top;
} tStack;

// Fila
typedef struct queue {
    tNode* front;
    tNode* rear;
} tQueue;

// Funcoes para lista
void insert_list(tList *list, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem memoria.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = list->first_elem;
    list->first_elem = new_node;
}

void print_list(tList *list) {
    tNode* current = list->first_elem;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->first_elem = NULL;
}

// Funcoes para pilha
void push(tStack *s, int x) {
    tNode* new_node = (tNode*)malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem memoria.\n");
        return;
    }
    new_node->data = x;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(tStack *s) {
    if (s->top == NULL) {
        printf("Erro: Pilha vazia.\n");
        return -1;
    }
    tNode* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

void print_stack(tStack *s) {
    tNode* current = s->top;
    printf("Pilha (topo -> base): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Funcoes para fila
void insert_rear(tQueue *q, int x) {
    tNode* new_node = (tNode*)malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem memoria.\n");
        return;
    }
    new_node->data = x;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int remove_front(tQueue *q) {
    if (q->front == NULL) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    tNode* temp = q->front;
    int val = temp->data;
    q->front = temp->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void print_queue(tQueue *q) {
    tNode* current = q->front;
    printf("Fila (frente -> tras): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Lista
    tList list = {NULL};
    printf("== LISTA ==\n");
    for (int i = 0; i < 5; i++) {
        int val;
        printf("Digite um valor para inserir na lista: ");
        scanf("%d", &val);
        insert_list(&list, val);
    }
    print_list(&list);
    free_list(&list);

    // Pilha
    tStack stack = {NULL};
    printf("\n== PILHA ==\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    print_stack(&stack);
    printf("Elemento removido da pilha: %d\n", pop(&stack));
    print_stack(&stack);

    // Fila
    tQueue queue = {NULL, NULL};
    printf("\n== FILA ==\n");
    insert_rear(&queue, 100);
    insert_rear(&queue, 200);
    insert_rear(&queue, 300);
    print_queue(&queue);
    printf("Elemento removido da fila: %d\n", remove_front(&queue));
    print_queue(&queue);

    return 0;
}
