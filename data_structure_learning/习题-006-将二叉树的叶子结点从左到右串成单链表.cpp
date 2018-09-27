//算法思想，对于叶子结点，前中后三种遍历方式都从左到右访问，则只要判断是叶子结点，并加入链表即可
void createLinkedList(BTNode * root, BTNode *& head, BTNode *& tail) {
	if (root != NULL) {
		if (root -> lchild == NULL && root -> rchild == NULL) {
			if (head == NULL) {
				head = tail = root;
			} else {
				tail -> lchild = root;
				tail = root;
			}
		}
	}
	createLinkedList(root -> lchild, head, tail);
	createLinkedList(root -> rchild, head, tail);
}