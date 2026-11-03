#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int> vec;
public:
    void push(int val){// TC=O(1)
        vec.push_back(val);
    }

    void pop(){// TC=O(1)
        if(isEmpty()){
            cout<<"stack is empty";
            return;
        }
        vec.pop_back();
    }

    int top(){// TC=O(1)
        if(isEmpty()){
            cout<<"stack is empty";
            return -1;
        }
        int lastidx=vec.size()-1;
        return vec[lastidx];
    }

    bool isEmpty(){// TC=O(1)
        return vec.size()==0;
    }

};

int main(){
    Stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}