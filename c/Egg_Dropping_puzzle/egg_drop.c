#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int min(int a,int b){
    if(a<b){
        return b;
    }
    return a;
}
int eggDropping_rec(int n,int k){
    int i,result,min=__INT32_MAX__;

    if(k==1||k==0||n==1)
        return k;

    for(i=1;i<=k;i++){
        result=max(eggDropping_rec(n-1,i-1),eggDropping_rec(n,k-i));
        if(result<min){
            min=result;
        }
    }
    return min+1;
}
int eggDropping_dp(int n,int k){

    int trails[n+1][k+1];
    int i,j,eggs,result,min=__INT32_MAX__;
    for(i=1;i<=n;i++){
        trails[i][0]=0;
        trails[i][1]=1;
    }
    for(i=1;i<=k;i++){
        trails[1][i]=i;
    }
    for(eggs=2;eggs<=n;eggs++){
        for(j=2;j<=k;j++){
            trails[eggs][j]=__INT32_MAX__;
            for(i=1;i<=j;i++){
                result=1+max(trails[eggs-1][i-1],trails[eggs][j-i]);
                if(result<trails[eggs][j]){
                    trails[eggs][j]=result;
                } 
            }
        }
    }
    return trails[n][k];
}
int main(){
    int n,k,trails;
    printf("Enter the number of Floors:\n");
    scanf("%d",&k);
    printf("Enter the number of Eggs\n");
    scanf("%d",&n);
    //For recursive approach
    //trails=eggDropping_rec(n,k);
    trails=eggDropping_dp(n,k);
    printf("The number of Min trails Required in Worst Case is %d\n",trails);
    return 0;
}