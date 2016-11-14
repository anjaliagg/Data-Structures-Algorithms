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

int lPalin(struct node* A) {
    int *arr;
    arr=malloc(sizeof(int)* 500000);
    int i=0;
    int j=0;
    int flag=0;
    struct node * temp=A;
    if(temp==NULL)
        return 0;
    while(temp!=NULL){
        // printf("%d*\n",i);
        arr[i]=temp->data;
        // printf("%d^\n",arr[i]);
        i++;
        temp=temp->next;
    }
    // printf("%d#\n",j);
    while(j<(i/2)){
        // printf("%d\n",i);
        if(arr[j]==arr[i-j-1]){
            j++;
        }
        else
            j=i+100;
    }
    if(j==i/2){
        flag=1;
        return 1;
    }
    return 0;
}


int main(){
    struct node* head=NULL;
    // push(&head,1);
    // push(&head,8);
    push(&head,1);
    push(&head,2);
    push(&head,1);
    push(&head,2);
    push(&head,1);
    // push(&head,0);
    printList(head);
    printf("\n\n");
    printf("%d\n",lPalin(head));
    return 0;
}