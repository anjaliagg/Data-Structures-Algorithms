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
struct node * create(int new_data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data= new_data;
    temp->flag=0;
    return temp;
}

int searchLoop(struct node* head){
    struct node* move= head;
    while(move!=NULL && move->flag==0){
        move->flag=1;
        move=move->next;
    }
    if(move->flag==1)
        return 1;
    return 0;
}

void main(){
    struct node * head=NULL;
    struct node* pointer;
    int a;
    push(&head,3);
    head->next= create(4);
    head->next->next= create(5);
    pointer=head->next->next;
    push(&head,2);
    pointer->next=head;
    push(&head,1);
    a=searchLoop(head);
    printf("%d",a);
}