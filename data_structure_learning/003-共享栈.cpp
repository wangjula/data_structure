class SeqStack {
private:
	int maxSize;
	int elem[maxSize];
	int top0;
	int top1;
public:
	SeqStack(int sz);
	~SeqStack();
	bool Push(int stNo, int & x);
	bool Pop(int stNo, int & x);
};

bool SeqStack::Pop(int stNo, int & x) {
	if (top0 + 1 < top1) {                    //判断栈不满
		if (stNo == 0) {                      //入栈s0
			elem[++ top0] = x;
			return true;
		} else if (stNo == 1) {               //入栈s1
			elem[-- top1] = x;
			return true;
		}
	}
	return false;
}

bool SeqStack::Push(int stNo, int & x) {
	if (stNo == 0 && top0 > 0) {                    //判断s0不为空
		x = elem[top0 --];                          //s0出栈
		return true;
	} else if (stNo == 1 && top1 < maxSize - 1) {   //判断s1不为空
		x = elem[top1 ++];                          //s1出栈
		return true;
	}
	return false;
}