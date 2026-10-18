#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

public:
  Node(int val){
    data=val;
    next=NULL;
  } 
  
  ~Node(){
    cout<<"~NODE "<<data<<endl;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
  }
};

class List{   
    Node* head;
    Node* tail;

public:
    List(){
        head=NULL;
        tail=NULL;
    }

    ~List(){
        cout<<"~LIST\n";
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }

    void push_back(int val){
        Node* newNode=new Node(val);//dynamic

        if(head==NULL){
           head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" --> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }

    
};

int main(){
    List ll;
    
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.print();
    
    return 0;
}