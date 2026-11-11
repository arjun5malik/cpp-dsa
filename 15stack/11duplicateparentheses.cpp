#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool duplicateParentheses(string str){// TC:O(N) & SC:O(N)
    stack<char> ans;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch!=')'){
            ans.push(ch);
        }else{
            if(ans.top()=='('){
                return true;
            }
            while(ans.top()!='('){
                ans.pop();
            }
            ans.pop();
        }
    }
    return false;
}

int main(){
    string str1="((a+b))";
    string str2="((a+b)+(c+d))";

    cout<<duplicateParentheses(str1)<<endl;// 1=true
    cout<<duplicateParentheses(str2)<<endl;// 0=false

    return 0;
}