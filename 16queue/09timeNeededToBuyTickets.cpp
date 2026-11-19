#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n=tickets.size();
    queue<int> q;

    for(int i=0;i<n;i++){
        q.push(i);
    }
    
    int sec=0;
    while(tickets[k]>0){
        if(tickets[q.front()]>0){
            tickets[q.front()]--;
            sec++;
            int temp=q.front();
            q.pop();
            q.push(temp);
        }else{
            q.pop();
        }
    }
    return sec;
}

int main(){
    vector<int> tickets={2,3,2};
    int k=2;
    cout<<timeRequiredToBuy(tickets,k)<<endl;

    return 0;
}
