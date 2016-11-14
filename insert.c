#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
	int data;
	struct node* next;
};

void push(struct node** head,int new_data){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=new_data;
    temp->next=*head;
    *head=temp;
}

void insert(struct node** head, int num) {
    struct node * temp=*head;
    struct node* prev=NULL;
    struct node * node_in=(struct node*)malloc(sizeof(struct node));
    node_in->data=num;
    if(temp->data>node_in->data){
        *head=node_in;
        node_in->next=temp;
        return;
    }
    while(temp!=NULL && temp->data<node_in->data){
            prev=temp;
            temp=temp->next;
    }
    prev->next=node_in;
    node_in->next=temp;
}

/* Function to print linked list */
void printList(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void main(){
    struct node* head=NULL;
    push(&head,9);
    push(&head,6);
    push(&head,5);
    push(&head,3);
    push(&head,2);
    printList(head);
    printf("\n\n");
    insert(&head,1);
    printList(head);
}