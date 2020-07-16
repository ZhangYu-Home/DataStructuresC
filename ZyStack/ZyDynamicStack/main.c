#include <stdio.h>
#include <stdlib.h>

#include "ZyDynamicStack.h"


int main(int argc, char *argv[]) {
	
	pStack pAddrStack = create_stack();
	
	printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	if(is_empty_stack(pAddrStack)){
		printf("当前栈为空栈！\n");
	}
	if(push_stack(pAddrStack, 1)){
		traverse_stack(pAddrStack);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	}
	if(is_empty_stack(pAddrStack)){
		printf("当前栈为空栈！\n");
	}
	if(push_stack(pAddrStack, 2)){
		traverse_stack(pAddrStack);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	} 
	if(push_stack(pAddrStack, 3)){
		traverse_stack(pAddrStack);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	} 
	if(push_stack(pAddrStack, 4)){
		traverse_stack(pAddrStack);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	} 
	
	ElemType RetVal = 0;
	if(pop_stack(pAddrStack, &RetVal)){
		printf("栈中弹出的值为：%d\n", RetVal);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("栈中弹出的值为：%d\n", RetVal);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("栈中弹出的值为：%d\n", RetVal);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	}
	if(is_empty_stack(pAddrStack)){
		printf("当前栈为空栈！\n");
	}
	if(pop_stack(pAddrStack, &RetVal)){
		printf("栈中弹出的值为：%d\n", RetVal);
		printf("当前动态栈长度为：%d\n",len_stack(pAddrStack));
	}
	if(is_empty_stack(pAddrStack)){
		printf("当前栈为空栈！\n");
	}
	
	destory_stack(&pAddrStack);
	if(NULL == pAddrStack){
		printf("当前动态栈已被摧毁！\n");
	}
	
	return 0;
}

