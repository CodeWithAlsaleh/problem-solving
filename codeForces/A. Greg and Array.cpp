#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using ll = long long;
using namespace std;

const ll N = 1e7 + 1;
const ll MOD = 1000000007;

struct Mint {
    int v;
    Mint(): v(0) {}
    Mint(ll _v) { v = int((_v % MOD + MOD) % MOD); }
 
    // Addition
    Mint& operator+=(const Mint& other) {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    // Subtraction
    Mint& operator-=(const Mint& other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }
    // Multiplication
    Mint& operator*=(const Mint& other) {
        v = int((ll)v * other.v % MOD);
        return *this;
    }
    // Fast exponentiation
    friend Mint power(Mint a, ll p) {
        Mint res = 1;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }
    // Modular inverse (only works if MOD is prime)
    Mint inv() const {
        return power(*this, MOD - 2);
    }
    // Division
    Mint& operator/=(const Mint& other) {
        return *this *= other.inv();
    }
 
    // Friends for operators
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.v; }
    friend istream& operator>>(istream& is, Mint& m) { ll x; is >> x; m = Mint(x); return is; }
};

void solve()
{
    int n , m , k; cin >> n >> m >> k;
    vector<ll> v(n);
    for(auto &it : v) cin >> it;
    vector<ll> diff(n + 1 , 0);
    vector<tuple<ll, ll , ll>> op;
    for(int i = 0 ; i < m ; ++i)
    {
        int l , r , d; cin >> l >> r >> d;
        op.push_back(make_tuple(l - 1 , r - 1 , d));
    }
    vector<ll> diff2(m + 1 , 0);
    for(int i = 0 ; i < k ; ++i)
    {
        int l , r; cin >> l >> r;
        l--;
        r--;
        diff2[l]++;
        diff2[r + 1]--;
    }

    vector<ll> arr(m , 0);
    arr[0] = diff2[0];
    for(int i = 1; i < m ; ++i)
     arr[i] = arr[i-1] + diff2[i];

    for(int i = 0 ; i < m ; ++i)
    {
        ll val = arr[i];
        auto [x,y,d] = op[i];
        ll val2 = d * val;
        diff[x] += val2;
        diff[y + 1] -= val2;
    }

    vector<ll> v2(n);
    v2[0] = diff[0];

    for(int i = 1 ; i < n ; ++i)
        v2[i] = v2[i-1] + diff[i];

    for(int i = 0 ; i < n ; ++i)
     v[i] += v2[i];

    for(auto it : v) cout<<it<<' ';
}

int main() {
    FAST;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
