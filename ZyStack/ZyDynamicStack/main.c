#include <stdio.h>
#include <stdlib.h>

#include "ZyDynamicStack.h"


int main(int argc, char *argv[]) {
	
	pStack pAddrStack = create_stack();
	
	printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	if(is_empty_stack(pAddrStack)){
		printf("��ǰջΪ��ջ��\n");
	}
	if(push_stack(pAddrStack, 1)){
		traverse_stack(pAddrStack);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	}
	if(is_empty_stack(pAddrStack)){
		printf("��ǰջΪ��ջ��\n");
	}
	if(push_stack(pAddrStack, 2)){
		traverse_stack(pAddrStack);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	} 
	if(push_stack(pAddrStack, 3)){
		traverse_stack(pAddrStack);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	} 
	if(push_stack(pAddrStack, 4)){
		traverse_stack(pAddrStack);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	} 
	
	ElemType RetVal = 0;
	if(pop_stack(pAddrStack, &RetVal)){
		printf("ջ�е�����ֵΪ��%d\n", RetVal);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("ջ�е�����ֵΪ��%d\n", RetVal);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("ջ�е�����ֵΪ��%d\n", RetVal);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	}
	if(is_empty_stack(pAddrStack)){
		printf("��ǰջΪ��ջ��\n");
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("ջ�е�����ֵΪ��%d\n", RetVal);
		printf("��ǰ��̬ջ����Ϊ��%d\n",len_stack(pAddrStack));
	}
	if(is_empty_stack(pAddrStack)){
		printf("��ǰջΪ��ջ��\n");
	}
	
	destory_stack(&pAddrStack);
	if(NULL == pAddrStack){
		printf("��ǰ��̬ջ�ѱ��ݻ٣�\n");
	}
	
	return 0;
}

