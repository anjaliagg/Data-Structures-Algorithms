
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int flag;
    struct node* next;
};

void push(struct node **head, int new_data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data= new_data;
    new_node->flag=0;
    new_node->next=*head;
    *head=new_node;
}

void printList(struct node* head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}

struct node * merge(struct node* A, struct node * B){
    struct node *head=NULL;
    struct node *temp1;
    struct node *temp2;
    struct node * temp;
    if(A->data<B->data){
        head=A;
        temp1=A->next;
        temp2=B;
    }
    else{
        head=B;
        temp1=A;
        temp2=B->next;
    }
    temp=head;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp->next=temp1;
            temp=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp2==NULL)
        temp->next=temp1;
    else temp->next=temp2;
    return head;
}

void main(){
    struct node * A= NULL;
    struct node * B= NULL;
    push(&A,8);
    push(&A,6);
    push(&A,5);
    push(&A,2);
  
    push(&B,7);
    push(&B,4);
    push(&B,3);
    printList(A);
    printf("\n\n");
    printList(B);
    printf("\n\n");
    printList(merge(A,B));
}
