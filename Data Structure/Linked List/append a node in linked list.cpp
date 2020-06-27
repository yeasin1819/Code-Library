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

void print(Node *head)
{
    while(head -> next != NULL)
    {
        cout<<head -> next -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;

    append(head, 1);
    append(head, 2);
    print(head);
    append(head, 3);
    print(head);

    return 0;
}
