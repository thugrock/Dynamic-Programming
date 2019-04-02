#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

#define MAX 1024

int key=1;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int lcs_rec(char* arr1,int pos1,char *arr2,int pos2,int size1,int size2){
    if(pos1==size1 || pos2==size2){
        return 0;
    }
    if(arr1[pos1]==arr2[pos2]){
        return 1+lcs_rec(arr1,pos1+1,arr2,pos2+1,size1,size2);
    }
    return max(lcs_rec(arr1,pos1+1,arr2,pos2,size1,size2),lcs_rec(arr1,pos1,arr2,pos2+1,size1,size2));
}

int lcs_dp( char *arr1, char *arr2, int size1, int size2 ) 
{ 

    //Code to Fill lcs array
   int lcs[size1+1][size2+1]; 
   int i, j,res;
   char *path; 
   int path_index=0;
   for (i=0; i<=size1; i++) 
   { 
     for (j=0; j<=size2; j++) 
     { 
       if (i == 0 || j == 0) 
         lcs[i][j] = 0; 
   
       else if (arr1[i-1] == arr2[j-1]) 
         lcs[i][j] = lcs[i-1][j-1] + 1; 
   
       else
         lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]); 
     } 
   }
   //Code to Print the LCS part
    res=lcs[size1][size2];
    path=(char*)malloc(sizeof(char)*res);
    i=size1,j=size2;
    while(i>=0&&j>=0)
    {
            
                if(arr1[i-1]==arr2[j-1]){
                    path[path_index++]=arr2[j-1];
                    res--;
                    i--;j--;
                }else if(lcs[i][j-1]>lcs[i-1][j]){
                    j--;
                }else
                {
                    i--;
                }
                            
    }
    printf("The Longest Common Subsequence is:\n");
    for(i=path_index;i>=0;i--){
        printf("%c",path[i]);
    }
    printf("\n");
     
   return lcs[size1][size2]; 
} 
int main(){
    int lcs_ans;
    char *arr1,*arr2;
    arr1=(char *)malloc(sizeof(char)*MAX);
    arr2=(char *)malloc(sizeof(char)*MAX);
    printf("Enter the %d String:",key++);
    gets(arr1);
    printf("Enter the %d String:",key++);
    gets(arr2);
    //For recursive approach
    //lcs=lcs_rec(arr1,0,arr2,0,strlen(arr1),strlen(arr2));
    lcs_ans=lcs_dp(arr1,arr2,strlen(arr1),strlen(arr2));
    printf("The Length of Longest Common Sub-Sequence is: %d\n",lcs_ans);
    return 0;
}