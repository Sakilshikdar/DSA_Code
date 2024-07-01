#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(int val, Node *&head, Node *&tail)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = tail = newnode;
        return;
    }
    newnode->prev = tail->next;
    tail->next = newnode;
    tail = newnode;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}
void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        insert_at_tail(val, head, tail);
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

int count_list(Node *head)
{
    Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

void insert_pos(int pos, int val, Node *&head, Node *&tail)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    int i = 1;
    if (pos > count_list(head) || pos < 1)
    {
        cout << "invalid pos" << endl;
    }
    else if(pos==1||head==NULL){
        insert_at_head( head, tail,val);
    }
    else if(pos==count_list(head)){
        insert_at_tail( val,head, tail);
    }

    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next=temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void insert_tail(int val,Node *&head,Node *&tail){
    Node *newnode = new Node(val);
    tail->next = newnode;
    newnode->prev = tail;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val,pos;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(val, head, tail);
    }
    cin >> pos;
    cin >> val;
    // insert_at_head( head, tail,val);
    // insert_pos(pos,val ,head, tail);
    insert_tail(val ,head, tail);
    // count_list(head);
    print_list(head);
    return 0;
}
