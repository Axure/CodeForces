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
    return a.weight < b.weight;
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

//  for (int i = 1; i <= n; ++i) {
//    cout << i << endl;
//    while(!edges[i].empty()) {
//      auto edge = edges[i].top();
//      cout << edge.start << edge.end << ", " << edge.weight << endl;
//      edges[i].pop();
//
//    }
//  }

  auto first_top_edge = edges[1].top();
  long long result_cost = 0;
  /**
   * Prim algorithm.
   *
   * Maintain a heap.
   *
   */
  priority_queue<edge, vector<edge>, edge_comparator> shortest_edges;
  bool if_vertex_known[100001] = {};

  if_vertex_known[1] = true;
  shortest_edges.push(first_top_edge);
  edges[1].pop();

  while (shortest_edges.size() < n - 1) {
//    cout << "SHortes edges esszie:" << shortest_edges.size() << endl;
//    getchar();
    /**
     * Get the shortest edge.
     */
    auto top_edge = shortest_edges.top();
    auto old_index = top_edge.start;
    auto target_index = top_edge.end;

    result_cost += top_edge.weight;
    /**
     * Mark the target vertex as known.
     */
    edge updated_edge;
    while (if_vertex_known[edges[old_index].top().end]) {
//      getchar();
//      cout << "edges old_index:" << endl;
//      cout << (edges[old_index]).size() << endl;
      (edges[old_index]).pop();
//      cout << (edges[old_index]).size() << endl;
    }
    updated_edge = edges[old_index].top();

    if_vertex_known[target_index] = true;
    while (if_vertex_known[edges[target_index].top().end]) {
//      getchar();
//      cout << "edges target_index:" << endl;
//      cout << (edges[target_index]).size() << endl;
//      cout << "edge to pop: "
//          << (edges[target_index].top().start) << ", "
//          << (edges[target_index].top().end) << ", "
//          << (edges[target_index].top().weight) << ", "
//          << endl;
      (edges[target_index]).pop();
//      cout << (edges[target_index]).size() << endl;
    }
    edge new_edge = edges[target_index].top();
//    getchar();
//    cout << "edges target_index 2:" << endl;
//    cout << (edges[target_index]).size() << endl;
    (edges[target_index]).pop();
//    cout << (edges[target_index]).size() << endl;
    /**
     * Update the known vertices.
     */
    shortest_edges.pop();
    shortest_edges.push(updated_edge);
    shortest_edges.push(new_edge);
  }

  cout << result_cost;

  return 0;
}