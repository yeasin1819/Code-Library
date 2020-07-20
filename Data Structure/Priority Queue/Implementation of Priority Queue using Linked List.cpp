#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
typedef struct priority_Queue PQ;

struct node
{
    int data;
    Node *next;
};

struct priority_Queue
{
    Node *head = NULL, *tail = NULL;

    void push(int data)
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = data;
        new_node -> next = NULL;

        if(head == NULL) head = tail = new_node;
        else if(head -> data < data) new_node -> next = head, head = new_node;
        else if(tail -> data > data) tail -> next = new_node, tail = new_node;
        else
        {
            Node *temp = head, *prev;
            while(temp -> data > data) prev = temp, temp = temp -> next;
            new_node -> next = prev -> next;
            prev -> next = new_node;
        }
    }

    void pop()
    {
        if(head == NULL) return;
        head = head -> next;
    }

    int top()
    {
        return head -> data;
    }
    void print()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};


int main()
{
    PQ pq;

    pq.push(1);
    pq.push(2);
    pq.push(0);
    pq.push(-1);
    pq.push(4);
    pq.push(3);
    pq.push(1);
    pq.push(10);
    pq.push(8);
    pq.print();
    cout<<pq.top()<<endl;
    pq.pop();
    pq.pop();
    pq.print();
    cout<<pq.top();

    return 0;
}
