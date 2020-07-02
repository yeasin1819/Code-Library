#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void append(Node *head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;
    while(head -> next != NULL) head = head -> next;
    head -> next = new_node;
}

void prepend(Node *head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = head -> next;
    head -> next = new_node;
}

void print(Node *head)
{
    while(head -> next != NULL)
    {
        cout<<head -> next -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

void reverse_list(Node *head)
{
    Node *prev = head, *rev = NULL;
    while(head -> next != NULL)
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = head -> next -> data;
        new_node -> next = rev;
        rev = new_node;
        head = head -> next;
    }
    prev -> next = rev;
}

int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;
    append(head, 2);
    append(head, 3);
    append(head, 4);
    prepend(head, 1);
    print(head);
    reverse_list(head);
    print(head);

    return 0;
}
