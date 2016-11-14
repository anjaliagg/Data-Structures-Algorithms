#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void reverse(struct node *head){
   if(head->next==NULL){
       printf("%d\n",head->data);
       return;
   }
   reverse(head->next);
   printf("%d\n",head->data);
}

void push(struct node **head, int new_data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data= new_data;
    new_node->next=*head;
    *head=new_node;
}

void printList(struct node* head){
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}

int main(){
    struct node * head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    printList(head);
    printf("\n\n");
    reverse(head);
    return 0;
}