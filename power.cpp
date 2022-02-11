#include<bits/stdc++.h>
#include "project.hpp"
using namespace std;
typedef long long ll;

double powerHelp(double &x, ll y){
    if(!y)
		return 1;
	double res = powerHelp(x, y / 2);
	double ans = res * res;
	if(!(y % 2))
		return ans;
	return (x * ans);    
}

double power(double &x, double &y){
	double p;
	p = powerHelp(x, 100000 * y);
	p += rootRes(x, 100000);
	return p;
}