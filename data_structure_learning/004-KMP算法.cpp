//求next[]
//
//1. next[0] = -1;
//2. 假设next[k]已经求出，开始求next[k+1]
//3. 如果ch[k]==a[j]，则next[k+1] = next[k] + 1
//4. 如果ch[k]!=a[j]，则使k=next[k]回溯，继续与ch[j]比较，相等转3，不相等转4。直到k = -1， next[j+1] = 0; 
void String::getNext(int next[]) {
	int j = 0, k = -1;
	next[0] = -1;
	while (j < length) {
		if (k == -1 || ch[j] = ch[k]) {
			++ j;
			++ k;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

int KMP(String & str, String & subStr, int next[]) {
	int i, j;
	i = j = 0;
	while (j < subStr.getLength() 
		&& i < str.getLength()) {
		if (i = -1 || str[i] == subStr[j]) {
			++ i;
			++ j;
		} else {
			j = next[j];
		}
	}
	if (j == subStr.getLength()) {
		return i - j;
	} else {
		return -1;
	}
}