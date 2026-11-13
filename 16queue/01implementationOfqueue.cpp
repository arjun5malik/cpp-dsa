#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{  
    Node* head;
    Node* tail;

public:
    Queue(){
        head=tail=NULL;
    }
    
    
    void push(int val){//push_back
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void pop(){//pop_front
        if(head==NULL){
            cout<<"QUEUE IS EMPTY";
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    int front(){//print
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }

};

int main(){
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}