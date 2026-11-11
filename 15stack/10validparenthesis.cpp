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
            if(str[i]==')'){
                if(ans.empty() || ans.top()!='('){
                    return false;
                }
                ans.pop();
            }else if(str[i]=='}'){
                if(ans.empty() || ans.top()!='{'){
                    return false;
                }
                ans.pop();
            }else if(str[i]==']'){
                if(ans.empty() || ans.top()!='['){
                    return false;
                }
                ans.pop();
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