#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 20000
typedef struct SORTTYPE
{
    char name[30]; //排序名称
    int num_compare;       //比较的次数
    int num_move;       //移动的次数
} ST;        //存储分析效率的数据
int num_compare = 0, num_move = 0; //关键字比较和移动的次数
ST st[5];                 //五种算法的分析数据
//直接插入排序算法
void InsertSort(int a[], int n);
//折半插入排序法
void BinInsertSort(int a[], int n);
//希尔排序算法
void ShellSort(int a[], int n);
//冒泡排序算法
void BubbleSort(int a[], int n);
/*快速排序算法*/
int partition(int a[], int s, int t); //一趟划分
//对a[s..t]的元素进行快速排序
void QuickSort(int a[], int s, int t);
//菜单
void menu();
//调用直接插入排序的实现函数，即菜单1
void op1(int a[]);
void op2(int a[]);
void op3(int a[]);
void op4(int a[]);
void op5(int a[]);
void op6(int a[]);
//打印数组数据
void printArray(int a[]);
//给数组生成随机数
void GetaandArray(int a[]);
//五种常见的算法
///
//直接插入排序算法
void InsertSort(int a[], int n)
{
    int i, j;
    int tmp;
    for (i = 1; i < n; i++) //for循环内一定比较了n-1次，if判断语句
    {
        if (a[i] < a[i - 1]) //一旦出现了逆序的关键字，就进行插入
        {
            tmp = a[i];
            j = i - 1;
            num_compare++;
            do //往后移动一个位置，腾空间给tmp；
            {
                a[j + 1] = a[j];
                num_move++; //移动加一
                j--;
                num_compare++; //比较次数加一
            }
            while (j >= 0 && a[j] > tmp);

            a[j + 1] = tmp; //最后把tmp放在对应的位置
            num_move += 2;  //移动的temp
        }
    }
}

//折半插入排序法
//把无序区插入到有序区里，由于前面的插入排序法实现了有序，所以直接在
//有序区利用折半查找来寻找的改进算法
void BinInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    int tmp;
    for (i = 1; i < n; i++) //已经比较了n-1次
    {
        if (a[i] < a[i - 1])
        {
            tmp = a[i];
            low = 0;
            high = i - 1;
            num_compare++;
            while (low <= high)
            {
                num_compare++; //while进入比较
                mid = (low + high) / 2;
                if (tmp < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
            {
                a[j + 1] = a[j];
                num_move++; //移动次数加一
            }
            a[high + 1] = tmp;
            num_move += 2; //tmp交换
        }
    }
}
///
//希尔排序算法
void ShellSort(int a[], int n)
{
    int i, j, d;
    int tmp;
    d = n / 2;

    while (d > 0)
    {
        for (i = d; i < n; i++)
        {
            tmp = a[i];
            j = i - d;

            while (j >= 0 && tmp < a[j])
            {
                num_compare++;
                num_move++;
                a[j + d] = a[j];
                j = j - d;
            }
            a[j + d] = tmp;
            num_move += 2; //tmp进行两次操作
        }
        d = d / 2;
    }
}
///
//冒泡排序算法
void BubbleSort(int a[], int n)
{
    int i, j;
    int tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
            {
                num_compare++;
                num_move += 3;
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
    }
}

/*快速排序算法*/
int partition(int a[], int s, int t) //一趟划分
{
    int i = s, j = t;
    int tmp = a[i]; //以a[i]为基准
    while (i < j)   //从两端交替向中间扫描,直至i=j为止
    {
        while (j > i && a[j] >= tmp)
        {
            j--;           //从右向左扫描,找一个小于tmp的a[j]
            num_compare++; //进行比较
        }
        a[i] = a[j]; //找到这样的a[j],放入a[i]处
        num_move++;  //移动+1
        while (i < j && a[i] <= tmp)
        {
            i++;           //从左向右扫描,找一个大于tmp的a[i]
            num_compare++; //比较加一
        }
        a[j] = a[i]; //找到这样的a[i],放入a[j]处
        num_move++;  //移动加一
    }
    a[i] = tmp;
    num_move += 2; //temp的交换
    return i;
}

void QuickSort(int a[], int s, int t)
//对a[s..t]的元素进行快速排序
{
    int i;
    if (s < t) //区间内至少存在两个元素的情况
    {
        i = partition(a, s, t);
        QuickSort(a, s, i - 1); //对左区间递归排序
        QuickSort(a, i + 1, t); //对右区间递归排序
    }
}


void menu()
{
    printf("***************************************************\n");
    printf("\t\t1.直接插入排序法\n");
    printf("\t\t2.折半插入排序法\n");
    printf("\t\t3.希尔排序法\n");
    printf("\t\t4.冒泡排序法\n");
    printf("\t\t5.快速排序法\n");
    printf("\t\t6.效率比较\n");
    printf("\t\t7.退出\n");
    printf("***************************************************\n");
    printf("请选择操作：");
}
void printArray(int a[]) //打印数组数据
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%2d%c", a[i], (i+1)%40 ? ' ' : '\n');
    putchar(10);
}

//调用直接插入排序的实现函数，即菜单1
void op1(int a[])
{
    GetaandArray(a);
    printf("伪随机数已经生成的20000个新的随机数\n");
    //打印排序前的数组
    // printArray(a);
    InsertSort(a, MAX);
    // printf("\n利用直接插入排序后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n直接插入排序法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[0].num_compare = num_compare;
    st[0].num_move = num_move;
    strcpy(st[0].name, "直接插入排序");
}
void op2(int a[])
{
    GetaandArray(a);
    printf("已经生成20000个新的随机数\n");
    //打印排序前的数组
    //  printArray(a);
    num_compare = 0;
    num_move = 0;
    BinInsertSort(a, MAX);
    //  printf("\n利用折半插入排序后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n折半插入排序：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[1].num_compare = num_compare;
    st[1].num_move = num_move;
    strcpy(st[1].name, "折半插入排序");
}

void GetaandArray(int a[]) //为数组获得随机数
{
    int i;
    for (i = 0; i < MAX; i++)
        a[i] = rand() % 100;
}
void op3(int a[])
{
    GetaandArray(a);
    printf("已经生成20000个新的随机数\n");
    //打印排序前的数组
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    ShellSort(a, MAX);
    //printf("\n利用希尔排序算法后的数列如下：\n");
    //打印排序后的数组
    //printArray(a);


    printf("\n\n希尔排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[2].num_compare = num_compare;
    st[2].num_move = num_move;
    strcpy(st[2].name, "希尔排序算法");
}
void op4(int a[])
{
    GetaandArray(a);
    printf("已经生成20000个新的随机数\n");

    //打印排序前的数组
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    BubbleSort(a, MAX);

    //  printf("\n利用冒泡排序法后的数列如下：\n");
    //打印排序后的数组

    //  printArray(a);

    printf("\n\n冒泡排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[3].num_compare = num_compare;
    st[3].num_move = num_move;
    strcpy(st[3].name, "冒泡排序算法");
}
void op5(int a[])
{
    GetaandArray(a);
    printf("已经生成20000个新的随机数\n");

    //打印排序前的数组
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    QuickSort(a, 0, MAX);
    //  printf("\n利用快速排序算法后的数列如下：\n");
    //打印排序后的数组
    // printArray(a);
    printf("\n\n快速排序算法：\n一共比较了%d次，移动了%d次\n", num_compare, num_move);
    st[4].num_compare = num_compare;
    st[4].num_move = num_move;
    strcpy(st[4].name, "快速排序算法");
}
void op6(int a[])
{
    int i;
    printf("各种排序算法的比较于移动次数的对比：\n\n");
    printf("   名称          比较次数          移动次数\n");

    for (i = 0; i < 5; i++)
    {
        printf("%-18s%-18d %d\n", st[i].name, st[i].num_compare, st[i].num_move);
    }
}
int main()
{
    int a[MAX]; //列表数组
    int op;
    srand((unsigned)time(NULL)); //随机种子
    do
    {
        system("cls");
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            op1(a);
            break;
        case 2:
            op2(a);
            break;
        case 3:
            op3(a);
            break;
        case 4:
            op4(a);
            break;
        case 5:
            op5(a);
            break;
        case 6:
            op6(a);
            break;
        default:
            break;
        }
        system("pause");

    }while(op!=7);
    return 0;
}

