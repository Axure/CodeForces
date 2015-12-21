#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int MAXN=100000;

struct union_find{
 private:
  int element[MAXN+2];
  int ancestor(int n)
  {
    if (!element[n]) return n;
    if (element[n]==n) return n;
    return element[n]=ancestor(element[n]);
  }
 public:
  bool judge(int x,int y)
  {
    return ancestor(x)==ancestor(y);
  }
  void combine(int x,int y)
  {
    if (!judge(x,y)) element[ancestor(x)]=ancestor(y);
  }
};

struct edge{
  int from,to;
  long long int distance;
};

struct edge_cmp{
  bool operator()(edge a,edge b)
  {
    return a.distance>=b.distance;
  }
};

struct graph{
 private:
//int distance[MAXN+2][MAXN+2];
  union_find mst;
  priority_queue<edge,vector<edge>,edge_cmp> edge_set;
 public:
/*graph()
{
memset(distance,0,sizeof(distance));
}*/
  void scan(int n,int m)
  {
    int count;
/*
for (countx=1;countx<=m;countx++){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
if ((distance[a][b]&&c<distance[a][b])||!distance[a][b]) distance[a][b]=c;
}*/
    for (count=1;count<=m;count++){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      edge_set.push({a,b,c});
      edge_set.push({b,a,c});
    }
  }
  long long int kruskal()
  {
    long long int ans=0;
    while (!edge_set.empty()){
      edge cur=edge_set.top();
      edge_set.pop();
      if (!mst.judge(cur.from,cur.to)){
        ans+=cur.distance;
        mst.combine(cur.from,cur.to);
      }
    }
    return ans;
  }
};//以上内容经优化以后可以用来去实现图的功能，如spfa，dijstra等

graph i;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  i.scan(n,m);
  printf("%lld",i.kruskal());
  return 0;
}

