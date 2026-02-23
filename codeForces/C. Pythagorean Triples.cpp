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

const ll N = 1e7 + 1;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;

void solve()
{
  /*
    n <= 2 => -1

    n is odd => n² / 2, n² + 1
    n is even => n² / 4 - 1, n² / 4 + 1
  */
  ll n;
  cin >> n;

  if (n <= 2)
  {
    cout << -1;
    return;
  }

  if (n & 1)
    cout << n * n / 2LL << ' ' << n * n / 2LL + 1;
  else
    cout << n * n / 4LL - 1 << ' ' << n * n / 4LL + 1;
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
