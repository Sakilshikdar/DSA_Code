 #include <bits/stdc++.h>
using namespace std;
 
 int queueo[5];

int front=-1;

int rear =-1;
void nqueue(int x){
    if (rear==sizeof(queueo)-1){
        cout << "queue in full";
    }
    if (front ==-1 && rear ==-1){
        front++;
        rear++;
        queueo[rear] = x;
    }
    else{ 
    rear++;
    queueo[rear] = x;
    }
}

void disqueue(){
    for (int i = 0; i < 5;i++){
        cout << queueo[i] << " ";
    }
}


int main(){
    int x;
    while (true)
    {
        cin >> x;
        if(x==-1)
            break;
        nqueue(x);
    }
    disqueue();

    return 0;
}