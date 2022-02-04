#include<bits/stdc++.h>
using namespace std;

class angle{
    public:
    int deg;
    int mins;
    int sec;
};

string subRes(string x, string y, int neg = 0){
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
        if(k < l){
            swap(x, y);
            neg = 1;
        }
        else if(k == l){
            int g = 0;
            while(g < x.length() && g < y.length() && x[g] == y[g]){
                g++;
            }
            if(g == x.length() || x[g] == '.' || x[g] < y[g]){
                swap(x, y);
                neg = 1;
            }
        }
    }
    else if(k != -1){
        y.push_back('.');
        for(int i = 0; i < x.length() - k; i++)
            y.push_back('0');
        if(y.length() > k){
            swap(x, y);
            neg = 1;
        }
        else if(y.length() == k){
            int g = 0;
            while(g < y.length() && x[g] == y[g]){
                g++;
            }
            if(x[g] < y[g]){
                swap(x, y);
                neg = 1;
            }
        }
    }
    else if(l != -1){
        x.push_back('.');
        for(int i = 0; i < y.length() - l; i++)
            x.push_back('0');
        if(x.length() < k){
            swap(x, y);
            neg = 1;
        }
        else if(x.length() == k){
            int g = 0;
            while(g < x.length() && x[g] == y[g]){
                g++;
            }
            if(x[g] < y[g]){
                swap(x, y);
                neg = 1;
            }
        }
    }
    else{
        int g = 0;
        while(g < x.length() && g < y.length() && x[g] == y[g]){
            g++;
        }
        if(g == x.length() && x.length() == y.length()){
            g = 1;
        }
        else if(g == x.length() || x[g] < y[g]){
            swap(x, y);
            neg = 1;
       }
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
    int *c = new int[max(x.length(), y.length()) + 1]();
    int i = 0;
    while(i < x.length() && i < y.length()){
        if(a[i] == -1){
            c[i] = -1;
            i++;
            continue;
        }
        int f;
        if(a[i] - b[i] >= 0)
            f = a[i] - b[i];
        else{
            f = a[i] + 10 - b[i];
            c[i + 1]--;
        }
        c[i] += f;
        i++;
    }
    while(i < x.length()){
        if(!a[i]){
            c[i + 1]--;
        }
        c[i] += a[i];
        i++;
    }
    string ans;
    int d = 0;
    if(neg == 1)
    ans.push_back('-');
    for(int j = i - 1; j >= 0; j--){
        if(!d && !c[j]){
            continue;
        }
        d = 1;
        if(c[j] == -1){
            ans.push_back('.');
            continue;
        }
        ans.push_back(c[j] + '0');
    }
    return ans;
}

angle subAngle(angle x, angle y){
    angle ans;
    long long a = (long long)x.deg * 3600 + x.mins * 60 + x.sec;
    long long b = (long long)y.deg * 3600 + y.mins * 60 + y.sec;
    long long c = abs(a - b);
    if(a < b)
        c *= -1;
    double x = (double)c / 3600;
    ans.deg = floor(c);
    ans.mins = floor((c - floor(c)) * 60);
    c = (c - floor(c)) * 60;
    ans.sec = ceil((c - floor(c)) * 60);
    return ans;
}