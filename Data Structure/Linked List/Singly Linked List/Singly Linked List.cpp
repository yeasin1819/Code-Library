#include <bits/stdc++.h>

using namespace std;

typedef struct node singlyList;

struct node
{
    int data;
    singlyList *next = NULL;
    singlyList *create_node(int data, singlyList *next)
    {
        singlyList *new_node = (singlyList*)malloc(sizeof(singlyList));
        new_node -> data = data;
        new_node -> next = next;
        return new_node;
    }
    void append(int data)
    {
        singlyList *temp = next;
        if(next == NULL)
        {
            next = create_node(data, NULL);
            return;
        }
       while(temp -> next != NULL) temp = temp -> next;
       temp -> next = create_node(data, NULL);
    }
    void insert_nth_pos(int data, int pos)
    {
        if(pos == 1)
        {
            next = create_node(data, next);
            return;
        }
        singlyList *temp = next;
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
        singlyList *temp = next;
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
        singlyList *temp = next;
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
        singlyList *rev = NULL, *temp = next;
        while(temp != NULL)
        {
            rev = create_node(temp -> data, rev);
            temp = temp -> next;
        }
        next = rev;
    }
    void print()
    {
        singlyList *t = next;
        while(t != NULL)
        {
            t->next==NULL ? cout<<t->data<<endl : cout<<t->data<<" ";
            t = t -> next;
        }
    }
};

int main()
{
    singlyList myList;
    myList.append(2);
    myList.insert_nth_pos(1, 1);
    myList.insert_nth_pos(3, 3);
    myList.append(4);
    myList.print();
    myList.reverse_list();
    myList.print();
    myList.reverse_list();
    myList.delete_nth_node(1);
    myList.delete_data(2);
    myList.print();

    return 0;
}
