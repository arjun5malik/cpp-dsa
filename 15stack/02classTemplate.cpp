#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class Stack{
    vector<T> vec;
public:
    void push(T val){// TC=O(1)
        vec.push_back(val);
    }

    void pop(){// TC=O(1)
        if(isEmpty()){
            cout<<"stack is empty";
            return;
        }
        vec.pop_back();
    }

    T top(){// TC=O(1)
        // if(isEmpty()){
        //     cout<<"stack is empty";
        //     return -1;
        // }
        int lastidx=vec.size()-1;
        return vec[lastidx];
    }

    bool isEmpty(){// TC=O(1)
        return vec.size()==0;
    }

};

int main(){
    Stack<string> s;

    s.push("arjun");
    s.push("abhay");
    s.push("harsh");
    s.push("rudra");

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}