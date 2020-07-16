#ifndef _ZYDYNAMICSTACK_H_
#define _ZYDYNAMICSTACK_H_

//C99֮��������bool������ʹ��ʱ��������µ�stdbool.h��
//���ʹ�õ�C����ΪC99֮ǰ�İ汾�������Զ���bool������Ҳ������int�͵�0��1���� 
#include <stdbool.h>

typedef int ElemType;

typedef struct Node{
	ElemType Data;
	struct Node *pNext; 
}Node, *pNode;

typedef struct Stack{
	pNode pTop;//ջ��ָ�� 
	pNode pBottom;//ջ��ָ��
	int ElemNum;//ջ������Ԫ�ظ��� 
}Stack, *pStack;

//����һ����̬ջ������Ҫָ����С 
pStack create_stack();

//�ݻٶ�̬ջ
bool destory_stack(pStack *ppAddrStack); 

//ѹջ
bool push_stack(pStack pAddrStack, ElemType DataPush);

//��ջ
bool pop_stack(pStack pAddrStack, ElemType *DataPop);

//�ж��Ƿ�Ϊ��ջ
bool is_empty_stack(pStack pAddrStack);

//���ص�ǰջ��Ԫ�ظ��� 
int len_stack(pStack pAddrStack);

//������ǰջ
void traverse_stack(pStack pAddrStack); 




#endif

