using ll = long long;
class Solution {
public:
    long long flowerGame(int n, int m) {
        /*
            Every odd number in range [1,n] must be with
            every even number in range [1,m] and vice versa
        */

        // To get the number of of even numbers in range [1,n] is [n / 2]
        // and the number of odd numbers in range [1,n] is [(n+1) / 2]
        ll oddInN = (n+1) / 2;
        ll evenInN = n / 2;
        ll oddInM = (m+1) / 2;
        ll evenInM = m / 2;

        return oddInN * evenInM + evenInN * oddInM;
    }
};
