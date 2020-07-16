#include <bits/stdc++.h>

using namespace std;

typedef struct node Stack;

struct node
{
    int data;
    Stack *next = NULL, *prev = NULL, *tail = NULL;

    Stack *create_node(int data, Stack *prev, Stack *next)
    {
        Stack *new_node = (Stack*)malloc(sizeof(Stack));
        new_node -> data = data;
        new_node -> prev = prev;
        new_node -> next = next;
        return new_node;
    }
    void push(int data)
    {
        if(next == NULL)
        {
            next = create_node(data, NULL, NULL);
            tail = next;
            return;
        }
        tail -> next = create_node(data, tail, NULL);
        tail = tail -> next;
    }
    void pop()
    {
        if(next == NULL) return;
        if(next -> next == NULL)
        {
            tail = next = NULL;
            return;
        }
        tail = tail -> prev;
        tail -> next = NULL;
    }
    int top()
    {
        return tail -> data;
    }
    void print()
    {
        Stack *temp = next;
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
    bool empty()
    {
        if(next == NULL) return 1;
        return 0;
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout<<s.empty()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    s.print();

    return 0;
}
