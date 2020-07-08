#include <bits/stdc++.h>

using namespace std;

typedef struct node Stack;

struct node
{
    int data;
    Stack *next;
};

void push(Stack *s, int data)
{
    Stack *new_Stack = (Stack*)malloc(sizeof(Stack));
    new_Stack -> data = data;
    new_Stack -> next = s -> next;
    s -> next = new_Stack;
}

void pop(Stack *s)
{
    if(s -> next == NULL) return;
    Stack *temp = s -> next;
    s -> next = s -> next -> next;
    delete temp;
}

void top(Stack *s)
{
    if(s -> next == NULL) return;
    cout<<s -> next -> data<<endl;
}

void print(Stack *s)
{
    while(s -> next != NULL)
    {
        cout<<s -> next -> data<<" ";
        s = s -> next;
    }
    cout<<endl;
}

int main()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s -> next = NULL;

    push(s, 1);
    push(s, 2);
    push(s, 3);
    pop(s);
    top(s);
    push(s, 3);
    print(s);

    return 0;
}
