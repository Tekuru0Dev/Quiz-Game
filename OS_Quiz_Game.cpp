#include<iostream>
using namespace std;

int score = 0;
bool isGameOver = false;
int  noOfQuestions = 5;

//Object created to use as an element in array
class Questions
{
    public:
    string statement;
    string optionA,optionB,optionC,optionD;
    string correctAnswer;

    void showQuestion();
};

void Questions::showQuestion()
{
    cout << statement << endl;
    cout << "A) " << optionA << endl;
    cout << "B) " << optionB << endl;
    cout << "C) " << optionC << endl;
    cout << "D) " << optionD << endl;
}

//If you want the game to end if you are incorrect even once
void gameOver()
{
    cout << " Try again ";
    cout << "Your score is : " << score << endl;
    isGameOver = true;
}

Questions ques[5];

void SetUp()
{
    ques[0].statement = "When can the binding of instructions and data to memory addresses be done?";
    ques[0].optionA = "Load Time";
    ques[0].optionB = "Compile Time";
    ques[0].optionC = "Execution Time";
    ques[0].optionD = "All of the Above";
    ques[0].correctAnswer = "D";

    ques[1].statement = "The two types of Semaphores are ?";
    ques[1].optionA = "Counting and Decimal";
    ques[1].optionB = "Counting and Binary";
    ques[1].optionC = "Counting and Mutex";
    ques[1].optionD = "None";
    ques[1].correctAnswer = "A";

    ques[2].statement = "When can the binding of instructions and data to memory addresses be done?";
    ques[2].optionA = "Load Time";
    ques[2].optionB = "Compile Time";
    ques[2].optionC = "Execution Time";
    ques[2].optionD = "All of the Above";
    ques[2].correctAnswer = "B";

    ques[3].statement = "Thread is a";
    ques[3].optionA = "Light Weight Process";
    ques[3].optionB = "Heavy Weight Process";
    ques[3].optionC = "Multi Process";
    ques[3].optionD = "I/O Process";
    ques[3].correctAnswer = "A";

    ques[4].statement = "Thread is not shared among which of theses ";
    ques[4].optionA = "Stack";
    ques[4].optionB = "Program counter";
    ques[4].optionC = "Both Program Counter and Stack";
    ques[4].optionD = "None";
    ques[4].correctAnswer = "C";
}

void Logic()
{
    for(int i = 0; i < noOfQuestions; i++)
    {
        string ans;
        ques[i].showQuestion();
        cin >> ans;

        for(char &c : ans) c = toupper(c);

        while(ans != "X" && ans != "A" && ans != "B" && ans != "C" && ans != "D")
        {
            cout << " Invalid Choice Try Again " << endl;
            cin >> ans;
            for(char &c : ans) c = toupper(c);
        }

        if(ans == ques[i].correctAnswer)
        {
            score += 100;
            cout << endl;
            cout << " You are correct! " << endl;
            cout << endl;
            cout << endl;
        }
        else if(ans == "X")
        {
            cout << endl;
            cout << "Game Over" << endl;
            cout << "Your Score is : " << score << endl;
            cout << endl;
            isGameOver = true;
            break;
        }
        else
        {
            cout << endl;
            cout << " You are incorrect " << endl;
            cout << endl;
            cout << endl;
            gameOver();
            if(isGameOver) break;
        }
    }

    if(!isGameOver)
    {
        cout << endl;
        cout << "Congratulations!!! You completed the quiz" << endl;
        cout << endl;
        cout << "Your Final Score is : " << score << endl;
        cout << endl;
    }
}

int main()
{
    cout << endl;
    cout << "This is a QUIZ of OS, Choose between the OPTIONS and try to COMPLETE the QUIZ, Press X to end the QUIZ" << endl;
    cout << endl;
    SetUp();    
    Logic();
    return 0;
}