#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} NODE;

typedef struct list{
    struct NODE *head;
}LIST;

void init(LIST*p){
    p->head = NULL;
}

 NODE *createnode(int data){
    NODE * nn = (NODE*)malloc(sizeof(NODE));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

void insertatFront(LIST * p, int data){
    NODE * nn = createnode(data);
    if(p->head == NULL){
        p->head = nn; 
    }
    else{
        nn->next = p->head;
        p->head = nn;
    }
}

void insertatEnd(LIST *p , int data){
    NODE * nn = createnode(data);
    if(p->head == NULL){
        p->head = nn;
    }
    else{
        NODE*q = p->head;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = nn;
    }
}

void insertatIndex(LIST * p , int index,int data){
    NODE * nn = createnode(data);
    int i = 0;
    if(p->head == NULL)
        p->head = nn;
    else if(index==0){
        insertatFront(p,data);
    }
    else{
    NODE * q = p->head;
    while(i != (index-1) && q!=NULL){
        q= q->next;
        i++;
    }
    NODE * r = q->next;
    q->next = nn;
    nn->next = r;
    }
}


void delete_alternate(LIST * p){
    NODE *  q = p->head;
    while (q != NULL && q->next != NULL){
  
    NODE *temp = q->next;
        q->next = temp->next;
        free(temp);
        q = q->next;
    }
}

void display(LIST *p){
    NODE * q = p->head;
    while(q!= NULL){
        printf("%d ->" , q->data);
        q= q->next;
    }

}

int main() {
    LIST myList;
    init(&myList);

    // Insert at the front
    insertatFront(&myList, 10);
    insertatFront(&myList, 20);
    insertatFront(&myList, 30);

    printf("List after inserting at front:\n");
    display(&myList);
    printf("NULL\n");

    // Insert at the end
    insertatEnd(&myList, 40);
    insertatEnd(&myList, 50);

    printf("List after inserting at end:\n");
    display(&myList);
    printf("NULL\n");

    // Insert at a specific index (e.g., index 2)
    insertatIndex(&myList, 0, 25);

    printf("List after inserting at index 0:\n");
    display(&myList);
    printf("NULL\n");

    // Delete alternate nodes
    delete_alternate(&myList);

    printf("List after deleting alternate nodes:\n");
    display(&myList);
    printf("NULL\n");

    return 0;
}
