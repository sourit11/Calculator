#include<bits/stdc++.h>
using namespace std;

class angle{
    public:
    int deg;
    int mins;
    int sec;
};

string addRes(string &x, string &y){
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
    /*
    for(int i = 0; i < x.length(); i++)
        cout << a[i];
    for(int i = 0; i < y.length(); i++)
        cout << b[i];
    */
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
    int *c = new int[max(x.length(), y.length()) + 1]();
    int i = 0;
    while(i < x.length() && i < y.length()){
        if(a[i] == -1){
            c[i] = -1;
            i++;
            continue;
        }
        int f = a[i] + b[i];
        c[i] += f;
        if(a[i + 1] != -1)
            c[i + 1] += c[i] / 10;
        else
            c[i + 2] += c[i] / 10;
        c[i] %= 10;
        //cout << c[i] << " ";
        i++;
    }
    //cout << c[4] << '\n';
    while(i < x.length()){
        c[i] += a[i];
        i++;
    }
    while(i < y.length()){
        c[i] += b[i];
        i++;
    }

    //c[i + 1] = c[i] / 10;
    string ans;
    int d = 0;
    for(int j = i; j >= 0; j--){
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

angle addAngle(angle &x, angle &y){
    angle ans;
    ans.sec = x.sec + y.sec;
    ans.mins = ans.sec >= 60 ? 1 : 0;
    ans.sec = ans.sec >= 60 ? ans.sec - 60 : ans.sec;
    ans.mins += x.mins + y.mins;
    ans.deg = ans.mins >= 60 ? 1 : 0;
    ans.mins = ans.mins >= 60 ? ans.mins - 60 : ans.mins;
    ans.deg += x.deg + y.deg;
    return ans;
}