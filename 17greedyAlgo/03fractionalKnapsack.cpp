#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first>p2.first; //descending based on ratio
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w){// TC:O(nlogn), SC:O(n)
    int n=val.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0)); //pair(ratio,index) -> (double,int)

    for(int i=0;i<n;i++){
        double r=val[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compare); //O(nlogn)
    int ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;//wt,val
        if(wt[idx]<=w){
           ans+=val[idx];
           w-=wt[idx];
        }else{
            ans+=w*ratio[idx].first;
            w=0;
            break;
        }
    }

    cout<<"Max Value = "<< ans <<endl;
    return ans;
}

int main(){
    vector<int> value={60,100,120};
    vector<int> wt={10,20,30};
    int w=50;

    fractionalKnapsack(value,wt,w);

    return 0; 
}