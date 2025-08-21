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

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    ll mn = *min_element(all(v));
    if (mn % 10 == 0)
    {
        for (auto it : v)
        {
            if (it != mn)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    if (mn % 10 == 5)
    {
        for (auto it : v)
        {
            if (it != mn and it != mn + 5)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    unordered_map<int, int> check;
    ll val = mn % 100;
    while (val <= 1000)
    {
        check[val]++;
        val += val % 10;
    }
    // for (auto [a, b] : check)
    //     cout << a << ' ';
    // cout << '\n';
    for (auto it : v)
    {
        if (it % 10 == 0 or it % 10 == 5)
        {
            cout << "NO\n";
            return;
        }
        ll val2 = it % 100;
        bool flag = false;
        while (val2 <= 109)
        {
            if (check[val2])
                flag = true;

            val2 += val2 % 10;
        }
        if (!flag)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    // int val = 1;
    // while (val < 1000)
    // {
    //     cout << val << '\n';
    //     val += val % 10;
    // }
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
