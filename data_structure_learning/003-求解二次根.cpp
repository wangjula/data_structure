//求解二次方根

//递归算法
float Sqrt_A1(float A, float p, float e) {
	if (fabs(p * p - A) >= e) {
		Sqrt_A1(A, (A +  A / p) / 2, e);
	}
	return p;
}

//非递归算法
float Sqrt_A2(float A, float p, float e) {
	while (fabs(p * p - A) >= e) {
		p = (A + A / p) / 2;
	}
	return p;
}