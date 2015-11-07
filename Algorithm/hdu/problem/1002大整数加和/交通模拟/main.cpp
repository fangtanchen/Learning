#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

#define MAX 2 /*车库容量*/ 
#define price 0.05 /*每车每分钟费用*/ 
typedef struct time{ 
	int hour; 
	int min; 
}Time; /*时间结点*/ 
typedef struct node{ 
	char num[10]; 
	Time reach; 
	Time leave; 
}CarNode; /*车辆信息结点*/ 
typedef struct NODE{ 
	CarNode *stack[MAX+1]; 
	int top; 
}SeqStackCar; /*模拟车站*/ 
typedef struct car{ 
	CarNode *data; 
	struct car *next; 
}QueueNode; 
typedef struct Node{ 
	QueueNode *head; 
	QueueNode *rear; 
}LinkQueueCar; /*模拟通道*/ 
/*------------------------------------------------------------------------------*/ 
void InitStack(SeqStackCar *); /*初始化栈*/ 
int InitQueue(LinkQueueCar *); /*初始化便道*/ 
int Arrival(SeqStackCar *,LinkQueueCar *); /*车辆到达*/ 
void Leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *); /*车辆离开*/ 
void List(SeqStackCar,LinkQueueCar); /*显示存车信息*/ 
/*------------------------------------------------------------------------------*/ 
void main() 
{ 
	SeqStackCar Enter,Temp; 
	LinkQueueCar Wait; 
	int ch; 
	InitStack(&Enter); /*初始化车站*/ 
	InitStack(&Temp); /*初始化让路的临时栈*/ 
	InitQueue(&Wait); /*初始化通道*/ 
	while(1) 
	{ 
		printf("\n1. the car arrive"); 
		printf(" 2. the car leave"); 
		printf(" 3. the schedule "); 
		printf(" 4. out\n"); 
		while(1) 
		{ 
			scanf("%d",&ch); 
			if(ch>=1&&ch<=4)break; 
			else printf("\nplease choose： 1|2|3|4."); 
		} 
		switch(ch) 
		{ 
		case 1:Arrival(&Enter,&Wait);break; /*车辆到达*/ 
		case 2:Leave(&Enter,&Temp,&Wait);break; /*车辆离开*/ 
		case 3:List(Enter,Wait);break; /*列表打印信息*/ 
		case 4:exit(0); /*退出主程序*/ 
		default: break; 
		} 
	} 
} 
/*------------------------------------------------------------------------------*/ 
void InitStack(SeqStackCar *s) /*初始化栈*/ 
{ 
	int i; 
	s->top=0; 
	for(i=0;i<=MAX;i++) 
		s->stack[s->top]=NULL; 
} 
int InitQueue(LinkQueueCar *Q) /*初始化便道*/ 
{ 
	Q->head=(QueueNode *)malloc(sizeof(QueueNode)); 
	if(Q->head!=NULL) 
	{ 
		Q->head->next=NULL; 
		Q->rear=Q->head; 
		return(1); 
	} 
	else return(-1); 
} 
void PRINT(CarNode *p,int room) /*打印出站车的信息*/ 
{ 
	int A1,A2,B1,B2; 
	printf("\nplease input thedepart time:/**:**/"); 
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min)); 
	printf("\nthe number of the car:"); 
	puts(p->num); 
	printf("\nthe time the car arrive: %d:%d",p->reach.hour,p->reach.min); 
	printf("the depart time: %d:%d",p->leave.hour,p->leave.min); 
	A1=p->reach.hour; 
	A2=p->reach.min; 
	B1=p->leave.hour; 
	B2=p->leave.min; 
	printf("\nthe fee: %2.1f元",((B1-A1)*60+(B2-A2))*price); 
	free(p); 
} 
int Arrival(SeqStackCar *Enter,LinkQueueCar *W) /*车辆到达*/ 
{ 
	CarNode *p; 
	QueueNode *t; 
	p=(CarNode *)malloc(sizeof(CarNode)); 
	flushall(); 
	printf("\ninput the number of the car(例:陕A1234):"); 
	gets(p->num); 
	if(Enter->top<MAX) /*车场未满，车进车场*/ 
	{ 
		Enter->top++; 
		printf("\nthe place of the car.",Enter->top); 
		printf("\nthe time thecar arrive:/**:**/"); 
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min)); 
		Enter->stack[Enter->top]=p; 
		return(1); 
	} 
	else /*车场已满，车进便道*/ 
	{ 
		printf("\n该车须在便道等待!"); 
		t=(QueueNode *)malloc(sizeof(QueueNode)); 
		t->data=p; 
		t->next=NULL; 
		W->rear->next=t; 
		W->rear=t; 
		return(1); 
	} 
} 
void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W) 
{ /*车辆离开*/ 
	int i, room; 
	CarNode *p,*t; 
	QueueNode *q; 
	/*判断车场内是否有车*/ 
	if(Enter->top>0) /*有车*/ 
	{ 
		while(1) /*输入离开车辆的信息*/ 
		{ 
			printf("\n请输入车在车场的位置/1--%d/：",Enter->top); 
			scanf("%d",&room); 
			if(room>=1&&room<=Enter->top) break; 
		} 
		while(Enter->top>room) /*车辆离开*/ 
		{ 
			Temp->top++; 
			Temp->stack[Temp->top]=Enter->stack[Enter->top]; 
			Enter->stack[Enter->top]=NULL; 
			Enter->top--; 
		} 
		p=Enter->stack[Enter->top]; 
		Enter->stack[Enter->top]=NULL; 
		Enter->top--; 
		while(Temp->top>=1) 
		{ 
			Enter->top++; 
			Enter->stack[Enter->top]=Temp->stack[Temp->top]; 
			Temp->stack[Temp->top]=NULL; 
			Temp->top--; 
		} 
		PRINT(p,room); 
		/*判断通道上是否有车及车站是否已满*/ 
		if((W->head!=W->rear)&&Enter->top<MAX) /*便道的车辆进入车场*/ 
		{ 
			q=W->head->next; 
			t=q->data; 
			Enter->top++; 
			printf("\n便道的%s号车进入车场第%d位置.",t->num,Enter->top); 
			printf("\n请输入现在的时间/**:**/:"); 
			scanf("%d:%d",&(t->reach.hour),&(t->reach.min)); 
			W->head->next=q->next; 
			if(q==W->rear) W->rear=W->head; 
			Enter->stack[Enter->top]=t; 
			free(q); 
		} 
		else printf("\n便道里没有车.\n"); 
	} 
	else printf("\n车场里没有车."); /*没车*/ 
} 
void List1(SeqStackCar *S) /*列表显示车场信息*/ 
{ 
	int i; 
	if(S->top>0) /*判断车站内是否有车*/ 
	{ 
		printf("\n车场:"); 
		printf("\n 位置 到达时间 车牌号\n"); 
		for(i=1;i<=S->top;i++) 
		{ 
			printf(" %d ",i); 
			printf("%d:%d ",S->stack[i]->reach.hour,S->stack[i]->reach.min); 
			puts(S->stack[i]->num); 
		} 
	} 
	else printf("\n车场里没有车"); 
} 
void List2(LinkQueueCar *W) /*列表显示便道信息*/ 
{ 
	QueueNode *p; 
	p=W->head->next; 
	if(W->head!=W->rear) /*判断通道上是否有车*/ 
	{ 
		printf("\n等待车辆的号码为:"); 
		while(p!=NULL) 
		{ 
			puts(p->data->num); 
			p=p->next; 
		} 
	} 
	else printf("\n便道里没有车."); 
} 
void List(SeqStackCar S,LinkQueueCar W) 
{ 
	int flag,tag; 
	flag=1; 
	while(flag) 
	{ 
		printf("\n请选择 1|2|3:"); 
		printf("\n1.车场\n2.便道\n3.返回\n"); 
		while(1) 
		{ 
			scanf("%d",&tag); 
			if(tag>=1||tag<=3) break; 
			else printf("\n请选择 1|2|3:"); 
		} 
		switch(tag) 
		{ 
		case 1:List1(&S);break; /*列表显示车场信息*/ 
		case 2:List2(&W);break; /*列表显示便道信息*/ 
		case 3:flag=0;break; 
		default: break; 
		} 
	} 
}