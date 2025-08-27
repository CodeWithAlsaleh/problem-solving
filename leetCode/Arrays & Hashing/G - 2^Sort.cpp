#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include "bits/stdc++.h"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using ll = long long;
using namespace std;

const ll N = 4e5;
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



void solve() {
    int n , k; cin >> n >> k;
    k++;
    vector<ll> v(n);
    for(auto &it : v) cin >> it;

    vector<int> check(n , 1);
    check[0] = 0;
    for(int i = 1 ; i < n ; ++i)
    {
        if(v[i] > v[i-1] / 2)
         check[i] = 0;
    }
    int cnt = 0;
    int L = 0;
    int ans = 0;
    for(int i = 0 ; i < k ; ++i)
        cnt += check[i];

    if(cnt - check[0] <= 0)
     ans++;

    for(int i = k ; i < n ; ++i)
    {
        cnt -= check[L++];
        cnt += check[i];
        if(cnt-check[L] <= 0)
         ans++;
    }
    cout<<ans<<'\n';
}

int main() {
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
