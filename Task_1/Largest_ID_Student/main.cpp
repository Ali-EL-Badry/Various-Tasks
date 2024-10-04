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

// To check the choices of the menu
string check_menu(const string& menuText , vector<string>choices){
    string correct;

    while(true){
        cout << menuText ;
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, correct);
        if(correct.size() != 1 || find(choices.begin(),choices.end(), correct) == choices.end())
            cout << "Please Enter a valid option\n" ;
        else
            break;
    }

    return correct;
}


//Check is it a number
bool isnumeric(const string& s){
    for( auto c: s){
        if(!isdigit(c))
            return false;
    }

    return  true;
}


//Lower strings
 string Lower(string s){
    for(auto& ch : s)
        ch=tolower(ch);
    return s;
}

// Problem 3 :

vector<string> spilt(const string& target ,const string &delimiter){
    vector<string> result;
    string temp;

    for(char i : target){
        temp.push_back(i);
        if(i == delimiter[0]){
            temp.pop_back();
            result.push_back(temp);
            temp = "";
        }
    }
    result.push_back(temp);

    return result;
}
void problem_3(){
    string target, delimiter;

    cout << "Enter The sentence You want to split: ";
    getline(cin,target);

    string delimiterMenu = "Do you want Delimiter to be as Default ' ' or something else? \n1) Default\n2) Enter your Own\nYour choice : ";
    vector<string> delimiterChoices = {"1","2"};
    string menuAnswer = check_menu(delimiterMenu, delimiterChoices);

    if(menuAnswer == "1")
        delimiter = " ";
    else{
        cout << "Enter your Delimter : ";
        cin >> delimiter;
    }

    vector<string> result;
    result = spilt(target, delimiter);

    cout << "Your vector = [ ";
    for(ll i = 0 ; i< result.size()-1 ; i++)
        cout << "\"" << result[i] << "\", ";
    cout << "\"" << result.back() << "\" ";
    cout << "]\n";
}

// Problem 6 :
// Problem 9 :

bool gameJudge(ll n){
    if (n == 42)
        return true;

    if (n < 42)
        return false;

    if (n % 2 == 0 && gameJudge(n / 2))
        return true;

    if (n % 3 == 0 || n % 4 == 0){
        ll last_digit = n % 10, second_digit = (n % 100) / 10;
        ll product = last_digit * second_digit;
        if (product > 0 && gameJudge(n - product))
            return true;
    }

    if (n % 5 == 0 && gameJudge(n - 42))
        return true;

    return false;
}

void problem_9(){

    string numberBears;

    while (true){
        cout << "Enter the number of bears : ";
        getline(cin,numberBears);
        if(isnumeric(numberBears))
            break;
        cout << "Please Enter a valid option" << endl;
    }

    cout << (gameJudge(stoll(numberBears)) ?  "You win" : "You Lose") << endl;

}

// Problem 12:
void problem_12(){
    map<string, int> phishingWords = {
        {"temporary", 3}, {"suspension", 2}, {"urgent", 3},{"click", 3},
        {"verify", 3}, {"password", 3}, {"account", 1},{"login", 2},
        {"limited", 2}, {"important", 3},{"bank", 3}, {"security", 3},
        {"alert", 3}, {"update", 2},{"congratulations", 2}, {"free", 2},
        {"won", 3}, {"gift", 2},{"fraud", 3}, {"secure", 3}, {"action", 3},
        {"sensitive", 3},{"information", 3}, {"immediately", 3},{"offer", 2},
        {"contact", 1}, {"unsubscribe", 1}, {"invoice", 2}, {"response", 3},
        {"payment", 3}, {"access", 3}, {"locked", 3}, {"service", 2},
    };

    ifstream email(R"(C:\Users\HP\OneDrive\Desktop\My_code\C212 Assignment\Task_1\email.txt)");
    ofstream outputFile(R"(C:\Users\HP\OneDrive\Desktop\My_code\C212 Assignment\Task_1\output.txt)");
    if(!email.is_open() || !outputFile.is_open()){
        cerr << "Cant open the file\n";
        return;
    }
    ll totalValuePoints = 0;

    string temp;
    map <string,int> numberRepetation;
    while(email >> temp)
        numberRepetation[temp]++;

    for(auto i : numberRepetation){
        if(phishingWords[i.first] != 0){
            int totalPointWord = i.second * phishingWords[i.first];
            outputFile <<  "Phishing term: \"" << i.first << "\", Occurrences: " << i.second << ", Points: " << totalPointWord << endl;
            totalValuePoints += totalPointWord;
        }
    }
    outputFile << "Total points = " << totalValuePoints << '\n';

    email.close();
    outputFile.close();
}

// Menu :


int main(){
    return 0;
}
