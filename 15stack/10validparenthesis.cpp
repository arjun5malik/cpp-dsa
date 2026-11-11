#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool validParenthesis(string str){
    stack<char> ans;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            ans.push(str[i]);
        }
        else{
            if(ans.empty()){
                return false;
            }
            
            int top=ans.top();
            if(top=='(' && str[i]==')' ||
               top=='{' && str[i]=='}' ||
               top=='[' && str[i]==']'){
                ans.pop();
            }else{
                return false;
            }
        }
    }
    return ans.empty();
}

int main(){
    string str1="([}])";// 0=false
    string str2="([{}])";// 1=true

    cout<<validParenthesis(str2)<<endl;

    return 0;
}