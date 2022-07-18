#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 20000
typedef struct SORTTYPE
{
    char name[30]; //��������
    int num_compare;       //�ȽϵĴ���
    int num_move;       //�ƶ��Ĵ���
} ST;        //�洢����Ч�ʵ�����
int num_compare = 0, num_move = 0; //�ؼ��ֱȽϺ��ƶ��Ĵ���
ST st[5];                 //�����㷨�ķ�������
//ֱ�Ӳ��������㷨
void InsertSort(int a[], int n);
//�۰��������
void BinInsertSort(int a[], int n);
//ϣ�������㷨
void ShellSort(int a[], int n);
//ð�������㷨
void BubbleSort(int a[], int n);
/*���������㷨*/
int partition(int a[], int s, int t); //һ�˻���
//��a[s..t]��Ԫ�ؽ��п�������
void QuickSort(int a[], int s, int t);
//�˵�
void menu();
//����ֱ�Ӳ��������ʵ�ֺ��������˵�1
void op1(int a[]);
void op2(int a[]);
void op3(int a[]);
void op4(int a[]);
void op5(int a[]);
void op6(int a[]);
//��ӡ��������
void printArray(int a[]);
//���������������
void GetaandArray(int a[]);
//���ֳ������㷨
///
//ֱ�Ӳ��������㷨
void InsertSort(int a[], int n)
{
    int i, j;
    int tmp;
    for (i = 1; i < n; i++) //forѭ����һ���Ƚ���n-1�Σ�if�ж����
    {
        if (a[i] < a[i - 1]) //һ������������Ĺؼ��֣��ͽ��в���
        {
            tmp = a[i];
            j = i - 1;
            num_compare++;
            do //�����ƶ�һ��λ�ã��ڿռ��tmp��
            {
                a[j + 1] = a[j];
                num_move++; //�ƶ���һ
                j--;
                num_compare++; //�Ƚϴ�����һ
            }
            while (j >= 0 && a[j] > tmp);

            a[j + 1] = tmp; //����tmp���ڶ�Ӧ��λ��
            num_move += 2;  //�ƶ���temp
        }
    }
}

//�۰��������
//�����������뵽�����������ǰ��Ĳ�������ʵ������������ֱ����
//�����������۰������Ѱ�ҵĸĽ��㷨
void BinInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    int tmp;
    for (i = 1; i < n; i++) //�Ѿ��Ƚ���n-1��
    {
        if (a[i] < a[i - 1])
        {
            tmp = a[i];
            low = 0;
            high = i - 1;
            num_compare++;
            while (low <= high)
            {
                num_compare++; //while����Ƚ�
                mid = (low + high) / 2;
                if (tmp < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (j = i - 1; j >= high + 1; j--)
            {
                a[j + 1] = a[j];
                num_move++; //�ƶ�������һ
            }
            a[high + 1] = tmp;
            num_move += 2; //tmp����
        }
    }
}
///
//ϣ�������㷨
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
            num_move += 2; //tmp�������β���
        }
        d = d / 2;
    }
}
///
//ð�������㷨
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

/*���������㷨*/
int partition(int a[], int s, int t) //һ�˻���
{
    int i = s, j = t;
    int tmp = a[i]; //��a[i]Ϊ��׼
    while (i < j)   //�����˽������м�ɨ��,ֱ��i=jΪֹ
    {
        while (j > i && a[j] >= tmp)
        {
            j--;           //��������ɨ��,��һ��С��tmp��a[j]
            num_compare++; //���бȽ�
        }
        a[i] = a[j]; //�ҵ�������a[j],����a[i]��
        num_move++;  //�ƶ�+1
        while (i < j && a[i] <= tmp)
        {
            i++;           //��������ɨ��,��һ������tmp��a[i]
            num_compare++; //�Ƚϼ�һ
        }
        a[j] = a[i]; //�ҵ�������a[i],����a[j]��
        num_move++;  //�ƶ���һ
    }
    a[i] = tmp;
    num_move += 2; //temp�Ľ���
    return i;
}

void QuickSort(int a[], int s, int t)
//��a[s..t]��Ԫ�ؽ��п�������
{
    int i;
    if (s < t) //���������ٴ�������Ԫ�ص����
    {
        i = partition(a, s, t);
        QuickSort(a, s, i - 1); //��������ݹ�����
        QuickSort(a, i + 1, t); //��������ݹ�����
    }
}


void menu()
{
    printf("***************************************************\n");
    printf("\t\t1.ֱ�Ӳ�������\n");
    printf("\t\t2.�۰��������\n");
    printf("\t\t3.ϣ������\n");
    printf("\t\t4.ð������\n");
    printf("\t\t5.��������\n");
    printf("\t\t6.Ч�ʱȽ�\n");
    printf("\t\t7.�˳�\n");
    printf("***************************************************\n");
    printf("��ѡ�������");
}
void printArray(int a[]) //��ӡ��������
{
    int i;
    for (i = 0; i < MAX; i++)
        printf("%2d%c", a[i], (i+1)%40 ? ' ' : '\n');
    putchar(10);
}

//����ֱ�Ӳ��������ʵ�ֺ��������˵�1
void op1(int a[])
{
    GetaandArray(a);
    printf("α������Ѿ����ɵ�20000���µ������\n");
    //��ӡ����ǰ������
    // printArray(a);
    InsertSort(a, MAX);
    // printf("\n����ֱ�Ӳ����������������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\nֱ�Ӳ������򷨣�\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[0].num_compare = num_compare;
    st[0].num_move = num_move;
    strcpy(st[0].name, "ֱ�Ӳ�������");
}
void op2(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����20000���µ������\n");
    //��ӡ����ǰ������
    //  printArray(a);
    num_compare = 0;
    num_move = 0;
    BinInsertSort(a, MAX);
    //  printf("\n�����۰�����������������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\n�۰��������\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[1].num_compare = num_compare;
    st[1].num_move = num_move;
    strcpy(st[1].name, "�۰��������");
}

void GetaandArray(int a[]) //Ϊ�����������
{
    int i;
    for (i = 0; i < MAX; i++)
        a[i] = rand() % 100;
}
void op3(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����20000���µ������\n");
    //��ӡ����ǰ������
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    ShellSort(a, MAX);
    //printf("\n����ϣ�������㷨����������£�\n");
    //��ӡ����������
    //printArray(a);


    printf("\n\nϣ�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[2].num_compare = num_compare;
    st[2].num_move = num_move;
    strcpy(st[2].name, "ϣ�������㷨");
}
void op4(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����20000���µ������\n");

    //��ӡ����ǰ������
    // printArray(a);

    num_compare = 0;
    num_move = 0;
    BubbleSort(a, MAX);

    //  printf("\n����ð�����򷨺���������£�\n");
    //��ӡ����������

    //  printArray(a);

    printf("\n\nð�������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[3].num_compare = num_compare;
    st[3].num_move = num_move;
    strcpy(st[3].name, "ð�������㷨");
}
void op5(int a[])
{
    GetaandArray(a);
    printf("�Ѿ�����20000���µ������\n");

    //��ӡ����ǰ������
    //printArray(a);
    num_compare = 0;
    num_move = 0;
    QuickSort(a, 0, MAX);
    //  printf("\n���ÿ��������㷨����������£�\n");
    //��ӡ����������
    // printArray(a);
    printf("\n\n���������㷨��\nһ���Ƚ���%d�Σ��ƶ���%d��\n", num_compare, num_move);
    st[4].num_compare = num_compare;
    st[4].num_move = num_move;
    strcpy(st[4].name, "���������㷨");
}
void op6(int a[])
{
    int i;
    printf("���������㷨�ıȽ����ƶ������ĶԱȣ�\n\n");
    printf("   ����          �Ƚϴ���          �ƶ�����\n");

    for (i = 0; i < 5; i++)
    {
        printf("%-18s%-18d %d\n", st[i].name, st[i].num_compare, st[i].num_move);
    }
}
int main()
{
    int a[MAX]; //�б�����
    int op;
    srand((unsigned)time(NULL)); //�������
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

