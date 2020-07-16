#include <stdio.h>

#include "ZyStaticStack.h"

int main(int argc, char** argv) {
	int Size = 4;//ջ�Ĵ�С 
	pStack pAddrStack = create_stack(Size);
	if(is_empty_stack(pAddrStack)){
		printf("���ǿ�ջ\n");
	}
	traverse_stack(pAddrStack);
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	
	//ѹջ 
	if(push_stack(pAddrStack, 1)){
		traverse_stack(pAddrStack);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 2)){
		traverse_stack(pAddrStack);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 3)){
		traverse_stack(pAddrStack);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));	
	if(is_full_stack(pAddrStack)){
		printf("������ջ\n");
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 4)){
		traverse_stack(pAddrStack);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(is_full_stack(pAddrStack)){
		printf("������ջ\n");
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 5)){
		traverse_stack(pAddrStack);
	}
	else{
		printf("��ջ������\n");
	} 

	//��ջ 
	ElemType RetVal = 0;
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(is_empty_stack(pAddrStack)){
		printf("���ǿ�ջ\n");
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	if(is_empty_stack(pAddrStack)){
		printf("���ǿ�ջ\n");
	}
	printf("��ǰջ���ô�СΪ��%d\n", remain_size(pAddrStack));
	//��ʱ�Ѿ��ǿ�ջ���޷����� 
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	else{
		printf("��ջ�ѿգ�\n");
	} 

	//�ݻ�ջ 
	destory_stack(&pAddrStack); 
	if(NULL == pAddrStack){
		printf("ջ�ѱ��ݻ�\n");
	}

	return 0;
}

