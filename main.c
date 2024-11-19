#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int value;
    struct element *next;
} Element;

void printList(Element *head) {
    while(head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    }
}

void insertAtHead(Element **head, int value) {
    Element* nhead = (Element*)malloc(sizeof(Element));
    nhead->value = value;
    nhead->next = *head;
    *head = nhead;
}

void insertAtTail(Element *head, int value) {
    Element* nElement = (Element*)malloc(sizeof(Element));
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = nElement;
    nElement->value = value;
    nElement->next = NULL;
}

void insertAtPosition(Element *head, int position, int value) {
    Element* nElement = (Element*)malloc(sizeof(Element));
    nElement->value = value;
    if(position == 0) {
        insertAtHead(&head, value);
    }
    else {
        for(int i = 0; i < position-1; i++) {
            head = head->next;
        }
        nElement->next = head->next;
        head->next = nElement;
    }

}

void deleteHead(Element *head) {
    *head = *head->next;
}
void deleteTail(Element* head) {
    while(head->next->next != NULL) {
        head = head->next;
    }
    head->next = NULL;
    free(head->next);
}
void deleteValue(Element *head, int value) {
    while(head->next->value != value) {
        head = head->next;
    }
    Element *toDelete = head->next;
    Element* prev = head;
    prev->next = head->next->next;
    free(toDelete);
}

Element *search(Element *head, int value);

void freeList(Element** head);
int main(void) {
    Element *head;
    head = (Element*)malloc(sizeof(Element));
    head->value=1;

    Element *second = (Element*)malloc(sizeof(Element));
    second->value=2;
    head->next = second;
    second->next = NULL;
    insertAtHead(&head, 0);
    insertAtTail(head, 4);
    insertAtPosition(head, 3, 3);
    deleteHead(head);
    deleteTail(head);
    deleteValue(head, 2);
    printList(head);

}
