#ifndef _ZYDYNAMICQUEUE_H_
#define _ZYDYNAMICQUEUE_H_

//C99֮��������bool������ʹ��ʱ��������µ�stdbool.h��
//���ʹ�õ�C����ΪC99֮ǰ�İ汾�������Զ���bool������Ҳ������int�͵�0��1���� 
#include <stdbool.h>

typedef int ElemType;

typedef struct Node{
	ElemType Data;
	struct Node *pNext; 
}Node, *pNode;

typedef struct Queue{
	pNode pFront;//��ͷָ�� 
	pNode pRear;//��βָ��
	int ElemNum;//����������Ԫ�ظ��� 
}Queue, *pQueue;

//����һ����̬���У�����Ҫָ����С 
pQueue create_queue();

//�ݻٶ�̬����
bool destory_queue(pQueue *ppAddrQueue); 

//��� 
bool push_queue(pQueue pAddrQueue, ElemType DataPush);

//����
bool pop_queue(pQueue pAddrQueue, ElemType *DataPop);

//�ж��Ƿ�Ϊ�ն���
bool is_empty_queue(pQueue pAddrQueue);

//���ص�ǰ������Ԫ�ظ��� 
int len_queue(pQueue pAddrQueue);

//�������� 
void traverse_queue(pQueue pAddrQueue);


#endif 

