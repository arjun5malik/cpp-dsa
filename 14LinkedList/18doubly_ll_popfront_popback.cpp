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

class DoublyList{
public:   
    Node* head;
    Node* tail;

public:
    DoublyList(){
        head=NULL;
        tail=NULL;
    }

    void pop_back(){
        Node* temp=head;
        
        while(temp->next->next!=NULL){
            temp=temp->next;
        }

        temp->next=NULL;
        tail->prev=NULL;
        tail=temp;
        
    }

    void pop_front(){
        Node* temp=head;
        head=head->next;
        
        if(head!=NULL) head->prev=NULL;
        
        temp->next=NULL;
        delete temp;
        
    }

    void printlist(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }

        cout<<"NULL\n";
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

};

int main(){
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printlist();//1<=>2<=>3<=>4<=>NULL

    cout<<"\n";

    dbll.pop_front();
    dbll.printlist(); 

    cout<<"\n";

    dbll.pop_back();
    dbll.printlist();

    return 0;
}