#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
typedef struct tree Tree;

struct node
{
    int data;
    Node *right, *left;
};

struct tree
{
    Node *root = NULL;

    void insert_node(int data)
    {
        Node *temp, *prev, *new_node = (Node*)malloc(sizeof(Node));
        new_node -> data = data;
        new_node -> left = NULL, new_node -> right = NULL;

        prev = NULL, temp = root;
        while(temp != NULL)
            prev = temp, temp -> data > data ? temp = temp -> left : temp = temp -> right;

        if(prev == NULL) root = new_node;
        else prev -> data > data ? prev -> left = new_node : prev -> right = new_node;
    }

    Node *remove_node(Node *root)
    {
        if(root -> left == NULL && root -> right == NULL) return NULL;
        if(root -> left == NULL) return root -> right;
        if(root -> right == NULL) return root -> left;

        Node *temp = root -> right, *prev = root;
        while(temp -> left != NULL) prev = temp, temp = temp -> left;
        root -> data = temp -> data;
        if(temp -> right != NULL)
        {
            if(prev -> left == temp) prev -> left = temp -> right;
            else prev -> right = temp -> right;
        }
        if(temp -> right == NULL)
        {
            if(prev -> left == temp) prev -> left = NULL;
            else prev -> right = NULL;
        }
        return root;
    }

    void delete_node(int data)
    {
        if(root == NULL) return;
        Node *temp = root, *prev = NULL;

        while(temp != NULL && temp -> data != data)
            prev = temp, temp -> data > data ? temp = temp -> left : temp = temp -> right;

        if(root -> data == data)
        {
            root = remove_node(root);
            return;
        }
        if(prev -> left != NULL)
            if(prev -> left -> data == data) prev -> left = remove_node(prev -> left);
        if(prev -> right != NULL)
            if(prev -> right -> data == data) prev -> right = remove_node(prev -> right);
        return;
    }

    void pre_order(Node *root)
    {
        if(root == NULL) return;
        cout<<root -> data<<" ";
        pre_order(root -> left);
        pre_order(root -> right);
    }

    void in_order(Node *root)
    {
        if(root == NULL) return;
        in_order(root -> left);
        cout<<root -> data<<" ";
        in_order(root -> right);
    }

    void post_order(Node *root)
    {
        if(root == NULL) return;
        post_order(root -> left);
        post_order(root -> right);
        cout<<root -> data<<" ";
    }
};

int main()
{
    Tree t;

    t.insert_node(45);
    t.insert_node(54);
    t.insert_node(40);
    t.insert_node(49);
    t.insert_node(38);
    t.insert_node(70);
    t.insert_node(30);
    t.insert_node(39);
    t.insert_node(41);
    t.insert_node(45);
    t.insert_node(44);

    while(1)
    {
        int data;
        cin>>data;
        t.delete_node(data);
        t.pre_order(t.root);
        cout<<endl;
        t.in_order(t.root);
        cout<<endl;
        t.post_order(t.root);
        cout<<endl;
    }
    return 0;
}
