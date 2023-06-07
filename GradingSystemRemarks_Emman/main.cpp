#include <iostream>
#include <limits>

//vars
using namespace std;
void restart();


//number input only
double getNumericInput(const std::string& prompt) {
    double input;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Number only. \n";
        } else {
            validInput = true;
        }
    }

    return input;
}


//letter input only
std::string getLetterInput(const std::string& prompt) {
    std::string input;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;
        std::cin >> input;

        bool containsNonLetter = false;
        for (char c : input) {
            if (!std::isalpha(c)) {
                containsNonLetter = true;
                break;
            }
        }

        if (containsNonLetter) {
            std::cout << "\nInvalid input. Letter only. \n";
        } else {
            validInput = true;
        }
    }

    return input;
}



//start
void start_system() {

    cout << "GRADING REMARKS SYSTEM\nby Emman P. Barrameda\n" << endl;

    std::string firstname = getLetterInput("Enter Your First Name: ");
    std::string lastname = getLetterInput("Enter Your Last Name: ");
    std::string course = getLetterInput("Enter Your Course: ");
    std::string subject = getLetterInput("Enter Your Subject: ");

    cout << "" << endl;

    double prelimQ = getNumericInput("Enter Your Prelim Quiz: ");
    double midtermQ = getNumericInput("Enter Your MidTerm Quiz: ");
    double preFinalQ = getNumericInput("Enter Your Pre-Final Quiz: ");
    double finalQ = getNumericInput("Enter Your Final Quiz: ");

    cout << "" << endl;

    double prelimEX = getNumericInput("Enter Your Prelim Exam: ");
    double midtermEX = getNumericInput("Enter Your MidTerm Exam: ");
    double preFinalEX = getNumericInput("Enter Your Pre-Final Exam: ");
    double finalEX = getNumericInput("Enter Your Final Exam: ");

    cout << "" << endl;

    //paste data
    cout << "----------------" << endl;
    cout << "= YOUR FULL NAME: " << firstname << " " << lastname << endl;

    cout << "= YOUR COURSE: " << course << endl;

    cout << "= YOUR SUBJECT: " << subject << endl;

    //computation
    double QuizAve = prelimQ+midtermQ+preFinalQ+finalQ;
    double QuizAveTotal = QuizAve/4;

    double ExamsAve = prelimEX+midtermEX+preFinalEX+finalEX;
    double ExamsAveTotal = ExamsAve/4;

    double YourGradeAveTotal = QuizAveTotal+ExamsAveTotal;
    double YourGradeAveTotal_main = YourGradeAveTotal / 2;

    cout << "= YOUR GRADE: " << YourGradeAveTotal_main << endl;
    cout<<"";

    //remarks
    if(YourGradeAveTotal_main>=98 && YourGradeAveTotal_main<=100)
		cout<<"= REMARKS: 1.0"<< endl;

    else if(YourGradeAveTotal_main>=94 && YourGradeAveTotal_main<98.99)
		cout<<"= REMARKS: 1.2"<< endl;

    else if(YourGradeAveTotal_main>=91 && YourGradeAveTotal_main<93.99)
		cout<<"= REMARKS: 1.3"<< endl;

    else if(YourGradeAveTotal_main>=87 && YourGradeAveTotal_main<90.99)
		cout<<"= REMARKS: 1.5"<< endl;

    else if(YourGradeAveTotal_main>=83 && YourGradeAveTotal_main<86.99)
		cout<<"= REMARKS: 1.8"<< endl;

    else if(YourGradeAveTotal_main>=79 && YourGradeAveTotal_main<82.99)
		cout<<"= REMARKS: 2.0"<< endl;

    else if(YourGradeAveTotal_main>=75 && YourGradeAveTotal_main<78.99)
		cout<<"= REMARKS: 2.5"<< endl;

    else if(YourGradeAveTotal_main>=70 && YourGradeAveTotal_main<74.99)
		cout<<"= REMARKS: 3.0"<< endl;

    else
        cout<<"= REMARKS: Invalid!"<<endl;

    cout << "----------------" << endl;

    //restart
    restart();

}


//ask to restart
void restart() {

    cout << "\nGo Back to Start? [Y/N]" << endl;
    char start;
    cin>> start;

    if(std::tolower(start) == 'y') {
        system("cls");
        start_system();

    } else if (std::tolower(start) == 'n') {
        cout << "Bye!" << endl;
        exit(0);

    } else {
        restart();
    }
}


//start here
int main() {
    start_system();
}



//THIS CONSOLE PROGRAM IS TESTED ON CODEBLOCKS IDE
//Copyright 2021 emmanpbarrameda
