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

void altDelete(struct node** head){
    if(*head==NULL)
        return;
    struct node*temp=*head;
    struct node* prev=*head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count%2==0){
            prev->next=temp->next;
            if(prev->next==NULL)
                return;
            prev=prev->next;
        }
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
    altDelete(&head);
    printf("\n\n");
    printList(head);
    return 0;
}