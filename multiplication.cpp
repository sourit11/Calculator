#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
string multi(string &x, string &y){
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
        for(int i = 0; i < x.length() - k - 1; i++)
            y.push_back('0');
    }
    else if(l != -1){
        x.push_back('.');
        for(int i = 0; i < y.length() - l - 1; i++)
            x.push_back('0');
    }

    int *a = new int[max(x.length(), y.length())];
    int *b = new int[max(x.length(), y.length())];
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
    for(int i = 0; i < max(x.length(), y.length()); i++)
        cout << a[i];
    cout << '\n';
    for(int i = 0; i < max(x.length(), y.length()); i++)
        cout << b[i];
    cout << '\n';
    int *c = new int[MAX]();
    int i = 0, z, p = 0;

    for(int i = 0; i < max(x.length(), y.length()); i++){
        if(b[i] == -1){
            k = i;
            continue;
        }
        z = 0;
        for(int j = 0; j < max(x.length(), y.length()); j++){
            if(a[j] == -1){
                l = j;
                continue;
            }
            cout << b[i] << " " << a[j] <<  " ";
            c[p + z] += (b[i] * a[j]);
            if(c[p + z] > 9){
                if(c[p + z + 1] != -1)
                    c[p + z + 1] += c[p + z] / 10;
                else
                    c[p + z + 2] += c[p + z] / 10;
                c[p + z] %= 10;
            }
            cout << c[p + z];
            //c[p + z + 1] += (x[i] * y[j]) / 10;
            z++;
        }
        cout << " ";
        p++;
    }
    int d = 0, e = 0;
    string ans;
    for(int j = p + z - 1, m = 0; j >= 0; j--){
        if(!d && !c[j]){
            if(k + l > 0 && j == k + l - 1)
                ans.push_back('.');
            if(!e && j > 0 && c[j - 1] == -1)
                ans.push_back('0');
            e++;
            continue;
        }
        d = 1;
        if(k + l > 0 && j == k + l - 1)
            ans.push_back('.');
        ans.push_back(c[j] + '0');
    }
    return ans;
}


// check 0.7 0.043