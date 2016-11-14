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

int identical(struct node*A,struct node *B){
    struct node* one=A;
    struct node* two=B;
    while(one!=NULL && two!=NULL){
        if(one->data!=two->data)
            return 0;
        one=one->next;
        two=two->next;
    }
    if(one==NULL && two==NULL)
        return 1;
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
    struct node* B=NULL;
    int i;
    
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    
    push(&B,7);
    push(&B,6);
    push(&B,5);
    push(&B,4);
    push(&B,3);
    push(&B,2);
    push(&B,1);
    
    i=identical(head,B);
    printf("%d",i);
    return 0;
}