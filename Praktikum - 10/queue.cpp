//
// Created by Defanda on 26/06/2024.
//
#include <iostream>
using namespace std;

int queue[100], n = 100, front = - 1, rear = - 1;
void EnQueue() {
    int val;
    if (rear == n - 1)
        cout<<"Queue Overflow"<<endl;
    else {
        if (front == - 1)
            front = 0;
        cout<<"Insert the element in queue : ";
        cin>>val;
        rear++;
        queue[rear] = val;cout<<" Berhasil ditambahkan.\n" << endl;
    }
}
void DeQueue() {
    if (front == - 1 || front > rear) {
        cout<<"Queue Underflow ";
        return ;
    } else {
        cout<<"Element deleted from queue is : "<< queue[front] <<endl;
        front++;cout<<"Elemen pertama masuk Berhasil dihapus.\n" << endl;
    }
}
void DisplayQueue() {
    if (front == - 1)
        cout<<"Queue is empty"<<endl;
    else {
        cout<<"Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout<<queue[i]<<" ";
        cout<<"\n"<<endl;
    }
}
int main() {
    int ch;
    cout<<"1) Entry element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Exit"<<endl;
    do {
        cout<<"Enter your choice : ";cin>>ch;
        switch (ch) {
            case 1: EnQueue();
                break;
            case 2: DeQueue();
                break;
            case 3: DisplayQueue();
                break;
            case 4: cout<<"Exit"<<endl;
                break;
            default: cout<<"Invalid choice"<<endl;
        }
    } while(ch!=4);
    return 0;
}
