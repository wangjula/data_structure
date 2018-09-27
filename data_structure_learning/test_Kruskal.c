typedef struct {
	int va, vb;
	int w;
} Road;

//查找根结点
int getRoot(int a) {
	while (a != v[a]) {
		a = va[a];
		return a;
	}
}

//边按照权值排序
void sort(Road road[], int E) {
	Road temp;
	for (int i = 1; i < E; ++ i) {
		for (int j = E - 1; j >= i; -- j) {
			if (road[j - 1].w > road[j].w) {
				temp = road[j - 1];
				road[j - 1] = road[j];
				road[j] = temp;
			}
		}
	} 
}

//Kruskal算法
int getShortest(int N, Road road[]) {
	int v[N];
	int E = N - 1;
	int sum = 0;

	for (int i = 0; i < N; ++i) {
		v[i] = i;
	}

	sort(road, E);

	for (int i = 0; i < E; i ++) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			sum += road[i].w;
		}
	}
	return sum;
}

int main() {
	int N, va, vb;
	scanf("%d", &N);
	Road road[maxSize];
	for (int i = 0; i < N - 1; ++ i) {
		scanf("%d", &va);
		scanf("%d", &vb);
		-- va;                    //令结点从0开始编号，所以需要在输入的基础上减1
		-- vb;
		road[i].w = 1;
		road[i].va = va;
		road[i].vb = vb;
	}
	printf("%d\n", getShortest(N, road));
}