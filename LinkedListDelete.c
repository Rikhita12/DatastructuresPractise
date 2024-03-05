#include <stdio.h>
#include <stdlib.h>

// Define the node structure globally
struct node {
    int data;
    struct node* next;
};

// Initialize the head of the linked list globally
struct node *head = NULL;

// Function to insert elements into the linked list
void insertElementAtLast(int data) {
    // Allocate memory for the new node
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
    
        // Assign data to the new node
         newnode->data = data;
         newnode->next = NULL;

        // If the list is empty, make the new node as the head
        if (head == NULL) {
            head = newnode;
        } 
        else {
        // Traverse to the end of the list
            struct node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
        // Insert the new node at the end
        temp->next = newnode;
        }
    }
    
    void insertElementAtLoc(int data,int loc) {
    // Allocate memory for the new node
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        if(loc<0){
        printf("Invalid position");
        return;}
        // Assign data to the new node
         newnode->data = data;
         newnode->next = NULL;
        // If the list is empty, make the new node as the head
        if (head == NULL) {
            head = newnode;
        } 
        else {
        // Traverse to the end of the list
            struct node* temp = head;
            int i=0;
            while (i<loc) {
                temp = temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            
        }
    }


void insertElementAtFirst(int data) {
    // Allocate memory for the new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Assign data to the new node
    newnode->data = data;
    newnode->next = NULL;

    // If the list is empty, make the new node as the head
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next=head;
        head=newnode;
        }
    }
    
    void deleteFirst(){
        struct node* temp=head;
        if(head==NULL)
        printf("LinkedList is empty");
        else{
            head=head->next;
            free(temp);
        }
    }
    
    void deleteLast(){
        struct node* temp=head;
        struct node* prevnode;
        if(head==NULL)
        printf("LinkedList is empty");
        else{
            while(temp->next!=NULL)
                {
                prevnode=temp;
                temp=temp->next;
                 }
            prevnode->next=0;
            free(temp);
            }
    }
    
    void deleteAtLoc(int loc){
        struct node* temp=head;
        struct node* prevnode;
        if(head==NULL)
        printf("LinkedList is empty");
        else{
            int i=0;
            while(i<loc)
                {
                prevnode=temp;
                temp=temp->next;
                i++;
                 }
            prevnode->next=temp->next;
            free(temp);
            }
    }
    

// Function to display all elements in the linked list
void displayElements() {
    struct node* temp = head;
    int i = 0;
    printf("The elements of linked list are:\n");
    while (temp != NULL) {
        printf("Element at loc %d is %d\n", i++, temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice = 1;
    while (choice != 0) {
        int data;
        if(choice==1){
        printf("Enter the data to insert into the linked list:");
        scanf("%d", &data);
        insertElementAtLast(data);}
        else if(choice==2){
        printf("Enter the data to insert into the linked list:");
        scanf("%d", &data);  
        insertElementAtFirst(data);}
        else if(choice==3){
            printf("Enter the data to insert into the linked list:");
            scanf("%d", &data);
            int loc;
            printf("Enter the position to insert new element:");
            scanf("%d",&loc);
            insertElementAtLoc(data,loc);
        }
        else if(choice==4){
        deleteFirst();}
        else if(choice==5){
        deleteLast();}
        else if(choice==6){
            int loc;
            printf("Enter the position to delete new element:");
            scanf("%d",&loc);
            deleteAtLoc(loc);
        }
        printf("Enter choice 0 or 1\n0-To display all elements\n1-InsertAtLast\n2-InsertAtFirst\n3-InsertAtLoc\n4-Delete at First\n5-DeleteLast\n6-Delete At Location");
        scanf("%d", &choice);
    }
    displayElements();
    return 0;
}
