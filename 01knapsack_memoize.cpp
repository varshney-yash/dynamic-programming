#include<bits/stdc++.h>
using namespace std;

static int dp[5][52]; 

int knapsack(int w[],int p[],int c,int n){
    if(n==0 || c==0)
        return 0;
    if(dp[n][c]!=-1)
        return dp[n][c];
    if(w[n-1]<=c)
        return dp[n][c]=max(p[n-1]+knapsack(w,p,c-w[n-1],n-1),knapsack(w,p,c,n-1));
    return dp[n][c]=knapsack(w,p,c,n-1); 
}

int main(){
    int weights[]={10, 20, 30};
    int profits[]={60, 100, 120};
    int capacity=50;
    int n=sizeof(weights)/sizeof(int);
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(weights,profits,capacity,n);
    return 0;
}