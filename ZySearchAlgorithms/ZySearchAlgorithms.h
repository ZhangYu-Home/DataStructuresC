#ifndef _ZYSEARCHALGORITHMS_H_
#define _ZYSEARCHALGORITHMS_H_

typedef int ElemType, *pElemType;//�����Ҫ���ҵ��Ǹ����ͣ�ֻ��Ҫ�����ͼ��� 

//˳����ң����Բ��ң�
//�÷������ҵ����������е�һ����Ŀ��Ԫ����ͬ��λ�� 
int linear_search(pElemType ArrData, int ArrLen, ElemType ObjElem);

//���ֲ��ң��۰���ң� ���豣֤����Ϊ��С�������� 
int binary_search(pElemType ArrData, int ArrLen, ElemType ObjElem); 



#endif
