#ifndef _ZYSORTALGORITHM_H_
#define _ZYSORTALGORITHM_H_

typedef int ElemType, *pElemType;//如果需要排序的是浮点型，只需要改类型即可 

//快速排序 
void quick_sort(pElemType ArrData, int Low, int High);

#endif
