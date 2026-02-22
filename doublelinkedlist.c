#include <stdio.h>
#include <stdlib.h>
// Structure definition for Doubly Linked List
struct node
{
    int data;
    struct node *prev;   // address of previous node
    struct node *next;   // address of next node
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
    while (1)
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
        switch (ch)
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
        }
    }
}
// Create doubly linked list
struct node* create(struct node *head)
{
    struct node *newnode, *temp;
    int x, ch = 1;
    while (ch)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &x);
        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Add more? (1/0): ");
        scanf("%d", &ch);
    }
    return head;
}
// Insert at beginning
struct node* insert_begin(struct node *head)
{
    struct node *newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
    return head;
}
// Insert at end
struct node* insert_end(struct node *head)
{
    struct node *newnode, *temp;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        newnode->prev = NULL;
        return newnode;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}
// Insert in middle (after given value)
struct node* insert_middle(struct node *head)
{
    struct node *newnode, *temp;
    int x, key;
    if (head == NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("Insert after value: ");
    scanf("%d", &key);
    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    return head;
}
// Delete from beginning
struct node* delete_begin(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}
// Delete from end
struct node* delete_end(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return head;
}
// Delete specific node
struct node* delete_specific(struct node *head)
{
    struct node *temp;
    int key;
    if (head == NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("Enter value to delete: ");
    scanf("%d", &key);
    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}
// Traverse doubly linked list
void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
