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
unordered_map<ll, vector<ll>> mp;
vector<ll> ind;
map<pair<int, ll>, ll> dp;

ll dfs(int i, ll len)
{
    if (dp.find({i, len}) != dp.end())
        return dp[{i, len}];

    ll ans = len;
    for (auto &it : mp[len])
        ans = max(ans, dfs(it, it + len));

    return dp[{i, len}] = ans;
}

void solve()
{

    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    ind.assign(n, 0);
    dp.clear();
    mp.clear();
    ll ans = n;

    for (int i = 1; i < n; ++i)
    {
        ll val = v[i] + i + 1 - 1;
        ind[i] = val;
        mp[val].push_back(i);
    }

    for (int i = 1; i < n; ++i)
    {
        if (n == ind[i])
            ans = max(ans, dfs(i, n));
    }

    cout << ans << '\n';
}

int main()
{
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
