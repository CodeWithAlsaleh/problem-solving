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
ll Mod = 998244353;
const ll N = 2e5 + 5;

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<ll> cnt(32, 0);
    for (int x : a) 
    {
        for (int b = 0; b < 32; b++)
        {
            if((x >> b) & 1)
                cnt[b]++;
        }
    }
    
    ll best = -1;

    for (int x : a)
    {
        ll total = 0;
        for (int b = 0; b < 32; b++)
        {
            if((x >> b) & 1)
                total += (n - cnt[b]) * pow(2 , b);
            else 
                total += cnt[b] * pow(2 , b);
        }

        if(total > best) 
            best = total;
    }
    
    cout << best << "\n";
}

int main() {
    FAST;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
