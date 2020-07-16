#include <stdio.h>
//#include <stdlib.h>
#include <assert.h>
#include <malloc.h> 

#include "ZyDynamicQueue.h" 

//创建一个动态队列，不需要指定大小 
pQueue create_queue(){
	pQueue pAddrQueue = (pQueue)malloc(sizeof(Queue));
	if(NULL == pAddrQueue){
		printf("内存不足！\n");
		exit(-1); 
	}
	pAddrQueue->pFront = (pNode)malloc(sizeof(Node));
	if(NULL == pAddrQueue->pFront){
		printf("内存不足！\n");
		exit(-1); 
	}
	pAddrQueue->pRear = pAddrQueue->pFront;
	pAddrQueue->ElemNum = 0;
	return pAddrQueue;
}

//摧毁动态队列
bool destory_queue(pQueue *ppAddrQueue){
	assert(NULL != ppAddrQueue);
	assert(NULL != *ppAddrQueue);
	assert(NULL != (*ppAddrQueue)->pFront);
	assert(NULL != (*ppAddrQueue)->pRear);
	pNode pTmp = NULL;
	while((*ppAddrQueue)->pFront != (*ppAddrQueue)->pRear){
		pTmp = (*ppAddrQueue)->pFront;
		(*ppAddrQueue)->pFront = pTmp->pNext;
		free(pTmp);
	}
	free((*ppAddrQueue)->pFront);
	free(*ppAddrQueue);
	*ppAddrQueue = NULL;
	
	return true;
}

//入队 
bool push_queue(pQueue pAddrQueue, ElemType DataPush){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pFront);
	assert(NULL != pAddrQueue->pRear);
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL == pNew){
		printf("内存不足!\n");
		exit(-1);
	}
	pNew->Data = DataPush;
	pNew->pNext = NULL;
	pAddrQueue->pRear->pNext = pNew;
	pAddrQueue->pRear = pNew;
	
	(pAddrQueue->ElemNum)++;
	return true;
}

//出队
bool pop_queue(pQueue pAddrQueue, ElemType *DataPop){
	if(is_empty_queue(pAddrQueue)){
		return false;
	}
	
	pNode pTmp = pAddrQueue->pFront->pNext;	
	*DataPop = pTmp->Data;	
	pAddrQueue->pFront->pNext = pTmp->pNext;
	free(pTmp);
	(pAddrQueue->ElemNum)--;
	//如果当前出队的为最后一个元素，则需要将队尾指针与队首指针同时指向头结点
	//否则会出错 
	if(NULL == pAddrQueue->pFront->pNext){
		pAddrQueue->pRear = pAddrQueue->pFront;
	}
	
	return true;
}

//判断是否为空队列
bool is_empty_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pFront);
	assert(NULL != pAddrQueue->pRear);
		
	return pAddrQueue->pFront == pAddrQueue->pRear; 
	
}

//返回当前队列中元素个数 
int len_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pFront);
	assert(NULL != pAddrQueue->pRear);
	return pAddrQueue->ElemNum;
}

//遍历队列 
void traverse_queue(pQueue pAddrQueue){
	if(is_empty_queue(pAddrQueue)){
		printf("这是空队列！\n");
	}
	printf("队列中元素为：\n");
	pNode pTmp = NULL;
	for(pTmp = pAddrQueue->pFront;pTmp != pAddrQueue->pRear;pTmp = pTmp->pNext){
		printf("%d  ",pTmp->pNext->Data);
	}
	printf("\n");
}

