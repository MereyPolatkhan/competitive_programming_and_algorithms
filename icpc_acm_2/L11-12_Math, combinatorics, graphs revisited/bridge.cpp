#include <iostream>
#include <vector>

int n, m;
std::vector<std::pair<int, int>> g[1000001];
bool marked[1000001];

int lvl[1000001], ch[1000001];

void dfs(int v, int level = 0, int parent_edge_id = -1)
{
    ch[v] = lvl[v] = level;
    marked[v] = true;
    bool is_vertex_point = true;
    int cnt_child = 0;

    for (const auto &i : g[v])
    {
        auto to = i.first;
        auto id = i.second;
        if (id == parent_edge_id)
        {
            continue;
        }

        // v -> to (back edge)
        if (marked[to] == true)
        {
            ch[v] = std::min(ch[v], lvl[to]);
        }
        else // v -> to (to is child)
        {
            cnt_child++;

            dfs(to, level + 1, id);
            ch[v] = std::min(ch[v], ch[to]);

            if (ch[to] > ch[v])
            {
                std::cout << "Bridge: " << v << " " << to << " id: " << id << '\n';
            }

            if (ch[to] < ch[v])
            {
                is_vertex_point = false;
            }
        }
    }
    if (cnt_child == 0)
    {
        is_vertex_point = false;
    }

    if (is_vertex_point == true)
    {
        std::cout << "Point: " << v << '\n';
    }
}

int main()
{
    std::cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    {
        std::cin >> u >> v; // u -> v, v -> u
        g[u].push_back(std::make_pair(v, i));
        g[v].push_back(std::make_pair(u, i));
    }
    for (int i = 1; i <= n; i++)
    {
        if (marked[i] == true)
        {
            continue;
        }
        dfs(i);
    }
    return 0;
}