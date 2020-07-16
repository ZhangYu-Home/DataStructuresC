#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "ZyCircleQueue.h"

//printf("\n");
//��������ΪSize��ѭ������ 
pQueue create_queue(int Size){
	pQueue pAddrQueue = (pQueue)malloc(sizeof(Queue));
	if(NULL == pAddrQueue){
		printf("�ڴ治�㣡\n");
		exit(-1); 
	}
	//ʵ�ʷ���Ŀռ��Ҫ��Ķ�һ�������ڶ��еĿպ�����֤ 
	pAddrQueue->pData = (ElemType*)malloc((Size+1)*sizeof(ElemType));
	if(NULL == pAddrQueue->pData){
		printf("�ڴ治�㣡\n");
		free(pAddrQueue);
		exit(-1); 
	}
	pAddrQueue->Rear = 0;
	pAddrQueue->Front = 0;
	pAddrQueue->Size = Size;
	return pAddrQueue;
}

//�ݻ�ѭ������ 
bool destory_queue(pQueue * ppAddrQueue){
	assert(NULL != ppAddrQueue);
	assert(NULL != *ppAddrQueue);
	assert(NULL != (*ppAddrQueue)->pData);
	
	free((*ppAddrQueue)->pData);
	free(*ppAddrQueue);
	*ppAddrQueue = NULL;
	
	return true;
}

//�ж϶����Ƿ�Ϊ��
bool is_empty_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pData);
	
	return (pAddrQueue->Rear == pAddrQueue->Front);
}

//�ж϶����Ƿ�Ϊ�� 
bool is_full_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pData);
	//����ʼ������һ���ռ� 
	return ((pAddrQueue->Rear+1)%(pAddrQueue->Size+1) == pAddrQueue->Front);
}

//��� 
bool push_queue(pQueue pAddrQueue, ElemType DataPush){
	//�ж϶����Ѿ����˶��� 
	if(is_full_queue(pAddrQueue)){
		return false;
	}
	pAddrQueue->pData[pAddrQueue->Rear] = DataPush;
	pAddrQueue->Rear = (pAddrQueue->Rear+1)%(pAddrQueue->Size+1);
	return true;
}

//����
bool pop_queue(pQueue pAddrQueue, ElemType * DataPop){
	//�ж϶ӿ��Ѿ����˶��� 
	if(is_empty_queue(pAddrQueue)){
		return false;
	}
	*DataPop = pAddrQueue->pData[pAddrQueue->Front];
	pAddrQueue->Front = (pAddrQueue->Front+1)%(pAddrQueue->Size+1);
	return true;
}

//�Ӷ��׿�ʼ�������� 
void traverse_queue(pQueue pAddrQueue){
	//�ж϶ӿ��Ѿ����˶��� 
	if(is_empty_queue(pAddrQueue)){
		printf("���ǿն��У�\n");
		return;
	}
	int i = 0; 
	printf("������Ԫ��Ϊ��");
	for(i = pAddrQueue->Front; i != pAddrQueue->Rear; i=(i+1)%(pAddrQueue->Size+1)){
		printf("%d  ",pAddrQueue->pData[i]);
	}
	printf("\n");
}

//���ص�ǰ���п��ô�С
int remain_size(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pData);
	return pAddrQueue->Size-(pAddrQueue->Rear+pAddrQueue->Size+1-pAddrQueue->Front)%(pAddrQueue->Size+1);
}

