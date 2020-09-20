#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
typedef struct minimum_heap m_heap;

struct node
{
    int v;
    Node *left, *right;
};

struct minimum_heap
{
    int idx = 0;
    Node *root = NULL;

    void heapify(Node *root)
    {
        if(root == NULL) return;
        Node *small = root;
        if((root->left != NULL)&&(root->left->v < small->v)) small = root->left;
        if((root->right != NULL)&&(root->right->v < small->v)) small = root->right;
        if(small != root) swap(root->v, small->v), heapify(small);
    }

    Node *root_of_last_node()
    {
        Node *temp = root;
        stack<int> s;
        int n = idx, t;
        while(n) s.push(n), n /= 2;
        s.pop();
        while(s.size() > 1)
        {
            t = s.top(), s.pop();
            t % 2 ? temp = temp->right : temp = temp->left;
        }
        return temp;
    }

    void insert(int v)
    {
        ++idx;
        Node *new_node = new Node;

        new_node->v = v, new_node->left = NULL, new_node->right = NULL;
        if(root == NULL)
        {
            root = new Node, root = new_node;
            return;
        }
        Node *temp = root_of_last_node();
        temp->left == NULL ? temp->left = new_node : temp->right = new_node;
    }
    Node *top()
    {
        return root;
    }
    void pop()
    {
        if(root == NULL) return;
        if(idx == 1)
        {
            root = NULL, idx--;
            return;
        }
        Node *temp = root_of_last_node();
        if(idx % 2) swap(root->v, temp->right->v), temp -> right = NULL;
        else swap(root->v, root->left->v), temp->left = NULL;
        idx--, heapify(root);
        return;
    }
    void heap(Node *root)
    {
        if(root == NULL) return;
        heap(root -> right);
        heap(root -> left);
        heapify(root);
    }
    int size()
    {
        return idx;
    }
};

int main()
{
    m_heap mh;

    mh.insert(2);
    mh.insert(3);
    mh.insert(1);

    mh.heap(mh.root);

    while(mh.size())
    {
        cout<<mh.top() -> v<<" ";
        mh.pop();
    }

    return 0;
}
