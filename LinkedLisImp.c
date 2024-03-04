#include <stdio.h>
#include<stdlib.h>

//Linked List Implementation using C Programming

void linkedImp(){
    struct node
    {
        int data;
        struct node* next;
    };
    struct node *head,*newnode,*temp;
    int choice=1;
    while(choice!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data to linked list:");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter choice 0 or 1\n0-To display all elements\n1-insert elements\n");
        scanf("%d",&choice);
    }
    temp=head;
    int i=0;
    printf("The elements of linked list are:\n");
    while(temp!=0)
        {
            printf("Element at loc %d is %d\n",i++,temp->data);
            temp=temp->next;
        }
}


int main()
{
    linkedImp();
    return 0;
}
