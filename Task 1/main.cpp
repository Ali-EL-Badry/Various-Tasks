/*
 * File Name : Task 1 (Tempo)
 * Purpose : (Tempo)
 * Section : (Tempo)
 * Auther 1 of (1|4|7|10) : Alaa Tarik Mohammed Salah El-Deen     * ID 1 : 20230064
 * Auther 2 of (2|5|8|11) : Fatema El-Zhraa Ahmed Mohamed El-Fiky * ID 2 : 20230280
 * Auther 3 of (3|6|9|12) : Aly El-Deen Yasser Ali Mohammed       * ID 3 : 20231109
 * TA :
 * Date : 8 Oct 2023
 */

// Defining only
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Common Used Functions :
string check_menu(const string& menuText , vector<string>choices){
    string correct;
    while(true){
        cout << menuText ;
        getline(cin, correct);
        if(correct.size() != 1 && find(choices.begin(),choices.end(), correct) != choices.end())
            cout << "Please Enter a valid option\n" ;
        else
            break;
        cin.ignore();
    }
    return correct;
}

// Problem 1 :

// Problem 2 :

// Problem 3 :

// Problem 4 :

// Problem 5 :

// Problem 6 :

// Problem 7 :

// Problem 8 :

// Problem 9 :

// Problem 10:

// Problem 11:

// Problem 12:

// Menu :


int main(){
    return 0;
}
