#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ZyList.h"

//�ú������ڴ�������������ֵΪ��ǰ�����ͷָ��
pNode create_list() {
	pNode pHead = (pNode)malloc(sizeof(Node));
	if (NULL == pHead) {
		printf("�ڴ治�㣬�������˳���\n");
		exit(-1);
	}
	pHead->pNext = NULL;
	return pHead;
}

//�˺������ڱ�������
void traverse_list(pNode pHead) {
	
	assert(pHead != NULL);
	
	if(!is_empty_list(pHead)){
		pNode pCur = NULL;
		printf("����Ϊ�� ");
		for (pCur = pHead->pNext; pCur != NULL; pCur = pCur->pNext) {
			printf("%d  ", pCur->Data);
		}
		printf("\n");
	}
	else{
		printf("����Ϊ�գ�\n");
	}
	
}

//��ȡ������λ��Ϊpos��������
bool get_elem_list(pNode pHead, int pos, ElemType* DataGet){
	
	assert(NULL != pHead);
	
	int i = 0;
	pNode p = pHead->pNext;
	
	while(NULL != p && i < pos){
		p = p->pNext;
		++i;
	}
	//��һ���ж�i>pos���Է�ֹ����posΪ��ֵ������
	//��һ��������ֹ����pos���������ȵ����� 
	if(i>pos || NULL == p){
		return false;
	}
	
	*DataGet = p->Data;
	
	return true;
}

//��������ͷ�巨
//����ֵ��ʾ�Ƿ����ɹ� 
bool front_insert_list(pNode pHead, ElemType Data) {
	
	assert(pHead != NULL);
	
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	if (NULL == pNewNode) {
		printf("�ڴ治�㣡\n");
		return -1;
	}
	pNewNode->Data = Data;
	pNewNode->pNext = pHead->pNext;
	pHead->pNext = pNewNode;

	return true;
}

//��������β�巨
//����ֵ��ʾ�Ƿ����ɹ� 
bool back_insert_list(pNode pHead, ElemType Data) {
	
	assert(pHead != NULL);
	
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	if (NULL == pNewNode) {
		printf("�ڴ治�㣡\n");
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

//�����ͷ��ɾ��
bool front_pop_list(pNode pHead, ElemType* pRetVal) {
	
	assert(pHead->pNext != NULL);
	
	*pRetVal = pHead->pNext->Data;
	pNode pTemp = pHead->pNext;
	pHead->pNext = pHead->pNext->pNext;
	free(pTemp);

	return true;
}

//�����β��ɾ��
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

//�ж��Ƿ�Ϊ������
//����1��ʾΪ�գ�0Ϊ�ǿ� 
bool is_empty_list(pNode pHead)
{
	assert(pHead != NULL);
	return (pHead->pNext == NULL);
}

//��ȡ������
int len_list(pNode pHead){
	assert(pHead != NULL);
	int Lenth = 0;
	while(pHead->pNext != NULL){
		Lenth++;
		pHead = pHead->pNext;
	}
		
	return Lenth;
}

//������������򣺴�С����
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

//�������posλ�ò���ֵ
bool insert_list(pNode pHead, int pos, ElemType DataInsert){
	
	int i = 0;
	pNode p = pHead;
	
	while(NULL != p && i < pos){
		p = p->pNext;
		++i;
	}
	//��һ���ж�i>pos���Է�ֹ����posΪ��ֵ������
	//��һ��������ֹ����pos���������ȵ����� 
	if(i>pos || NULL == p){
		return false;
	}
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL == pNew){
		printf("�ڴ治�㣡\n");
		exit(-1);
	}
	
	pNode pTmp = p->pNext;
	p->pNext = pNew;
	pNew->pNext = pTmp;
	pNew->Data = DataInsert;
	
	return true;
	
	
	
} 

//ɾ������posλ�õĽڵ� 
bool pop_list(pNode pHead, int pos, ElemType* DataInsert){
	
	int i = 0;
	pNode p = pHead;
	
	while(NULL != p->pNext && i < pos){
		p = p->pNext;
		++i;
	}
	//��һ���ж�i>pos���Է�ֹ����posΪ��ֵ������
	//��һ��������ֹ����pos���������ȵ����� 
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

//��������
//����ֵ��ʾ�Ƿ�ɾ���ɹ� 
bool destory_list(pNode *ppHead) {
	
	assert(ppHead != NULL);
	assert(*ppHead != NULL);
	
	pNode pTemp = NULL;
	//��ͷ�ڵ㿪ʼ������ͷ����� 
	while((*ppHead) != NULL) {
		pTemp = (*ppHead);
		(*ppHead) = (*ppHead)->pNext;
		free(pTemp);
	}
	*ppHead = NULL;

	return true;
}






