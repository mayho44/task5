#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
#include<bits/stdc++.h>
#include <string>
using namespace std;
#define endl '\n'
//#define haha cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
class Deque{
    private:
    int size{};
    int front{};
    int rear{};
    int *arr{};
    int added_elements{};
    public:
    Deque(int size):size(size),front(-1),rear(-1){arr=new int[size];}
bool empty(){
    if(front==-1&&rear==-1)return true;
    else return false;
}
bool full(){
    if(front==0&&rear==size-1)return true;
    else if(front==rear+1)return true;
    else return false;
}
void enque_rear(int value){
    if(full())cout<< "can't perform the operation"<<endl;
    else 
    {
     if(rear+1==size)rear=0,arr[rear]=value;
    else
        arr[++rear]=value; 
    }
}
void enque_front(int value){
    if(full())cout<< "can't perform the operation"<<endl;
    else{
        if(front==-1)arr[++front]=value,rear++;
         else if( front==0)front=size-1,arr[front]=value;
else  if(front<=rear)arr[++front]=value;
else arr[--front]=value;
    }
}
int deque_front(){
if(empty())cout<<"can't perform the operation"<<endl;
else{
 if(front==size-1){
    front=0;
    return arr[size-1];
 }
else if(front==rear){int val=arr[front],front=rear=-1;return val;}
else return arr[front++];
}
}
int deque_rear(){
    if(empty())cout<<"can't perform the operation"<<endl;
    else{
        if(rear==0){rear=size-1;return arr[0];}
        else if(front==rear){
            int val=arr[rear];
            rear=front=-1;
            return val;
        }
        else return arr[rear--];
    }
}
int peek(){
    if(empty())return -1;
    return arr[front];
}
void display() {
    if (empty()||front==-1) {
        cout << "Deque is empty" << endl;
    } else {
        if (rear >= front) {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
    }
    cout << endl;
}
int next(int pos){
    if(pos==size-1)return arr[0];
    return arr[++pos];
}
};
int main(){
Deque q(6);
q.enque_front(3);
q.enque_front(2);
q.enque_rear(4);
q.enque_front(1);
q.display();
cout<<q.deque_rear()<<endl;
q.display();
cout<<q.deque_front()<<endl;
q.display();
cout<<q.deque_rear()<<endl;
cout<<q.deque_front()<<endl;
q.display();
// q.enque_rear(7);
// q.display();

}