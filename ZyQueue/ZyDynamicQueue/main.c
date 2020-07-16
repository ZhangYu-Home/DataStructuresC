#include <stdio.h>
#include <stdlib.h>

#include "ZyDynamicQueue.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//������̬���� 
	pQueue pAddrQueue = create_queue();
	//��֤�����Ƿ�Ϊ�� 
	if(is_empty_queue(pAddrQueue)){
		printf("���ǿն��У�\n");
	}
	printf("---------------------------------\n");
	//���
	int i = 0;
	for(i = 1; i < 5; ++i){
		if(push_queue(pAddrQueue, i)){
			traverse_queue(pAddrQueue);
		}
	} 
	printf("---------------------------------\n");
	//����
	ElemType RetVal = 0;
	for(i = 0; i < 4; ++i){
		if(pop_queue(pAddrQueue,&RetVal)){
			printf("����Ԫ��Ϊ��%d\n",RetVal);
		}
		if(is_empty_queue(pAddrQueue)){
			printf("���ǿն��У�\n");
		}
	}
	printf("---------------------------------\n");
	//���
	for(i = 5; i < 10; ++i){
		if(push_queue(pAddrQueue, i)){
			traverse_queue(pAddrQueue);
		}
	} 
	printf("---------------------------------\n");
	//����
	for(i = 0; i < 10; ++i){
		if(pop_queue(pAddrQueue,&RetVal)){
			printf("����Ԫ��Ϊ��%d\n",RetVal);
		}
		if(is_empty_queue(pAddrQueue)){
			printf("���ǿն��У�\n");
		}
	}
	printf("---------------------------------\n");
	
	//�ݻٶ��� 
	if(destory_queue(&pAddrQueue)){
		if(NULL == pAddrQueue){
			printf("���дݻٳɹ���\n");
		}
	}
	return 0;
}

