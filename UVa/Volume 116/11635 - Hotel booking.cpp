#include <iostream>
#include <vector>
#include <queue>
#include <utility>

const int MAX = 10000 + 10;

bool hotel[MAX];
std::vector<std::pair<int, int> > graph_origin[MAX];
std::vector<std::pair<int, int> > graph_oneday[MAX];

struct dis {
	int idx, d;
	dis(int idx=0, int d=0) : idx(idx), d(d) {}
	bool operator < (const dis& in) const {
		return d > in.d;
	}
};


bool vis[MAX];
int dist[MAX];

bool relax(int start, int end, int d) {
	if (vis[end]) {return false;}

	int d_edge = dist[start] + d;
	if (dist[end] > d_edge) {
		dist[end] = d_edge;
		return true;
	}
	return false;
}
void dijkstra(int s, std::vector<std::pair<int, int> > graph[MAX]) {
	std::priority_queue<dis> heap;

	std::fill(vis, vis+MAX, false);
	std::fill(dist, dist+MAX, 1e9);
	dist[s] = 0;

	dis cur;
	heap.push(dis(s, 0));
	while(!heap.empty()) {
		cur = heap.top(); heap.pop();
		if (vis[cur.idx]) {continue;}
		vis[cur.idx] = true;

		for(int i=0;i<graph[cur.idx].size();++i) {
			std::pair<int, int> edge = graph[cur.idx][i];
			if (relax(cur.idx, edge.first, edge.second)) {
				heap.push(dis(edge.first, dist[edge.first]));
			}
		}
	}
}


int main(int argc, const char * argv[]) {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	std::ios_base::sync_with_stdio(false);

	int N;
	while(std::cin >> N && N != 0) {
		int h;
		std::cin >> h;

		std::fill(hotel, hotel+MAX, false);
		for(int i=0;i<h;++i) {
			int c;
			std::cin >> c;
			hotel[c] = true;
		}
		hotel[1] = hotel[N] = true;

		int m, a, b, t;
		std::cin >> m;
		for(int i=1;i<=N;++i) {
			graph_origin[i].clear();
			graph_oneday[i].clear();
		}
		for(int i=0;i<m;++i) {
			std::cin >> a >> b >> t;
			graph_origin[a].push_back(std::pair<int, int>(b, t));
			graph_origin[b].push_back(std::pair<int, int>(a, t));
		}

		for(int i=1;i<=N;++i) {
			if (hotel[i]) {
				dijkstra(i, graph_origin);

				for(int j=1;j<=N;++j) {
					if (hotel[j] && dist[j] <= 600) {
						graph_oneday[i].push_back(std::pair<int, int>(j, 1));
					}
				}
			}

		}

		dijkstra(1, graph_oneday);
		if (dist[N] == 1e9) {
			std::cout << -1 << std::endl;
		} else {
			std::cout << dist[N] - 1 << std::endl;
		}
	}
	return 0;
}
