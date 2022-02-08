#ifndef PROJECT_HPP
#define PROJECT_HPP 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class angle{
    public:
    int deg;
    int mins;
    int sec;
};

string addRes(string, string);

angle addAngle(angle, angle);

string subRes(string, string, int);

angle subAngle(angle, angle);

string multi(string, string);

string div(string, int);

double powerHelp(double, ll);

double power(double, double);

double rootRes(double, ll);

double logRes(double, double);

ll ncr(ll, ll);

ll fact(ll);

#endif