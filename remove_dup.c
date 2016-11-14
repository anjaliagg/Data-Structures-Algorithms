#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

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

void removeDuplicate(struct node* head){
    struct node * a= head;
    struct node * b;
    struct node * prev;
    while(a->next!=NULL){
        b=a->next;
        prev=a;
        while(b!=NULL){
            if(a->data==b->data){
                prev->next=b->next;
                free(b);
                b=prev->next;
            }
            else{
                b=b->next;
                prev=prev->next;
            }        
        }
        a=a->next;
    }
}


int main(){
    struct node * head=NULL;
    push(&head,61);
    push(&head,43);
    push(&head,41);
    push(&head,12);
    push(&head,12);
    push(&head,12);
    push(&head,12);
    printList(head);
    printf("\n\n");
    removeDuplicate(head);
    printList(head);
    return 0;
}
