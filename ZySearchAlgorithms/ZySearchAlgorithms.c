#include "ZySearchAlgorithms.h"

//˳����ң����Բ��ң�
int linear_search(pElemType ArrData, int ArrLen, ElemType ObjElem){
	int i = 0;
	for(i = 0; i < ArrLen; ++i){
		if(ArrData[i] == ObjElem){
			return i;
		}
	}
	
	//���û���ҵ�������-1�� 
	return -1;
}

//���ֲ��ң��۰���ң� ���豣֤����Ϊ��С�������� 
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
	//�������ʧ�ܣ�����-1�� 
	return -1;
} 
