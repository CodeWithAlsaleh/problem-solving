#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using ll = long long;
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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> v;

    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        v.push_back(make_pair(x, 0));
    }

    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        v[i].second = x;
    }

    sort(all(v));

    vector<ll> places(n + 1, 0);

    int st = -1, en = -1;
    for (int i = 0; i < k; ++i)
    {
        auto p = v[i];
        places[p.first] = 1;

        if (st == -1)
            st = p.first;

        en = p.first;
    }

    vector<ll> values(n + 1, 0);

    int ind = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (places[i])
        {
            auto p = v[ind++];
            values[i] = p.second;
        }
    }

    vector<ll> v1(n + 1, oo);
    ll val = values[st];

    for (int i = st; i <= n; ++i)
    {
        if (places[i])
            val = min(val, values[i]);

        v1[i] = val;

        val++;
    }

    // for (auto it : v1)
    //     cout << it << ' ';
    // cout << '\n';

    vector<ll> v2(n + 1, oo);
    val = values[en];
    for (int i = en; i >= 1; --i)
    {
        if (places[i])
            val = min(val, values[i]);

        v2[i] = val;

        val++;
    }
    // for (auto it : v2)
    //     cout << it << ' ';
    // cout << '\n';

    vector<ll> ans;

    for (int i = 1; i <= n; ++i)
        ans.push_back(min(v1[i], v2[i]));

    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
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
