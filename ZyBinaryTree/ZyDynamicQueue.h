#ifndef _ZYDYNAMICQUEUE_H_
#define _ZYDYNAMICQUEUE_H_

//C99֮��������bool������ʹ��ʱ��������µ�stdbool.h��
//���ʹ�õ�C����ΪC99֮ǰ�İ汾�������Զ���bool������Ҳ������int�͵�0��1���� 
#include <stdbool.h>
//��ΪҪ�õ� 
#include "ZyBinaryTree.h"

typedef pTreeNode QueueValType;

typedef struct QueueNode{
	QueueValType Data;
	struct QueueNode *pNext; 
}QueueNode, *pQueueNode;

typedef struct Queue{
	pQueueNode pFront;//��ͷָ�� 
	pQueueNode pRear;//��βָ��
	int ElemNum;//����������Ԫ�ظ��� 
}Queue, *pQueue;

//����һ����̬���У�����Ҫָ����С 
pQueue create_queue();

//�ݻٶ�̬����
bool destory_queue(pQueue *ppAddrQueue); 

//��� 
bool push_queue(pQueue pAddrQueue, QueueValType DataPush);

//����
bool pop_queue(pQueue pAddrQueue, QueueValType *DataPop);

//�ж��Ƿ�Ϊ�ն���
bool is_empty_queue(pQueue pAddrQueue);

//���ص�ǰ������Ԫ�ظ��� 
int len_queue(pQueue pAddrQueue);

//�������� 
void traverse_queue(pQueue pAddrQueue);


#endif 


