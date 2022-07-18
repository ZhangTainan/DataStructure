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

struct index { //�����Ľṹ
   int key;
   int start;
} newIndex[10];


void display(int arr[]) {
    printf("����:\n");
    for (int i = 0; i < 1000; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//ð������
void bubbleSort(int arr[])
{

    int i,j,temp;//��ʱ���� k��Ϊ�Ƚϴ����ؼ���
    for ( i = 0; i < 1000; i++)
    {
        for ( j = 0; j < 1000-i; j++)
        {
            if(arr[j]>arr[j+1])
            //���j����j+1 �����������н���
            {
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//˳�����
int SeqSearch(int arr[],int len, int key)//˳�����
{
    int k=0;
	//ÿ��ѭ������Ҫ�����ж�
	//���ж��ܴ���Ϊ2*len

	for(int i = 1; i < len; i++){
        
		if(arr[i] == key)
		{
			printf("�ؼ�����ϢΪ:%d", key);
            printf("���Ҵ���:%d\n",k);
            return 1;
		}
        k++;
    }
    printf("δ�ҵ�");
    return -1;
}


//���ֲ���
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

            printf("���ҵ�%d��",key);
	        printf("���Ҵ���:%d\n",k);

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

//�ֿ����
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
            
			printf("�ؼ�����ϢΪ:%d", key);
            printf("���Ҵ���Ϊ:%d\n", k);
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
            printf("���ҵ�%d����",key);
	        printf("���Ҵ���:%d\n",k);
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
//쳲���������
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


//쳲���������
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
            printf("���ҵ�%d����",key);
	        printf("���Ҵ���:%d\n",k);
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
    srand((int)time(NULL));//�趨��������� 


    for (int x = 0; x < 1000; x++)
    {
        arr[x]=  rand()%1000;//���� 0-999 ���������
    }

    
    bubbleSort(arr);

    display(arr);
    printf("������ؼ��֣�");
    scanf("%d",&key);
    // printf("������ؼ��֣�");
    // scanf("%d",&key);
    result = SeqSearch(arr,1000,key);

    result = BinarySearch(arr,1000,key);


    result = FibSearch(arr,1000,key);

    result = InsertSearch(arr,1000,key);

    
    // ��������зֿ�
    for (int i = 0; i < 10; i++)
    {
        newIndex[i].start = j;
        j+=100;
        newIndex[i].key = arr[j];
    }

    

    result = BlockSearch(arr,key);


    // printf("���%d��",result);
    return 0;
}

