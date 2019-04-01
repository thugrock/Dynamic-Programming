#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int* inputFromUser(int size){
    int *arr,i;
    arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the Array Elements:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    return arr;
}
//Recursive Approach
int lis(int *arr,int size){
    int i,j,lis_here,max_lis=1;
    if(size==1){
        return 1;
    }
    for(i=1;i<size;i++){
        lis_here=lis(arr,i);
        if(arr[i-1]<arr[size-1] && lis_here+1>max_lis){
            max_lis=lis_here+1;
        }
    }
    return max_lis;
}
//Dynamic Programming Approach
int* lis_dp(int* arr,int size){
    int i,j,max_lis=1;
    int *lis;
    lis=(int *)malloc(sizeof(int)*size);
    lis[0]=1;
    for(i=1;i<size;i++){
        lis[i]=1;
        for(j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[j]+1>lis[i]){
                lis[i]=lis[j]+1;
            }
        }
    }
    return lis;
}
void print_Array(int* arr,int size){
    int i;
    for(i=size-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
}
void printLis(int *lis,int *arr,int size){
    int result = -1;
	int index = -1;
	int *path;
    
	int res ,path_index=1;

	for (int i = 0; i < size; i++) {
			if (result < lis[i]) {
				result = lis[i];
				index = i;
			}
	}
    res=result-1;
    path=(int *)malloc(sizeof(int)*result);
    path[0]=arr[index];
	for (int i = index-1; i >= 0; i--) {
		if(lis[i]==res){
			path[path_index++]=arr[i];
			res--;
		}			
	}
	printf("Actual Elements:\n ");
    print_Array(path,result);		
	
}
int getMax(int *arr,int size){
    int max_lis=1,i,j;
    for(i=0;i<size;i++){
        if(max_lis<arr[i])
            max_lis=arr[i];
    }
    return max_lis;
}
int main(){
    int size,max_lis_len;
    int *arr,*lis;

    printf("Enter the Size of Array\n");
    scanf("%d",&size);
    arr=inputFromUser(size);
    lis=lis_dp(arr,size);
    printf("The Length of Longest Increasing Sub-Sequence is: %d\n",getMax(lis,size));
    printLis(lis,arr,size);
    return 0;
}