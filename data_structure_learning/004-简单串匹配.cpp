int String::Find(String & subStr, int k) {
	int i, j;
	for (i = k; i < length - subStr.length; ++ i) {
		for (j = 0; j < subStr.length; ++ j) {
			if (subStr.ch[j] != ch[i + j]) {
				break;
			}
		}
		if (j == subStr.length) {
			return i;
		}
	}
	return -1;
}

//简单匹配，如果可以匹配返回开始匹配的坐标，否则返回-1
int find(String & str, String & subStr) {
	int i, j, k;
	i = j = k = 0;
	while (i < str.getLength() 
		&& j < subStr.getLength()) {
		if (str[i] == subStr[i]) {
			++ i;
			++ j;
		} else {
			j = 0;
			i = ++ k;
		}
	}
	if (j == subStr.getLength()) {
		return k;
	} else {
		return -1;
	}
}