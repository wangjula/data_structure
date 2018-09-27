//算法思想：空树的叶子结点数为0；若不为空，且无左、右子女说明是叶子可结点，
//否则递归计算左子树叶子结点数lc，右子树叶子结点数rc，总计叶子结点数即为rc + lc
int leafNodes(BTNode * root) {
	if (root != NULL) {
		int lc = 0, rc = 0;                                      //lc：左子树叶子结点数 rc：右子树结点数
		if (root -> lchild == NULL && root -> rchild == NULL) {
			return 1;
		}
		
		lc = leafNodes(root -> lchild);
		rc = leafNodes(root -> rchild);
		return lc + rc;
	}
	return 0;
}

//算法2:也可使用全局计数器n, 遍历二叉树，仅当结点为叶子结点时，n++，最后n即为叶子结点数
int n = 0;
void count(BTNode * root) {
	if (root != NULL) {
		if (root -> lchild == NULL && root -> rchild == NULL) {
			++ n;
		}
		count(root -> lchild);
		count(root -> rchild);
	}
}