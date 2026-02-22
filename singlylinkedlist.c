#include <stdio.h>
#include <stdlib.h>
//Structure definition
struct node
{
    int data;
    struct node *addr;   // stores address of next node
};
// Function declarations
struct node* create(struct node *head);
struct node* insert_begin(struct node *head);
struct node* insert_end(struct node *head);
struct node* insert_middle(struct node *head);
struct node* delete_begin(struct node *head);
struct node* delete_end(struct node *head);
struct node* delete_specific(struct node *head);
void traverse(struct node *head);
int main()
{
    struct node *head = NULL;
    int ch;
    while(1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert in Middle\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete Specific Node\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: head = create(head); break;
            case 2: head = insert_begin(head); break;
            case 3: head = insert_end(head); break;
            case 4: head = insert_middle(head); break;
            case 5: head = delete_begin(head); break;
            case 6: head = delete_end(head); break;
            case 7: head = delete_specific(head); break;
            case 8: traverse(head); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }    }   }
//Create linked list 
struct node* create(struct node *head)
{
    struct node *newnode, *temp;
    int x, ch = 1;
    while(ch)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &x);
        newnode->data = x;
        newnode->addr = NULL;
        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->addr = newnode;
            temp = newnode;
        }
        printf("Add more? (1/0): ");
        scanf("%d", &ch);
    }
    return head;
}
//Insert at beginning 
struct node* insert_begin(struct node *head)
{
    struct node *newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->addr = head;
    head = newnode;
    return head;
}
//Insert at end 
struct node* insert_end(struct node *head)
{
    struct node *newnode, *temp;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->addr = NULL;
    if(head == NULL)
        return newnode;
    temp = head;
    while(temp->addr != NULL)
        temp = temp->addr;
    temp->addr = newnode;
    return head;
}
//Insert in middle 
struct node* insert_middle(struct node *head)
{
    struct node *newnode, *temp;
    int x, key;
    if(head == NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("Insert after value: ");
    scanf("%d", &key);
    temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->addr;
    if(temp == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->addr = temp->addr;
    temp->addr = newnode;
    return head;
}
// Delete from beginning 
struct node* delete_begin(struct node *head)
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    temp = head;
    head = head->addr;
    free(temp);
    return head;
}
//Delete from end
struct node* delete_end(struct node *head)
{
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    if(head->addr == NULL)
    {
        free(head);
        return NULL;
    }
    prev = NULL;
    temp = head;
    while(temp->addr != NULL)
    {
        prev = temp;
        temp = temp->addr;
    }
    prev->addr = NULL;
    free(temp);
    return head;
}
//Delete specific node 
struct node* delete_specific(struct node *head)
{
    struct node *temp, *prev;
    int key;
    if(head == NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("Enter value to delete: ");
    scanf("%d", &key);
    if(head->data == key)
    {
        temp = head;
        head = head->addr;
        free(temp);
        return head;
    }
    prev = head;
    temp = head->addr;
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->addr;
    }
    if(temp == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    prev->addr = temp->addr;
    free(temp);
    return head;
}
//Traverse linked list 
void traverse(struct node *head)
{
    if(head == NULL)
    {
        printf("List empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->addr;
    }
    printf("NULL\n");
}
