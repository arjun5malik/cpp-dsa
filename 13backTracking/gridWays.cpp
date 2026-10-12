#include<iostream>
using namespace std;

int gridWays(int row,int col,int n,int m){
   if(row==n-1 && col==m-1) return 1;//REACH THE DESTINATION

   if(row>=n || col>=m) return 0;//OUT OF BOUNDS

   int Right=gridWays(row,col+1,n,m);
   int Down=gridWays(row+1,col,n,m);

   return Right+Down;
}

int main(){
    int n=3;
    int m=3;
    
    // int w=gridWays(0,0,n,m);
    cout<<"NUMBER OF WAYS TO EXIT ARE "<<gridWays(0,0,n,m)<<endl;

    return 0;
}