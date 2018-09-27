//图深度优先搜索：通过递归回溯遍历
//可能回溯，为了避免重复访问，使用visited[]表示访问过的顶点
void DFS(LGraph & G, char key) {
	int i, n, loc;

	n = G.NumberOfVertices();
	bool * visited = new bool[n];
	for (i = 0; i < n; ++ i) {
		visit[i] = false;
	}

	loc = G.getVertexPos(key);
	doDFS(G, loc, visited);
	delete [] visited;
}

void doDFS(LGraph & G, int v, bool visited[]) {
	cout << G.getValue(v) << endl;
	visited[v] = true;
	int w = getFirstNeighbor(v);
	while (w != -1) {
		if (visited[w] == false) {
			doDFS(G, w, visited);
		}
		w = G.getNextNeighbor(v, w);
	}
}