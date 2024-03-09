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
 class Stack{
    private:
    int size{};
    int top{};
    int *array{};
    public :
    Stack(int size):
        size(size),top(-1){
            array=new int [size];
    }
    int isfull(){
        return top==size-1;
    }
    bool isempty(){
    return top==-1;
    }
    void display(){
        for(int i=top;i>=0;i--)cout<<array[i]<<" ";
        cout<<endl;
    }
    void push(int ele){
        if(top==size-1)return;
       array[++top]=ele;   
    }
    int pop(){
        if(top==-1);
       else return array[top--];
    }
    int peek(){
        if(top==-1);
       else  return array[top];
    }
};
class Queue{
    private :
     int size{};
    int front{};
    int rear{};
    int *arr{};
    int added_elements{};
    Stack st,st2;
    public:
     Queue(int size):size(size),front(-1),rear(-1),st(size),st2(size){arr=new int[size];}
    bool empty(){
     return added_elements==0;
}
bool full(){
    return added_elements==size-1;
}
    void enque(int value){
if(full())return;
st.push(value);
added_elements++;
    }
    int deque(){
        if(empty())return -1;
        int num=--added_elements;
        while(num--){
            st2.push(st.pop());
        }
        int val =st.peek();
Stack s3(size);
int t=added_elements;
while(t--){
    s3.push(st2.pop());
}
swap(st2,s3);
        return val;

       
    }
};
int main(){
    Queue q(6);
for(int i=1;i<=3;i++)q.enque(i);
cout<<q.deque();
}