#include <stdio.h>
#include <stdlib.h>
#include "ZyCircleQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//�������� 
	pQueue pAddrQueue = create_queue(4);
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���
	if(push_queue(pAddrQueue, 1)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���
	if(push_queue(pAddrQueue, 2)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���
	if(push_queue(pAddrQueue, 3)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���
	if(push_queue(pAddrQueue, 4)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue));
	//���
	if(push_queue(pAddrQueue, 5)){
		traverse_queue(pAddrQueue);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue));
	
	
	//���� 
	ElemType RetVal = 0;
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("������Ԫ��Ϊ��%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���� 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("������Ԫ��Ϊ��%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���� 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("������Ԫ��Ϊ��%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue)); 
	//���� 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("������Ԫ��Ϊ��%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue));
	//���� 
	if(pop_queue(pAddrQueue, &RetVal)){
		printf("������Ԫ��Ϊ��%d\n",RetVal);
	}
	if(is_empty_queue(pAddrQueue)){
		printf("����Ϊ�գ�\n");
	}
	if(is_full_queue(pAddrQueue)){
		printf("����Ϊ����\n");
	}
	printf("��ǰ���п��ÿռ�Ϊ��%d\n",remain_size(pAddrQueue));
	 
	
	
	
	//�ݻٶ��� 
	if(destory_queue(&pAddrQueue)){
		if(NULL == pAddrQueue){
			printf("���дݻٳɹ���\n");
		}
	}
	return 0;
}

