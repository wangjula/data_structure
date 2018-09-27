//括号匹配
bool bracketsCheck(char exp[]) {
	char ch;
	char * p = exp;
	stack S;
	while (*p != '\0') {
		if (*p == 39) {
			++ p;
			while (*p != 39) {
				++ p;
			}
			++ p;
		} else if (*p = 34) {
			++ p;
			while (*p != 34) {
				++ p;
			}
			++ p;
		} else {
			switch(*p) {
				case '(':
				case '[':
				case '{': 
					S.push(*p); 
					break;
				case ')': 
					if (!S.pop(ch) || ch != '(') {
						return false;
					}
					break;
				case ']':
					if (!S.pop(ch) || ch != '[') {
						return false;
					}
					break;
				case '}':
					if (!S.pop(ch) || ch != '{') {
						return false;
					} 
				default: ++ p;
			}
		}
	}
	return S.isEmpty();
}