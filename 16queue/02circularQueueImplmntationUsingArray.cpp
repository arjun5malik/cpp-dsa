#include<iostream>
using namespace std;

class Queue{
    int* arr;

    int capacity;//size of array
    int currsize;//how many elements are stored in array

    int f;//front
    int r;//rear
public:
    Queue(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
        currsize=0;
        f=0;
        r=-1;
    } 
    
    void push(int data){//O(1)
        if(currsize==capacity){
            cout<<"Queue is Full\n";
            return;
        }
        
        r=(r+1)%capacity;
        arr[r]=data;
        currsize++;
    }

    void pop(){//O(1)
        if(empty()){
            cout<<"Queue is Empty\n";
            return ;
        }

        f=(f+1)%capacity;
        currsize--;
    }

    int front(){//O(1)
        if(empty()){
            cout<<"Queue is EMPYT\n";
            return -1;
        }

        return arr[f];
    }

    bool empty(){
        return currsize==0;
    }
    
    int printRear(){
        return arr[r];
    }
};

int main(){
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.push(5);
    cout<<q.front()<<endl;
    cout<<q.printRear()<<endl;

    return 0;
}