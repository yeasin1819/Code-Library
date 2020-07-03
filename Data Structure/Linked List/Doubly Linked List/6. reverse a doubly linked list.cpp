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
    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    while(head -> next != NULL) head = head -> next;
    new_node -> prev = head;
    head -> next = new_node;
}
void reverse_print(Node *head)
{
    Node *temp = head -> next;
    while(temp -> next != NULL) temp = temp -> next;
    while(temp -> prev != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> prev;
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
    reverse_print(head);
    return 0;
}
