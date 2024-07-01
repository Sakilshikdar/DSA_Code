#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
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
    tail->next = newnode;
    tail = newnode;
}

int count_list(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_head(Node *&head, Node *&tail, int val)
{
    if (head == NULL)
    {
        insert_at_tail(val, head, tail);
    }
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insert_pos(Node *&head, Node *&tail, int val, int pos)
{
    int i = 1;
    Node *temp = head;
    Node *newnode = new Node(val);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_head(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete (temp);
}
void delete_tail(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete (tail);
    tail = temp;
    tail->next = NULL;
}

void delete_pos(Node *&head, Node *&tail, int pos)
{
    Node *temp = head;
    Node *del = NULL;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    del = temp->next;
    temp->next = temp->next->next;
    delete (del);
}

void print_list_recursive(Node *head, Node *tail)
{
    if (head == NULL)
    {
        return;
    }
    print_list_recursive(head->next, tail);
    cout << head->val << "->";

    // Node *prev = NULL;
    // Node *curr = head;
    // Node *next = NULL;

    // while (curr != NULL)
    // {
    //     next = curr->next; // Store the next node
    //     curr->next = prev; // Reverse the current node's pointer
    //     prev = curr;       // Move pointers one position ahead
    //     curr = next;
    // }

    // // Update head and tail
    // tail = head;
    // head = prev;
}

int main()
{
    Node *head = NULL; // Initialize head
    Node *tail = NULL; // Initialize tail
    int val, pos;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(val, head, tail);
    }
    // print_list(head);
    cin >> val;
    // insert_head(head, tail, val);
    // cin >> pos;
    // insert_pos(head,tail, val,pos);
    // delete_head(head);
    // delete_tail(head,tail);
    // delete_pos(head,tail,val);
    // reverse_list(head, tail);
    print_list_recursive(head, tail);
    cout << "NULL";
    // print_list(head);
    // int c = count_list(head);
    // cout << "size" << c << endl;
    return 0;
}
