//操作符都在内部结点，数字都在叶子结点
//将一次运算分为两部分，左右子树为操作数，中间为操作符
int compute(BTNode * root) {
	int A, B;
	if (root != NULL) {
		if (root -> lchild != NULL && root -> rchild != NULL) {
			A = compute(root -> lchild);
			B = compute(root -> rchild);
			return op(root -> data, A, B);
		} else {
			root data - '0';
		}
		
	}
	return 0;
}