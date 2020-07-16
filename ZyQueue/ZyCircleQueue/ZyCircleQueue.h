#ifndef _ZYCIRCLEQUEUE_H_
#define _ZYCIRCLEQUEUE_H_

//C99以后版本可以使用stdbool.h库，否则可自定义bool类型 
#include <stdbool.h>

typedef int ElemType;

typedef struct Queue{
	ElemType* pData;//用于形成循环队列的数组
	int Size;//队列最大长度 
	int Front;//用于指示队首 
	int Rear; //用于指示队尾 
}Queue, *pQueue; 

//创建长度为Size的循环队列 
pQueue create_queue(int Size);

//摧毁循环队列 
bool destory_queue(pQueue * ppAddrQueue); 

//判断队列是否为空
bool is_empty_queue(pQueue pAddrQueue);

//判断队列是否为满 
bool is_full_queue(pQueue pAddrQueue);

//入队 
bool push_queue(pQueue pAddrQueue, ElemType DataPush); 

//出队
bool pop_queue(pQueue pAddrQueue, ElemType * DataPop); 

//从队首开始遍历队列 
void traverse_queue(pQueue pAddrQueue); 

//返回当前队列可用大小
int remain_size(pQueue pAddrQueue); 

#endif 

