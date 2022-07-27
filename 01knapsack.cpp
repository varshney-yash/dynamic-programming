#include<iostream>
using namespace std;

int knapsack(int w[],int p[],int c,int n){
    if(n==0 || c==0)
        return 0;
    if(w[n-1]<=c)
        return max(p[n-1]+knapsack(w,p,c-w[n-1],n-1),knapsack(w,p,c,n-1));
    return knapsack(w,p,c,n-1);
}

int main(){
    int weights[]={10, 20, 30};
    int profits[]={60, 100, 120};
    int capacity=50;
    int n=sizeof(weights)/sizeof(int);
    cout<<knapsack(weights,profits,capacity,n);
    return 0;
}