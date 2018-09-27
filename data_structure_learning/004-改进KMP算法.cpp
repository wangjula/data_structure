//算法思想：
//若ch[j]与ch[next[j]]相等，则与ch[next[j]]的比较不必要，而是应该直接转向next[next[j]]，记为nextval[j] = next[next[j]];
//依次类推，ch[j]应该与next[next[...]]位置上与ch[j]不相等的元素比较，记为nextval[j] = next[next[...]];
//若next[j] == -1表示已经回溯到最前，将nextval[j]设为-1即可
void String::getNextval(int nextval[]) {
	int j = 0, k = -1;
	while (j < length) {
		if (k == -1 || ch[j] == ch[k]) {
			++ j;
			++ k;
			if (ch[j] != ch[k]) {
				nextval[j] = k;
			} else {
				nextval[j] = nextval[k];       //计算nextval[k]时，next[k-1], next[k-2]...必已经求得
			}
		} else {
			k = nextval[k];
		}
	}
}