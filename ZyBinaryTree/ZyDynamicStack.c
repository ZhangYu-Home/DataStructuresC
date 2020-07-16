#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h> 

#include "ZyDynamicStack.h" 

//创建一个动态栈，不需要指定大小 
pStack create_stack(){
	pStack pAddrStack = (pStack)malloc(sizeof(Stack));
	if(NULL == pAddrStack){
		printf("内存不足!\n");
		exit(-1);
	}
	pAddrStack->pTop = (pStackNode)malloc(sizeof(StackNode));
	if(NULL == pAddrStack->pTop){
		printf("内存不足!\n");
		//释放空间 
		free(pAddrStack);
		exit(-1);
	}
	pAddrStack->pBottom = pAddrStack->pTop;
	pAddrStack->ElemNum = 0;
	return pAddrStack;
}

//摧毁动态栈
bool destory_stack(pStack *ppAddrStack){
	
	assert(NULL != ppAddrStack);
	assert(NULL != *ppAddrStack);
	
	pStackNode pTmp = NULL;
	while((*ppAddrStack)->pTop != (*ppAddrStack)->pBottom){
		pTmp = (*ppAddrStack)->pTop;
		(*ppAddrStack)->pTop = (*ppAddrStack)->pTop->pNext;
		free(pTmp);
	}
	//释放头结点
	free((*ppAddrStack)->pTop); 
	//释放动态栈指针对应的空间 
	free(*ppAddrStack);
	*ppAddrStack = NULL; 
	return true;
} 

//压栈
bool push_stack(pStack pAddrStack, StackValType DataPush){
	assert(NULL != pAddrStack);
	assert(NULL != pAddrStack->pTop);
	
	pStackNode pNew = (pStackNode)malloc(sizeof(StackNode));
	if(NULL == pNew){
		printf("内存不足!\n");
		exit(-1);
	}
	pNew->Data = DataPush;
	pNew->pNext = pAddrStack->pTop;
	pAddrStack->pTop = pNew;
	
	(pAddrStack->ElemNum)++;
	
	return true;
}

//弹栈
bool pop_stack(pStack pAddrStack, StackValType *DataPop){
	if(is_empty_stack(pAddrStack)){
		return false;
	}
	
	*DataPop = pAddrStack->pTop->Data;
	pStackNode pTmp = pAddrStack->pTop;
	pAddrStack->pTop = pAddrStack->pTop->pNext;
	(pAddrStack->ElemNum)--;
	
	return true;
}

//判断是否为空栈
bool is_empty_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	assert(NULL != pAddrStack->pTop);
	return (0 == pAddrStack->ElemNum);
}

//返回当前栈中元素个数 
int len_stack(pStack pAddrStack){
	assert(NULL != pAddrStack);
	assert(NULL != pAddrStack->pTop);
	return pAddrStack->ElemNum;
}

//遍历当前栈
void traverse_stack(pStack pAddrStack){
	//判断栈空已经有了断言 
	if(is_empty_stack(pAddrStack)){
		printf("这是空栈！\n");
		return;
	}
	
	pStackNode pTmp = NULL;
	printf("栈中元素为：");
	for(pTmp = pAddrStack->pTop; pTmp != pAddrStack->pBottom; pTmp = pTmp->pNext){
		printf("%d  ", pTmp->Data);
	}
	printf("\n");
	
} 



