#ifndef _ZYSTATICSTACK_H_
#define _ZYSTATICSTACK_H_

//C99֮��������bool������ʹ��ʱ��������µ�stdbool.h��
//���ʹ�õ�C����ΪC99֮ǰ�İ汾�������Զ���bool������Ҳ������int�͵�0��1���� 
#include <stdbool.h> 

typedef int ElemType;

typedef struct Stack{
	ElemType* pData; //��̬ջָ��
	int Top; //ջ����ţ�ָ��ջ��Ԫ�ص��Ϸ� 
	int SizeStack; //ջ�Ĵ�С  
	int RemSize; //ջʣ��Ĵ�С 
	
}Stack, *pStack;

//����һ����СΪSize��ջ
pStack create_stack(int Size);

//�ݻپ�̬ջ
bool destory_stack(pStack *ppAddrStack); 

//�ж��Ƿ�Ϊ��ջ 
bool is_empty_stack(pStack pAddrStack);

//�ж�ջ�Ƿ�����  
bool is_full_stack(pStack pAddrStack); 

//ѹջ
//����ֵ��ʾ�Ƿ�ѹջ�ɹ� 
bool push_stack(pStack pAddrStack, ElemType Data);

//��ջ
//����ֵ��ʾ�Ƿ�ջ�ɹ� 
bool pop_stack(pStack pAddrStack, ElemType *pData); 

//��ջ�׿�ʼ����ջ����ջ������ 
void traverse_stack(pStack pAddrStack);

//���ص�ǰջ���ÿռ��С 
int remain_size(pStack pAddrStack);


#endif

