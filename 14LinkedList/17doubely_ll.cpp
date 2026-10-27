#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;
    Node* prev;

public:
  Node(int val){
    data=val;
    prev=next=NULL;
  }    
};

class DoubelyList{
public:   
    Node* head;
    Node* tail;

public:
    DoubelyList(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void push_back(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void printist(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }

        cout<<"NULL\n";
    }
};

int main(){
    DoubelyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printist();//1<=>2<=>3<=>4<=>NULL

    cout<<"\n";

    dbll.push_back(4);
    dbll.push_back(3);
    dbll.push_back(2);
    dbll.push_back(1);
    dbll.printist();//4<=>3<=>2<=>1<=>NULL

    return 0;
}