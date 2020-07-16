#include <stdio.h>

#include "ZyStaticStack.h"

int main(int argc, char** argv) {
	int Size = 4;//栈的大小 
	pStack pAddrStack = create_stack(Size);
	if(is_empty_stack(pAddrStack)){
		printf("这是空栈\n");
	}
	traverse_stack(pAddrStack);
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	
	//压栈 
	if(push_stack(pAddrStack, 1)){
		traverse_stack(pAddrStack);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 2)){
		traverse_stack(pAddrStack);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 3)){
		traverse_stack(pAddrStack);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));	
	if(is_full_stack(pAddrStack)){
		printf("这是满栈\n");
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 4)){
		traverse_stack(pAddrStack);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(is_full_stack(pAddrStack)){
		printf("这是满栈\n");
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(push_stack(pAddrStack, 5)){
		traverse_stack(pAddrStack);
	}
	else{
		printf("此栈已满！\n");
	} 

	//弹栈 
	ElemType RetVal = 0;
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(is_empty_stack(pAddrStack)){
		printf("这是空栈\n");
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	if(is_empty_stack(pAddrStack)){
		printf("这是空栈\n");
	}
	printf("当前栈可用大小为：%d\n", remain_size(pAddrStack));
	//此时已经是空栈，无法弹出 
	if(pop_stack(pAddrStack, &RetVal)){
		printf("RetVal = %d\n", RetVal);
	}
	else{
		printf("此栈已空！\n");
	} 

	//摧毁栈 
	destory_stack(&pAddrStack); 
	if(NULL == pAddrStack){
		printf("栈已被摧毁\n");
	}

	return 0;
}

