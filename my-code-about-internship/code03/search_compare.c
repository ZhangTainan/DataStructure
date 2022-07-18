#include<stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#define MAX_SIZE 101
typedef int Status;
typedef struct array {
	int length;
	int arr[MAX_SIZE];
}Array;
typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

struct index { //定义块的结构
   int key;
   int start;
} newIndex[10];


void display(int arr[]) {
    printf("数据:\n");
    for (int i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//冒泡排序
void bubbleSort(int arr[])
{

    int i,j,temp;//临时变量 k作为比较次数关键字
    for ( i = 0; i < 1000; i++)
    {
        for ( j = 0; j < 1000-i; j++)
        {
            if(arr[j]>arr[j+1])
            //如果j大于j+1 则两个数进行交换
            {
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//顺序查找
int SeqSearch(int arr[],int len, int key)//顺序查找
{
    int k=0;
	//每次循环都需要两次判断
	//故判断总次数为2*len

	for(int i = 1; i < len; i++){
        
		if(arr[i] == key)
		{
			printf("关键字信息为:%d", key);
            printf("查找次数:%d\n",k);
            return 1;
		}
        k++;
    }
    printf("未找到");
    return -1;
}


//二分查找
int BinarySearch(int arr[],int n, int key)
{
    int low=0;
    int high = n-1;
    int mid,k=0;
    // display(arr);
    while (low<=high)
    {
        k++;
        mid = (low+high)/2;
        if (arr[mid] == key)
        {   

            printf("查找的%d数",key);
	        printf("查找次数:%d\n",k);

            return mid;
        }
        if (arr[mid]<key)
        {
 
            low = mid+1;
            k++;

        }
        if (arr[mid]>key)
        {
  
            high = mid-1;
            k++;
        }

    }
    return -1;
    
}

//分块查找
int BlockSearch(int arr[],int key)
{

    int i,start,k=0;
    while (i<10 && key>newIndex[i].key)
    {
        i++;
    }
    start = newIndex[i].start;

    for (int x = 0; x < 100; x++)
    {
        k++;
        if(arr[x+start] == key)
		{
            
			printf("关键字信息为:%d", key);
            printf("查找次数为:%d\n", k);
            return 1;
		}
    }
    return -1;

}

int InsertSearch(int arr[],int n, int key)
{ 
    int low=0; 
    int high = n-1;  
    int mid,k=0;
    while (low<=high)
    {
        k++;
        mid = low+(key-arr[low])*(high-low)/(arr[high]+arr[low]);
        if (arr[mid] == key)
        {            
            printf("查找的%d数的",key);
	        printf("查找次数:%d\n",k);
            return mid;
        }
        if (arr[mid]<key)
        {
            low = mid+1;
            k++;

        }
        if (arr[mid]>key)
        {
            high = mid-1;
            k++;
        }

    }

    return -1;
    
}
//斐波那契查找
int fib(int n)
{
	int f=0,f0=0,f1=1;
	if (n==0) 
		return 0; 
	if (n==1) 
		return 1; 
	while(f<n){
		f=f0+f1;
		f0=f1;
		f1=f;
	}
	return f0;
}


//斐波那契查找
int FibSearch(int arr[],int n, int key)
{
    int low=0;
    int high = n-1;
    int mid,k=0;
    while (low<=high)
    {
        k++;
        int f = fib(high-low);
        mid = low +f;
        if (arr[mid] == key)
        {   
            printf("查找的%d数的",key);
	        printf("查找次数:%d\n",k);
            return mid;
        }
        if (arr[mid]<key)
        {
            low = mid+1;
            k++;

        }
        if (arr[mid]>key)
        {
            high = mid-1;
            k++;
        }

    }

    return -1;
    
}

int main()
{

    int arr[1000];
    int key,result;
    int j=0;
    srand((int)time(NULL));//设定随机数种子 


    for (int x = 0; x < 1000; x++)
    {
        arr[x]=  rand()%1000;//产生 0-999 的随机数。
    }

    
    bubbleSort(arr);

    display(arr);
    printf("请输入关键字：");
    scanf("%d",&key);
    // printf("请输入关键字：");
    // scanf("%d",&key);
    result = SeqSearch(arr,1000,key);

    result = BinarySearch(arr,1000,key);


    result = FibSearch(arr,1000,key);

    result = InsertSearch(arr,1000,key);

    
    // 对数组进行分块
    for (int i = 0; i < 10; i++)
    {
        newIndex[i].start = j;
        j+=100;
        newIndex[i].key = arr[j];
    }

    

    result = BlockSearch(arr,key);


    // printf("结果%d：",result);
    return 0;
}

