#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
typedef struct priority_Queue PQ;

struct node
{
    int data;
    Node *left, *right;
};

struct priority_Queue
{
    Node *root = NULL;

    void enQueue(int data)
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = data;
        new_node -> left = new_node -> right = NULL;

        Node *temp = root, *prev = NULL;
        while(temp != NULL)
        prev = temp, temp -> data > data ? temp = temp -> left : temp = temp -> right;
        if(prev == NULL) root = new_node;
        else prev -> data > data ? prev -> left = new_node : prev -> right = new_node;
    }

    void deQueue()
    {
        Node *prev = NULL, *temp = root;
        if(temp == NULL) return;
        while(temp -> right != NULL) prev = temp, temp = temp -> right;
        if(prev == NULL) root = root -> left;
        else if(temp -> left != NULL) prev -> right = temp -> left;
        else prev -> right = NULL;
    }

    int top()
    {
        Node *temp = root;
        while(temp -> right != NULL) temp = temp -> right;
        return temp -> data;
    }

    void print(Node *root)
    {
        if(root == NULL) return;
        print(root -> right);
        cout<<root -> data<<" ";
        print(root -> left);
    }
};

int main()
{
    PQ pq;

    pq.enQueue(26);
    pq.enQueue(90);
    pq.enQueue(80);
    pq.enQueue(70);
    pq.enQueue(100);

    cout<<pq.top()<<endl;
    pq.print(pq.root);
    cout<<endl;

    pq.deQueue();
    pq.deQueue();

    cout<<pq.top()<<endl;
    pq.print(pq.root);
    cout<<endl;

    return 0;
}
