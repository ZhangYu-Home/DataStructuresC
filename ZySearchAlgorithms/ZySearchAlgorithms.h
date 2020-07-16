#ifndef _ZYSEARCHALGORITHMS_H_
#define _ZYSEARCHALGORITHMS_H_

typedef int ElemType, *pElemType;//如果需要查找的是浮点型，只需要改类型即可 

//顺序查找（线性查找）
//该方法查找到的是数组中第一个与目标元素相同的位置 
int linear_search(pElemType ArrData, int ArrLen, ElemType ObjElem);

//二分查找（折半查找） ，需保证数组为从小到大排列 
int binary_search(pElemType ArrData, int ArrLen, ElemType ObjElem); 



#endif
