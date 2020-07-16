#ifndef _ZYBINARYTREE_H_
#define _ZYBINARYTREE_H_

//C99֮��������bool������ʹ��ʱ��������µ�stdbool.h��
//���ʹ�õ�C����ΪC99֮ǰ�İ汾�������Զ���bool������Ҳ������int�͵�0��1���� 
#include <stdbool.h>

typedef char TreeValType;

typedef struct TreeNode{
	TreeValType Data;
	struct TreeNode * Left;
	struct TreeNode * Right;
}TreeNode, *pTreeNode;

//���������� 
pTreeNode create_binarytree();

//ǰ����������������ݹ鷽ʽ
//������ȱ��� 
void pre_order_traverse_r(pTreeNode pRoot);
//ǰ����������������ǵݹ鷽ʽ
void pre_order_traverse(pTreeNode pRoot);

//������������������ݹ鷽ʽ
void in_order_traverse_r(pTreeNode pRoot);
//������������������ǵݹ鷽ʽ
void in_order_traverse(pTreeNode pRoot); 

//������������������ݹ鷽ʽ
void post_order_traverse_r(pTreeNode pRoot);
//������������������ǵݹ鷽ʽ
void post_order_traverse(pTreeNode pRoot);

//������������ǵݹ鷽ʽʵ�� 
//���������������Ҫ���ö���ʵ��
//�˴���ʹ�õݹ鷽ʽʵ�֣��ݹ鷽ʽ���������ӡ�
void level_order_traverse(pTreeNode pRoot); 

//��������������ȡ����ݹ鷽ʽ 
int get_max_depth_r(pTreeNode pRoot);

//��������������ȡ����ǵݹ鷽ʽ 
//���ò���������� �����⣬����������ǰ�������ʽ��⣩ 
int get_max_depth(pTreeNode pRoot);

//�����������С��ȡ����ݹ鷽ʽ 
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ����� 
int get_min_depth_r(pTreeNode pRoot);

//�����������С���
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ����� 
int get_min_depth(pTreeNode pRoot);



#endif 


