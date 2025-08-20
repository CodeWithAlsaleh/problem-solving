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
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> v(n);

  for (int i = 0; i < n; ++i)
  {
    ll x, y, z;
    cin >> x >> y >> z;

    v[i] = make_tuple(x, y, z);
  }
  sort(all(v));
  ll prev = 0;
  ll mn = m, mx = m;

  for (int i = 0; i < n; ++i)
  {
    auto [x, y, z] = v[i];
    ll val = x - prev;
    prev = x;
    mn -= val;
    mx += val;

    /*
      max(mn, y) > min(mx, z)

      this is the same as doing

      bool check1 = mn <= y and mx >= y;
      bool check2 = mn <= z and mx >= z;
      bool check3 = y <= mn and z >= mn;
      bool check4 = y <= mx and z >= mx;
    */

    if (max(mn, y) > min(mx, z))
    {
      cout << "NO\n";
      return;
    }

    mn = max(mn, y), mx = min(mx, z);
  }

  cout << "YES\n";
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
