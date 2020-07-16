#ifndef _ZYBINARYTREE_H_
#define _ZYBINARYTREE_H_

//C99之后，引入了bool变量，使用时需包含如下的stdbool.h库
//如果使用的C语言为C99之前的版本，可以自定义bool变量，也可以用int型的0和1代替 
#include <stdbool.h>

typedef char TreeValType;

typedef struct TreeNode{
	TreeValType Data;
	struct TreeNode * Left;
	struct TreeNode * Right;
}TreeNode, *pTreeNode;

//创建二叉树 
pTreeNode create_binarytree();

//前序遍历二叉树——递归方式
//深度优先遍历 
void pre_order_traverse_r(pTreeNode pRoot);
//前序遍历二叉树——非递归方式
void pre_order_traverse(pTreeNode pRoot);

//中序遍历二叉树——递归方式
void in_order_traverse_r(pTreeNode pRoot);
//中序遍历二叉树——非递归方式
void in_order_traverse(pTreeNode pRoot); 

//后序遍历二叉树——递归方式
void post_order_traverse_r(pTreeNode pRoot);
//后序遍历二叉树——非递归方式
void post_order_traverse(pTreeNode pRoot);

//层序遍历——非递归方式实现 
//广度优先搜索，需要利用队列实现
//此处不使用递归方式实现，递归方式反而更复杂。
void level_order_traverse(pTreeNode pRoot); 

//求二叉树的最大深度——递归方式 
int get_max_depth_r(pTreeNode pRoot);

//求二叉树的最大深度——非递归方式 
//利用层序遍历方法 （另外，还可以利用前序遍历方式求解） 
int get_max_depth(pTreeNode pRoot);

//求二叉树的最小深度——递归方式 
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量 
int get_min_depth_r(pTreeNode pRoot);

//求二叉树的最小深度
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量 
int get_min_depth(pTreeNode pRoot);



#endif 


