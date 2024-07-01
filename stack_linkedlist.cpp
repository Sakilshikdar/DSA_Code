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
Node *top = 0;

void stackPush(int val, Node *&head)
{
    Node *newnode = new Node(val);
    newnode->val = val;
    newnode->next = top;
    top = newnode;
}
void printStack()
{
    Node *top2 = top;
    while (top2 != NULL)
    {
        cout << top2->val << " ";
        top2 = top2->next;
    }
}
void popStack() {
    Node *temp = top;
    if(temp==0){
        cout << "stack is empty" << endl;
        return;
    }
    top = top->next;
    delete (temp);
};

int main()
{
    Node *head = NULL;
    int num;
    while (true)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        stackPush(num, head);
    }
    cout << endl;
    cout << top->val << endl;
    printStack();
    cout << endl;
    popStack();
    printStack();
    return 0;
}