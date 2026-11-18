#include<iostream>
#include<deque>
using namespace std;

class Queue{
    deque<int> deq;
public:
    void enqueue(int val){
        deq.push_back(val);
    }
    
    void dequeue(){
        if(empty()){
            cout<<"QUEUE IS EMPTY\n";
            return;
        }
        deq.pop_front();
    }

    int front(){
        return deq.front();
    }

    bool empty(){
        return deq.empty();
    }
};

int main(){
    Queue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    //1 2 3

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.dequeue();
    }//1 2 3

    return 0;
}