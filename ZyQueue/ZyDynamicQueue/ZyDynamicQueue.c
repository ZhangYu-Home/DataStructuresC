#include <stdio.h>
//#include <stdlib.h>
#include <assert.h>
#include <malloc.h> 

#include "ZyDynamicQueue.h" 

//����һ����̬���У�����Ҫָ����С 
pQueue create_queue(){
	pQueue pAddrQueue = (pQueue)malloc(sizeof(Queue));
	if(NULL == pAddrQueue){
		printf("�ڴ治�㣡\n");
		exit(-1); 
	}
	pAddrQueue->pFront = (pNode)malloc(sizeof(Node));
	if(NULL == pAddrQueue->pFront){
		printf("�ڴ治�㣡\n");
		exit(-1); 
	}
	pAddrQueue->pRear = pAddrQueue->pFront;
	pAddrQueue->ElemNum = 0;
	return pAddrQueue;
}

//�ݻٶ�̬����
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

//��� 
bool push_queue(pQueue pAddrQueue, ElemType DataPush){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pFront);
	assert(NULL != pAddrQueue->pRear);
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL == pNew){
		printf("�ڴ治��!\n");
		exit(-1);
	}
	pNew->Data = DataPush;
	pNew->pNext = NULL;
	pAddrQueue->pRear->pNext = pNew;
	pAddrQueue->pRear = pNew;
	
	(pAddrQueue->ElemNum)++;
	return true;
}

//����
bool pop_queue(pQueue pAddrQueue, ElemType *DataPop){
	if(is_empty_queue(pAddrQueue)){
		return false;
	}
	
	pNode pTmp = pAddrQueue->pFront->pNext;	
	*DataPop = pTmp->Data;	
	pAddrQueue->pFront->pNext = pTmp->pNext;
	free(pTmp);
	(pAddrQueue->ElemNum)--;
	//�����ǰ���ӵ�Ϊ���һ��Ԫ�أ�����Ҫ����βָ�������ָ��ͬʱָ��ͷ���
	//�������� 
	if(NULL == pAddrQueue->pFront->pNext){
		pAddrQueue->pRear = pAddrQueue->pFront;
	}
	
	return true;
}

//�ж��Ƿ�Ϊ�ն���
bool is_empty_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pFront);
	assert(NULL != pAddrQueue->pRear);
		
	return pAddrQueue->pFront == pAddrQueue->pRear; 
	
}

//���ص�ǰ������Ԫ�ظ��� 
int len_queue(pQueue pAddrQueue){
	assert(NULL != pAddrQueue);
	assert(NULL != pAddrQueue->pFront);
	assert(NULL != pAddrQueue->pRear);
	return pAddrQueue->ElemNum;
}

//�������� 
void traverse_queue(pQueue pAddrQueue){
	if(is_empty_queue(pAddrQueue)){
		printf("���ǿն��У�\n");
	}
	printf("������Ԫ��Ϊ��\n");
	pNode pTmp = NULL;
	for(pTmp = pAddrQueue->pFront;pTmp != pAddrQueue->pRear;pTmp = pTmp->pNext){
		printf("%d  ",pTmp->pNext->Data);
	}
	printf("\n");
}

