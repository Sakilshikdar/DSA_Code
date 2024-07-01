#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int arr[N];
int top = -1;

void pushStack(int n)
{
    if(top==N-1){
        cout << "stack is overflow";
    }
    top++;
    arr[top] = n;
}

void popStack(){
    if(arr[top]==-1){
        cout << "stack is empty";
    }
    int n =arr[top];
    top--;
}
void printTop(){
    cout << arr[top] << endl;

}
void printStack()
{   
    if(arr[top]==-1){
        cout << "stack is empty";
    }
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    pushStack(5);
    pushStack(3);
    pushStack(2);
    pushStack(1);
    pushStack(6);

    popStack();
    printTop();
    printStack();
    return 0;
}