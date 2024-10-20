#include <bits/stdc++.h>
#define ll long long
#include "chat.h"
#include "gemini.h"
#define en <<'\n'
using namespace std;

int main() {
    ifstream in (R"(C:\Users\HP\OneDrive\Desktop\My_code\programs_code\C++ codes\OOP Train\text.txt)");

    for(ll _ = 0 ; _ < 50 ; _++){
        string numArray1;in >> numArray1;vector<double>Array1;

        for(ll i = 0 ; i <= stoll(numArray1) ; i++){
            string num; in >> num;
            Array1.push_back(stod(num));
        }

        string numArray2;in >> numArray2;vector<double>Array2;
        for(ll i = 0 ; i <= stoll(numArray2) ; i++){
            string num; in >> num;
            Array2.push_back(stod(num));
        }

        cout <<"Test Case" << _ en << "Chat GPT: " en;
        Polynomial p1(Array1);
        Polynomial p2(Array2);
        Polynomial p3 = p1;
        if(p3 == p1)
            cout << "Blah Blah" en;
        cout << p1-p3 en;
        cout << p1 + p3 en;
        cout << p1 * p3 en;

        cout << p1.degree() << ' ' << p2.degree() en;
        cout << p1.evaluate(5) en;
        cout << p2.derivative() en;

        cout << p1.integral() en;
        cout << p3.integral(0,1) en;

        // cout << p3.getRoot() en;

        cout <<"Test Case" << _ en << "Geimini: " en;
        Polynomial p4(Array1);
        Polynomial p5(Array2);
        Polynomial p6 = p4;
        if(p3 == p4)
            cout << "Blah Blah" en;
        cout << p4-p6 en;
        cout << p4 + p6 en;
        cout << p4 * p6 en;

        cout << p4.degree() << ' ' << p5.degree() en;
        cout << p4.evaluate(5) en;
        cout << p5.derivative() en;

        cout << p4.integral() en;
        cout << p6.integral(0,1) en;

        // cout << p6.getRoot() en;


    }

    return 0;
}
