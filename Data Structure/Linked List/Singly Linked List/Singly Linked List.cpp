#include <bits/stdc++.h>

using namespace std;

typedef struct node SinglyList;

struct node
{
    int data;
    SinglyList *next = NULL, *tail = NULL;
    SinglyList *create_node(int data, SinglyList *next)
    {
        SinglyList *new_node = (SinglyList*)malloc(sizeof(SinglyList));
        new_node -> data = data;
        new_node -> next = next;
        return new_node;
    }
    void append(int data)
    {
        if(next == NULL)
        {
            next = create_node(data, NULL);
            tail = next;
            return;
        }
        tail -> next = create_node(data, NULL);
        tail = tail -> next;
    }
    void insert_nth_pos(int data, int pos)
    {
        if(pos == 1)
        {
            next = create_node(data, next);
            return;
        }
        SinglyList *temp = next;
        pos -= 2;
        while((temp -> next != NULL) && pos--) temp = temp -> next;
        temp -> next = create_node(data, temp -> next);
    }
    void delete_nth_node(int pos)
    {
        if(pos == 1)
        {
            next = next -> next;
            return;
        }
        SinglyList *temp = next;
        pos -= 2;
        while(temp -> next != NULL && pos--) temp = temp -> next;
        if(temp -> next == NULL) return;
        temp -> next = temp -> next -> next;
    }
    void delete_data(int data)
    {
        if(next -> data == data)
        {
            next = next -> next;
            return;
        }
        SinglyList *temp = next;
        while(temp -> next != NULL)
        {
            if(temp -> next -> data == data)
            {
                temp -> next = temp -> next -> next;
                return;
            }
            temp = temp -> next;
        }
    }
    void reverse_list()
    {
        SinglyList *rev = NULL, *temp = next;
        while(temp != NULL)
        {
            rev = create_node(temp -> data, rev);
            temp = temp -> next;
        }
        next = rev;
    }
    void print()
    {
        SinglyList *t = next;
        while(t != NULL)
        {
            t->next==NULL ? cout<<t->data<<endl : cout<<t->data<<" ";
            t = t -> next;
        }
    }
};

int main()
{
    SinglyList obj;
    obj.append(2);
    obj.insert_nth_pos(1, 1);
    obj.insert_nth_pos(3, 3);
    obj.print();
    obj.reverse_list();
    obj.print();
    obj.reverse_list();
    obj.delete_nth_node(1);
    obj.delete_data(2);
    obj.print();

    return 0;
}
