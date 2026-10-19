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
        Node* newNode=new Node(val);

        if(tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }

    int helper(Node* head,int key){// head-->is the local variable for this function
        if(head==NULL){
        return -1;
        }
        if(head->data==key){
        return 0;
        }

        int idx=helper(head->next,key);
        if(idx== -1){
            return -1;
        }
        return idx+1;
    }

    int searchRec(int key){
      return helper(head,key);
    }
};

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.print();
    cout<<'\n';
    cout<<ll.searchRec(5)<<"\n";

    return 0;
}