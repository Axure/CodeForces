#include <iostream>
// Prim algorithm

#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
  int start, end;
  int weight;

  struct edge operator = (const struct edge& b) {
    this->start = b.start;
    this->end = b.end;
    this->weight = b.weight;

    return *this;
  }
} edge;

class edge_comparator {
 public:
  bool operator()(edge a, edge b) {
    return a.weight >= b.weight;
  }
};

typedef priority_queue<edge, vector<edge>, edge_comparator> edge_set;

int main(int argc, char *argv[]) {

  edge_set edges[100001];
  int n, m;
  cin >> n >> m;

  edge edge_template;

  int a, b, c;
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b >> c;

    edge_template.start = a;
    edge_template.end = b;
    edge_template.weight = c;
    edges[a].push(edge_template);

    edge_template.start = b;
    edge_template.end = a;
    edges[b].push(edge_template);

  }

  long long result_cost = 0;
  /**
   * Prim algorithm.
   *
   * Maintain a heap.
   *
   */
//  priority_queue<edge, vector<edge>, edge_comparator> shortest_edges;
  bool if_vertex_known[100001] = {};
  int known_count = 0;
  vector<int> known_vertices;

  if_vertex_known[1] = true;
  known_count += 1;
  known_vertices.push_back(1);

  while (known_count < n) {
    /**
     * Get the shortest edge.
     */
    edge top_edge;
    top_edge.weight = -1;
    for (vector<int>::iterator it = known_vertices.begin(); it != known_vertices.end(); ++it) {
      while (!(edges[*it].empty()) && if_vertex_known[edges[*it].top().end]) {
        edges[*it].pop();
      }
      if (!(edges[*it].empty())) {
        if (top_edge.weight == -1 ||  top_edge.weight > edges[*it].top().weight) {
          top_edge = edges[*it].top();
        }
      }
    }
    int target_index = top_edge.end;
    /**
     * Mark the target vertex as known.
     */
    if_vertex_known[target_index] = true;
    known_count += 1;
    known_vertices.push_back(target_index);
//    cout << top_edge.start << " " << top_edge.end << " " << top_edge.weight << " " << endl;
    result_cost += top_edge.weight;
  }

  cout << result_cost;

  return 0;
}