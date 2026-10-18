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
public:
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

     int searchItr(int key){
        Node* temp=head;
        int idx=-0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
        }
        return -1;
     }

     void print(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
     }
};

int main(){
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.print();//1->2->3->NULL
    cout<<'\n';
    cout<<ll.searchItr(5)<<"\n";

    return 0;
}