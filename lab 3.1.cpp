//очередь c приоритетом
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
void pushBack(DblLinkedList* list, void* Value, int value) {
    Node* tmp = list->head;
    Node* tmp_prev = tmp;
    int index = 0;
    while (tmp!=NULL) {
        if (value <= *((int*)(tmp->value))) {
            tmp_prev = tmp;
            tmp = tmp->next;
            index++;
        }
        else 
            break;      
    }
    if (index==0) {
        Node* ins = (Node*)malloc(sizeof(Node));
        if (ins == NULL) {
            exit(1);
        }
        ins->value = Value;
        ins->next = list->head;
        ins->prev = NULL;
        if (list->head) {
            list->head->prev = ins;
        }
        list->head = ins;

        if (list->tail == NULL) {
            list->tail = ins;
        }
        list->size++;
    }
    else if (tmp==NULL) {
        Node* ins = (Node*)malloc(sizeof(Node));
        if (ins == NULL) {
            exit(3);
        }
        ins->value = Value;
        ins->next = NULL;
        ins->prev = list->tail;
        if (list->tail) {
            list->tail->next = ins;
        }
        list->tail = ins;

        if (list->head == NULL) {
            list->head = ins;
        }
        list->size++;
    }
    else{
        Node* ins = NULL;
        if (tmp_prev == NULL) {
            exit(5);
        }
        ins = (Node*)malloc(sizeof(Node));
        ins->value = Value;
        ins->prev = tmp_prev;
        ins->next = tmp_prev->next;
        if (tmp_prev->next) {
            tmp_prev->next->prev = ins;
        }
        tmp_prev->next = ins;

        if (!tmp_prev->prev) {
            list->head = tmp_prev;
        }
        if (!tmp_prev->next) {
            list->tail = tmp_prev;
        }

        list->size++;
    }
}

//удаление первого элемента
void* popFront(DblLinkedList* list) {
    Node* prev;
    void* tmp;
    if (list->head == NULL) {
        exit(2);
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);

    list->size--;
    return tmp;
}

//вывод первого элемента
Node* getN(DblLinkedList* list) {
    Node* tmp = list->head;
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
    setlocale(0, "");
    DblLinkedList* list = createDblLinkedList();

    int a = 10, b = 30, c = 20, d = 50, e = 40;
    pushBack(list, &a,a);
    pushBack(list, &b,b);
    pushBack(list, &c,c);
    pushBack(list, &d,d);
    pushBack(list, &e,e);

    //вывод очереди
    printDblLinkedList(list);

    printf("Первый элемент %d\n", *((int*)(popFront(list))));

    printf("Первый элемент %d\n", *((int*)(getN(list))->value));
    popFront(list);

    printf("Первый элемент %d\n", *((int*)(list->head->value)));
    popFront(list);

    deleteDblLinkedList(&list);
    system("pause");
    return 0;
}


