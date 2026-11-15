#include<iostream>
#include<queue>
using namespace std;

class Stack{//FIFO
   queue<int> q1;
   queue<int> q2;
public: 
   
    void push(int data){//O(n)
        //q1 --> q2
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(data);

        //q2 --> q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop(){//O(1)
        q1.pop();
    }

    int top(){//O(1)
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    return 0;
}