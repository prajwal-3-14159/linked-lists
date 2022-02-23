#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node
{
    int number;
    Node *next;

} Node;

// Node *head;

void Insert(Node **head, int x);
void insert_at_n(Node **head, int x, int n);
void insert_at_end(Node **head, int x);
void delete_1st_node(Node **head);
void delete_nth_node(Node **head, int n);
void delete_end(Node **head);
void Print(Node *head);

int main()
{
    Node *head;
    head = NULL; // empty list
    // cout<<"how many numbers?\n";
    int i, n, x;
    // scanf("%d", &n);
    n = 7;
    for (i = 0; i < n; i++)
    {
        // cout<<"enter the number\n";
        // cin>>x;
        Insert(&head, i);
        Print(head);
    }

    insert_at_n(&head, 314, 3);
    Print(head);
    insert_at_n(&head, 271, 3);
    Print(head);
    delete_nth_node(&head, 3);
    Print(head);
    delete_nth_node(&head, 3);
    Print(head);
    insert_at_end(&head, 314);
    Print(head);
    Insert(&head, 7);
    Print(head);
    delete_1st_node(&head);
    Print(head);
    delete_end(&head);
    Print(head);

    /*for(i = n; i>0; i-- )
    {
        //cout<<"enter the number\n";
        //cin>>x;
        delete_nth_node(&head, i);
        Print(head);
    }*/
    // Print(head);
    return 0;
}

void Insert(Node **head, int x)
{
    Node *temp = new Node();
    temp->number = x;
    temp->next = *head;
    *head = temp;
}

void insert_at_n(Node **head, int x, int n)
{
    Node *ptr = *head;
    Node *temp = (Node *)malloc(sizeof(Node));

    temp->number = x;
    temp->next = NULL;

    if (n == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    for (int i = 0; i < (n - 2); i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void insert_at_end(Node **head, int x)
{
    Node *temp = new Node;
    Node *ptr = *head;

    temp->number = x;
    temp->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    //*head = temp;
}

void delete_1st_node(Node **head)
{
    Node *ptr = *head;
    // Node* temp = *head;

    *head = ptr->next;
    free(ptr);
    ptr = NULL;
}

void delete_nth_node(Node **head, int n)
{
    Node *ptr = *head;
    Node *temp = *head;

    if (n == 1)
    {
        *head = temp->next;
        free(temp);
        free(ptr);
        return;
    }

    ptr = ptr->next;

    for (int i = 0; i < (n - 2); i++)
    {
        ptr = ptr->next;
        temp = temp->next;
    }
    temp->next = ptr->next;
    free(ptr);
    ptr = NULL;
}

void delete_end(Node **head)
{
    Node *temp = *head;
    Node *ptr = *head;

    ptr = ptr->next;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        temp = temp->next;
    }

    temp->next = NULL;
    free(ptr);
    ptr = NULL;
}

void Print(Node *head)
{
    Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->number);
        temp = temp->next;
    }
    printf("\n");
}
