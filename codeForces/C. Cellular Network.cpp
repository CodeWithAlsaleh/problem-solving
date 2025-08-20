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

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  vector<ll> b(m);

  for (auto &it : a)
    cin >> it;
  for (auto &it : b)
    cin >> it;

  ll ans = -1e9;

  for (int i = 0; i < n; ++i)
  {
    int ind = lower_bound(all(b), a[i]) - b.begin();

    if (ind == m)
      ans = max(ans, abs(a[i] - b[ind - 1]));
    else if (ind == 0)
      ans = max(ans, abs(a[i] - b[ind]));
    else
      ans = max(ans, min(abs(a[i] - b[ind]), abs(a[i] - b[ind - 1])));
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
