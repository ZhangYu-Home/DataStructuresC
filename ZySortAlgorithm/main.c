#include <stdio.h>
#include <stdlib.h>

#include "ZySortAlgorithms.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ElemType ArrData[] = {5,4,6,3,7,8,4,9};
	//ֻ���ڵ�ǰ�ļ����������ſ��������������� 
	int Lens = sizeof(ArrData)/sizeof(ArrData[0]);
	
	printf("����ǰ��");
	int i = 0;
	for(i = 0; i < Lens; ++i){
		printf("\t%d",ArrData[i]);
	}
	printf("\n");
	
	quick_sort(ArrData, 0, Lens-1);
	 
	printf("�����");
	for(i = 0; i < Lens; ++i){
		printf("\t%d",ArrData[i]);
	}
	printf("\n");
	
	return 0;
}
