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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  ll sum1 = 0, sum2 = 0, ans1 = 0, ans2 = 0;
  int L = 0;

  // change a
  for (int i = 0; i < n; ++i)
  {
    if (s[i] == 'a')
      sum1++;
    else
      sum2++;

    while (sum1 > k)
    {
      if (s[L] == 'a')
        sum1--;
      else
        sum2--;

      L++;
    }

    ans1 = max(ans1, sum1 + sum2);
  }

  // change b
  sum1 = 0, sum2 = 0, L = 0;
  for (int i = 0; i < n; ++i)
  {
    if (s[i] == 'a')
      sum1++;
    else
      sum2++;

    while (sum2 > k)
    {
      if (s[L] == 'a')
        sum1--;
      else
        sum2--;

      L++;
    }

    ans2 = max(ans2, sum1 + sum2);
  }

  cout << max(ans1, ans2);
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
