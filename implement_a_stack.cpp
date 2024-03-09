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
class Queue{
        private:
    int size{};
    int front{};
    int rear{};
    int *arr{};
    int added_elements{};
    public:
   Queue(int size):size(size),front(-1),rear(-1){arr=new int[size];}
bool empty(){
    if(front==-1&&rear==-1)return true;
    else return false;
}
bool full(){
    if(front==0&&rear==size-1)return true;
    else if(front==rear+1)return true;
    else return false;
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
int peek(){
    if(empty())return -1;
    return arr[front];
}
};
class Stack{
    private : Queue q;int added_elements;
     public:
    Stack(int size):q(size){};
    bool empty(){
return added_elements==0;
    }
    void push(int value){
    q.enque_front(value);
    added_elements++;
    }
    void pop(){
       q.deque_front();
    added_elements--;
    }
   int peek(){
       if(!empty()) return q.peek();
      
    }
};
int main(){
Stack st(3);
st.push(10);
st.push(20);
st.push(30);
while(!st.empty()){
    cout<<st.peek()<<" ";
    st.pop();
}
}