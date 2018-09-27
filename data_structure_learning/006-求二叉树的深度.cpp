int getDepth(BTNode * root) {
	int LD, RD;
	if (root == NULL) {
		return 0;
	} else {
		LD = getDepth(root -> lchild);
		RD = getDepth(root -> rchild);
		return (LD > RD ? LD : RD) + 1;
	} 
}