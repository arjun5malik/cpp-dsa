#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int> deq;
public:
    void push(int val){
        // deq.push_back(val);
        deq.push_front(val);
    }
    
    void pop(){
        if(empty()){
            cout<<"STACK IS EMPTY\n";
            return;
        }
        // deq.pop_back();
        deq.pop_front();
    }

    int top(){
        // return deq.back();
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }
};

int main(){
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    //1 2 3

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }//3 2 1

    return 0;
}