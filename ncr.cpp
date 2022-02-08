#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll fact(ll n){
    if(n == 1 || !n)
        return 1;
    ll ans = (n % mod * fact(n - 1) % mod) % mod;
    return ans;
}

ll ncr(ll n, ll r){
    return fact(n) / (fact(n - r) * fact(r));
}