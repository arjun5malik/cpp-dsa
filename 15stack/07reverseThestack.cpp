#include<iostream>
#include<stack>
#include<string>
using namespace std;

void pushAtBottom(stack<int>& s,int val){
    if(s.empty()){
        s.push(val);//push at he top = push at the bottom
        return;
    }

    int temp=s.top();
    s.pop();
    pushAtBottom(s,val);

    s.push(temp);

}

void reverseStack(stack<int>& s){// TC:O(N) & SC:O(1)
    if(s.empty()){
        return;
    }
   
    int temp=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,temp);      
}

void print(stack<int>& s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    stack<int> s;

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    reverseStack(s);
    print(s);

    return 0;
}
