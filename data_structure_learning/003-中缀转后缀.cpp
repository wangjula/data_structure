//中缀转后缀
bool postfix(char[] exp) {
	char * p = exp;
	char ch1, ch2, op;
	stack<char> S;
	ch1 = '#';
	S.Push(ch1);
	while (!S.IsEmpty() && *p != '#') {
		if (isdigit(*p)) {
			cout << *p;
			++ p;
		} else {
			ch2 = S.getTop;
			if (isp(ch2) < icp(*p)) {
				S.Push(*p);
				++ p;
			} else if (isp(ch2) > icp(*p)) {
				S.Pop(op);
				cout << op;
				++ p;
			} else {
				S.Pop(op);
				if (op == '(') {
					++ p;
				} else {
					return false;
				}
			}
		}
	}
	return true;
}