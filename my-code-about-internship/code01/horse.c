#include <stdio.h>
//初始化X
#define X 8
//初始化Y
#define Y 8
//棋盘数组
int chess[X][Y];

//根据step 的值尝试不同走法，若能走通返回1,走不通返回0
int try(int *x, int *y, int step) {
    switch (step) {
        case 0:
            //判断条件：当下一个位置不超出棋盘范围且没有走过，坐标更改并返回1
            //当数组对应位置不为0时说明已经走过
            if ((*x) + 2 <= X - 1 && (*y) - 1 >= 0 && chess[(*x) + 2][(*y) - 1] == 0) {
                *x = *x + 2;
                *y = *y - 1;
                return 1;
            }
            break;
        case 1:
            if ((*x) + 1 <= X - 1 && (*y) - 2 >= 0 && chess[(*x) + 1][(*y) - 2] == 0) {
                *x = *x + 1;
                *y = *y - 2;
                return 1;
            }
            break;
        case 2:
            if ((*x) - 1 >= 0 && (*y) - 2 >= 0 && chess[(*x) - 1][(*y) - 2] == 0) {
                *x = *x - 1;
                *y = *y - 2;
                return 1;
            }
            break;
        case 3:
            if ((*x) - 2 >= 0 && (*y) - 1 >= 0 && chess[(*x) - 2][(*y) - 1] == 0) {
                *x = *x - 2;
                *y = *y - 1;
                return 1;
            }
            break;
        case 4:
            if ((*x) - 2 >= 0 && (*y) + 1 <= Y - 1 && chess[(*x) - 2][(*y) + 1] == 0) {
                *x = *x - 2;
                *y = *y + 1;
                return 1;
            }
            break;
        case 5:
            if ((*x) - 1 >= 0 && (*y) + 2 <= Y - 1 && chess[(*x) - 1][(*y) + 2] == 0) {
                *x = *x - 1;
                *y = *y + 2;
                return 1;
            }
            break;
        case 6:
            if ((*x) + 1 <= X - 1 && (*y) + 2 <= Y - 1 && chess[(*x) + 1][(*y) + 2] == 0) {
                *x = *x + 1;
                *y = *y + 2;
                return 1;
            }
            break;
        case 7:
            if ((*x) + 2 <= X - 1 && (*y) + 1 <= Y - 1 && chess[(*x) + 2][(*y) + 1] == 0) {
                *x = *x + 2;
                *y = *y + 1;
                return 1;
            }
            break;
        default:
            break;
    }
    return 0;
}

//打印棋盘
void print() {
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%2d ", chess[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//深度优先遍历
//x，y为当前马的位置
//tag为当前走的步数
int traverseChess(int x, int y, int tag) {
    //定义马位置的坐标副本x1、y1,以及控制马走方向的变量step，接收能否走通的返回值flag
    int x1 = x, y1 = y, step = 0, flag;
    //设置马当前位置坐标为马走的步数，可以记录马的第几步走过这个位置
    chess[x][y] = tag;
    //如果马走了8*8 64步，打印棋盘
    if (X * Y == tag) {
        print();
        return 1;
    }

    //依次尝试8种走法
    flag = try(&x1, &y1, step);
    while (!flag && step < 7) {
        step++;
        flag = try(&x1, &y1, step);
    }
    //若走通	
    while (flag) {
        //递归当前函数，步数加一，当走到64步递归结束
        if (traverseChess(x1, y1, tag + 1)) {
            return 1;
        }
        //当遇到8条路都走不通时，回溯上一步，尝试下一种走法
        step++;
        x1 = x;
        y1 = y;
        flag = try(&x1, &y1, step);
        while (!flag && step < 7) {
            step++;
            flag = try(&x1, &y1, step);
        }
    }
    //走不通时，返回0，因为走不通时要回溯上一步，所以把当前坐标重新置为0（没有走过）
    chess[x][y] = 0;
    return 0;

}

int main() {
    //初始化棋盘全为0（全都没有走过）
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            chess[i][j] = 0;
        }

    }
    //从0,0的位置开始走第一步
    traverseChess(0, 0, 1);
    return 0;
}
