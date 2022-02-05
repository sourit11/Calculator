#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll powerHelp(ll x, ll y){
    if(!y)
		return 1;
	ll res = powerHelp(x, y / 2);
	ll ans = res * res;
    ans %= mod;
	if(!(y % 2))
		return ans;
	return (x * ans) % mod;    
}

template <typename T>
T power(T x, T y){
    
}