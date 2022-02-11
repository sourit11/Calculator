#include<bits/stdc++.h>
#include "project.hpp"

using namespace std;
typedef long long ll;

double rootRes(double &x, ll y){
    double low, high;
    double epsilon = 0.000001;
    if(x < 1){
        low = 0;
        high = 1;
    }       
    else{
        low = 1;
        high = x;
    }
    double guess = ((double)low + high) / 2;
    while (abs(powerHelp(guess, y) - x) >= epsilon){
        if(powerHelp(guess, y) > x)
            high = guess;
        else
            low = guess;
        guess = (low + high) / 2; 

    }
    return guess;
}
