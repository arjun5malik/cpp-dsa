#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums,int st,int end){
    int idx=st-1;/*TO PLACE ELEMENTS AT CORRECT PLACE 
    THAT ARE LESS THAN PIVOT*/
    int pivot=nums[end];
    for(int j=st;j<end;j++){
        if(nums[j]<=pivot){
            idx++;
            swap(nums[j],nums[idx]);
        }
    }

    //TO PLACE THE PIVOT ELEMENT AT THE CORRECT PLACE
    idx++;
    swap(nums[end],nums[idx]);
    return idx;
}

void quicksort(vector<int>& nums,int st,int end){
    if(st<end){
        int pivIdx=partition(nums,st,end);

        //LEFT
        quicksort(nums,st,pivIdx-1);

        //RIGHT
        quicksort(nums,pivIdx+1,end);
    }
}

int main(){
    vector<int> nums={5,2,6,4,1,3};

    quicksort(nums,0,nums.size()-1);

    for(int k=0;k<nums.size();k++){
        cout<<nums[k]<<" ";
    }

    return 0;
}