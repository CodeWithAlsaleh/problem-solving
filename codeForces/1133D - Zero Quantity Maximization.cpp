// The idea is to use long double instead of double
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

typedef tree<
    pair<ll, int>,
    null_type,
    greater<pair<ll, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

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

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &it : a)
        cin >> it;
    for (auto &it : b)
        cin >> it;

    // We have to use ld here instead of double cuz ld can store
    // more digits after the decimal point so in case of double
    // which will make our calculations more accurate
    unordered_map<ld, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            if (b[i] == 0)
                cnt++;

            continue;
        }

        ld val = ld(b[i]) / a[i];
        mp[-val]++;
    }

    int mx = 0;

    for (auto [a, b] : mp)
        mx = max(mx, b);

    cout << mx + cnt;
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
