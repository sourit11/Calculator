#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double logRes(double &x, double &y){
    ll a = x * 100000;
    ll b = y * 100000;
    double ans = ((double)log2(a) - log2(100000)) / ((double)log2(b) - log2(100000));
    return ans;
}