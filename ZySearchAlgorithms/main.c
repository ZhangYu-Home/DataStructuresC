#include <stdio.h>

#include "ZySearchAlgorithms.h"

int main(int argc, char *argv[]){
	
	//˳����ҵĲ��� 
	//ElemType ArrData[] = {5,4,6,3,7,8,4,9};
	//ֻ���ڵ�ǰ�ļ����������ſ��������������� 
	//int Lens = sizeof(ArrData)/sizeof(ArrData[0]);
	
	//int ElemPos = linear_search(ArrData,Lens,10);
	
	//���ֲ��ҵĲ��� 
	ElemType ArrData[] = {3,4,5,6,7,8,9,10};
	//ֻ���ڵ�ǰ�ļ����������ſ��������������� 
	int Lens = sizeof(ArrData)/sizeof(ArrData[0]);
	
	int ElemPos = binary_search(ArrData,Lens,2);
	
	
	if(-1 == ElemPos){
		printf("Ŀ��Ԫ�ز����ڣ�\n");
	}
	else{
		printf("Ŀ��Ԫ��λ��Ϊ��%d\n��", ElemPos);
	}
	
	return 0;
}
