#include "ZySortAlgorithms.h"

//快速排序
void quick_sort(pElemType ArrData, int Low, int High){
	//当前需要排序的数据多于一个 
	if(Low < High){
		ElemType TmpData = ArrData[Low];
		int i = Low;
		int j = High;
		while(i < j){
			while(i < j && ArrData[j] >= TmpData){
				j--;
			}
			ArrData[i] = ArrData[j];
			while(i < j && ArrData[i] < TmpData){
				i++;
			}
			ArrData[j] = ArrData[i];
		} 
		ArrData[i] = TmpData;
		//采用递归形式，即分治策略 
		quick_sort(ArrData, Low, i-1);
		quick_sort(ArrData, i+1, High);
	}
	else{
		return; 
	}
}


