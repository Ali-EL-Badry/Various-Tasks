/*
 * File Name : Task 1 (Tempo)
 * Purpose : Problem 2 | 5| 8 | 11
 * Problem 2 --> it converts the male speech into general speech
 * Problem 5 --> it gets the top 10 players and their highest score
 * Problem 8 --> it draws a certain pattern tha t are 2 power n and gets all the 2 power less than that number in recursive calls
 * Problem 11 -->it compares two files and giving two options compare through char by char  or word by word
 * Section : (Tempo)
 * Author 1 of (1|4|7|10) : Alaa Tarik Mohammed Salah El-Deen     * ID 1 : 20230064
 * Author 2 of (2|5|8|11) : Fatema El-Zhraa Ahmed Mohamed El-Fiky * ID 2 : 20230280
 * Author 3 of (3|6|9|12) : Aly El-Deen Yasser Ali Mohammed       * ID 3 : 20231109
 * TA :
 * Date : 8 Oct 2023
 */

// Defining only
#include <bits/stdc++.h>
#include <fstream>
#define ll long long
using namespace std;

//================================================================
// Common Used Functions :



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


//Validation of existence of the files
string validation(string name){

    while (true){
        ifstream files(name);
        try {
            if (files.is_open())
                break;
            else {
                throw runtime_error("please enter again \n");
            }

        }catch(exception & e){//exception is parent to the runtime error //"class"
            cout<<"Please try again !!\n\n Enter a Valid File : ";
            getline(cin,name);
            /* cin.ignore();*/
        }

    }
    return name;

}


//================================================================




// Problem 2 :

//need some clean code
void problem_2(){


    vector<pair<string,string>>strings={{"him", "her"}, {"he", "she"}, {"his", "hers"},
                                        {"himself","herself"}};

    string sentence; cout<<"Enter your sentence : ";
    getline(cin,sentence);




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
        ss=v[i]; ss[0]=tolower(ss[0]);
        bool checks= true;
        for (int j = 0; j < strings.size(); ++j) {

            if(ss==strings[j].first){

                string add;
                if(isupper(v[i][0])){
                    add= strings[j].second;
                    add[0]= toupper(add[0]);
                }else{
                    add= strings[j].second;;
                }
                v[i] += " or ";
                v[i] += add;

                break;
            }

        }
        answer += v[i];
    }
    cout<<"\n\n #### Here is your Conversion ####  \n\n"<<answer;

}





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


    cout<<"Enter the name : ";getline(cin,p.name);// s=p.name;

    /* cin.ignore();*/



    cout<<"Enter the score : ";cin>>scores;
    while (!isnumeric(scores)) {
        cout << "Please Enter a valid number : ";
        cin >> scores;
    }
    cin.ignore();


    p.score=stoi(scores);

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

    string n;

    cout<<"Enter the name : ";  getline(cin,n);

    /* cin.ignore();*/

    int size;

    // limitation of 10
    if(v.size()>10)
        size=10;
    else
        size=v.size();

    for (int i = 0; i < size ; ++i) {


        if(n==v[i].name) {
            cout<<"The highest score of \'"<<v[i].name<<'\''
                << " is : " << v[i].score << '\n';
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

        string menu = "Choose from the following menu :\n\n1.Add Player\n2.Print the top 10 players\n3.Getting the highest score of certain player\n4.Exit that program \nEnter your choice : ";
        cout<<menu;
        string choice ;cin>>choice;
        while (choice!="1"&& choice!="2"&&choice!="3"&&choice!="4"){
            cout<<"Please enter a valid choice : ";cin>>choice;
        }

        cin.ignore();
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



// Problem 8 :

void recurse(int n, int i){

    if(n==1) {
        for(int j=0;j<i;j++)
            cout<<" ";
        cout<<"*\n";
        return;
    }

    recurse(n/2,i);


    for(int j=0;j<i;j++){
        cout<<" ";
    }
    for(int j=0;j<n;j++){
        cout<<"* ";
    }cout<<'\n';


    recurse(n/2,i+n);




}
void problem_8(){

    string n;cout<<"Welcome to the drawing program\n";
    Again:
    cout<<"Enter an integer power of 2 as : 2 , 4, 8, 16, ... \n";
    cout<<"Enter the number : ";
    cin>>n;

    while (!isnumeric(n)){
        cout<<"Please Enter a valid number : ";cin>>n;
    }

    if(stoi(n)<0||__builtin_popcount(stoi(n))!=1) {
        cout<<"Please enter a valid number of power of two !!\n\n";
        goto Again;
    }
    cin.ignore();


    Again_2:
    string spaces;cin>>spaces;
    while (!isnumeric(spaces)){
        cout<<"Please Enter a valid number : ";cin>>spaces;
    }
    if(stoi(spaces)<0) {
        cout<<"Please enter a valid number of power of two !!\n\n";
        goto Again_2;
    }
    cin.ignore();


    recurse(stoi(n),stoi(spaces));




}




// Problem 11:
void problem_11(){

    cout<<"######### Welcome to the Facility Comparing Files #########\n\n";
    cout<<"Which type of compare do you want ? \n\nChoose from the following :\n1.Character by Character\n2.Word by Word \n\n ";
    cout<<"Enter your choice : ";

    string choice;cin>>choice;
    while(choice!="2"&&choice!="1"){
        cout<<"Please Enter a Valid Choice : ";
        cin>>choice;
    }
    cin.ignore();
    //Enter the files
    cout<<"Please Enter the file names !\n\n";


    cout<<"Enter the first file name : ";
    string name1,name2;
    getline(cin,name1);
    name1= validation(name1);
    /* cin.ignore();*/

    cout<<"Enter the second file name : ";

    getline(cin,name2);
    name2= validation(name2);
    /*cin.ignore();*/

    ifstream files1 (name1);
    ifstream  files2 (name2);

    if(choice=="1"){
        char c1=files1.get() ,c2=files2.get(),k1,k2;
        //bool equal = true;

        ll number=1;
        while(!files1.eof()&&!files2.eof()){

            if(c1!=c2){
                // equal=false;
                break;
            }
            if(c1 =='\n'){
                number++;
            }
            k1=c1;k2=c2;
            c1=files1.get(); c2=files2.get();
        }
        // counting number of lines


        if(c1==EOF && c2==EOF)
            cout<<"The two files are identical \n";
        else if( c1==EOF && c2!=EOF) {
            cout << "The two files are not identical \n";
            //c2=files2.get();
            if(c2=='\n'){
                cout<<"Line : "<<++number<<'\n'<<"First File : No line \n"<<"Second File : \'"<<"\\n"<<"\'\n";
            }else{
                cout<<"Line : "<<number<<'\n'<<"First File :  \'"<<k1<<'\''<<'\n'<<"Second File : \'"<<c2<<'\''<<'\n';
            }
            /* cout<<"The first file is smaller than the second file \n";*/
        }else if( c1!=EOF && c2==EOF ){
            cout << "The two files are not identical \n";
            // c1=files1.get();
            if(c1=='\n'){
                cout<<"Line : "<<++number<<"First File : \'"<<"\\n"<<'\''<<'\n'<<"Second File :  No line"<<"\n";
            }else{
                cout<<"Line : "<<number<<"First File :  \'"<<c1<<'\''<<'\n'<<"Second File : \'"<<k2<<'\''<<'\n';
            }

        }else{
            cout << "The two files are not identical \n";
            if(c1=='\n')

                cout<<"Line : "<<number<<"\nFirst file : \'"<<"\\n"<<"\'"<<'\n'
                    <<"Second File  : \'"<<c2<<"\'\n\n";
            if(c2=='\n')
                cout<<"Line : "<<number<<"\nFirst file : \'"<<c1<<"\'"<<'\n'
                    <<"Second File  : \'"<<"\\n"<<"\'\n\n";
            else
                cout<<"Line : "<<number<<"\nFirst file : \'"<<c1<<"\'"<<'\n'
                    <<"Second File  : \'"<<c2<<"\'\n\n";

        }



    }else{

        string word1,word2;
        char c1,c2;
        int number=1;
        c1=files1.get();c2=files2.get();
        while (!files1.eof()&&!files2.eof()){

            int number1=0, number2=0;
            while (c1=='\n'||c1==' '){
                if(c1=='\n')
                    number1++;
                c1=files1.get();
                if(!word1.empty()){ word1.clear(); }
            }

            while (c2=='\n'||c2==' '){
                if(c2=='\n')
                    number2++;
                c2=files2.get();
                if(!word2.empty()){ word2.clear(); }
            }
            word1+=c1;word2+=c2;
           number+=max(number1,number2);

            if(word1!=word2)//changed for try
            {
                break;
            }
            c1=files1.get();c2=files2.get();

        }
       if(c1==EOF&&c2==EOF){
           cout<<"The two files are identical\n";
       }else if(c1==EOF && c2!=EOF){
           /*cout<<"The two files are not identical\n";*/
           string s;
           if(c2==' '||c2=='\n'){
               while (c2==' '||c2=='\n'){
                   if(c2=='\n')
                       number++;
                   c2=files2.get();
               }
               if(files2.peek()!='\n'&&files2.peek()!=' '){ files2 >> s; }
               if(c2==EOF){
                   cout<<"The two files are  identical\n";
               }else{
                   cout<<"The two files are not identical\n";
                   cout <<"Line : "<<number<<'\n'<<"File 1 : "<<"none\n"<<"File 2 : "<<"\""<<c2+s<<"\""<<'\n';
               }
           }else{//change
               cout<<"The two files are not identical\n";
               if(files2.peek()!='\n'&&files2.peek()!=' '){ files2 >> s; }

               cout <<"Line : "<<number<<'\n'<<"File 1 : "<<word1<<"\n"<<"File 2 : "<<"\""<<word2+s<<"\""<<'\n';
           }
       } else if(c1!=EOF&&c2==EOF){
         //  cout<<"The two files are not identical\n";
         string s;
         if(c1==' '||c1=='\n'){
             while (c1==' '||c1=='\n'){
                 if(c1=='\n')
                     number++;
                 c1=files1.get();
             }
             if(files1.peek()!='\n'&&files1.peek()!=' '){ files1 >> s; }
             if(c1==EOF){
                 cout<<"The two files are  identical\n";
             }else{
                 cout<<"The two files are not identical\n";
                 cout<<"Line : "<<number<<'\n'<<"File 1 : \""<<c1+s<<"\""<<'\n'<<"File 2 : none\n";
             }
         }else{//change
             cout<<"The two files are not identical\n";
             if(files1.peek()!='\n'&&files1.peek()!=' ') {files1>>s;}
             cout<<"Line : "<<number<<'\n'<<"File 1 : \""<<word1+s<<"\""<<'\n'<<"File 2 : "<<word2<<"\n";
         }

       }else{//change
           cout<<"The two files are not identical\n";
           string s1,s2;
           if(files1.peek()!='\n'&&files1.peek()!=' '){
               files1 >> s1;
           }
           if(files2.peek()!='\n'&&files2.peek()!=' '){
               files2 >> s2;
           }
           cout<<"Line : "<<number<<'\n'<<"File 1 : \""<<word1+s1<<"\""<<'\n'<<"File 2 : "<<"\""<<word2+s2<<"\""<<'\n';

       }

    }



}



int main(){


    cout<<"\n\n######### Welcome to our program #########\n\n";
    while (true) {


        cout << "\n\nThe Menu : \n\n" << "1.Converting Male speech into Neutral speech\n" <<
             "2.Top 10 Players\n3.Some Draws\n4.Comparing Files\n5.Exit";
        cout<<"\n\nEnter your choice : ";


        string choice;
        cin >> choice;
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
            cout << "Please Enter a Valid Choice : ";
            cin >> choice;
        }
        cin.ignore();


        if (choice == "1") {//it is okay

            problem_2();

        } else if (choice == "2") {//it is okay

            problem_5();

        } else if (choice == "3") { //draw problem 8

            problem_8();

        } else if (choice == "4") {

            problem_11();

        } else {

            cout << "\n\n    ###### Thanks for using that program ######  \n\n";
            break;

        }

    }
    return 0;
}
