#include <bits/stdc++.h>

using namespace std;

typedef struct node doublyList;

struct node
{
    int data;
    doublyList *prev = NULL, *next = NULL;

    doublyList *create_node(int data, doublyList *prev, doublyList *next)
    {
        doublyList *new_node = (doublyList*)malloc(sizeof(doublyList));
        new_node -> data = data;
        new_node -> prev = prev;
        new_node -> next = next;
        return new_node;
    }
    void append(int data)
    {
        if(next == NULL)
        {
            next = create_node(data, NULL, NULL);
            return;
        }
        doublyList *temp = next;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = create_node(data, temp, NULL);
    }
    void insert_nth_pos(int data, int pos)
    {
        if(pos == 1)
        {
            next -> prev = create_node(data, NULL, next);
            next = next -> prev;
            return;
        }
        pos -= 2;
        doublyList *temp = next;
        while(temp -> next != NULL && pos--) temp = temp -> next;
        if(temp->next == NULL) temp->next = create_node(data, temp, NULL);
        else
        {
            temp -> next -> prev = create_node(data, temp, temp -> next);
            temp -> next = temp -> next -> prev;
        }
    }
    void delete_nth_node(int pos)
    {
        if(pos == 1)
        {
            next = next -> next;
            next -> prev = NULL;
            return;
        }
        doublyList *temp = next;
        pos -= 2;
        while(temp -> next != NULL && pos--) temp = temp -> next;
        if(temp -> next == NULL) return;
        if(temp -> next -> next == NULL)
        {
            temp -> next = NULL;
            return;
        }
        temp -> next -> next -> prev = temp;
        temp -> next = temp -> next -> next;
    }
    void delete_data(int data)
    {
        if(next -> data == data)
        {
            next = next -> next;
            next -> prev = NULL;
            return;
        }
        doublyList *temp = next;
        while(temp -> next != NULL)
        {
            if(temp -> next -> data == data)
            {
                if(temp -> next -> next == NULL)
                {
                    temp -> next = NULL;
                    return;
                }
                temp -> next -> next -> prev = temp;
                temp -> next = temp -> next -> next;
                return;
            }
            temp = temp -> next;
        }

    }
    void print()
    {
        doublyList *temp = next;
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
    void reverse_print()
    {
        doublyList *temp = next;
        while(temp -> next != NULL) temp = temp -> next;
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> prev;
        }
        cout<<endl;
    }

};

int main()
{
    doublyList myList;

    myList.append(2);
    myList.insert_nth_pos(1, 1);
    myList.insert_nth_pos(0, 1);
    myList.append(3);
    myList.append(4);
    myList.print();
    myList.delete_nth_node(3);
    myList.delete_data(0);
    myList.print();
    myList.reverse_print();

    return 0;
}
