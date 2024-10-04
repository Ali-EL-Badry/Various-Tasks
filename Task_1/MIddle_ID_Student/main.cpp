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


//================================================================


// Problem 1 :

// Problem 2 :
bool check(const vector<pair<string,string>> & strings ,const vector<string> & v, long long index ){

    if(index+4<v.size()){

        string s= Lower(v[index+2]);

     if(s!="or"){
         return true;
     }else{
         s= Lower(v[index+4]);
         for (const auto & string : strings) {
             if(s==string.first||s==string.second)
                 return false;
         }
         return true;
     }


    }else
        return true;
}
void problem_2(){


    vector<pair<string,string>>strings={{"her", "him"}, {"he", "she"}, {"his", "hers"}, {"mrs", "mr"}, {"sir", "miss"},
                                         {"actor", "actress"},{"father","mother"},{"boy","girl"} };

    string sentence2,sentence; cout<<"Enter your sentence : ";
    while(getline(cin,sentence2)) {
       /* if(sentence2=="exit")
            break;*///clion problem
        if(!sentence2.empty()){ sentence += sentence2; }
        sentence+='\n';
    }
    sentence.pop_back();


    string answer,part;
    vector<string>v;
    for (int i = 0; i < sentence.size(); ++i) {
        if (ispunct(sentence[i])||sentence[i]=='\n'||sentence[i]==' '){
            if(!part.empty()){
                v.push_back(part); part.clear();
            }
            part+=sentence[i]; v.push_back(part);
            part.clear();
        }else{

            part+=sentence[i];
        }
    }
    if(!part.empty()){
        v.push_back(part);
    }


    for (int i = 0; i < v.size(); ++i) {
        string ss;
        ss=v[i]; ss= Lower(ss);
        bool checks= true;
        for (int j = 0; j < strings.size(); ++j) {

            if(ss==strings[j].first){
                if(check(strings,v,i)) {
                    v[i] += " or ";
                    v[i] += strings[j].second;
                }else{
                    for (int k = i; k <=4 ; ++k) {
                        answer+=v[k];
                    }
                    i+=4;
                    checks=false;
                }

                break;
            }else if(ss==strings[j].second){
                if(check(strings,v,i)){
                    v[i] += " or ";
                    v[i] += strings[j].first;
                }else{
                    for (int k = i; k <=i+4 ; ++k) {
                        answer+=v[k];
                    }
                    i+=4;
                    checks=false;
                }

                break;
            }

        }
        if(checks){ answer += v[i]; }
    }
    cout<<"\n\n #### Here is your Conversion ####  \n\n"<<answer;

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

// Problem 10:

// Problem 11:

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
    problem_12();
    return 0;
}