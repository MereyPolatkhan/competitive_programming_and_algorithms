#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 500;
const int inf = 1e9;

int n, dist[N];
pair<int, int> g[N];

int get(int i, int j){
    return abs(g[i].first - g[j].first) + abs(g[i].second - g[j].second);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> g[i].first >> g[i].second;
    }

    dist[1] = 0;
    for(int i = 2;i <= n;i++) dist[i] = inf;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int cur = pq.top().second, d = pq.top().first;
        pq.pop();

        for(int to = 1;to <= n;to++){
            if(to != cur){
                if(max(d, get(cur, to)) < dist[to]){
                    dist[to] = max(d, get(cur, to));
                    pq.push(make_pair(dist[to], to));
                }
            }
        }
    }

    cout << dist[n] << '\n';
}