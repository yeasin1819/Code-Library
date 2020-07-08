#include <bits/stdc++.h>

#define SIZE 100000

using namespace std;

typedef struct stack_data_structure Stack;

struct stack_data_structure
{
    int data[SIZE], top;
};

bool empty_stack(Stack *s)
{
    if(s -> top == -1) return 0;
    return 1;
}

void push(Stack *s, int data)
{
    s -> top++;
    s -> data[s -> top] = data;
}

void pop(Stack *s)
{
    s -> data[s -> top] = '\0';
    s -> top--;
}

void top(Stack *s)
{
    cout<<s -> data[s -> top]<<endl;
}

int main()
{
    Stack s;
    s.top = -1;

    cout<<empty_stack(&s)<<endl;
    push(&s, 1);
    push(&s, 2);
    pop(&s);
    push(&s, 3);
    push(&s, 4);
    top(&s);
    for(int i = 0; i <= s.top; i++) cout<<s.data[i]<<" ";

    return 0;
}
