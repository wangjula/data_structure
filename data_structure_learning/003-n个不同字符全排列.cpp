//n个不同字符的全排列

void perm(char str[], int k, int n) {
	int i;
	if (k == 0) {
		for (i = 0; i < n; ++ i) {
			cout << str[i];
		}
	} else {
		for (i = 0; i <= k; ++ i) { //假设（k-1）个全排列已经完成，对于第k个元素可以依次交换到str[i]，在此基础上得到（k+1个）新排列
			swap(str[k], str[i]);
			perm(str, k - 1, n);
			swap(str[k], str[i]);
		}
		
	}
}

void swap(int & x, int & y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}