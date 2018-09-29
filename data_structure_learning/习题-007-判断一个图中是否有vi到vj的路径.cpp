//算法思想：采用广度优先遍历，从vi出发，若到达vj返回true，否则遍历完返回false
//图采用邻接矩阵表示
bool BFS(MGraph & G, int vi, int vj) {
	int i, w, u;
	int Queue[maxSize];
	int front = rear = 0;

	int n = G.NumberOfVertices();
	bool isFind = false;                           //返回标记，访问到vj返回true，否则返回false
	bool * visited = new bool[n];                  //visited表示已经被访问过
	for (i = 0; i < n; ++ i) {
		visited[i] = false;
	}

	visited[vi] = true;                            //vi入队，标记已经访问
	rear = (rear + 1) % maxSize;
	Queue[rear] = vi;

	while (rear != front) {                        
		front = (front + 1) % maxSize;
		u = Queue[front];                          
		if (u == vj) {                            //依次从队列取出顶点，若访问到vj，修改返回标记并跳出
			isFind = true;                        //否则继续访问相邻顶点，并入队                      
			break;
		}

		w = G.getFirstNeighbor(u);
		while (w != -1) {
			if (visited[w] == false) {	
				visited[w] = true;
				rear = (rear + 1) % maxSize;
				Queue[rear] = w;
			}
			w = G.getNextNeighbor(u, w);
		}
	} 
	delete [] visited;
	return isFind;
}