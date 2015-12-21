#include <iostream>
// Prim algorithm

#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
  int start, end;
  int weight;
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

  edge first_top_edge = edges[1].top();
  long long result_cost = 0;
  /**
   * Prim algorithm.
   *
   * Maintain a heap.
   *
   */
  priority_queue<edge, vector<edge>, edge_comparator> shortest_edges;
  bool if_vertex_known[100001] = {};
  int known_count = 0;

  if_vertex_known[1] = true;
  known_count += 1;
  shortest_edges.push(first_top_edge);
  edges[1].pop();

  while (known_count < n) {
    /**
     * Get the shortest edge.
     */
    edge top_edge = shortest_edges.top();
    shortest_edges.pop();
    int old_index = top_edge.start;
    int target_index = top_edge.end;
    known_count += 1;
    cout << top_edge.start << " " << top_edge.end << " " << top_edge.weight << " " << endl;
    result_cost += top_edge.weight;
    /**
     * Mark the target vertex as known.
     */
    edge updated_edge;

    while (!(edges[old_index].empty())
        && if_vertex_known[edges[old_index].top().end]) {
      (edges[old_index]).pop();
    }
    if (!(edges[old_index].empty())) {
      updated_edge = edges[old_index].top();
      shortest_edges.push(updated_edge);
    }

    if_vertex_known[target_index] = true;

    while (!(edges[target_index].empty())
        && if_vertex_known[edges[target_index].top().end]) {
      (edges[target_index]).pop();
    }
    if (!(edges[target_index].empty())) {
      edge new_edge = edges[target_index].top();
      shortest_edges.push(new_edge);
      (edges[target_index]).pop();
    }
  }

  cout << result_cost;

  return 0;
}