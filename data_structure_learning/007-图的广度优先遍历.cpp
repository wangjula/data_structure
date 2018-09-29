//图的广度优先遍历
void BFS(LGraph & G, char key) {
	int i, n;

	n = G.NumberOfVertices();             //visited[]标记顶点已经遍历过
	bool * visited = new bool[n];
	for (i = 0; i < n; ++ i) {
		visited[i] = false;
	}

	int loc = G.getVertexPos(key);
	doBFS(G, loc, visited);
	delete [] visited;
}

void doBFS(LGraph & G, int v, int visited[]) {      //图的广度优先遍历需使用一个队列
	int Queue[maxSize];
	int front = rear = 0;                           //声明队列
	int w, loc;

	cout << G.getValue(v) << endl;                  //访问第一个结点，并将其入队
	visited[v] = true;
	rear = (rear + 1) % maxSize;
	Queue[rear] = v;

	while (front != rear) {                         //使用队列记录访问过的顶点，用于出队时继续访问其邻接顶点
		front = (front + 1) % maxSize;              //依次出队元素
		loc = Queue[front];
		w = G.getFirstNeighbor(loc);                //依次访问邻接顶点，并将入队
		while (w != -1) {
			if (visited[w] == false) {
				cout << G.getValue(w) << endl;
				visited[w] = true;

				rear = (rear + 1) % maxSize;
				Queue[rear] = w;
			}
			w = G.getNextNeighbor(loc, w);
		}
	}
}