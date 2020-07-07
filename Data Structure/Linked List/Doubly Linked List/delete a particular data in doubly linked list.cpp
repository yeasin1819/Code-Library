#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
    Node *next;
};

void append(Node *head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    while(head -> next != NULL) head = head -> next;
    new_node -> data = data;
    new_node -> prev = head;
    head -> next = new_node;
    new_node -> next = NULL;
}

void delete_data(Node *head, int data)
{
    while(head -> next != NULL)
    {
        if(head -> next -> data == data)
        {
            if(head -> next -> next == NULL)
            {
                head -> next = NULL;
                return;
            }
            head -> next -> next -> prev = head -> next -> prev;
            head -> next = head -> next -> next;
        }
        head = head -> next;
    }
    return;
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

void reverse_print(Node *head)
{
    while(head -> next != NULL) head = head -> next;
    while(head -> prev != NULL)
    {
        cout<<head -> data<<" ";
        head = head -> prev;
    }
    cout<<endl;
}

int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> prev = NULL;
    head -> next = NULL;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    print(head);
    delete_data(head, 2);
    print(head);
    reverse_print(head);

    return 0;
}
