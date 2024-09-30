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

//================================================================
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


//================================================================


// Problem 1 :

// Problem 2 :

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

// Problem 4 :

// Problem 5 :

struct player{
private:
    string name;
    double score;

public:
    void print (const vector <player> & v);
    void add (vector <player> & v);
    static bool way(player p1, player p2);
    void getter( const vector<player> & v);
};

void player::print (const vector <player> & v){
    // limitation of 10
    int size = (v.size() > 10 ? 10 : v.size());

    for (int i = 0; i < size; i++)
        cout << i + 1 << "." << "Name : \'" << v[i].name << "\'        " << "Score : " << v[i].score << '\n';
}

bool player :: way(player p1, player p2){
    return (p1.score>=p2.score);
}

void player :: add (vector <player> & v){
    player p;
    string s,ss,scores;
    x:

    if (cin.peek() == '\n') cin.ignore();

    cout<<"Enter the name : ";getline(cin,p.name); s=p.name;
    s= Lower(s);


    cout<<"Enter the score : ";cin>>scores;
    while (!isnumeric(scores)) {
        cout << "Please Enter a valid number : ";
        cin >> scores;
    }


    p.score=stoi(scores);
    for (int i = 0; i < v.size(); ++i) {
        ss=v[i].name;
        ss= Lower(ss);

        if(s==ss&& p.score==v[i].score) {
            cout<<"This player with that name and that score is already entered !!\nTry again!\n\n";
            goto x;
        }
    }
    v.push_back(p);
    sort(v.begin(),v.end(),way);

    //erase the rest
    if(v.size()>10){
        for (int i = 10; i <v.size(); ++i)
            v.erase(i+v.begin());
    }
}

void player :: getter( const vector<player> & v){
    xx:

    string n;    if (cin.peek() == '\n') cin.ignore();
    cout<<"Enter the name : ";  getline(cin,n);
    n=Lower(n);
    int size;

    // limitation of 10
    if(v.size()>10)
        size=10;
    else
        size=v.size();

    for (int i = 0; i < size ; ++i) {

        string s =v[i].name;
        s= Lower(s);

        if(n==s) {
            cout << "The score is : " << v[i].score << '\n';
            return;
        }

    }

    cout<<"\n\nThis player is not from the top 10 \n\n Try again!\n\n";

    goto xx;
}

void problem_5 (){

    vector<player>Player;
    //Small Menu
    while(true){
        //Menu and Validations

        string menu = "Choose from the following menu :\n\n1.Add Player\n2.Print the top 10 players\n3.Getting the highest score of certain player\n4.Exit that program \nEnter Your Choice : ";
        vector<string>v={"1","2","3","4"};
        string choice = check_menu(menu,v);

        if(choice=="1"){//Add

            Player[0].add(Player);

        }else if( choice =="2"){//Printing

           if(!Player.empty())
               Player[0].print(Player);
           else
               cout<<"\n\nThere is no player is added \n\n";

        }else if (choice =="3"){//Getting score of a player

            Player[0].getter(Player);

        }else {//exit
         cout<<"\n\n\n ######### Thanks for using that program #########\n\n\n";
         break;
        }

    }
}

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
