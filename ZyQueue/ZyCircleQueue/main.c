#include <stdio.h>
#include <stdlib.h>
#include "ZyCircleQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//创建队列 
	pQueue pAddrQueue = create_queue(4);
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//入队
	if(push_queue(pAddrQueue, 1)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//入队
	if(push_queue(pAddrQueue, 2)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//入队
	if(push_queue(pAddrQueue, 3)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//入队
	if(push_queue(pAddrQueue, 4)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue));
	//入队
	if(push_queue(pAddrQueue, 5)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue));
	
	
	//出队 
	ElemType RetVal = 0;
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("弹出的元素为：%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//出队 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("弹出的元素为：%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//出队 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("弹出的元素为：%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue)); 
	//出队 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("弹出的元素为：%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue));
	//出队 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("弹出的元素为：%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("队列为空！\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("队列为满！\n");
	}
	printf("当前队列可用空间为：%d\n",remain_size(pAddrQueue));
	 
	
	
	
	//摧毁队列 
	if(destory_queue(&pAddrQueue)){
		if(NULL == pAddrQueue){
			printf("队列摧毁成功！\n");
		}
	}
	return 0;
}

