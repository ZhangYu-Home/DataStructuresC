#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#include "ZyStaticStack.h"

pStack create_stack(int Size){
	pStack pAddrStack = (pStack)malloc(sizeof(Stack));
	if(NULL == pAddrStack){
		printf("内存不足!\n");
		exit(-1);
	}
	//分配静态栈 
	pAddrStack->pData = (ElemType*)malloc(Size*sizeof(ElemType));
	pAddrStack->Top = 0;
	pAddrStack->SizeStack = Size;
	
	return pAddrStack;
}

//摧毁静态栈
bool destory_stack(pStack *ppAddrStack){
	
	assert(NULL != ppAddrStack);
	assert(NULL != *ppAddrStack);
	
	free((*ppAddrStack)->pData);
	free(*ppAddrStack);
	
	*ppAddrStack = NULL;
	
	return true;
}

//判断是否为空栈 
bool is_empty_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	return (pAddrStack->Top == 0);
}

//判断栈是否已满 
bool is_full_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	return (pAddrStack->Top == pAddrStack->SizeStack);
}

//压栈
bool push_stack(pStack pAddrStack, ElemType Data){
	//判断栈满已经有了断言 
	if(is_full_stack(pAddrStack)){
		return false;
	}
	//压栈 
	pAddrStack->pData[pAddrStack->Top] = Data; 
	(pAddrStack->Top)++;

	return true;
}

//弹栈
bool pop_stack(pStack pAddrStack, ElemType *pData){
	//判断栈空已经有了断言 
	if(is_empty_stack(pAddrStack)){
		return false;
	}
	//弹栈 
	(pAddrStack->Top)--;
	*pData = pAddrStack->pData[pAddrStack->Top];
	return true; 
}

//从栈底开始遍历栈，到栈顶结束 
void traverse_stack(pStack pAddrStack){
	//判断栈空已经有了断言 
	if(is_empty_stack(pAddrStack)){
		printf("这是空栈！\n");
		return;
	}
	int i = 0;
	printf("栈中元素为：");
	for(i = 0; i < pAddrStack->Top; i++){
		printf("%d  ", pAddrStack->pData[i]);
	}
	printf("\n");
}

//返回当前栈可用空间大小 
int remain_size(pStack pAddrStack){
	assert(NULL != pAddrStack);
	return ((pAddrStack->SizeStack)-(pAddrStack->Top));
} 

 



