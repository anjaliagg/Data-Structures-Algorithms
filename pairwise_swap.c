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

void swap(struct node**head){
    struct node* curr=*head;
    struct node* next=curr->next;
    struct node* prev=*head;
    if(*head==NULL)
        return;
    while(curr!=NULL && next!=NULL){
        curr->next=next->next;
        next->next=curr;
        if(curr==*head){
            *head=next;
            prev=prev;
        }
        else{
            prev->next=next;
            prev=curr;
        }
        curr=curr->next;
        next=curr->next;
    }
}

void printList(struct node * head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node* head=NULL;
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printList(head);
    swap(&head);
    printf("\n\n");
    printList(head);
    return 0;
}