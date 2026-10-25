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
};

class List{   
    Node* head;
    Node* tail;

public:
    List(){
        head=NULL;
        tail=NULL;
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

    void insert(int val,int pos){
        Node* newNode=new Node(val);
        
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"POSITION IS INVALID\n";
                return;
            }
            temp=temp->next;
        }

        //temp at pos-1 i.e. prev or left node
        newNode->next=temp->next;
        temp->next=newNode;
    }
};

int main(){
    List ll;

    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.print();
    cout<<"\n";
    ll.insert(100,2);
    ll.print();
    
    return 0;
}