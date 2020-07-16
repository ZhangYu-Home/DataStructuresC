#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "ZyCircleQueue.h"

//printf("\n");
//创建长度为Size的循环队列 
pQueue create_queue(int Size){
	pQueue pAddrQueue = (pQueue)malloc(sizeof(Queue));
	if(NULL == pAddrQueue){
		printf("内存不足！\n");
		exit(-1); 
	}
	//实际分配的空间比要求的多一个，便于队列的空和满验证 
	pAddrQueue->pData = (ElemType*)malloc((Size+1)*sizeof(ElemType));
	if(NULL == pAddrQueue->pData){
		printf("内存不足！\n");
		free(pAddrQueue);
		exit(-1); 
	}
	pAddrQueue->Rear = 0;
	pAddrQueue->Front = 0;
	pAddrQueue->Size = Size;
	return pAddrQueue;
}

//摧毁循环队列 
bool destory_queue(pQueue * ppAddrQueue){
	assert(NULL != ppAddrQueue);
	assert(NULL != *ppAddrQueue);
	assert(NULL != (*ppAddrQueue)->pData);
	
	free((*ppAddrQueue)->pData);
	free(*ppAddrQueue);
	*ppAddrQueue = NULL;
	
	return true;
}

//判断队列是否为空
bool is_empty_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pData);
	
	return (pAddrQueue->Rear == pAddrQueue->Front);
}

//判断队列是否为满 
bool is_full_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pData);
	//队列始终留有一个空间 
	return ((pAddrQueue->Rear+1)%(pAddrQueue->Size+1) == pAddrQueue->Front);
}

//入队 
bool push_queue(pQueue pAddrQueue, ElemType DataPush){
	//判断队满已经有了断言 
	if(is_full_queue(pAddrQueue)){
		return false;
	}
	pAddrQueue->pData[pAddrQueue->Rear] = DataPush;
	pAddrQueue->Rear = (pAddrQueue->Rear+1)%(pAddrQueue->Size+1);
	return true;
}

//出队
bool pop_queue(pQueue pAddrQueue, ElemType * DataPop){
	//判断队空已经有了断言 
	if(is_empty_queue(pAddrQueue)){
		return false;
	}
	*DataPop = pAddrQueue->pData[pAddrQueue->Front];
	pAddrQueue->Front = (pAddrQueue->Front+1)%(pAddrQueue->Size+1);
	return true;
}

//从队首开始遍历队列 
void traverse_queue(pQueue pAddrQueue){
	//判断队空已经有了断言 
	if(is_empty_queue(pAddrQueue)){
		printf("这是空队列！\n");
		return;
	}
	int i = 0; 
	printf("队列中元素为：");
	for(i = pAddrQueue->Front; i != pAddrQueue->Rear; i=(i+1)%(pAddrQueue->Size+1)){
		printf("%d  ",pAddrQueue->pData[i]);
	}
	printf("\n");
}

//返回当前队列可用大小
int remain_size(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pData);
	return pAddrQueue->Size-(pAddrQueue->Rear+pAddrQueue->Size+1-pAddrQueue->Front)%(pAddrQueue->Size+1);
}

