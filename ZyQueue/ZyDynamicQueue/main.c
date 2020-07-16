#include <stdio.h>
#include <stdlib.h>

#include "ZyDynamicQueue.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//创建动态队列 
	pQueue pAddrQueue = create_queue();
	//验证队列是否为空 
	if(is_empty_queue(pAddrQueue)){
		printf("这是空队列！\n");
	}
	printf("---------------------------------\n");
	//入队
	int i = 0;
	for(i = 1; i < 5; ++i){
		if(push_queue(pAddrQueue, i)){
			traverse_queue(pAddrQueue);
		}
	} 
	printf("---------------------------------\n");
	//出队
	ElemType RetVal = 0;
	for(i = 0; i < 4; ++i){
		if(pop_queue(pAddrQueue,&RetVal)){
			printf("出队元素为：%d\n",RetVal);
		}
		if(is_empty_queue(pAddrQueue)){
			printf("这是空队列！\n");
		}
	}
	printf("---------------------------------\n");
	//入队
	for(i = 5; i < 10; ++i){
		if(push_queue(pAddrQueue, i)){
			traverse_queue(pAddrQueue);
		}
	} 
	printf("---------------------------------\n");
	//出队
	for(i = 0; i < 10; ++i){
		if(pop_queue(pAddrQueue,&RetVal)){
			printf("出队元素为：%d\n",RetVal);
		}
		if(is_empty_queue(pAddrQueue)){
			printf("这是空队列！\n");
		}
	}
	printf("---------------------------------\n");
	
	//摧毁队列 
	if(destory_queue(&pAddrQueue)){
		if(NULL == pAddrQueue){
			printf("队列摧毁成功！\n");
		}
	}
	return 0;
}

