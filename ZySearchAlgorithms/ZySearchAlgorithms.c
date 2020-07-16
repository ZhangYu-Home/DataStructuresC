#include "ZySearchAlgorithms.h"

//顺序查找（线性查找）
int linear_search(pElemType ArrData, int ArrLen, ElemType ObjElem){
	int i = 0;
	for(i = 0; i < ArrLen; ++i){
		if(ArrData[i] == ObjElem){
			return i;
		}
	}
	
	//如果没有找到，返回-1； 
	return -1;
}

//二分查找（折半查找） ，需保证数组为从小到大排列 
int binary_search(pElemType ArrData, int ArrLen, ElemType ObjElem){
	int Low = 0;
	int High = ArrLen-1;
	int Mid = (High+Low)/2;
	while(Low <= High){
		Mid = (High+Low)/2;
		if(ObjElem == ArrData[Mid]){
			return Mid;
		}
		else if(ObjElem <= ArrData[Mid]){
			High = Mid - 1;
		}
		else{
			Low = Mid + 1;
		}
	}
	//如果查找失败，返回-1； 
	return -1;
} 
