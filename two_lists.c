#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void push(struct node ** head, int num){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=*head;
    *head=new_node;
}

void printList(struct node * head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void two(struct node* head){
    struct node* A=head;
    if(A==NULL)
        return;
    struct node* B=head->next;
    struct node* temp1=A;
    struct node* temp2=B;
    if(temp2==NULL){
        printList(A);
        return;
    }
    while(temp1->next!=NULL && temp2->next!=NULL){
        temp1->next=temp1->next->next;
        temp1=temp1->next;
        temp2->next=temp2->next->next;
        temp2=temp2->next;
        if(temp1==NULL || temp2==NULL)
            break;
    }
    temp1->next=NULL;
    temp2->next=NULL;
    printList(A);
    printf("\n\n");
    printList(B);
}

int main(){
    struct node* head=NULL;
    push(&head,1);
    push(&head,0);
    push(&head,1);
    push(&head,0);
    push(&head,1);
    push(&head,0);
    push(&head,1);
    push(&head,0);
    printList(head);
    printf("\n\n");
    two(head);
    return 0;
}