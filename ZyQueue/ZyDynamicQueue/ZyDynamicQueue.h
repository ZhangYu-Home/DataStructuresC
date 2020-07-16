#ifndef _ZYDYNAMICQUEUE_H_
#define _ZYDYNAMICQUEUE_H_

//C99之后，引入了bool变量，使用时需包含如下的stdbool.h库
//如果使用的C语言为C99之前的版本，可以自定义bool变量，也可以用int型的0和1代替 
#include <stdbool.h>

typedef int ElemType;

typedef struct Node{
	ElemType Data;
	struct Node *pNext; 
}Node, *pNode;

typedef struct Queue{
	pNode pFront;//队头指针 
	pNode pRear;//队尾指针
	int ElemNum;//队列中已有元素个数 
}Queue, *pQueue;

//创建一个动态队列，不需要指定大小 
pQueue create_queue();

//摧毁动态队列
bool destory_queue(pQueue *ppAddrQueue); 

//入队 
bool push_queue(pQueue pAddrQueue, ElemType DataPush);

//出队
bool pop_queue(pQueue pAddrQueue, ElemType *DataPop);

//判断是否为空队列
bool is_empty_queue(pQueue pAddrQueue);

//返回当前队列中元素个数 
int len_queue(pQueue pAddrQueue);

//遍历队列 
void traverse_queue(pQueue pAddrQueue);


#endif 

