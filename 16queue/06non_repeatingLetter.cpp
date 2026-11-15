#include<iostream>
#include<queue>
using namespace std;

void print(int arr[]){
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<" ";
    }
}

void FirstNonRepeating(string str){
    queue<char> Q;
    int freq[26] = {0};

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        Q.push(ch);
        freq[ch-'a']++;
        print(freq);

        while(!Q.empty() && freq[Q.front()-'a']>1){
           Q.pop();
        }

        if(Q.empty()){
            cout<<"-1\n";
        }else{
            cout<<Q.front()<<endl;
        }
    }

}

int main(){
    string str="aabccxb";
    FirstNonRepeating(str);

    return 0;
}