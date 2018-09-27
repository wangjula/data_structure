//算法思想：若二叉树不为空，递归计算左子树结点数为lc，右子树为rc，则总结点数为rc + rc + 1；若为空二叉树结点数为0
int allNodes(BTNode * root) {
	if (root != NULL) {
		int lc, rc;
		lc = allNodes(root -> lchild);
		rc = allNodes(root -> rchild);
		return lc + rc + 1;
	}
	return 0;
}

//算法2：设置一个全局计数器count，遍历结点，每访问结点一次，count++，最后count即为结点数
int count = 0;
int count(BTNode * root) {
	if (root != NULL) {
		count ++;
		count(root -> lchild);
		count(root -> rchild);
	}
}