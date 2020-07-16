#include <stdio.h>
#include <stdlib.h>

#include "ZyBinaryTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	pTreeNode pRoot = create_binarytree();
	//ǰ��ݹ����
	printf("�ݹ�ǰ�������\n"); 
	pre_order_traverse_r(pRoot);
	//����ݹ���� 
	printf("�ݹ����������\n");
	in_order_traverse_r(pRoot);
	//����ݹ����
	printf("�ݹ���������\n");
	post_order_traverse_r(pRoot);
	//ǰ��ǵݹ����
	printf("�ǵݹ�ǰ�������\n");
	pre_order_traverse(pRoot);
	//����ǵݹ���� 
	printf("�ǵݹ����������\n");
	in_order_traverse(pRoot);
	//����ǵݹ����
	printf("�ǵݹ���������\n");
	post_order_traverse(pRoot);
	//����ǵݹ���� 
	printf("�ǵݹ���������\n");
	level_order_traverse(pRoot); 
	//�ݹ��ȡ������������
	printf("�ݹ��ȡ�����������ȣ�%d\n",get_max_depth_r(pRoot)); 
	//�ǵݹ��ȡ������������
	printf("�ǵݹ��ȡ�����������ȣ�%d\n",get_max_depth(pRoot)); 
	//�ݹ��ȡ��������С���
	printf("�ݹ��ȡ��������С��ȣ�%d\n",get_min_depth_r(pRoot)); 
	//�ǵݹ��ȡ��������С���
	printf("�ǵݹ��ȡ��������С��ȣ�%d\n",get_min_depth(pRoot)); 
	
	
	
	return 0;
}
