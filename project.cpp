#include<bits/stdc++.h>
#include "project.hpp"
using namespace std;
typedef long long ll;

int main(){
    cout << "\tWelcome to my calculator project!!!\n";
    cout << "You can perform the following operations:\n"
         << "1. Addition (+)\n"
         << "2. Subtraction (-)\n"
         << "3. Multiplication (*)\n"
         << "4. Division (/)\n"
         << "5. Power(^)\n"
         << "6. nth Root\n"
         << "7. Logarithm\n"
         << "8. nCr\n";
    cout << "Enter your choice among 1-8: ";
    int ch;
    do{
        cin >> ch;
        switch(ch){
            case 0: cout << "Thanks for using my calculator :)\n";
                    break;
            case 1: {
                    cout << "Enter a. for addition of numeric values or b. for addition of angles\n";
                    char ch1;
                    cin >> ch1;
                    switch(ch1){
                        case 'a': {
                                cout << "Enter the two values to be added: ";
                                string x, y;
                                cin >> x >> y;
                                if(x[0] == '-' && y[0] == '-'){
                                    x = x.substr(1);
                                    y = y.substr(1);
                                    cout << x << " + " << y << " = -" << addRes(x, y) << '\n';
                                }
                                else if(x[0] == '-'){
                                    x = x.substr(1);
                                    cout << x << " + " << y << " = " << subRes(y, x, 0) << '\n';
                                }
                                else if(y[0] == '-'){
                                    y = y.substr(1);
                                    cout << x << " + " << y << " = " << subRes(x, y, 0) << '\n';
                                }
                                else
                                    cout << x << " + " << y << " = " << addRes(x, y) << '\n';
                                break;
                                }
                        case 'b': {
                                cout << "Enter the two angles to be added in the format degrees, minutes, seconds: ";
                                angle a, b;
                                cin >> a.deg >> a.mins >> a.sec >> b.deg >> b.mins >> b.sec;
                                cout << a.deg << "° " << a.mins << "\' " << a.sec << "\" " << " + " << b.deg << "° " << b.mins << "\' " << b.sec << "\" " << " = " << addAngle(a, b).deg << "° " << addAngle(a, b).mins << "\' " << addAngle(a, b).sec << "\" " << '\n';
                                break;
                                }   
                        default: cout << "Wrong input!\n";
                    }
                    break;
                    }      
            case 2: {
                    cout << "Enter c. for subtraction of numeric values or d. for subtraction of angles\n";
                    char ch2;
                    cin >> ch2;
                    switch(ch2){
                        case 'c': {
                                cout << "Enter the two values to be subtracted: ";
                                string x1, y1;
                                cin >> x1 >> y1;
                                if(x1[0] == '-' && y1[0] == '-'){
                                    y1 = y1.substr(1);
                                    x1 = x1.substr(1);
                                    cout << x1 << " - " << y1 << " = -" << subRes(y1, x1, 0) << '\n';
                                }
                                else if(x1[0] == '-'){
                                    x1 = x1.substr(1);
                                    cout << x1 << " - " << y1 << " = -" << addRes(y1, x1) << '\n';
                                }
                                else if(y1[0] == '-'){
                                    y1 = y1.substr(1);
                                    cout << x1 << " - " << y1 << " = " << addRes(x1, y1) << '\n';
                                }
                                else
                                    cout << x1 << " - " << y1 << " = " << subRes(x1, y1, 0) << '\n';
                                break;
                                }
                        case 'd': {
                                cout << "Enter the two angles to be subtracted in the format degrees, minutes, seconds: ";
                                angle a1, b1;
                                cin >> a1.deg >> a1.mins >> a1.sec >> b1.deg >> b1.mins >> b1.sec;
                                cout << a1.deg << "° " << a1.mins << "\' " << a1.sec << "\" " << " - " << b1.deg << "° " << b1.mins << "\' " << b1.sec << "\" " << " = " << subAngle(a1, b1).deg << "° " << subAngle(a1, b1).mins << "\' " << subAngle(a1, b1).sec << "\" " << '\n';
                                break;
                                }
                        default: cout << "Wrong input!\n";
                    }
                    break;
                    }
            case 3: {
                    cout << "Enter the two values to be multiplied: ";
                    string x2, y2;
                    cin >> x2 >> y2;
                    cout << x2 << " * " << y2 << " = " ;
                    if(x2[0] == '-' && y2[0] == '-'){
                        x2 = x2.substr(1);
                        y2 = y2.substr(1);
                        cout << multi(y2, x2) << '\n';
                    }
                    else if(x2[0] == '-'){
                        x2 = x2.substr(1);
                        cout << " -" << multi(y2, x2) << '\n';
                    }
                    else if(y2[0] == '-'){
                        y2 = y2.substr(1);
                        cout << " -" << multi(x2, y2) << '\n';
                    }
                    else
                        cout << multi(x2, y2) << '\n';
                    break;
                    }
            case 4: {
                cout << "Enter the values for division in the format numerator first then denominator: ";
                    string x3;
                    ll y3;
                    cin >> x3 >> y3;
                    if(!y3){
                        cout << "Denominator cannot be zero!\n";
                        break;
                    }
                    
                    cout << x3 << " / " << y3 << " = " << div(x3, y3) << '\n';
                    break;
                    }
            case 5: {
                    cout << "Enter the values in the format x then y where x^y: ";
                    double x4, y4;
                    cin >> x4 >> y4;
                    cout << x4 << " ^ " << y4 << " = " << power(x4, y4) << '\n';
                    break;
                    }
            case 6: {
                    cout << "Enter the values in the format x then y where you want to calculate the xth root of y: ";
                    double x5;
                    ll y5;
                    cin >> x5 >> y5;
                    cout << x5 << "th root of " << y5 << " = " << rootRes(x5, y5) << '\n';
                    break;
                    }
            case 7: {
                    cout << "Enter the values in the format x then y where you want to calculate the log of y to the base x: ";
                    double x6, y6;
                    cin >> x6 >> y6;
                    cout << "log " << y6 << "to the base " << x6 << " = " << logRes(x6, y6) << '\n';
                    break;
                    }
            case 8: {
                    cout << "Enter the values in the format n then r where you want to calculate nCr: ";
                    ll n, r;
                    cin >> n >> r;
                    if(r < n){
                        cout << "Values should be whole numbers only!\n";
                        break;
                    }
                    cout << n << "C" << r << " = " << ncr((ll)n, (ll)r) << '\n';
                    break;
                    }
            default: cout << "Wrong input! Please select among 1-8!\n";
        }
    }while(ch);
    
    return 0;
}