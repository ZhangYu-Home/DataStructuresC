#ifndef _ZYLIST_H_
#define _ZYLIST_H_ 

//C99�Ժ����ʹ��stdbool.h���������ѡ���Զ���bool���� 
#include <stdbool.h> 

//����ڵ���������Ԫ�ص����ͣ�����֮�󴴽��������͵�����ʱ�����޸ģ�
typedef int ElemType;
//����ڵ�����
typedef struct LinkNode
{
    ElemType Data;
    struct LinkNode *pNext;

} Node, *pNode;

//�ú������ڴ�����������ֵΪ��ǰ�����ͷָ��
pNode create_list();

//�˺������ڱ�������
void traverse_list(pNode pHead);

//��ȡ������λ��Ϊpos��������
bool get_elem_list(pNode pHead, int pos, ElemType* DataGet); 

//��������ͷ�巨
bool front_insert_list(pNode pHead, ElemType Data);

//��������β�巨
bool back_insert_list(pNode pHead, ElemType Data);

//�����ͷ��ɾ��
bool front_pop_list(pNode pHead, ElemType* pRetVal); 

//�����β��ɾ��
bool back_pop_list(pNode pHead, ElemType* pRetVal);

//�ж��Ƿ�Ϊ������
//����1��ʾΪ�գ�0Ϊ�ǿ� 
bool is_empty_list(pNode pHead);

//��ȡ������
int len_list(pNode pHead);

//������������򣺴�С����
bool sort_list(pNode pHead);

//�������posλ�ò���ֵ
bool insert_list(pNode pHead, int pos, ElemType DataInsert);

//ɾ������posλ�õĽڵ� 
bool pop_list(pNode pHead, int pos, ElemType* DataInsert);

//��������
bool destory_list(pNode *ppHead); 

#endif 


