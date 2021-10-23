#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode{
    public:
        int data;
        SinglyLinkedListNode *next;
};

class SinglyLinkedList{
    public:
        SinglyLinkedListNode *head;
    public:
        SinglyLinkedList(){
            head = NULL;
        }    
        SinglyLinkedListNode* new_node(int value){

            SinglyLinkedListNode *node = new SinglyLinkedListNode();
            node -> data = value;
            node -> next = NULL;
            return node;
        }

        void append(int data) {
            if(head == NULL) {
                head = new_node(data);
                return;
            }
            SinglyLinkedListNode *temp;
            temp = head;
            while(temp ->next != NULL) temp = temp ->next;
            temp->next = new_node(data);
            return;
        }

        void reverse_linked_list(){
            SinglyLinkedListNode* rev = NULL, *temp;

            while(head != NULL){
                temp = head;
                head = head->next;
                temp->next = rev;
                rev = temp;
            }
            head = rev;
            return;
        }

        void print(){
            SinglyLinkedListNode *temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            return;
        }

        ~SinglyLinkedList(){
            while(head){
                SinglyLinkedListNode *temp = head;
                head = head->next;
                free(temp);
            }
        }
};

int main()
{

    SinglyLinkedList llist;

    llist.append(1);
    llist.append(2);
    llist.append(3);
    llist.append(3);
    llist.append(4);
    llist.append(5);

    llist.reverse_linked_list();

    llist.print();

    cout<<endl<<sizeof(SinglyLinkedList);
    
    return 0;
}
