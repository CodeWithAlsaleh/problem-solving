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

void solve(istream &fin, ostream &fout)
{
    int n;
    cin >> n;
    vector<int> uni(n);
    vector<ll> v(n);

    for (auto &it : uni)
        cin >> it;
    for (auto &it : v)
        cin >> it;

    unordered_map<int, vector<ll>> mp;

    for (int i = 0; i < n; ++i)
        mp[uni[i]].push_back(v[i]);

    for (auto &[a, b] : mp)
        sort(all(b));

    for (auto &[a, b] : mp)
    {
        // debug(a);
        for (int i = 1; i < b.size(); ++i)
            b[i] += b[i - 1];
        // cout << '\n';
    }

    for (int k = 1; k <= n; ++k)
    {
        if (!mp.size())
        {
            for (int i = k; i <= n; ++i)
                cout << 0 << ' ';
            break;
        }

        ll sum = 0;
        for (auto it = mp.begin(); it != mp.end();)
        {
            auto &b = it->second;

            if (k > b.size())
            {
                // We don't increase it here (it++) cuz erasing by iterator
                // will return the next iterator so we don't have to increase it
                it = mp.erase(it);
                continue;
            }

            int rem = b.size() % k;
            ll val = 0;

            if (rem > 0)
                val = b[rem - 1];

            sum += b.back() - val;
            it++;
        }
        cout << sum << ' ';
    }
    cout << '\n';
}

int main()
{
    ifstream fin("Round1.in");
    ofstream fout("Round1.out");
    FAST;
    int t = 1;
    cin >> t;
    // fin >> it;
    while (t--)
        solve(fin, fout);
    return 0;
}
