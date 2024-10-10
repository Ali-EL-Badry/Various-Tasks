/*
 * File Name : A1_T1_20230280
 * Purpose : Problem 2 | 5| 8 | 11
 * Problem 2 --> it converts the male speech into general speech
 * Problem 5 --> it gets the top 10 players and their highest score
 * Problem 8 --> it draws a certain pattern tha t are 2 power n and gets all the 2 power less than that number in recursive calls
 * Problem 11 -->it compares two files and giving two options compare through char by char  or word by word
 * Section : S23
 * Author  of (2|5|8|11) : Fatema El-Zhraa Ahmed Mohamed El-Fiky  *   ID  : 20230280
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


void problem_2(){


    // All the masculine pronouns
    vector<pair<string,string>>strings={{"him", "her"}, {"he", "she"}, {"his", "hers"},
                                        {"himself","herself"}};
    //Taking one line
    string sentence; cout<<"Enter your sentence : ";
    getline(cin,sentence);




    string answer,part;
    vector<string>v;

    //Taking and separating  the words  and putting them in a vector to handel them
    for (long long  i = 0; i < sentence.size(); ++i) {
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


// see the masculine words and converting them by taking the opposite one in the pair and putting the answer
//in a string and print that string
    for (long long i = 0; i < v.size(); ++i) {
        string ss;
        ss=v[i]; ss[0]=tolower(ss[0]);
        bool checks= true;
        for (long long  j = 0; j < strings.size(); ++j) {

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
    long long  size = (v.size() > 10 ? 10 : v.size());

    for (int i = 0; i < size; i++)
        cout << i + 1 << "." << "Name : \'" << v[i].name << "\'        " << "Score : " << v[i].score << '\n';
}

//comparison way
bool player :: way(player p1, player p2){
    return (p1.score>=p2.score);
}

void player :: add (vector <player> & v){

    player p;
    string s,ss,scores;



    cout<<"Enter the name : ";getline(cin,p.name);




    cout<<"Enter the score : ";cin>>scores;
    while (!isnumeric(scores)) {
        cout << "Please Enter a valid number : ";
        cin >> scores;
    }
    cin.ignore();


    p.score=stoll(scores);

    v.push_back(p);
    sort(v.begin(),v.end(),way);

    //erase the rest
    if(v.size()>10){
        for (long long  i = 10; i <v.size(); ++i)
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

    for (long long  i = 0; i < size ; ++i) {


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

void recurse( long long n, long long space){

    // base case
    if(n==1) {
        for( long long j=0;j<space;j++)
            cout<<" ";
        cout<<"*\n";
        return;
    }

    // first call
    recurse(n/2,space);


    for( long long j=0;j<space;j++){
        cout<<" ";
    }
    for( long long j=0;j<n;j++){
        cout<<"* ";
    }cout<<'\n';

// second call responsible for getting all the left behind power of 2 numbers
    recurse(n/2,space+n);


}


void problem_8(){

    //Some Validations on the number to be power of 2 and positive and of course to be numeric

    string n;cout<<"Welcome to the drawing program\n";
    Again:
    cout<<"Enter an integer power of 2 as : 2 , 4, 8, 16, ... \n";
    cout<<"Enter the number : ";
    cin>>n;

    while (!isnumeric(n)){
        cout<<"Please Enter a valid number : ";cin>>n;
    }

    if(stoll(n)<0||__builtin_popcount(stoll(n))!=1) {
        cout<<"Please enter a valid number of power of two !!\n\n";
        goto Again;
    }
    cin.ignore();

// validate on the spaces
    Again_2:
    string spaces;cin>>spaces;
    while (!isnumeric(spaces)){
        cout<<"Please Enter a valid number : ";cin>>spaces;
    }
    if(stoll(spaces)<0) {
        cout<<"Please enter a valid number !!\n\n";
        goto Again_2;
    }
    cin.ignore();


    recurse(stoll(n),stoll(spaces));




}




// Problem 11:
void problem_11(){

    //Menu and Validations on it
    cout<<"######### Welcome to the Facility Comparing Files #########\n\n";
    cout<<"Which type of compare do you want ? \n\nChoose from the following :\n1.Character by Character\n2.Word by Word \n\n ";
    cout<<"Enter your choice : ";

    string choice;cin>>choice;
    while(choice!="2"&&choice!="1"){
        cout<<"Please Enter a Valid Choice : ";
        cin>>choice;
    }
    cin.ignore();
    //Enter the files and some validations on them
    cout<<"Please Enter the file names !\n\n";


    cout<<"Enter the first file name : ";
    string name1,name2;
    getline(cin,name1);
    name1= validation(name1);


    cout<<"Enter the second file name : ";

    getline(cin,name2);
    name2= validation(name2);


    ifstream files1 (name1);
    ifstream  files2 (name2);

    //First choice is char to char
    if(choice=="1"){

        char c1=files1.get() ,c2=files2.get(),k1,k2;


        ll number=1;
        while(!files1.eof()&&!files2.eof()){

            if(c1!=c2){

                break;
            }
            //count the number of lines
            if(c1 =='\n'){
                number++;
            }
            // the past char before taking new ones and closing the loop to keep them for usage in the next lines
            k1=c1;k2=c2;
            c1=files1.get(); c2=files2.get();
        }
        // counting number of lines


        if(c1==EOF && c2==EOF)
            cout<<"The two files are identical \n";
        else if( c1==EOF && c2!=EOF) {// if file1 is subset from file2
            cout << "The two files are not identical \n";

            if(c2=='\n'){
                cout<<"Line : "<<++number<<'\n'<<"First File : No line \n"<<"Second File : \'"<<"\\n"<<"\'\n";
            }else{
                cout<<"Line : "<<number<<'\n'<<"First File :  \'"<<k1<<'\''<<'\n'<<"Second File : \'"<<c2<<'\''<<'\n';
            }

        }else if( c1!=EOF && c2==EOF ){// if file2 is subset from file1
            cout << "The two files are not identical \n";

            if(c1=='\n'){
                cout<<"Line : "<<++number<<"First File : \'"<<"\\n"<<'\''<<'\n'<<"Second File :  No line"<<"\n";
            }else{
                cout<<"Line : "<<number<<"First File :  \'"<<c1<<'\''<<'\n'<<"Second File : \'"<<k2<<'\''<<'\n';
            }

        }else{// the first difference before getting to the end of any file
            cout << "The two files are not identical \n";
            if(c1=='\n')

                cout<<"Line : "<<number<<"\nFirst file : \'"<<"\\n"<<"\'"<<'\n'
                    <<"Second File  : \'"<<c2<<"\'\n";
            if(c2=='\n')
                cout<<"Line : "<<number<<"\nFirst file : \'"<<c1<<"\'"<<'\n'
                    <<"Second File  : \'"<<"\\n"<<"\'\n";
            else
                cout<<"Line : "<<number<<"\nFirst file : \'"<<c1<<"\'"<<'\n'
                    <<"Second File  : \'"<<c2<<"\'\n";

        }



    }else{// if we are going  to compare word to word

        string word1,word2;
        char c1,c2;
        int number=1;
        c1=files1.get();c2=files2.get();
        while (!files1.eof()&&!files2.eof()){

            int number1=0, number2=0;
            while (c1=='\n'||c1==' '){//as here we skip the spaces and the tabs and the new lines
                if(c1=='\n')
                    number1++;
                c1=files1.get();
                if(!word1.empty()){ word1.clear(); }
            }

            while (c2=='\n'||c2==' '){//as here we skip the spaces and the tabs and the new lines
                if(c2=='\n')
                    number2++;
                c2=files2.get();
                if(!word2.empty()){ word2.clear(); }
            }
            word1+=c1;word2+=c2;
            //we say the difference in the line which has the largest index of lines
           number+=max(number1,number2);

            if(word1!=word2)//We compare word to word
            {
                break;
            }
            c1=files1.get();c2=files2.get();

        }
       if(c1==EOF&&c2==EOF){
           cout<<"The two files are identical\n";
       }else if(c1==EOF && c2!=EOF){// if the first file is subset from the second file
                                   // it contains some cases
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
           }else{
               cout<<"The two files are not identical \n";
               word2+=c2;
               if(files2.peek()!='\n'&&files2.peek()!=' '){ files2 >> s; }

               cout <<"Line : "<<number<<'\n'<<"File 1 : "<<word1<<"\n"<<"File 2 : "<<"\""<<word2+s<<"\""<<'\n';
           }
       } else if(c1!=EOF&&c2==EOF){// if the second file is subset from the first file
                                 // it contains some cases

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
         }else{
             cout<<"The two files are not identical\n";
             if(files1.peek()!='\n'&&files1.peek()!=' ') {files1>>s;}
             word1+=c1;
             cout<<"Line : "<<number<<'\n'<<"File 1 : \""<<word1+s<<"\""<<'\n'<<"File 2 : "<<word2<<"\n";
         }

       }else{// the first difference before reaching to EOF to both files

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


        if (choice == "1") {//masculine speech into general

            problem_2();

        } else if (choice == "2") {// top 10 players

            problem_5();

        } else if (choice == "3") { //Draw of powers of 2

            problem_8();

        } else if (choice == "4") {// comparing files

            problem_11();

        } else {//exit

            cout << "\n\n    ###### Thanks for using that program ######  \n\n";
            break;

        }

    }
    return 0;
}
