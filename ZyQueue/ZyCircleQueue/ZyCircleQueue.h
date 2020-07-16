#ifndef _ZYCIRCLEQUEUE_H_
#define _ZYCIRCLEQUEUE_H_

//C99�Ժ�汾����ʹ��stdbool.h�⣬������Զ���bool���� 
#include <stdbool.h>

typedef int ElemType;

typedef struct Queue{
	ElemType* pData;//�����γ�ѭ�����е�����
	int Size;//������󳤶� 
	int Front;//����ָʾ���� 
	int Rear; //����ָʾ��β 
}Queue, *pQueue; 

//��������ΪSize��ѭ������ 
pQueue create_queue(int Size);

//�ݻ�ѭ������ 
bool destory_queue(pQueue * ppAddrQueue); 

//�ж϶����Ƿ�Ϊ��
bool is_empty_queue(pQueue pAddrQueue);

//�ж϶����Ƿ�Ϊ�� 
bool is_full_queue(pQueue pAddrQueue);

//��� 
bool push_queue(pQueue pAddrQueue, ElemType DataPush); 

//����
bool pop_queue(pQueue pAddrQueue, ElemType * DataPop); 

//�Ӷ��׿�ʼ�������� 
void traverse_queue(pQueue pAddrQueue); 

//���ص�ǰ���п��ô�С
int remain_size(pQueue pAddrQueue); 

#endif 

