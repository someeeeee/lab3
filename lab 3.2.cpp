//�������
#include "stdafx.h"
#include <iostream>
using namespace std;

//���������� ������(�����������)
typedef struct _Node {
    void* value;
    struct _Node* next; //������ ����� ���������� ����
    struct _Node* prev; //������ ����� ����������� ����
} Node;

// ��������� ��������
typedef struct _DblLinkedList {
    size_t size;
    Node* head;
    Node* tail;
    //� ������, ����� � ������ ��� ���������, ��� ��� ����� ����
} DblLinkedList;

//����� ��������� ��������� DblLinkedList
DblLinkedList* createDblLinkedList() {
    DblLinkedList* tmp = (DblLinkedList*)malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

//�������� ������
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

//���������� � �����
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

//�������� ������� ��������
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

//����� ������� ��������
Node* getN(DblLinkedList* list) {
    Node* tmp = list->head;
    return tmp;
}

//����� ������
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

    int a = 20, b = 10, c = 30, d = 50, e = 40;
    pushBack(list, &a);
    pushBack(list, &b);
    pushBack(list, &c);
    pushBack(list, &d);
    pushBack(list, &e);

    //����� �������
    printDblLinkedList(list);

    printf("������ ������� %d\n", *((int*)(popFront(list))));

    printf("������ ������� %d\n", *((int*)(getN(list))->value));
    popFront(list);

    printf("������ ������� %d\n", *((int*)(list->head->value)));
    popFront(list);

    deleteDblLinkedList(&list);
    system("pause");
    return 0;
}




