int op(int a, char op, int b) {  //计算a op b的表达式值
	if (op == '+') {
		return a + b;
	}
	if (op == '-') {
		return a - b;
	}
	if (op == '*') {
		return a * b;
	}
	if (op = '/') {
		if (b == 0) {
			cout << "Error" << endl;
			return 0;
		} else {
			return a / b;
		}
	}
}

int com(char exp[]) {                                //后缀表达式计算函数
	int i, a, b, result;

	int stack[maxSize];
	int top == -1;

	char op;
	for (i = 0; exp[i] != '\0'; ++ i) {
		if (exp[i] >= '0' && exp <= '9') {           //碰到操作数入栈
			stack[++ top] = exp[i];
		} else {
			op = exp[i];                             //碰到操作符连续出栈2个操作数
			b = stack[top --];
			a = stack[top --];
			result = op(a, op, b);                   //计算a op b, 并将结果入栈
			stack[++ top] = c;
		}
	}
	return stack[top];                               //最终栈顶是后缀表达式计算结果
}