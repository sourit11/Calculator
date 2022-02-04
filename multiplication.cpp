#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
string multi(string x, string y){
    int k = -1, l = -1;
    for(int i = x.length() - 1; i >= 0; i--){
        if(x[i] == '.'){
            k = i;
            break;
        }
    }
    for(int i = y.length() - 1; i >= 0; i--){
        if(y[i] == '.'){
            l = i;
            break;
        }
    }
    if(k != -1 && l != -1){
        int decx = x.length() - k;
        int decy = y.length() - l;
        if(decx != decy){
            if(decx > decy){
                for(int i = 0; i < decx - decy; i++){
                    y.push_back('0');
                }
            }
            else{
                for(int i = 0; i < decy - decx; i++){
                    x.push_back('0');
                }
            }
        }
    }
    else if(k != -1){
        y.push_back('.');
        for(int i = 0; i < x.length() - k; i++)
            y.push_back('0');
    }
    else if(l != -1){
        x.push_back('.');
        for(int i = 0; i < y.length() - l; i++)
            x.push_back('0');
    }

    int *a = new int[x.length()];
    int *b = new int[y.length()];
    for(int i = x.length() - 1, j = 0; i >= 0; i--){
        if(x[i] == '.')
            a[j++] = -1;
        else
            a[j++] = x[i] - '0';
    }
    for(int i = y.length() - 1, j = 0; i >= 0; i--){
        if(y[i] == '.')
            b[j++] = -1;
        else    
            b[j++] = y[i] - '0';   
    }   
    int *c = new int[MAX]();
    int i = 0, z, p = 0;

    for(int i = 0; i < y.length(); i++){
        if(x[i] == -1)
            continue;
        z = 0;
        for(int j = 0; j < x.length(); j++){
            if(y[j] == -1){
                continue;
            }
            c[p + z] += (x[i] * y[j]) % 10;
            if(c[p + z] > 9){
                c[p + z + 1] += c[p + k] / 10;
                c[p + z] %= 10;
            }
            c[p + z + 1] += (x[i] * y[j]) / 10;
            z++;
        }
        p++;
    }
    
    string ans;
    if(k == -1)
        k++;
    if(l == -1)
        l++;
    for(int j = p + z, m = 0; j >= 0; j--, m++){
        if(k + l > 0 && m == k + l)
            ans.push_back('.');
        ans.push_back(c[j] + '0');
    }
    return ans;
}