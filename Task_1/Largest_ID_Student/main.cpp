/*
 * @File      : A1_T1_S23_20231109.cpp
 * @brief     : This Program contains Different Problems/Games that serve different Tasks
 * @auther    : Aly El-Deen Yasser Ali Mohammed
 * @ID        : 20231109
 * @Section   : S23
 * @date      : 8 Oct 2023
 * @Details   : This program contains 4 Problems/Games :
                1) Spilt problem        : In this Problem we take the string from user then split it
                                          to a vector of words of this sentence at the delimiter place

                2) ToBinary             : In this Problem we have two ways to change number to binary
                                             I)  we change the number that we take form the user to
                                                 a binary number Range ( 0 --> LONG_LONG_MAX)
                                             II) We get all the possible number that we will get from this
                                                 prefix and suffix

                3) teddyBearPicnic      : In this Game we try to find a way to reduce the number that we
                                          take from user to 42 to win the Game

                4) phishingScanner      : In this Problem we try to give score to the email we get so user
                                          Can Determine if it is spam or no
 */

// Used Liberaries
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

/* Common Used Functions :*/

/*
 * @brief  To check the choices of the menu
 * @param  menuText It is the text that we want to print
 * @param  choices  It is the choices that is in the menu
 * @return return the last correct choice for user
 */
string check_menu(const string& menuText , vector<string>choices){
    string currentAnswer;

    while(true){
        cout << menuText ;
        getline(cin, currentAnswer);
        if(currentAnswer.size() != 1 || find(choices.begin(),choices.end(), currentAnswer) == choices.end())
            cout << "Please Enter a valid option\n" ;
        else
            break;
    }
    cin.ignore(0, '\n');

    return currentAnswer;
}

/* @brief To check if the entire string is numeric */
bool isnumeric(const string& s) {
    return all_of(s.begin(), s.end(), [](char c){
        return isdigit(c);
    });
}

/*
 * @brief  To check that the user number is
 * @param  name it is what we want from user
 * @return returns the last correct number that the user entered
 */
long long getNumberUser(const string& name = "your number"){
    string number;
    while (true){
        cout << "Enter " << name << " : ";
        getline(cin, number);
        if(isnumeric(number))
            break;
        cout << "Pls Enter a Valid Number!! \n";
    }
    return stoll(number);
}

/*
 * @brief  Spilt what we will spilt according to delimiter
 * @param  target    is the complete sentence that we get from user
 * @param  delimiter is the place that we will split at
 * @return Retutn a vector that consist of spilted strings at the place of delimiter
 */
vector<string> spilt(const string& target ,const string &delimiter){
    vector<string> result;
    string currentWord;

    for(char i : target){
        currentWord.push_back(i);
        if(i == delimiter[0]){
            currentWord.pop_back();
            result.push_back(currentWord);
            currentWord = "";
        }
    }
    result.push_back(currentWord);
    return result;
}
/* @brief  Manage user interface with this problem and take parameters */
void problem_3(){
    string target, delimiter;
    // To take the sentence from user
    cout << "Enter The sentence You want to split: ";
    getline(cin,target);

    // To check what user want
    string delimiterMenu = "Do you want Delimiter to be as Default ' ' or something else? \n1) Default\n2) Enter your Own\nYour choice : ";
    vector<string> delimiterChoices = {"1","2"};
    string menuAnswer = check_menu(delimiterMenu, delimiterChoices);


    if(menuAnswer == "1")
        delimiter = " ";
    else{
        cout << "Enter your Delimter : ";
        getline(cin,delimiter);
    }

    vector<string> result = spilt(target, delimiter);

    // To Print the Result
    cout << "Your vector = [ ";
    for(int i = 0 ; i< result.size()-1 ; i++)
        cout << "\"" << result[i] << "\", ";
    cout << "\"" << result.back() << "\" ";
    cout << "]\n";
}

/*
 * @brief  Change the number that you will get to a binary number
 * @param  number the number that the user entered
 */
void printBinary(long long number){
    if (number > 1)
        printBinary(number / 2);
    cout << number % 2;
}
/*
 * @brief  Get all the possible binary number with definite suffix
 * @param  prefix       the number that the user entered to complete on
 * @param  numberSuffix the number of suffix terms that need to be added
 */
void allPossibleBinary(const string& prefix, long long numberSuffix) {
    if (numberSuffix == 0)
        cout << prefix << " ";
    else {
        allPossibleBinary(prefix + "0", numberSuffix - 1);
        cout << " ";
        allPossibleBinary(prefix + "1", numberSuffix - 1);
    }
}

/* @brief  Manage user interface with this problem and take parameters */
void problem_6(){
    string menu = "Welcome to binary Calculator\nWhich one do you want to do ? \n1) Print Binary number of your number\n2) Print results of prefix and suffix\nYour Choice: ";
    vector<string> menuChoices = {"1", "2"};

    string menuChoice = check_menu(menu, menuChoices);

    // To changee number to binary
    if(menuChoice == "1"){
        long long number = getNumberUser();
        cout << "Your number in Binary is:";
        printBinary(number);
        cout << '\n';
    }
    // To get possible results from this prefix and suffix
    else{
        string prefix = to_string(getNumberUser("your prefix"));
        long long numberSuffix = getNumberUser("number of suffix terms");

        cout << "The possible answers are :";
        allPossibleBinary(prefix,numberSuffix);
        cout << '\n';
    }
}

/*
 * @brief  takes number of Bear and see if we can win
 * @param  numberBears the number that the game start with
 * @return Bool value with win or lose
 */
bool teddyBearPicnic(long long numberBears){
    // To check if we made it to 42 or not
    if (numberBears == 42)
        return true;
    if (numberBears < 42)
        return false;

    // First condition
    if (numberBears % 2 == 0 && teddyBearPicnic(numberBears / 2))
        return true;

    // Second condition
    if (numberBears % 3 == 0 || numberBears % 4 == 0){
        long long last_digit = numberBears % 10, second_digit = (numberBears % 100) / 10;
        long long product = last_digit * second_digit;
        if (product > 0 && teddyBearPicnic(numberBears - product))
            return true;
    }

    // Third condition
    if (numberBears % 5 == 0 && teddyBearPicnic(numberBears - 42))
        return true;

    return false;
}
/* @brief  Manage user interface with this problem and take parameters */
void problem_9(){
    cout << "Welcome to Teddy Bear picnic!!\n";
    long long numberBears = getNumberUser("the number of Bears");
    cout << (teddyBearPicnic(numberBears) ?  "You win" : "You Lose") << endl;
}

/*
 * @brief  it give each word definit number of point which its sum identify if it is scam or not
 * @param  email it is the file that contain the spam email
 */

void scamEmailDetecter(ifstream& email) {
    // Some possible words and their phishing points
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

    // Output file to store results
    string temp;
    map<string, int> wordCount;
    vector<string> finalOutput;
    long long totalValuePoints = 0;

    // Get all the words in the email file
    while (email >> temp) {
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        wordCount[temp]++;
    }

    // Iterate through the counted words and check against phishing words
    for (const auto& entry : wordCount) {
        const string& word = entry.first;
        int count = entry.second;
        if (phishingWords[word] != 0) {
            int points = count * phishingWords[word];
            string currentSentence = "Phishing term: \"" + word + "\", Occurrences: " + to_string(count) + ", Points: " + to_string(points) ;
            totalValuePoints += points;
            finalOutput.push_back(currentSentence);
        }
    }

    // Menu to know where the user want the output
    string outputMenu = "Where do you want to get the output?\n1) Terminal\n3) In another File\nYour choice:";
    vector<string> outputMenuChoice = {"1", "2", "3"};
    string choice = check_menu(outputMenu, outputMenuChoice);

    if(choice == "1"){
        for(const string &i : finalOutput )
            cout << i << endl;
        cout << "The total number of points: " << totalValuePoints <<endl;
    }
    else if(choice == "2"){
        ofstream file;string name;
        while (true) {
            cout << "Enter the path of the email file: ";
            getline(cin, name);

            // Try opening the file with the given path
            file.open(name);

            // Check if the file was successfully opened
            if (file.is_open()) {
                cout << "File opened successfully.\n";
                break;
            }
            cout << "Error: Could not open file. Please enter a valid file path.\n";
        }
        for(const string &i : finalOutput)
            file << i << endl;
        file << "The total number of points: " << totalValuePoints <<endl;
    }
}

/* @brief  Manage user interface and take parameters */
void Problem_12() {
    string name;
    ifstream file;

    cout << "Welcome to Scam Email Detector\n";

    while (true) {
        cout << "Enter the path of the email file: ";
        getline(cin, name);

        // Try opening the file with the given path
        file.open(name);

        // Check if the file was successfully opened
        if (file.is_open()) {
            cout << "File opened successfully.\n";
            break;
        }
        cout << "Error: Could not open file. Please enter a valid file path.\n";
    }

    scamEmailDetecter(file);
    cout << "Answer Executed Succesfully\n";
    file.close();
}

// Menu :
void menu(){
    // To keep Program Running
    while (true){
        // The Main Menu
        string menu = "Welcome to our Program :\nWhich one do you want ?\n1) Split Problem\n2) Binary Calculator\n3) Teddy Bear Picnic\n4) Scam Email Detector\n5) Exit\nEnter your choice: ";
        vector<string> choices = {"1","2","3","4","5"};
        string choice = check_menu(menu,choices);

        // If you want spilt problem
        if (choice == "1")
            problem_3();
        // if you want binary calculator
        else if (choice == "2")
            problem_6();
        // if you want teddy bear picnic Game
        else if (choice == "3")
            problem_9();
        // if you want scam email detector
        else if (choice == "4")
            Problem_12();
        // Exit
        else if (choice == "5"){
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        string endMenu = "Do you want to continue?\n1) Yes\n2) No\nYour choice is :";
        vector<string> endMenuChoices = {"1", "2"};
        string endChoice = check_menu(endMenu, endMenuChoices);
        if(endChoice == "2"){
            cout << "Exiting program. Goodbye!\n";
            break;
        }
    }
}

/* === Main Function === */
int main(){
    menu();
    return 0;
}
