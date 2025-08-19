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
  ll n;
  cin >> n;
  vector<int> a(n + 1, 0);
  vector<int> b(n + 1, 0);
  vector<int> c(n + 1, 0);
  vector<int> d(n + 1, 0);
  a[1] = 1;
  b[1] = 1;
  c[1] = 1;

  for (int i = 2; i <= n; ++i)
  {
    ll aa = a[i - 1], bb = b[i - 1], cc = c[i - 1], dd = d[i - 1];

    a[i] = (bb + cc + dd) % MOD;
    b[i] = (aa + cc + dd) % MOD;
    c[i] = (aa + bb + dd) % MOD;
    d[i] = (aa + bb + cc) % MOD;
  }

  cout << d[n];
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
