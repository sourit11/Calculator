#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class angle{
    public:
    int deg;
    int mins;
    int sec;
};

template <typename T>

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
            case 1: cout << "Enter 1. for addition of numeric values or 2. for addition of angles\n";
                    int ch2;
                    cin >> ch2;
                    switch(ch2){
                        case 1: cout << "Enter the two values to be added: ";
                                string x, y;
                                cin >> x >> y;
                                if(x[0] == '-' && y[0] == '-')
                                    cout << x << " + " << y << " = -" << addRes(x.substr(1), y.substr(1)) << '\n';
                                else if(x[0] == '-')
                                    cout << x << " + " << y << " = " << subRes(y, x.substr(1)) << '\n';
                                else if(y[0] == '-')
                                    cout << x << " + " << y << " = " << subRes(x, y.substr(1)) << '\n';
                                else
                                    cout << x << " + " << y << " = " << addRes(x, y) << '\n';
                                break;
                        case 2: cout << "Enter the two angles to be added in the format degrees, minutes, seconds: ";
                                angle x, y;
                                cin >> x.deg >> x.mins >> x.sec >> y.deg >> y.mins >> y.sec;
                                cout << x.deg << "° " << x.mins << "\' " << x.sec << "\" " << " + " << y.deg << "° " << y.mins << "\' " << y.sec << "\" " << " = " << addAngle(x, y).deg << "° " << addAngle(x, y).mins << "\' " << addAngle(x, y).sec << "\" " << '\n';
                                break;
                        default: cout << "Wrong input!\n";
                    }
                    break;
            case 2: cout << "Enter 1. for subtraction of numeric values or 2. for subtraction of angles\n";
                    int ch2;
                    cin >> ch2;
                    switch(ch2){
                        case 1: cout << "Enter the two values to be subtracted: ";
                                string x, y;
                                cin >> x >> y;
                                if(x[0] == '-' && y[0] == '-')
                                    cout << x << " - " << y << " = -" << subRes(y.substr(1), x.substr(1)) << '\n';
                                else if(x[0] == '-')
                                    cout << x << " - " << y << " = -" << addRes(y, x.substr(1)) << '\n';
                                else if(y[0] == '-')
                                    cout << x << " - " << y << " = " << addRes(x, y.substr(1)) << '\n';
                                else
                                    cout << x << " - " << y << " = " << subRes(x, y) << '\n';
                                break;
                        case 2: cout << "Enter the two angles to be subtracted in the format degrees, minutes, seconds: ";
                                angle x, y;
                                cin >> x.deg >> x.mins >> x.sec >> y.deg >> y.mins >> y.sec;
                                cout << x.deg << "° " << x.mins << "\' " << x.sec << "\" " << " - " << y.deg << "° " << y.mins << "\' " << y.sec << "\" " << " = " << subAngle(x, y).deg << "° " << subAngle(x, y).mins << "\' " << subAngle(x, y).sec << "\" " << '\n';
                                break;
                        default: cout << "Wrong input!\n";
                    }
                    break;
            case 3: cout << "Enter the two values to be multiplied: ";
                    string x, y;
                    cin >> x >> y;
                    cout << x << " * " << y << " = " ;
                    if(x[0] == '-' && y[0] == '-')
                        cout << multi(y.substr(1), x.substr(1)) << '\n';
                    else if(x[0] == '-')
                        cout << " -" << multi(y, x.substr(1)) << '\n';
                    else if(y[0] == '-')
                        cout << " -" << multi(x, y.substr(1)) << '\n';
                    else
                        cout << multi(x, y) << '\n';
                    break;
            case 4: cout << "Enter the values for division in the format numerator first then denominator: ";
                    string x;
                    ll y;
                    cin >> x >> y;
                    if(!y){
                        cout << "Denominator cannot be zero!\n";
                        break;
                    }
                    
                    cout << x << " / " << y << " = " << div(x, y) << '\n';
                    break;
            case 5: cout << "Enter the values in the format x then y where x^y: ";
                    T x, y;
                    cin >> x >> y;
                    cout << x << " ^ " << y << " = " << power(x, y) << '\n';
                    break;
            case 6: cout << "Enter the values in the format x then y where you want to calculate the xth root of y: ";
                    T x, y;
                    cin >> x >> y;
                    cout << x << "th root of " << y << " = " << rootRes(x, y) << '\n';
                    break;
            case 7: cout << "Enter the values in the format x then y where you want to calculate the log of y to the base x: ";
                    T x, y;
                    cin >> x >> y;
                    cout << "log " << y << "to the base " << x << " = " << logRes(x, y) << '\n';
                    break;
            case 8: cout << "Enter the values in the format n then r where you want to calculate nCr: ";
                    T n, r;
                    cin >> n >> r;
                    if(T != int){
                        cout << "Values should be whole numbers only!\n";
                        break;
                    }
                    cout << n << "C" << r << " = " << ncr(n, r) << '\n';
                    break;
            default: cout << "Wrong input! Please select among 1-8!\n";
        }
    }while(ch)
    return 0;
}