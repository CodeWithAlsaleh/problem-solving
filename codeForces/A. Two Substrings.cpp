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

int mod(int ind, int n)
{
    return ind - n * (ind / n);
}

void solve()
{
    string s;
    cin >> s;

    vector<pair<int, int>> ab;
    vector<pair<int, int>> ba;

    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (s[i] == 'A' and s[i + 1] == 'B')
            ab.push_back(make_pair(i, i + 1));
        else if (s[i] == 'B' and s[i + 1] == 'A')
            ba.push_back(make_pair(i, i + 1));
    }

    if (ab.size() > ba.size())
        swap(ab, ba);

    int ind = ba.size() - 1;

    // Searching for non-overlapping choices
    for (int i = 0; i < ab.size(); ++i)
    {
        auto p = ab[i];
        auto p2 = ba[ind];
        if (p.first != p2.second and p.second != p2.first)
        {
            cout << "YES";
            return;
        }

        /*
            Use this formula to get the correct mod when it goes to neg numbers
            => (-1 % n = n - 1)
        */

        ind = mod(ind - 1, ba.size());
    }

    cout << "NO";
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
