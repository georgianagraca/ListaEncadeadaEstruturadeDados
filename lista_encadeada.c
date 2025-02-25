#include <stdio.h>
#include <stdlib.h>

// Definindo o nó da lista
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definindo a estrutura da lista
typedef struct {
    Node* head;
    int size;
} ListaEncadeada;

// Criando uma lista vazia
ListaEncadeada* createListaEncadeada() {
    ListaEncadeada* list = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    if (list == NULL) {
        printf("Erro ao alocar memoria para a lista.\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Verificando se a lista está vazia
int isEmpty(ListaEncadeada* list) {
    return list->size == 0;
}

// Obtendo o tamanho da lista
int getSize(ListaEncadeada* list) {
    return list->size;
}

// Obtendo o valor de um elemento em uma determinada posição
int getElement(ListaEncadeada* list, int position) {
    if (position < 1 || position > list->size) {
        printf("Posicao invalida.\n");
        exit(1);
    }
    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

// Modificando o valor de um elemento em uma determinada posição
void setElement(ListaEncadeada* list, int position, int value) {
    if (position < 1 || position > list->size) {
        printf("Posicao invalida.\n");
        exit(1);
    }
    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    current->data = value;
}

// Inserindo um elemento em uma determinada posição
void insertElement(ListaEncadeada* list, int position, int value) {
    if (position < 1 || position > list->size + 1) {
        printf("Posicao invalida.\n");
        exit(1);
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memoria para o novo no.\n");
        exit(1);
    }
    newNode->data = value;

    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// Retirando um elemento de uma determinada posição
void removeElement(ListaEncadeada* list, int position) {
    if (position < 1 || position > list->size) {
        printf("Posicao invalida.\n");
        exit(1);
    }
    Node* temp;
    if (position == 1) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        Node* current = list->head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    list->size--;
}

// Imprimindo os elementos da lista
void printList(ListaEncadeada* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Liberando a memória alocada para a lista
void freeListaEncadeada(ListaEncadeada* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    // Testes
    ListaEncadeada* list = createListaEncadeada();

    printf("Lista esta vazia? %s\n", isEmpty(list) ? "Sim" : "Nao");

    insertElement(list, 1, 10);
    insertElement(list, 2, 20);
    insertElement(list, 3, 30);

    printf("Lista apos insercoes: ");
    printList(list);

    printf("Tamanho da lista: %d\n", getSize(list));

    printf("Elemento na posicao 2: %d\n", getElement(list, 2));

    setElement(list, 2, 25);
    printf("Lista apos modificar o elemento na posicao 2: ");
    printList(list);

    removeElement(list, 1);
    printf("Lista apos remover o elemento na posicao 1: ");
    printList(list);

    printf("Lista esta vazia? %s\n", isEmpty(list) ? "Sim" : "Nao");

    freeListaEncadeada(list);

    return 0;
}