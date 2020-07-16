#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ZyList.h"

//该函数用于创建空链表，返回值为当前链表的头指针
pNode create_list() {
	pNode pHead = (pNode)malloc(sizeof(Node));
	if (NULL == pHead) {
		printf("内存不足，程序已退出！\n");
		exit(-1);
	}
	pHead->pNext = NULL;
	return pHead;
}

//此函数用于遍历链表
void traverse_list(pNode pHead) {
	
	assert(pHead != NULL);
	
	if(!is_empty_list(pHead)){
		pNode pCur = NULL;
		printf("链表为： ");
		for (pCur = pHead->pNext; pCur != NULL; pCur = pCur->pNext) {
			printf("%d  ", pCur->Data);
		}
		printf("\n");
	}
	else{
		printf("链表为空！\n");
	}
	
}

//获取链表中位置为pos处的数据
bool get_elem_list(pNode pHead, int pos, ElemType* DataGet){
	
	assert(NULL != pHead);
	
	int i = 0;
	pNode p = pHead->pNext;
	
	while(NULL != p && i < pos){
		p = p->pNext;
		++i;
	}
	//第一个判断i>pos可以防止输入pos为负值的情形
	//后一个用来防止输入pos大于链表长度的情形 
	if(i>pos || NULL == p){
		return false;
	}
	
	*DataGet = p->Data;
	
	return true;
}

//链表插入的头插法
//返回值表示是否插入成功 
bool front_insert_list(pNode pHead, ElemType Data) {
	
	assert(pHead != NULL);
	
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	if (NULL == pNewNode) {
		printf("内存不足！\n");
		return -1;
	}
	pNewNode->Data = Data;
	pNewNode->pNext = pHead->pNext;
	pHead->pNext = pNewNode;

	return true;
}

//链表插入的尾插法
//返回值表示是否插入成功 
bool back_insert_list(pNode pHead, ElemType Data) {
	
	assert(pHead != NULL);
	
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	if (NULL == pNewNode) {
		printf("内存不足！\n");
		return -1;
	}
	pNewNode->Data = Data;
	pNewNode->pNext = NULL;

	while (pHead->pNext != NULL) {
		pHead = pHead->pNext;
	}
	pHead->pNext = pNewNode;
	
	return true;
}

//链表的头部删除
bool front_pop_list(pNode pHead, ElemType* pRetVal) {
	
	assert(pHead->pNext != NULL);
	
	*pRetVal = pHead->pNext->Data;
	pNode pTemp = pHead->pNext;
	pHead->pNext = pHead->pNext->pNext;
	free(pTemp);

	return true;
}

//链表的尾部删除
bool back_pop_list(pNode pHead, ElemType* pRetVal) {
	
	assert(pHead->pNext != NULL);
	
	while(pHead->pNext->pNext != NULL) {
		pHead = pHead->pNext;
	}
	
	*pRetVal = pHead->pNext->Data;
	free(pHead->pNext);
	pHead->pNext = NULL;

	return true;
}

//判断是否为空链表
//返回1表示为空，0为非空 
bool is_empty_list(pNode pHead)
{
	assert(pHead != NULL);
	return (pHead->pNext == NULL);
}

//求取链表长度
int len_list(pNode pHead){
	assert(pHead != NULL);
	int Lenth = 0;
	while(pHead->pNext != NULL){
		Lenth++;
		pHead = pHead->pNext;
	}
		
	return Lenth;
}

//对链表进行排序：从小到大
bool sort_list(pNode pHead){
	assert(pHead != NULL);
	ElemType Tmp = 0;
	pNode pFront = NULL;
	pNode pBack = NULL;
	for(pFront = pHead->pNext; pFront != NULL; pFront = pFront->pNext)
	{
		for(pBack = pFront->pNext; pBack != NULL; pBack = pBack->pNext)
		{
			if(pFront->Data > pBack->Data){
				ElemType Tmp = pFront->Data;
				pFront->Data = pBack->Data;
				pBack->Data = Tmp;
			}
		}
	}
	return true;
}

//在链表的pos位置插入值
bool insert_list(pNode pHead, int pos, ElemType DataInsert){
	
	int i = 0;
	pNode p = pHead;
	
	while(NULL != p && i < pos){
		p = p->pNext;
		++i;
	}
	//第一个判断i>pos可以防止输入pos为负值的情形
	//后一个用来防止输入pos大于链表长度的情形 
	if(i>pos || NULL == p){
		return false;
	}
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL == pNew){
		printf("内存不足！\n");
		exit(-1);
	}
	
	pNode pTmp = p->pNext;
	p->pNext = pNew;
	pNew->pNext = pTmp;
	pNew->Data = DataInsert;
	
	return true;
	
	
	
} 

//删除链表pos位置的节点 
bool pop_list(pNode pHead, int pos, ElemType* DataInsert){
	
	int i = 0;
	pNode p = pHead;
	
	while(NULL != p->pNext && i < pos){
		p = p->pNext;
		++i;
	}
	//第一个判断i>pos可以防止输入pos为负值的情形
	//后一个用来防止输入pos大于链表长度的情形 
	if(i>pos || NULL == p->pNext){
		return false;
	}
	
	pNode pTmp = p->pNext;
	*DataInsert = pTmp->Data;
	p->pNext = p->pNext->pNext;
	free(pTmp);
	pTmp = NULL;
	
	return true;
} 

//销毁链表
//返回值表示是否删除成功 
bool destory_list(pNode *ppHead) {
	
	assert(ppHead != NULL);
	assert(*ppHead != NULL);
	
	pNode pTemp = NULL;
	//从头节点开始，逐个释放链表 
	while((*ppHead) != NULL) {
		pTemp = (*ppHead);
		(*ppHead) = (*ppHead)->pNext;
		free(pTemp);
	}
	*ppHead = NULL;

	return true;
}






