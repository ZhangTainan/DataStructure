# 实习：

#### 目录里的pdf就是实习要求，代码我也是搬的别人的。

#### 所有的实习题目网上都可以找到，也不一定完全按照老师的要求来，你写出来讲得通就行，语言也没有限制死，最后的时候Java、C++都有人用的。

#### 先说一下就是你不去找老师，他也会给你70分。所以可以摆。

#### 再说一下去找他，至少有73分以上，要诚实（问你是不是抄的），重点是前两个算法，抄的就是抄的，你把代码讲的通就好。后面的基础的查找排序算法他不太看。

#### 实习报告老师一般也不会看。





# 考试

## 论述题（20分）考的是第一章的名词解释，总共5个小题，我记得下面几个：

- ### 	数据结构

- ###     空串

### 记不得没关系，选择填空里抄一下。

## 选择题

### 都是书上（数据结构第三版严蔚敏）的课后题原题

## 填空题

### 逻辑结构有______________和____________。

### 就这种也比较简单。

## 大题：

#### 1.给了一个无序数组，让你写出冒泡排序每一趟的排序后的结果。

#### 2.给了一个有序数组，让你求：

- ##### 二分查找某个数（存在于给定数组的）的查找次数

- ##### 列出查找某个数的经过的数（mid值）

- ##### 二分查找某个数（不存在于给定数组的）的比较次数

#### 3.给了一个很简单的带权无向图，让你用普利姆法求最小生成树。

#### 4.给了一个二叉树的先序遍历和中序遍历的结果，让你求后续遍历结果。

###### 		（这个好像是书上的原题，数组好像是+-*/efghab这几个）

## 代码题：

### 	1.一个单链表，设计一个向链表第i个位置的前一个位置插入一个节点的程序。

```c
#include <stdio.h>

typedef struct List{
    int data;
    struct List *next;
} L;

void insert(L *head,L* node,int position){
    L* p = head;
    int i=0;
    while(i<position){
        i++; 
        p=p->next;
    }
    node->next=p->next;
    p->next=node;
}
```

#### 差不多就这种就可以了，反正他不会拿你的代码去运行。

### 	2.递归方式实现遍历二叉树。

```c
#include <stdio.h>

typedef struct Tree{
    int data; 
    struct Tree *leftChild;
    struct Tree *rightChild;
} T;

void traversalTree(T* tree){
    if(tree==null){
        return;
    }
    printf("%d\t",tree->data);
    traversalTree(tree->leftChild);
    traversalTree(tree->rightChild);
}
```

#### 实在不会写就写点思路上去也给分。

# $\textcolor{Orange}{希望对大家有帮助，记得给我github多点star}$

