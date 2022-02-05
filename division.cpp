#include<bits/stdc++.h>
using namespace std;

string div(string x, int y)
{
    string ans;
    int idx = 0;
    int temp = x[idx] - '0';
    while (temp < y)
        temp = temp * 10 + (x[++idx] - '0');
    while (x.size() > idx) {
        ans += (temp / y) + '0';
        if(x.size() == idx + 1){
            temp = temp % y;
        }
        else
            temp = (temp % y) * 10 + x[++idx] - '0';
    }
    double c = temp / y;
    ans.push_back('.');
    for(int i = 0; i < 4; i++){
        c *= 10;
        ans.push_back(floor(c));
    }
    if (ans.length() == 0)
        return "0";
    return ans;
}