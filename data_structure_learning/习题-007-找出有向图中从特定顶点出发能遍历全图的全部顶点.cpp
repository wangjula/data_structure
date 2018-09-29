//问题描述：有向图中从特定顶点出发，能够遍历全图的顶点称为根顶点，打印所有根顶点
//算法思想：对所有顶点，依次调用深度优先遍历，如果是根顶点则直接打印
void DFS(LGraph & G, int v, bool visited[], int & sum) {
	sum ++;
	visited[v] = true;

	int w = G.getFirstNeighbor(v);
	while (w != -1) {
		if (visited[w] == false) {
			DFS(G, w, visited, sum);
		}
		w = G.getNextNeighbor(v, w);
	}
}

void print(LGraph & G) {
	int i, j, sum;
	int n = G.NumberOfVertices();
	bool * visited = new bool[n];

	for (i = 0; i < n; ++ i) {           //对每个顶点，依次深度遍历
		for (j = 0; j < n; ++ j) {
			visited[j] = false;
		}

		sum = 0;
		DFS(G, i, visited, sum);
		if (sum == n) {                  //若遍历的顶点数为n，表示全图被遍历，即根顶点
			cout << i << endl;
		}
	}
}