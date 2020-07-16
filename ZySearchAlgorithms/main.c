#include <stdio.h>

#include "ZySearchAlgorithms.h"

int main(int argc, char *argv[]){
	
	//顺序查找的测试 
	//ElemType ArrData[] = {5,4,6,3,7,8,4,9};
	//只有在当前文件定义的数组才可以这样测量长度 
	//int Lens = sizeof(ArrData)/sizeof(ArrData[0]);
	
	//int ElemPos = linear_search(ArrData,Lens,10);
	
	//二分查找的测试 
	ElemType ArrData[] = {3,4,5,6,7,8,9,10};
	//只有在当前文件定义的数组才可以这样测量长度 
	int Lens = sizeof(ArrData)/sizeof(ArrData[0]);
	
	int ElemPos = binary_search(ArrData,Lens,2);
	
	
	if(-1 == ElemPos){
		printf("目标元素不存在！\n");
	}
	else{
		printf("目标元素位置为：%d\n。", ElemPos);
	}
	
	return 0;
}
