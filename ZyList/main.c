#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ZyList.h"

int main()
{
	pNode pHead = create_list();

	back_insert_list(pHead, 5);
	back_insert_list(pHead, 7);
	back_insert_list(pHead, 6);
	
	front_insert_list(pHead, 9);
	front_insert_list(pHead, 8);
	front_insert_list(pHead, 10);
	
	traverse_list(pHead);
	sort_list(pHead);
	traverse_list(pHead);
	int DataGet = 0;
	int pos = -1;
	if(get_elem_list(pHead, pos, &DataGet)){
		printf("λ��%d����Ԫ��Ϊ��%d\n",pos,DataGet);
	}
	else{
		printf("Error!\n");
	}
	
	if(insert_list(pHead,-1,100)){
		printf("True!\n");
	}
	else{
		printf("False!\n");
	}
	traverse_list(pHead);
	
	ElemType RetVal = 0;
	if(pop_list(pHead, 6, &RetVal)){
		printf("Return Value: %d\n", RetVal);
	}
	else{
		printf("False!\n");
	}
	traverse_list(pHead);
//	
//	if(front_pop_list(pHead, &RetVal)){
//		printf("Return Value: %d\n", RetVal);
//	}
//	printf("������Ϊ��%d��\n",len_list(pHead));	
//	traverse_list(pHead);
//	
//	if(front_pop_list(pHead, &RetVal)){
//		printf("Return Value: %d\n", RetVal);
//	}	
//	printf("������Ϊ��%d��\n",len_list(pHead));
//	traverse_list(pHead);
//	
//	if(back_pop_list(pHead, &RetVal)){
//		printf("Return Value: %d\n", RetVal);
//	}	
//	printf("������Ϊ��%d��\n",len_list(pHead));
//	traverse_list(pHead);
//	
//	if(back_pop_list(pHead, &RetVal)){
//		printf("Return Value: %d\n", RetVal);
//	}	
//	printf("������Ϊ��%d��\n",len_list(pHead));
//	traverse_list(pHead);
//	
//	if(back_pop_list(pHead, &RetVal)){
//		printf("Return Value: %d\n", RetVal);
//	}	
//	printf("������Ϊ��%d��\n",len_list(pHead));
//	traverse_list(pHead);
	
	//�������� 
	destory_list(&pHead);
	if(NULL == pHead){
		printf("ɾ���ɹ���\n");
	} 
	return 0;
}


