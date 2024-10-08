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
                cout<<"Line : "<<++number<<"First File : No line \n"<<"Second File : \'"<<"\\n"<<"\'\n";
            }else{
                cout<<"Line : "<<number<<"First File :  \'"<<k1<<'\''<<'\n'<<"The Second file contains \'"<<c2<<'\''<<'\n';
            }
           /* cout<<"The first file is smaller than the second file \n";*/
        }else if( c1!=EOF && c2==EOF ){
            cout << "The two files are not identical \n";
           // c1=files1.get();
            if(c1=='\n'){
                cout<<"Line : "<<++number<<"First File : \'"<<"\\n"<<'\''<<'\n'<<"Second File :  No line"<<"\n";
            }else{
                cout<<"Line : "<<number<<"First File :  \'"<<c1<<'\''<<'\n'<<"The Second file contains \'"<<k2<<'\''<<'\n';
            }
           /* cout<<"The second file is smaller than the first file \n";*/
        }else{
            cout << "The two files are not identical \n";
            cout<<"Line : "<<number<<"\nFirst file : \'"<<c1<<"\'"<<'\n'
                <<"Second file contains : \'"<<c2<<"\'\n\n";
        }



    }else{

     string s1,s2,s,ss;char k1,k2;
     files1>>s1;files2>>s2;
        ll number=1;

      while(!files1.eof()&&!files2.eof()){
      if(s1!=s2) { break; }

      for(auto cc:s1){
          if(cc=='\n')
              number++;
      }
      s=s1;ss=s2;
      files1>>s1;files2>>s2;

      }
      if(files1.eof()&&files2.eof()){
          cout<<"The two files are identical \n";
      }else if( files1.eof()&&!files2.eof()){


                  cout<<"The two files are not identical \n";





      }else if(!files1.eof()&&files2.eof()){

          string parts;
          ll nums=number;
          while (true){
              if(k2!='\n'&&k2!=' ')
                  break;
              if(k2=='\n'){ number++; }
              files1.get(k2);
          }
          files2>>parts;
          cout<<"The two files are not identical \n";
          cout<<"Line : "<<number<<"The First File : "<<k2+parts<<'\n'<<"The Second File : ";
          if(number !=nums){
              cout<<"No Line \n";
          }else{
              cout<<ss;
          }



      }else{
          cout<<"The two files are not identical \n";
          cout<<"Line : "<<number<<"\nFirst File \""<<s1<<"\""<<" \nSecond File \""<<s2<<"\"";
      }



    }



}



int main(){


  cout<<"\n\n######### Welcome to our program #########\n\n";
    while (true) {


        cout << "The Menu : \n\n" << "1.Converting Male speech into Neutral speech\n" <<
             "2.Top 10 Players\n3.Some Draws\n4.Comparing Files\n6.Exit";
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
