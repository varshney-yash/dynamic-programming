#include<bits/stdc++.h>
using namespace std;

int dp[5][52]; //IMPORTANT!!

int knapsack(int weights[],int profits[],int capacity,int size){
    //base condtition=>initialisation of the table
    for(int i=0;i<size;i++){
        for(int j=0;j<capacity;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    //recurisve steps to iteration
    for(int i=1;i<size+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(weights[i-1]<=j)
                dp[i][j]=max(profits[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[size][capacity];
}

int main(){
    int weights[]={10, 20, 30};
    int profits[]={60, 100, 120};
    int capacity=50;
    int n=sizeof(weights)/sizeof(int);
    // memset(dp,-1,sizeof(dp));
    cout<<knapsack(weights,profits,capacity,n);
    return 0;
}