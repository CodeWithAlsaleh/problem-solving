#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using ll = long long;
using namespace std;

const ll N = 1e7 + 1;
const ll MOD = 1e9 + 7;

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

void fun(set<string> &first, set<string> &second)
{
    while (first.size() > 0)
    {
        string a = *first.begin(), b;
        first.erase(first.find(a));
        if (first.size() > 0)
        {
            b = *first.begin();
            first.erase(first.find(b));
        }
        else
        {
            b = *second.begin();
            second.erase(second.find(b));
        }
        cout << a << ' ' << b << '\n';
    }
}

void solve()
{
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    set<string> s;
    set<string> c;
    set<string> h;
    set<string> d;

    for (int i = 0; i < 2 * n; ++i)
    {
        string x;
        cin >> x;
        if (x[1] == 'S')
            s.insert(x);
        if (x[1] == 'H')
            h.insert(x);
        if (x[1] == 'C')
            c.insert(x);
        if (x[1] == 'D')
            d.insert(x);
    }

    int size = 0;

    if (trump == 'C')
    {
        size = c.size();
        size -= s.size() % 2;
        size -= h.size() % 2;
        size -= d.size() % 2;
    }
    if (trump == 'S')
    {
        size = s.size();
        size -= c.size() % 2;
        size -= h.size() % 2;
        size -= d.size() % 2;
    }
    if (trump == 'D')
    {
        size = d.size();
        size -= c.size() % 2;
        size -= h.size() % 2;
        size -= s.size() % 2;
    }
    if (trump == 'H')
    {
        size = h.size();
        size -= c.size() % 2;
        size -= s.size() % 2;
        size -= d.size() % 2;
    }

    if (size < 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    if (trump == 'C')
    {
        fun(s, c);
        fun(h, c);
        fun(d, c);
        fun(c, c);
    }
    if (trump == 'S')
    {
        fun(c, s);
        fun(h, s);
        fun(d, s);
        fun(s, s);
    }
    if (trump == 'D')
    {
        fun(s, d);
        fun(h, d);
        fun(c, d);
        fun(d, d);
    }
    if (trump == 'H')
    {
        fun(s, h);
        fun(c, h);
        fun(d, h);
        fun(h, h);
    }
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
