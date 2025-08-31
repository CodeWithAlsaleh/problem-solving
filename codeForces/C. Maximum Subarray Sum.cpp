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

ll getSum(vector<ll> &v)
{
    ll sum = 0, ans = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        sum += v[i];
        sum = max(sum, 0LL);
        ans = max(ans, sum);
    }

    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(n);

    for (auto &it : v)
        cin >> it;

    int ind = -1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        if (getSum(v) == k)
        {
            cout << "Yes\n";
            for (auto it : v)
                cout << it << ' ';
            cout << '\n';
        }
        else
            cout << "No\n";
        return;
    }

    int L = ind - 1, R = ind + 1;
    ll mxL = 0, mxR = 0;
    ll sumL = 0, sumR = 0;
    while (L >= 0 and s[L] == '1')
    {
        sumL += v[L];
        mxL = max(mxL, sumL);
        L--;
    }

    while (R < n and s[R] == '1')
    {
        sumR += v[R];
        mxR = max(mxR, sumR);
        R++;
    }

    ll val = k;
    val -= max(mxR, 0LL);
    val -= max(mxL, 0LL);

    v[ind] = val;
    s[ind] = '1';

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            v[i] = -1e15;
    }

    if (getSum(v) == k)
    {
        cout << "Yes\n";
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
    }
    else
        cout << "No\n";
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
