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

struct Mint
{
    int v;
    Mint() : v(0) {}
    Mint(ll _v) { v = int((_v % MOD + MOD) % MOD); }

    Mint &operator+=(const Mint &other)
    {
        v += other.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    Mint &operator-=(const Mint &other)
    {
        v -= other.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    Mint &operator*=(const Mint &other)
    {
        v = int((ll)v * other.v % MOD);
        return *this;
    }
    friend Mint power(Mint a, ll p)
    {
        Mint res = 1;
        while (p > 0)
        {
            if (p & 1)
                res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    Mint inv() const
    {
        return power(*this, MOD - 2);
    }
    Mint &operator/=(const Mint &other)
    {
        return *this *= other.inv();
    }

    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }
    friend ostream &operator<<(ostream &os, const Mint &m) { return os << m.v; }
    friend istream &operator>>(istream &is, Mint &m)
    {
        ll x;
        is >> x;
        m = Mint(x);
        return is;
    }
};

int n;
vector<vector<int>> v;
vector<int> vis;
vector<int> ans;

void bfs(int root)
{
    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        int check = vis[top];

        for (auto &it : v[top])
        {
            q.push(it);
            check &= vis[it];
        }
        if (check)
            ans.push_back(top);
    }
}

void solve()
{
    cin >> n;
    v.assign(n, {});
    vis.resize(n);
    int root = -1;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x == -1)
        {
            root = i;
            continue;
        }

        x--;

        v[x].push_back(i);
        vis[i] = y;
    }
    // for (auto it : vis)
    //     cout << it << ' ';
    // cout << '\n';
    bfs(root);
    // cout << "HERE: " << ans.size() << '\n';

    if (ans.size() == 0)
    {
        cout << -1;
        return;
    }

    sort(all(ans));
    for (auto it : ans)
        cout << it + 1 << ' ';
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
