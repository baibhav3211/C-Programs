#include<stdio.h>
#include<stdlib.h>

void print(int arr[] ,int a){
    int i;
     for(i=0;i<a;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int search(int arr[],int value , int a){
int i,j=0;
for(i=0;i<a;i++){
    if(arr[i] == value){
    j=1;
    break;
    }
}
if(j == 1){
    return i+1;
}
else{
    return 0;
}
}

int binarysearch(int arr[] , int val , int l , int r){
    if(l<=r){
    int mid = r+l/2;
    if(arr[mid] == val){
        return mid+1;
    }
    else if(arr[mid]<val){
        binarysearch(arr,val,mid+1,r);
    }
    else{
        binarysearch(arr,val,l,mid-1);
    }
    }
    else{
    return -1;
    }
}

int main(){
    int a,arr[20];
    printf("enter size of array : ");
    scanf("%d",&a);
    int i,j;
    printf("enter elements in sorted manner :");
    for(i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }

    printf("array is :");
    print(arr,a);
    printf("Enter your choice : \n");
    while(1){
        int choice,value,p;
        printf("1. Liner search : ");
        printf("\n2. Binary search : ");
        printf("\n3. exit : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter value to search: ");
                    scanf("%d",&value);
                    p=search(arr,value,a);
                    if(p!=0){
                        printf("%d fount at position %d \n",value,p);
                    }
                    else{
                        printf("%d is not present in the array\n",value);
                    }
                    break;
            case 2: printf("Enter value to search: ");
                    scanf("%d",&value);
                    p = binarysearch(arr,value,0,a);
                    if(p!=-1){
                        printf("%d fount at position %d \n",value,p);
                    }
                    else{
                        printf("%d is not present in the array\n",value);
                    }
                    break;
            case 3: exit(0);
            default:printf("Enter a valid input :");
        }
    }

    return 0;
}