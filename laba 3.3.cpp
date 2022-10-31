//стек
#include "stdafx.h"
#include <iostream>
using namespace std;

//реализация списка(двухсвязный)
typedef struct _Node {
    void* value;
    struct _Node* next; //хранит адрес следующего узла
    struct _Node* prev; //хранит адрес предыдущего узла
} Node;

// структура элемента
typedef struct _DblLinkedList {
    size_t size;
    Node* head;
    Node* tail;
    //В случае, когда в списке нет элементов, оба они равны нулю
} DblLinkedList;

//оздаёт экземпляр структуры DblLinkedList
DblLinkedList* createDblLinkedList() {
    DblLinkedList* tmp = (DblLinkedList*)malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

//удаление списка
void deleteDblLinkedList(DblLinkedList** list) { 
    Node* tmp = (*list)->head;
    Node* next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

//добавление в конец
void pushBack(DblLinkedList* list, void* value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

//удаление последнего элемента
void* popBack(DblLinkedList* list) {
    Node* next;
    void* tmp;
    if (list->tail == NULL) {
        exit(4);
    }

    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);

    list->size--;
    return tmp;
}

//вывод последнего элемента
Node* getN(DblLinkedList* list) {
    Node* tmp = list->tail;
    return tmp;
}

//вывод списка
void printDblLinkedList(DblLinkedList* list) {
    Node* tmp = list->head;
    while (tmp) {
        printf("%d ", *((int*)tmp->value));
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    setlocale(0,"");
    DblLinkedList* list = createDblLinkedList();

    int a = 20, b = 10, c = 30, d = 50, e = 40;
    pushBack(list, &a);
    pushBack(list, &b);
    pushBack(list, &c);
    pushBack(list, &d);
    pushBack(list, &e);

    //вывод очереди
    printDblLinkedList(list);

    printf("Последний элемент %d\n", *((int*)(popBack(list))));    

    printf("Последний элемент %d\n", *((int*)(getN(list))->value));
    popBack(list);

    printf("Последний элемент %d\n", *((int*)(list->tail->value))); //можно и без вызова функции
    popBack(list);

    deleteDblLinkedList(&list);
    system("pause");
    return 0;
}



