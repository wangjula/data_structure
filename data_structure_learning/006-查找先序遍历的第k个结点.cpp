//操作第k个结点，每访问一个结点，k减1，至k=0
BTNode * travelk(BTNode * root, int & k) {
	if (root != NULL) {
		-- k;
		if (k == 0) {
			return root;
		} else {
			travelk(root -> lchild, k);
			if (k != 0) {
				travel(root -> lch );
			}
		}
	}
	return NULL;
};