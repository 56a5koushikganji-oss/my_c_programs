#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
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
//Create Single Circular Linked List
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
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
        printf("Add more? (1/0): ");
        scanf("%d", &ch);
    }
    return head;
}
// Insert at beginning
struct node* insert_begin(struct node *head)
{
    struct node *newnode, *temp;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    newnode->data = x;
    if (head == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    newnode->next = head;
    temp->next = newnode;
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
    if (head == NULL)
    {
        newnode->next = newnode;
        return newnode;
    }
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
    return head;
}
// Insert in middle (after given value)
struct node* insert_middle(struct node *head)
{
    struct node *newnode, *temp;
    int key, x;
    if (head == NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("Insert after value: ");
    scanf("%d", &key);
    temp = head;
    do
    {
        if (temp->data == key)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &x);
            newnode->data = x;
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Element not found\n");
    return head;
}
//Delete from beginning
struct node* delete_begin(struct node *head)
{
    struct node *temp, *last;
    if (head == NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    last = head;
    while (last->next != head)
        last = last->next;
    temp = head;
    head = head->next;
    last->next = head;
    free(temp);
    return head;
}
//Delete from end 
struct node* delete_end(struct node *head)
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("List empty\n");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    temp = head;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}
//Delete specific node
struct node* delete_specific(struct node *head)
{
    struct node *temp, *prev;
    int key;
    if (head == NULL)
    {
        printf("List empty\n");
        return head;
    }
    printf("Enter value to delete: ");
    scanf("%d", &key);
    temp = head;
    prev = NULL;
    do
    {
        if (temp->data == key)
        {
            if (temp == head)
                return delete_begin(head);
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    printf("Element not found\n");
    return head;
}
//Traverse Single Circular Linked List
void traverse(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
	while (temp != head);
    printf("(HEAD)\n");
}
