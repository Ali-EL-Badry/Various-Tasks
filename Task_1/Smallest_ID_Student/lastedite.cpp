#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include<cmath>
#include <regex>
#include<fstream>
#define ll long long int

using namespace std;

//validation for integer inputs
double  validation (ll &x,string message="please enter a positive intger number")
{
    cin>>x;
//validation of the input
    while(cin.fail()||x!= trunc(x)||x<0)
    {
        cout<<message<<endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin>>x;
    }
    return x;
}



double  validation2 (int &x,ll constrain,string message="please enter a positive intger number")
{
    cin>>x;
//validation of the input
    while(cin.fail()||x!= trunc(x)||x<0||x>constrain)
    {
        cout<<message <<" your limitation is to "<<constrain<<endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cin>>x;
    }
    return x;
}


//function of problem 1
void problem1() {

    string input;
//to detect the the number of space to erase it later
    int num_of_space =0;

    string message;
//to detect if capital is needed or not
    bool capital_needed=0;
//to stop counting number of spaces and delete the right amount of it
    bool space_detected=0;

    cout << "Enter text and if you want to end write letter z in any case" <<endl;

    while (true)
    {

        getline(cin, input);

        if (input =="z"||input =="Z")  break;

        message += input + " "; // Append the line with a space

    }
//    transform every letter to lowercase
    transform(message.begin(),message.end(),message.begin(),::tolower);



    for (int i = 1; i < message.size(); ++i) {

        if (message[i]==message[i-1]&&isspace(message[i]))
        {
            num_of_space++;
            if (!space_detected)
            {
                space_detected=1;
            }
        }
        if (space_detected&&!(isspace(message[i])))
        {
//            erase the extra spaces
            message.erase(i-num_of_space,num_of_space);
// returning to the right index after deleting
            i-=num_of_space;

            space_detected=0;

            num_of_space=0;

        }
//        check if the capital letter is needed
        if (message[i]=='.'||message[i]=='?'||message[i]=='!')
        {
            capital_needed=1;
        }
        if (capital_needed&&isalpha(message[i]))
        {
            message[i]=toupper(message[i]);

            capital_needed=0;
        }
    }
    if (message[0]==' '){
        message.erase(0,1);
        message[0]=toupper(message[0]);
    }else{
        message[0]=toupper(message[0]);
    }
cout<<message<<endl;
//end of problem 1
 }

//function for problem4 ( prime numbers )

void problem4(){

    ll n;
    cout<<"please enter the number you want to get prime numbers until it\n";
   n= validation(n);
    if(n==0||n==1)
    {
        cout<<"None\n";
        return;
    }
    ll arr[n-1];

//    get an array from 2 : n
    for ( ll i = 0; i < n-1; ++i)
    {
        arr[i]=i+2;
    }

    for ( ll i = 0; i < n-2; ++i)
    {
//        to prevent dividing by 0 =>0 represent circuled elements
        if(arr[i]!=0)
        {
           for ( ll j = 2; j <=n/arr[i] ; ++j)
            {
                ll circled_index =arr[i]*j;
                if ((circled_index-2)>0&&(circled_index-2)<n)
                         {
                           arr[circled_index-2]=0;
                         }else break;
            }
        }
    }
//    print the result
    sort(arr,arr+n-1);
    for (int i = 0; i < n-1; ++i)
    {
        if (i==0){
            cout<<'{';
        }

        if (arr[i]!=0&&i!=n-2)
        {
            cout<<arr[i]<<',';
        }
        if (arr[i]!=0&&i==n-2)
        {
            cout<<arr[i]<<'}'<<endl;
        }
    }
//    end of problem4
}


//define struct domain
struct domina{
    int leftdots;
    int rightdots;

//function to get piece of domina
    void setdomina()
    {
        cout<<"please assign the side of  pieces of domina left then right "<<endl;
        cout<<"the left: "<<endl;
        this->leftdots= validation2(leftdots,6,"please enter a number from 0 :6");
        cout<<"the right: "<<endl;
        this->rightdots= validation2(rightdots,6,"please enter a number from 0 :6");
    }
//function to print dominas
    void getdomina()
    {
        cout<<this->leftdots<<'|'<<rightdots;
    }

};

//boolean function to arrange dominas and return true if it can be arranged and false if not
bool FormsDominoChain(vector<domina> & dominos,vector<domina> & organized_domina,vector<bool>&taken)
{
    if(organized_domina.size()==dominos.size())
    {
        return true;
    }
    for (int i = 0; i < dominos.size(); ++i)
    {
        if (organized_domina.empty()||(organized_domina.back().rightdots==dominos[i].leftdots&&!(taken[i])))
        {
            taken[i]=true;
            organized_domina.push_back(dominos[i]);
          bool ans=FormsDominoChain(dominos,organized_domina,taken);
            organized_domina.pop_back();
            taken[i]=false;
            if (ans) return true;
        }
    }
//    if the base case is not done return false
    return false;
}


void problem7()
{

cout<<"please enter the number of pieces from 1 to 28\n";

    int num_pieces;

    validation2(num_pieces,28);
//   original set of domina
    vector<domina>piecies(num_pieces);
//    organized domina
    vector<domina>organized_domina;
//    taken dominas as we do not want to use it again until the base case!!
    vector<bool>taken(num_pieces,false);
//get dominas
    for (int i = 0; i < num_pieces; ++i) {
        piecies[i].setdomina();
    }


    if (FormsDominoChain( piecies, organized_domina,taken))
    {
     for (int i = 0; i < num_pieces; ++i)
     {
        organized_domina[i].getdomina();
        if (i!=num_pieces-1)
        {
            cout<<" - ";
        }
     }
    } else
        {
          cout<<"the dominos can not be organized"<<endl;
        }
    cout<<endl;
}

//problem 10


void problem10(){
    ifstream replac;
    replac.open("arab.txt");//the file which we take the words from it
    string arr[49][2];
// take from reolac as input for the array
    for (int i = 0; i < 49&&!(replac.eof()); ++i)
    {
        getline(replac,arr[i][1],',');//bad word

        getline(replac,arr[i][0],'\n');//good word

    }
//    file closed
    replac.close();
cin.ignore();
    string filename;
    regex pattern ("^[a-zA-Z0-9\\s]+\\.?(?:txt)$");

    ifstream inputfile;

    cout<<"please enter the name of the file which you want to edite (with txt format) \n";
    getline(cin,filename,'\n');
//validation of the file name
    while(!regex_match(filename,pattern))
    {

        cout<<"please write it in the txt format\n";

        filename="";

        getline(cin,filename,'\n');
    }

    inputfile.open(filename);

    while(inputfile.fail())
    {
        cout<<"Failed to open it please write the name correctly\n";

        getline(cin,filename,'\n');

        while(!regex_match(filename,pattern)){

            cout<<"please write it in the txt format\n";

            filename="";

            getline(cin,filename,'\n');
        }
        inputfile.open(filename);
    }
//        end validation
cout<< "choose the name of output file: \n";
string ofname;
    getline(cin,ofname,'\n');
    //validation of outputfile name
    while(!regex_match(ofname,pattern)){

        cout<<"please write it in the txt format\n";

        filename="";

        getline(cin,ofname,'\n');
    }
    //end validation
    ofstream outputfile;
outputfile.open(ofname);
    while(!(inputfile.eof()))
    {
        string line ;
        getline(inputfile,line,'\n');

        for (int i = 0; i < 49; ++i)
        {
            auto pos=line.find(arr[i][1]);
            while(pos!=string :: npos)
            {
//               replace bad word with good word
                line.replace(pos,arr[i][1].length(),arr[i][0]);
//         edite the value of pos
                pos=line.find(arr[i][1],pos+arr[i][0].length());

            }
        }
//        print the edited line in outputfile
        outputfile<<line<<endl;
    }
cout<<"Done\n";
//close files
    inputfile.close();
    outputfile.close();
}


int main(){
//    menu
    cout<<"\n*********************************************Welcome To My Program ^_^**************************************************\n"
        <<"please read from the menu and then choose (1:5) : \n"
        <<"1- problem 1 (Correction of Spaces and Capital Letters )\n"
        <<"2- problem 4 (Prime Numbers)\n"
        <<"3- problem 7 (The Game of dominos)\n"
        <<"4- problem 10 (Message Altering to Avoid Censorship)\n"
        <<"5- Exit\n";
    while(true) {
        int choice;
        cout<<"your chosen number is :  ";
        validation2(choice, 5);
          if (choice==1)
          {
            problem1();
          }
          else if (choice==2)
          {
          problem4();
          }
          else if (choice==3)
          {
           problem7();
          }
           else if (choice==4)
          {
          problem10();
          }
           else
          {
            break;
          }
    }
}
