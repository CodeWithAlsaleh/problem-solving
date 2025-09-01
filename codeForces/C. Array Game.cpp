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

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    if (k >= 3)
    {
        cout << 0 << '\n';
        return;
    }

    vector<ll> diff;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            diff.push_back(abs(v[i] - v[j]));
    }

    ll mn2 = *min_element(all(v));
    ll mn3 = *min_element(all(diff));

    if (k == 1)
    {
        cout << min(mn2, mn3) << '\n';
        return;
    }

    sort(all(v));

    ll mn = 1e18;

    for (int i = 0; i < diff.size(); ++i)
    {
        ll val = diff[i];
        int ind = lower_bound(all(v), val) - v.begin();
        if (ind == n)
            mn = min(mn, abs(val - v[ind - 1]));
        else if (ind == 0)
            mn = min(mn, abs(val - v[ind]));
        else
        {
            ll check1 = abs(val - v[ind]);
            ll check2 = abs(val - v[ind - 1]);
            mn = min(mn, min(check1, check2));
        }
    }

    cout << min(mn, min(mn2, mn3)) << '\n';
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
