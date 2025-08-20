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
    ll k;
    cin >> k;
    string s = "codeforces";

    ll mul = 1;
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;

    for (int i = 0; i < 10; ++i)
        pq.push(make_pair(1, i));

    while (mul < k)
    {
        auto p = pq.top();
        pq.pop();

        mul /= p.first;
        p.first++;
        mul *= p.first;

        pq.push(p);
    }

    string ans = "";

    vector<int> v(10, 0);

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        v[p.second] = p.first;
    }

    for (int i = 0; i < 10; ++i)
    {
        char ch = s[i];

        for (int j = 0; j < v[i]; ++j)
            ans += ch;
    }

    cout << ans;
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
