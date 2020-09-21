#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;
typedef struct heap Heap;

struct node
{
    char ch;
    int f;
    Node *left, *right;
};

struct heap
{
    Node *arr[100] = {NULL};
    int idx = 0;

    void heapify(int i)
    {
        int left = 2 * i, right = 2 * i + 1, small = i;
        if(left<=idx && arr[left]->f < arr[small]->f) small = left;
        if(right<=idx && arr[right]->f < arr[small]->f) small = right;
        if(small != i) swap(arr[i], arr[small]), heapify(small);
    }

    void insert(Node *new_node)
    {
        idx++, arr[idx] = new Node;
        arr[idx]->ch = new_node->ch, arr[idx]->f = new_node->f;
        arr[idx]->left = new_node->left, arr[idx]->right = new_node->right;
        int n = idx / 2;
        while(n) heapify(n), n /= 2;
    }
    int size()
    {
        return idx;
    }
    void pop()
    {
        if(idx) swap(arr[1], arr[idx]), idx--, heapify(1);
        return;
    }
    Node *top()
    {
        return arr[1];
    }
};

void print_coding(Node *root, string code)
{
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL)
    {
        cout<<root->ch<<" "<<root->f<<" "<<code<<endl;
        return;
    }
    print_coding(root -> left, code + '0');
    print_coding(root -> right, code + '1');
}

void huffman_coding(Heap h)
{
    while(h.size() > 1)///build huffman tree.
    {
        Node *new_node = new Node;
        new_node->f = h.top()->f;
        new_node->left = h.top();
        h.pop();
        new_node->f += h.top()->f;
        new_node->right = h.top();
        h.pop();
        h.insert(new_node);
    }
    string code= "";
    print_coding(h.top(), code);
}

int main()
{
    /*input:
    6
    a 1
    b 1
    c 3
    d 4
    e 4
    f 7
    */
    Heap h;
    Node *a;
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a -> ch>>a -> f, h.insert(a);
    huffman_coding(h);

    return 0;
}
