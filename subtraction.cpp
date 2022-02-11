#include<bits/stdc++.h>
using namespace std;

class angle{
    public:
    int deg;
    int mins;
    int sec;
};

string subRes(string &x, string &y, int neg = 0){
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
    //cout << k << " " << l << '\n';
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
            x.swap(y);
            neg = 1;
        }
        else if(k == l){
            int g = 0;
            while(g < x.length() && g < y.length() && x[g] == y[g]){
                g++;
            }
            if(g == x.length() || x[g] == '.' || x[g] < y[g]){
                x.swap(y);
                neg = 1;
            }
        }
    }
    else if(k != -1){
        if(y.length() > k){
            x.swap(y);
            neg = 1;
            x.push_back('.');
            for(int i = 0; i < y.length() - k - 1; i++)
                x.push_back('0');
        }
        else if(y.length() == k){
            int g = 0;
            while(x[g] == y[g]){
                g++;
                if(g == y.length())
                    break;
            }
            if(g == y.length() || (g < y.length() && (x[g] - '0') < (y[g] - '0'))){
                x.swap(y);
                neg = 1;
                x.push_back('.');
                for(int i = 0; i < y.length() - k - 1; i++)
                    x.push_back('0');
            }
            else{
                y.push_back('.');
                for(int i = 0; i < x.length() - k - 1; i++)
                    y.push_back('0');
            }
        }
        else{
            y.push_back('.');
            for(int i = 0; i < x.length() - k - 1; i++)
                y.push_back('0');
        }
    }
    else if(l != -1){
        //cout << x.length() << " " << l << '\n';
        if(x.length() < l){
            x.swap(y);
            neg = 1;
            y.push_back('.');
            for(int i = 0; i < x.length() - l - 1; i++)
                y.push_back('0');
        }
        else if(x.length() == l){
            int g = 0;
            while(x[g] == y[g]){
                g++;
                if(g == x.length())
                    break;
            }
            if(g == x.length() || (g < x.length() && (x[g] - '0') < (y[g] - '0'))){
                x.swap(y);
                neg = 1;
                y.push_back('.');
                for(int i = 0; i < x.length() - l - 1; i++)
                    y.push_back('0');
            }
            else{
                x.push_back('.');
                for(int i = 0; i < y.length() - l - 1; i++)
                    x.push_back('0');
            }
        }
        else{
            x.push_back('.');
            for(int i = 0; i < y.length() - l - 1; i++)
                x.push_back('0');
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
        else if(g == x.length() || x[g] -'0' < y[g] - '0'){
            x.swap(y);
            neg = 1;
       }
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
    //cout << x.length() << " " << y.length() << "\n";
    if(x.length() < y.length()){
        for(int i = x.length(); i < y.length(); i++){
            a[i] = 0;
        }
    }
    else{
        for(int i = y.length(); i < x.length(); i++){
            b[i] = 0;
        }
    }
    /*for(int i = 0; i < max(x.length(), y.length()); i++)
        cout << a[i];
    cout << '\n';
    for(int i = 0; i < max(x.length(), y.length()); i++)
        cout << b[i];
    cout << '\n';
    */
    int *c = new int[max(x.length(), y.length()) + 1]();
    int i = 0;
    while(i < max(x.length(), y.length())){
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
            if(a[i + 1] != -1){
                b[i + 1]++;
            }
            else
                b[i + 2]++;
        }
        c[i] += f;
        //cout << c[i];
        //c[i] %= 10;
        i++;
    }
    string ans;
    int d = 0, e = 0;
    if(neg == 1)
    ans.push_back('-');
    for(int j = i - 1; j >= 0; j--){
        if(!d && !c[j]){
            if(!e && j > 0 && c[j - 1] == -1)
                ans.push_back('0');
            e++;
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

angle subAngle(angle &x, angle &y){
    angle ans;
    long long a = (long long)x.deg * 3600 + x.mins * 60 + x.sec;
    long long b = (long long)y.deg * 3600 + y.mins * 60 + y.sec;
    long long c = abs(a - b);
    double d = (double)c / 3600;
    //cout << d << " ";
    ans.deg = floor(d);
    ans.mins = floor((c - floor(d) * 3600) / 60);
    ans.sec = ((c - floor(d) * 3600) - 60 * ans.mins);
    //ans.sec = ceil((c - floor(c)) * 60);
    if(a < b)
        ans.deg *= -1;
    return ans;
}



// check 5873872782287 378287278.2978229
// not wokring for 10 10.99