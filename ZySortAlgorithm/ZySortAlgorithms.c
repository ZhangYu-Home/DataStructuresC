#include "ZySortAlgorithms.h"

//��������
void quick_sort(pElemType ArrData, int Low, int High){
	//��ǰ��Ҫ��������ݶ���һ�� 
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
		//���õݹ���ʽ�������β��� 
		quick_sort(ArrData, Low, i-1);
		quick_sort(ArrData, i+1, High);
	}
	else{
		return; 
	}
}


