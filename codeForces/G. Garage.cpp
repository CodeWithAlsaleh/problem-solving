#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cout << #x << " = " << x << '\n';
using ll = long long;
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
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 3 << '\n';
        return;
    }

    ll x = (n - 4) / 3;

    if (x * 3 + 4 == n)
    {
        cout << 8LL + (4LL * x);
        return;
    }

    double L = n, R = n;

    while (true)
    {
        L--;
        R++;

        if ((L - 4) / 3 == ll((L - 4) / 3))
        {
            int check = n - L;
            check--;
            ll ind = (L - 4) / 3;
            ll val = 8LL + (4LL * ind) + 1;

            while (check--)
                val += 2;

            cout << val;
            return;
        }
        else if ((R - 4) / 3 == ll((R - 4) / 3))
        {
            int check = R - n;
            check--;
            ll ind = (R - 4) / 3;
            ll val = 8LL + (4LL * ind) - 1;

            while (check--)
                val -= 2;

            cout << val;
            return;
        }
    }
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
