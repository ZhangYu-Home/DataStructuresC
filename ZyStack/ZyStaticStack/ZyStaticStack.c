#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#include "ZyStaticStack.h"

pStack create_stack(int Size){
	pStack pAddrStack = (pStack)malloc(sizeof(Stack));
	if(NULL == pAddrStack){
		printf("�ڴ治��!\n");
		exit(-1);
	}
	//���侲̬ջ 
	pAddrStack->pData = (ElemType*)malloc(Size*sizeof(ElemType));
	pAddrStack->Top = 0;
	pAddrStack->SizeStack = Size;
	
	return pAddrStack;
}

//�ݻپ�̬ջ
bool destory_stack(pStack *ppAddrStack){
	
	assert(NULL != ppAddrStack);
	assert(NULL != *ppAddrStack);
	
	free((*ppAddrStack)->pData);
	free(*ppAddrStack);
	
	*ppAddrStack = NULL;
	
	return true;
}

//�ж��Ƿ�Ϊ��ջ 
bool is_empty_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	return (pAddrStack->Top == 0);
}

//�ж�ջ�Ƿ����� 
bool is_full_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	return (pAddrStack->Top == pAddrStack->SizeStack);
}

//ѹջ
bool push_stack(pStack pAddrStack, ElemType Data){
	//�ж�ջ���Ѿ����˶��� 
	if(is_full_stack(pAddrStack)){
		return false;
	}
	//ѹջ 
	pAddrStack->pData[pAddrStack->Top] = Data; 
	(pAddrStack->Top)++;

	return true;
}

//��ջ
bool pop_stack(pStack pAddrStack, ElemType *pData){
	//�ж�ջ���Ѿ����˶��� 
	if(is_empty_stack(pAddrStack)){
		return false;
	}
	//��ջ 
	(pAddrStack->Top)--;
	*pData = pAddrStack->pData[pAddrStack->Top];
	return true; 
}

//��ջ�׿�ʼ����ջ����ջ������ 
void traverse_stack(pStack pAddrStack){
	//�ж�ջ���Ѿ����˶��� 
	if(is_empty_stack(pAddrStack)){
		printf("���ǿ�ջ��\n");
		return;
	}
	int i = 0;
	printf("ջ��Ԫ��Ϊ��");
	for(i = 0; i < pAddrStack->Top; i++){
		printf("%d  ", pAddrStack->pData[i]);
	}
	printf("\n");
}

//���ص�ǰջ���ÿռ��С 
int remain_size(pStack pAddrStack){
	assert(NULL != pAddrStack);
	return ((pAddrStack->SizeStack)-(pAddrStack->Top));
} 

 



