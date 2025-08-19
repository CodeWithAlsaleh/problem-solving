// I can't prove why my code works
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cout << #x << " = " << x << '\n';
using ll = long long;
using ld = long double;
using namespace __gnu_pbds;
using namespace std;

const ll N = 1e7 + 1;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;

ll n, m;
vector<vector<int>> graph;
vector<int> vis;
int flag = 1;

void bfs(int node)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto it : graph[top])
        {
            /*
                Here we shouldn't return after finding a case where
                (graph[it].size() != 2) gives u true cuz we have to mark
                all nodes in that wrong component as visited so when our
                loop at solve fun check any node in this wrong component
                it will be marked as visited so we have to play it safe
            */
            if (graph[it].size() != 2)
                flag = 0;

            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    graph.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i] and graph[i].size() == 2)
        {
            flag = 1;
            bfs(i);
            ans += flag;
        }
    }
    cout << ans;
}

int main()
{
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
