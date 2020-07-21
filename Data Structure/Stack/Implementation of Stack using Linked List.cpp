#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
typedef struct stack_ds Stack;

struct node
{
    int data;
    Node *next;
};

struct stack_ds
{
    Node *head = NULL;

    void push(int data)
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = data;
        new_node -> next = NULL;
        if(head == NULL)
        {
            head = new_node;
            return;
        }
        new_node -> next = head;
        head = new_node;
    }

    int top()
    {
        return head -> data;
    }
    void pop()
    {
        if(head == NULL) return;
        head = head -> next;
    }
    bool empty()
    {
        if(head == NULL) return 1;
        return 0;
    }
};

int main()
{
    ///input: 9 10 12 16 24 21 16 14 12 ctrl + z
    Stack s;

    int n, data;
    while(cin>>data != NULL)
    {
        s.push(data);
    }
    cout<<"Element at top of the stack: "<<s.top()<<endl;
    cout<<"Stack data element are: "<<endl;
    while(!s.empty())
    {
        int x = s.top();
        cout<<x<<endl;
        s.pop();
    }
    return 0;
}
