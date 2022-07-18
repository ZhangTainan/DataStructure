#include <stdio.h>
#include <stdlib.h>


//定义一个结构体保留每次的位置信息、移动信息
typedef struct{
	int x;						
	int y;						
	int direction;					
	int moveTime;					
	struct RNode * last;			
	struct RNode * next;			
}RNode;

//迷宫
int Maze[11][11]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,1,1},
	{1,0,1,1,1,0,0,1,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,1,1},
	{1,0,1,1,1,1,0,0,1,1},
	{1,1,1,0,0,0,1,0,1,1},
	{1,1,1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}};

//可移动方式
void Move(RNode * road,int dir){
	if(dir==0){
		road->x--;
		//移动后看是否撞墙，若撞墙则不移动
		if(Maze[road->x][road->y]==1){
			road->x++;
		}
	}
	if(dir==1){
		road->y++;
		//移动后看是否撞墙，若撞墙则不移动
		if(Maze[road->x][road->y]==1){
			road->y--;
		}
	}
	if(dir==2){
		road->x++;
		//移动后看是否撞墙，若撞墙则不移动
		if(Maze[road->x][road->y]==1){
			road->x--;
		}
	}	
	if(dir==3){
		road->y--;
		//移动后看是否撞墙，若撞墙则不移动
		if(Maze[road->x][road->y]==1){
			road->y++;
		}
	}
}
//创建路节点
RNode * Create(RNode * Lroad){
	RNode * road=(RNode *)malloc(sizeof(RNode));
	road->x=Lroad->x;
	road->y=Lroad->y;
	road->direction=Lroad->direction;
	road->moveTime=0;
	road->next=NULL;
	road->last=Lroad;
	Lroad->next=road;
	return road;
}

//输出
void print(RNode * head){
	RNode * node=(RNode *)malloc(sizeof(RNode));
	node=head;
	while(node!=NULL){
		printf("(%d,%d,%d)\n",node->x,node->y,node->direction);
		node=node->next;
	}
}

//寻路
int findWay(RNode * road){
	RNode * Lroad=(RNode *)malloc(sizeof(RNode));
	Lroad=road->last;
	for(int i=road->moveTime;i<=5;i++){
		if(i==1||i==2||i==4){
			//根据方向移动
			Move(road, road->direction);
			//若移动则退出循环
			if(road->x!=Lroad->x||road->y!=Lroad->y){
				road->moveTime=i;
				//ShowRoad(road);
				Maze[Lroad->x][Lroad->y]=1;
				Maze[road->x][road->y]=1;
				break;
			}else{
			//未移动则改变方向
				road->direction++;
				road->direction=(road->direction)%4;
			}
		}
		//第三次移动时，为原方向的反方向，不能移动，继续改变方向
		if(i==3){
			road->direction++;
			road->direction=(road->direction)%4;
		}
		//第五次移动时，为原方向，改为回溯
		if(i==5){
			return 0;
		}
	}
	return 1;
}

void Start(RNode * head){
	RNode * Lroad=head;
	int result=1;
	while(1){
		RNode * road=Create(Lroad);
		result=findWay(road);
		if(result==1){
			if(road->x==9&&road->y==8){
				
					break;
				
			}
			Lroad=road;
		}
		else{
			Lroad=road->last;
			Lroad->next=NULL;
			Lroad=Lroad->last;
			Lroad->next=NULL;
			Maze[Lroad->x][Lroad->y]=0;
		}
	}
}

int main() {
	RNode * head=(RNode *)malloc(sizeof(RNode));
	head->x=1;
	head->y=1;
	head->direction=1;
	head->moveTime=1;
	head->next=NULL;
	head->last=NULL;
	Start(head);
	print(head);
	
}