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

vector<int> div(int n)
{
  vector<int> ans;

  for (int i = 1; i * i <= n; ++i)
  {
    if (n % i == 0)
    {
      ans.push_back(i);
      if (n / i != n)
        ans.push_back(n / i);
    }
  }
  return ans;
}

void solve()
{
  int n;
  cin >> n;

  int last = 0, cnt = 0;

  for (int i = 0; i < 32; ++i)
  {
    int bit = (n >> i) & 1;
    if (bit)
      last = i, cnt++;
  }

  if (cnt == last + 1)
  {
    int ans = 0;
    vector<int> v = div(n);

    for (auto &it : v)
      ans = max(ans, gcd(n ^ it, n & it));

    cout << ans << '\n';
    return;
  }

  int b = 0;

  for (int i = 0; i < last; ++i)
  {
    int bit = (n >> i) & 1;

    if (!bit)
      b += (1 << i);
  }

  cout << gcd(n ^ b, n & b) << '\n';
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
