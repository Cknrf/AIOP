/*Mearck Francis Voughn M. Odi
  Joshua Alexcy M. Caniete
  Karl Andrey Talain

  Duration: December 4, 2023 to January 17, 2024
  Date of Submission: January 17, 2024

  Assignment's title: All In One Program (AI OP)

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <iomanip>
#include <cctype>
#include <locale>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <limits>


// MAIN PROGRAM and DESIGN

void mainProgram(const std::string username);
void mainDesign();
std::string centerAlign(const std::string& str, int width);

// User Authentication
void userAuthentication();
bool login(const std::string& username, const std::string& password);
void registerUser(const std::string& username, const std::string& password, bool &userAvailable);
std::string callLogIn();


//? ENTERTAINMENT
//! 1. Riddle Game
void f_wriddleGame();
void f_chooseDificultiesRG(std::string username);
void f_easyDifficultyRG(std::string username);
void f_mediumDifficultyRG(std::string username);
void f_hardDifficultyRG(std::string username);
void f_displayResultRG(int lives, int correct, std::string username);

//! 2. Rock Paper Scissor
void f_displayRPC(int &playerChoice);
void f_computerChoice(int &computerChoice);
void f_winning(int playerChoice, int computerChoice, int &counterWin, int &counterLose);
void f_displayWeapon(int playerChoice, int computerChoice);
void f_counter(int counterWin, int counterLose);
void f_termination(int &termination, std::string username);
void f_wRockPaperScissor(std::string username);

//! 3. Number Guessing Game
void f_numberGuess(int &range, int &attempt);
void f_answerNG(int range, int attempt, int guess);
void f_wnumberGuess(std::string username);

//! 4. Coin Flip
void f_wcoinFlip (int &flip);
void f_coinSide (int flip, int &counterWin, int &counterLose);
void f_showCounter (int counterWin, int counterLose);
void f_terminationCF (int &termination, std::string username);
void f_mcoinFlip(std::string username);

//! 5. Guess the Word
void f_wGuessTheWord();
void f_displayResult(int correctCounter, int lives, int numClues, int level, std::string username);
void f_easyDifficulty(std::string username);
void f_mediumDifficulty(std::string username);
void f_hardDifficulty(std::string username);
void f_chooseDificulties(std::string username);

//! 6. Snake Game
    class SnakeGame {
    private:
        bool gameOver;
        const int width;
        const int height;
        int x, y, fruitX, fruitY, score;
        int* tailX;
        int* tailY;
        int nTail;
        std::string username;
        enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
        eDirecton dir;

    public:
        SnakeGame(int w, int h, const std::string& username) : width(w), height(h), username(username) {
            tailX = new int[100];
            tailY = new int[100];
        }

        ~SnakeGame() {
            delete[] tailX;
            delete[] tailY;
        }

        void Setup() {
            gameOver = false;
            dir = STOP;
            x = width / 2;
            y = height / 2;
            fruitX = rand() % width;
            fruitY = rand() % height;
            score = 0;
            nTail = 0;
        }

        void Draw()
    {
        system("cls"); //system("clear");
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'B' to exit\n\n";
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tInstructions:\n";
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t'w' to move upward\n";
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t's' to move downward\n";
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t'a' to move left\n";
        std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t'd' to move right\n";

        for (int i = 0; i < width+2; i++)
            std::cout << "#";
        std::cout << std::endl;
    
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0)
                    std::cout << "#";
                if (i == y && j == x)
                    std::cout << "O";
                else if (i == fruitY && j == fruitX)
                    std::cout << "F";
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            std::cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        std::cout << " ";
                }
                    
    
                if (j == width - 1)
                    std::cout << "#";
            }
            std::cout << std::endl;
        }
    
        for (int i = 0; i < width+2; i++)
            std::cout << "#";
        std::cout << std::endl;
        std::cout << "Score:" << score << std::endl;
    }
    void Input(std::string username)
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'b':
                gameOver = true;
                system("cls");
                mainProgram(username);
                break;
            
            case 'B':
                gameOver = true;
                system("cls");
                mainProgram(username);
                break;
            }
        }
    }
    void Logic()
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < nTail; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir)
        {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
        }
        //if (x > width || x < 0 || y > height || y < 0)
        //  gameOver = true;
        if (x >= width) x = 0; else if (x < 0) x = width - 1;
        if (y >= height) y = 0; else if (y < 0) y = height - 1;
    
        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y)
                gameOver = true;
    
        if (x == fruitX && y == fruitY)
        {
            score += 10;
            fruitX = rand() % width;
            fruitY = rand() % height;
            nTail++;
        }
    }

        void RunGame(std::string username) {
            std::string choice;
            Setup();
            while (!gameOver) {
                Draw();
                Input(username);
                Logic();
                Sleep(100);
            }

    do{
            std::cout << "Want to play again? (Y/N): ";
            std::cin >> choice;

            if(choice == "N" || choice == "n"){
                system("cls");
                mainProgram(username);
            }

            if(choice == "Y" || choice == "y"){
                system("cls");
                RunGame(username);
            }


    }while(choice != "Y" && choice != "y");


        }
    };

//! 7. Tic-Tac-Toe
void f_ticTacToe(std::string username);
void display_board(char board[10]);
bool win_check(char board[10], char player);
bool draw_check(char board[10]);
void player_turn(char board[10], char player);
void ai_turn(char board[10], char ai);

//! 8. ChatBox 
void f_chatBox(std::string username);

//? UTILITIES
//! 1. Simple Calculator
void f_simpleCalculator(std::string username);
void f_terminationSC(std::string username);

//! 2. Student Grade Calculator
void f_studentCalculator(int &arraySize, int array[]);
void f_average(int arraySize, int array[]);
void f_highestLowest(int arraySize, int array[]);
void f_mstudentCalculator(std::string username);
void f_terminationGC(std::string username);

//! 3. BMI Calculator
void f_wbmiCalculator(std::string username);

//! 4. Tip Calculator
void f_wtipCalculator(std::string username);

//! 5. Unit Converter
void f_wunitConverter(std::string username);

//! 6. Word Counter
void f_wdisplaywordCounter();
void f_wwordCounter(std::string username);

//! 7. Dice Roller
void f_wdiceRoller(std::string username);

//! 8. Currency Converter
void f_wcurrencyConverter(std::string username);

//! 9. Pattern Maker
void f_wpatternMaker(std::string username);

//? STUDIES
//! 1. Random Fact Generator
void f_wrandomFact(std::string username);

//! 2. Quiz 
void f_wquizGame();
void f_chooseDifficultyQG(std::string username);
void f_easyDifficultyQG(std::string username);
void f_mediumDifficultyQG(std::string username);
void f_hardDifficultyQG(std::string username);
void f_displayResultQG(int correct, std::string username);

//? SECURITY
//! 1. Password Generator
void f_wpasswordGenerator(std::string username);

//? PERSONAL DATA
//! 1. To Do List
struct User {
    std::string username;
    std::string password;
};
struct Task {
    std::string name;
    std::string priority;
    std::string deadline;
    std::string description;
    std::string product;
    std::string date;
    std::string cost;
    std::string password;
    int balance;
};
void addTask(const std::string& username, const Task& task);
void viewTasks(const std::string& username);
void deleteTask(const std::string& username);
std::string trim(const std::string& str);
void f_toDoList(std::string username);

//! 2. Expense Tracker
void f_wexpenseTracker(std::string username);
void addExpense(const std::string& username, const Task& task);
void viewExpense(const std::string& username);
void deleteExpense(const std::string& username);

//! 3. Password Manager
void f_wpasswordManager(std::string username);
void addAccount(const std::string& username, const Task& task);
void viewAccount(const std::string& username);
void deleteAccount(const std::string& username);

//! 4. Reminder App
void f_reminder(std::string username);
void addReminder(const std::string& username, const Task& task);
void viewReminder(const std::string& username);
void deleteReminder(const std::string& username);

//! 5. Bank Account Management
void f_bankAccount(std::string username);
void checkBalance(const std::string username);
void deposit(const std::string& username);
void withdraw(const std::string& username);


int main(){

    mainDesign();
    userAuthentication();

    
    return 0;

}

// Main Program
void userAuthentication(){
    int mChoice = 0;
    std::string username, password;
    bool userAvailable = true;

    do{
    system("cls");
    std::cout << "Welcome to AI OP\n";
    std::cout << "Choose following options:\n";
    std::cout << "1. Register\n";
    std::cout << "2. Log-in\n";
    std::cout << "3. Continue as a guest\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> mChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            mChoice = 10;
        }
    }while(mChoice != 1 && mChoice != 2 && mChoice != 3 && mChoice !=4);

    switch(mChoice){
        case 1: 
            system("cls");
            std::cout << "Registration:\n\n";
            do{
                do{
                std::cout << "Enter username: ";
                std::cin >> username;

                if(username == "Guest"){
                    system("cls");
                    std::cout << "Username should not be named Guest. Try Again!\n\n";
                }

                if(username == "B" || username == "b"){
                    system("cls");
                    std::cout << "Username should not be 'b' or 'B'. Try Again!\n\n";
                }

                }while(username == "B" || username == "b" || username == "Guest");

                std::cout << "Enter password(password must not contain any spaces): ";
                std::cin >> password;


                registerUser(username, password, userAvailable);
            } while(!userAvailable);

            std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            char anyKey;
            std::cin.get(anyKey); 
            system("cls");
            std::cout << "Login successful!" << "\t\tHello there " << username << "!\n";
            mainProgram(username);
        
        break;

        case 2:
            system("cls");
            username = callLogIn();
            mainProgram(username);
        
        break;

        case 3: 
            system("cls");
            username = "Guest";
            mainProgram(username);
            break;

        case 4:
            system("cls");
            std::cout << "Thank you for using AI OP\n";
            break;
    }

}

void mainProgram(const std::string username){
    int categories = 0;
    int choice = 0;
    std::string password;
    
    

    
    do{
    categories = 0;
    std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to exit the program\n";
    std::cout << "1. Entertainment\n";
    std::cout << "2. Utilities\n";
    std::cout << "3. Studies\n";
    std::cout << "4. Security\n";
    std::cout << "5. " << username << "'s Data\n";
    std::cout << "6. Switch user account\n";
    std::cout << "Choose Categories: ";
    std::cin >> categories;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            categories = 10;
        }
    
   

    system("cls");

    }while(categories != 1 && categories != 2 && categories != 3 && categories != 4 && categories !=5 && categories != 6 && categories != 0);


    switch(categories){
        case 1: 
        do{
            system("cls");
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
            std::cout << "Entertainment:\n";
            std::cout << "1. Riddle Game\n";
            std::cout << "2. Rock Paper Scissor\n";
            std::cout << "3. Number Guessing Game\n";
            std::cout << "4. Coin Flip\n";
            std::cout << "5. Guess the Word\n";
            std::cout << "6. Snake\n";
            std::cout << "7. Tic-Tac-Toe\n";
            std::cout << "8. ChatBox\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }
        }while(!(choice >= 1 && choice <= 8) && choice != 0);

                        switch(choice){
                            case 0:
                                    system("cls");
                                    mainProgram(username);
                                    break;
                            case 1: 
                                    system("cls");
                                    f_wriddleGame();
                                    f_chooseDificultiesRG(username);
                                    break;
                            
                            case 2: 
                                    system("cls");
                                    f_wRockPaperScissor(username);
                                    break;

                            case 3: 
                                    system("cls");
                                    f_wnumberGuess(username);
                                    break;
                            
                            case 4: 
                                    system("cls");
                                    f_mcoinFlip(username);
                                    break;
                            
                            case 5: 
                                    system("cls");
                                    //* TODO: Guess The Word
                                    f_wGuessTheWord();
                                    f_chooseDificulties(username);
                                    break;
                            
                            case 6: {
                                    system("cls");
                                    SnakeGame snakeGame(20, 20, username);
                                    snakeGame.RunGame(username);
                                    break;
                            }

                            case 7: 
                                    system("cls");
                                    f_ticTacToe(username);
                                    break;
                                    
                            case 8:
                                    system("cls");
                                    f_chatBox(username);
                                    break;
                        }

            break;

        case 2: 
            do{
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
            std::cout << "Utilities:\n";
            std::cout << "1. Simple Calculator\n";
            std::cout << "2. Student Grade Calculator\n";
            std::cout << "3. BMI Calculator\n";
            std::cout << "4. Tip Calculator\n";
            std::cout << "5. Unit Converter\n";
            std::cout << "6. Word Counter\n";
            std::cout << "7. Dice Roller\n";
            std::cout << "8. Currency Converter\n";
            std::cout << "9. Pattern Maker\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }
            system("cls");
            }while(!(choice >= 1 && choice <= 9) && choice != 0);

                        switch(choice){
                            case 0: 
                                    system("cls");
                                    mainProgram(username);
                                    break;

                            case 1: 
                                    system("cls");
                                    f_simpleCalculator(username);
                                    break;
                            
                            case 2: 
                                    system("cls");
                                    f_mstudentCalculator(username);
                                    break;

                            case 3: 
                                    system("cls");
                                    f_wbmiCalculator(username);
                                    break;
                            
                            case 4: 
                                    system("cls");
                                    f_wtipCalculator(username);
                                    break;

                            case 5: 
                                    system("cls");
                                    f_wunitConverter(username);
                                    break;

                            case 6: 
                                    system("cls");
                                    f_wdisplaywordCounter();
                                    f_wwordCounter(username);
                                    break;

                            case 7: 
                                    system("cls");
                                    f_wdiceRoller(username);
                                    break;

                            case 8: 
                                    system("cls");
                                    f_wcurrencyConverter(username);
                                    break;

                            case 9: 
                                    system("cls");
                                    f_wpatternMaker(username);
                                    break;

                                    
                        }

            break;
        
        case 3: 
            do{
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
            std::cout << "Studies:\n";
            std::cout << "1. Random Fact Generator\n";
            std::cout << "2. Quiz\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }
            system("cls");
            }while(choice != 1 && choice != 2 && choice != 0);

                        switch(choice){

                            case 0: 
                                    system("cls");
                                    mainProgram(username);
                                    break;
                            
                            case 1: 
                                    system("cls");
                                    f_wrandomFact(username);
                                    break;
                            
                            case 2: 
                                    system("cls");
                                    f_wquizGame();
                                    f_chooseDifficultyQG(username);
                                    break;

                        }

            break;

        case 4: 
            do{
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
            std::cout << "Security:\n";
            std::cout << "1. Password Generator\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }
            system("cls");
            }while(choice != 1 && choice != 0);

                    switch(choice){

                        case 0:
                                system("cls");
                                mainProgram(username);
                                break;

                        case 1: 
                                system("cls");
                                f_wpasswordGenerator(username);
                                break;
                                
                    }
            break;

        case 5:
            if(username == "Guest"){
                system("cls");
                std::cout << "Access Denied: You must log-in first\n";
                std::cout << "Press any key to continue: ";
            // Clear input buffer
            std::cin.clear();
            // Wait for Enter key
            std::cin.get();
            system("cls");
            mainProgram(username);
            }
            do{
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
            std::cout << username << "'s Data\n";
            std::cout << "1. To-Do-List\n";
            std::cout << "2. Expense Tracker\n";
            std::cout << "3. Account Manager\n";
            std::cout << "4. Reminder App\n";
            std::cout << "5. Bank Account\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }
            system("cls");
            }while(choice != 1 && choice !=2 && choice != 3 && choice !=4 && choice != 5 && choice != 0);



                    switch(choice){

                        case 0: 
                                system("cls");
                                mainProgram(username);

                        case 1:   
                                system("cls");
                                f_toDoList(username);
                                break;
                        
                        case 2: 
                                system("cls");
                                f_wexpenseTracker(username);
                                break;

                        case 3:
                                system("cls");
                                f_wpasswordManager(username);
                                break;

                        case 4: 
                                system("cls");
                                f_reminder(username);
                                break;
                        
                        case 5: 
                                system("cls");
                                f_bankAccount(username);
                                break;

                        
                    }

        case 6: 
            system("cls");
            userAuthentication();
            break;

        case 0:
            system("cls");
            std::cout << "Thank you for using AI OP";
            break;
    }

}

void mainDesign(){
    int terminalWidth = 200; 
    


   
    std::cout<< std::endl;
    std::cout << centerAlign("              #-          -++++++.                .=+******=:         +++++++++==:.         ", terminalWidth) << "\n";
	std::cout << centerAlign("            #@@.          .+@@=                =%%=.     .=%@*:      ..@@%:  .:-*@%+        ", terminalWidth) << "\n";
    std::cout << centerAlign("           =@%@%           +@@.              -@@+           +@@*       @@#       :@@%       ", terminalWidth) << "\n";
    std::cout << centerAlign("          :@:.@@*          +@@.             :@@+             =@@#      @@#        %@@:      ", terminalWidth) << "\n";
    std::cout << centerAlign("          %+  -@@=         +@@.             %@@               #@@-     @@#        @@@       ", terminalWidth) << "\n";
    std::cout << centerAlign("         *%    +@@.        +@@.            .@@#               =@@#     @@#      .#@%:       ", terminalWidth) << "\n";
    std::cout << centerAlign("        -@.     %@%        +@@.            .@@%               =@@*     @@%---=+#%*-         ", terminalWidth) << "\n";
    std::cout << centerAlign("       .@%******#@@#       +@@.             %@@:              *@@-     @@#::::.             ", terminalWidth) << "\n";
    std::cout << centerAlign("       ##        -@@+      +@@.             :@@%.            :@@*      @@#                  ", terminalWidth) << "\n";
    std::cout << centerAlign("      +@.         *@@:     +@@.              :%@%:          -@@=       @@#                  ", terminalWidth) << "\n";
    std::cout << centerAlign("    .+@*:.       .*@@#::  :%@@-:               =#@#=:    :=%%+.      .=@@#::.               ", terminalWidth) << "\n";
    std::cout << centerAlign("     -----:       ------- :------.                 :=+***++-.         -------:              ", terminalWidth) << "\n";

    

    std::cout << "\n" << centerAlign("=====================-ALL-IN-ONE-PROGRAM-=======================", terminalWidth) << "\n";
    std::cout << "\n" << centerAlign("                            @CKNRF                              ", terminalWidth) << "\n";
    std::cout << "\n\n" << centerAlign("Press any key to continue: ", terminalWidth);
    // Clear input buffer
    std::cin.clear();
    // Wait for Enter key
    std::cin.get();

    system("cls");
}

std::string centerAlign(const std::string& str, int width){
    int padding = (width - str.length()) / 2;
    return std::string(padding, ' ') + str;
}



// User Authentication

bool login(const std::string& username, const std::string& password){
    std::ifstream userFile(username + ".txt");

    if (!userFile.is_open()) {
        return false;
        
    }

    std::string storedPassword;
    userFile >> storedPassword;

    if (storedPassword == password) {
        system("cls");
        std::cout << "Login successful!" << "\t\tHello there " << username << "!\n";
        return true;
    } else {
        return false;
    }
}

void registerUser(const std::string& username, const std::string& password, bool &userAvailable){
    // Check if the user already exists
    system("cls");
    std::ifstream existingUser(username + ".txt");
    if (existingUser.is_open()) {
        std::cout << "Username already exists. Please choose a different username.\n";
        userAvailable = false;
        return;
    }
    existingUser.close();

    // If the user doesn't exist, proceed with registration
    std::ofstream userFile(username + ".txt");
    userFile << password << "\n";
    userFile.close();

    std::cout << "Registration Successful!\n";
    userAvailable = true;
}

std::string callLogIn(){
    std::string username, password;
    std::cout << "Log-In:";
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'B' to back\n";
    std::cout << "\n\nEnter username: ";
    std::cin >> username;

    if(username == "B" || username == "b"){
        system("cls");
        userAuthentication();
    }

    std::cout << "Enter password: ";
    char ch;

    do{

         ch = _getch();  // Use _getch() to get a character without echoing it to the console

        // Break the loop on Enter
        if (ch == 13) {
            break;
        } 
        // Handle backspace
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Move the cursor back, print a space, move the cursor back again
            }
        } 
        // Handle other characters
        else {
            password.push_back(ch);
            std::cout << '*';
        }

    }while(true);

    if (login(username, password)){
        return username;
    }
    else{
        system("cls");
        std::cout << "Username/Password is incorrect. Please Try Again!" << "\t\tPress 'B' to go to the main menu\n\n";
        return callLogIn();
    }
    return username;
}


//? PERSONAL DATA
//! 1. To Do List
void f_toDoList(std::string username){
                        system("cls");

                        std::string password;
                        int choice = 0;

                        do{
                        password.clear();
                        std::cout << "\t\t\t\t\t\t\t\t\t\tPress 'B' to back\n";
                        std::cout << "Enter your password: ";

         char ch;

                        do{

        
         ch = _getch();  // Use _getch() to get a character without echoing it to the console

        // Break the loop on Enter
        if (ch == 13) {
            break;
        } 
        // Handle backspace
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Move the cursor back, print a space, move the cursor back again
            }
        } 
        // Handle other characters
        else {
            password.push_back(ch);
            std::cout << '*';
        }

    }while(true);


                        if(password == "B" || password == "b"){
                            system("cls");
                            mainProgram(username);
                        }

                        if(login(username, password) != true){
                         system("cls");
                         std::cout << "Incorrect password. Please try again.\n";
                        }

                        }while(login(username, password) != true);

                        if (login(username, password)) {
                            
        Task task;

        do {
            std::cout << "\n1. Add Task\n";
            std::cout << "2. View Tasks\n";
            std::cout << "3. Delete Task\n";
            std::cout << "4. Back\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
            std::cout << "\n";

            switch (choice) {
                case 1:
                    system("cls");
                    std::cout << username << "'s To-Do-List\n\n";
                    do{
                        std::cout << "Enter task name: ";
                        std::getline(std::cin, task.name);

                        if(task.name.length() > 20){
                            system("cls");
                            std::cout << "Task's name can't exceed 20 characters\n\n";
                        }
                    } while(task.name.length() > 20);

                    do{
                        std::cout << "Enter deadline: ";
                        std::getline(std::cin, task.deadline);

                        if(task.deadline.length() > 20){
                            system("cls");
                            std::cout << "Deadline can't exceed 20 characters\n\n";
                        }
                    } while(task.deadline.length() > 20);

                    do{
                        std::cout << "Enter priority level (low, medium, high): ";
                        std::getline(std::cin, task.priority);

                        if(task.priority.length() > 20){
                            system("cls");
                            std::cout << "Priority level can't exceed 20 characters\n\n";
                        }
                    } while(task.priority.length() > 20);
                    
                    do{
                        std::cout << "Enter description: ";
                        std::getline(std::cin, task.description);

                        if(task.description.length() > 100){
                            system("cls");
                            std::cout << "Description can't exceed 100 characters\n\n";
                        }
                    } while(task.description.length() > 100);

                    addTask(username, task);
                    break;

                case 2:
                    viewTasks(username);
                    break;

                case 3:
                    deleteTask(username);
                    break;

                case 4:
                    system("cls");
                    mainProgram(username);
                    break;

                default:
                    system("cls");
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
    else{
        system("cls");
        std::cout << "Username/Password is incorrect. Please Try Again!" << "\t\tPress 'B' to go to the main menu\n\n";
        callLogIn();
    }
}

void addTask(const std::string& username, const Task& task) {
    std::ofstream taskFile(username + "_tasks.txt", std::ios::app);
    
    taskFile << task.name << " | " << task.deadline << " | " << task.priority << " | " << task.description << "\n";
    taskFile.close();
    system("cls");
    std::cout << "Task added!\n";
}

void viewTasks(const std::string& username) {
    std::ifstream taskFile(username + "_tasks.txt");
    system("cls");

    if (!taskFile.is_open()) {
        system("cls");
        std::cout << "No tasks found.\n";
        return;
    }

    Task task;
    const int nameWidth = 30;
    const int deadlineWidth = 30;
    const int priorityWidth = 30;
    const int descriptionWidth = 70;

    std::cout << std::setw(nameWidth) << std::left << "Name:"
              << std::setw(deadlineWidth) << std::left << "Deadline:"
              << std::setw(priorityWidth) << std::left << "Priority:"
              << std::setw(descriptionWidth) << std::left << "Description:" << "\n";
    std::cout << std::setw(nameWidth + deadlineWidth + priorityWidth + descriptionWidth) << std::setfill('-') << "" << "\n";
    std::cout << std::setfill(' ');

    while (std::getline(taskFile, task.name, '|') >> std::ws &&
           std::getline(taskFile, task.deadline, '|') >> std::ws &&
           std::getline(taskFile, task.priority, '|') >> std::ws &&
           std::getline(taskFile, task.description)) {
        // Display task details
        std::cout << std::setw(nameWidth) << std::left << task.name
                  << std::setw(deadlineWidth) << std::left << task.deadline
                  << std::setw(priorityWidth) << std::left << task.priority;

        // Display description with line breaks for long descriptions
        std::istringstream descriptionStream(task.description);
        std::string line;
        while (std::getline(descriptionStream, line, ' ')) {
            if (line.length() + 1 + descriptionWidth < nameWidth + deadlineWidth + priorityWidth + descriptionWidth) {
                std::cout << line << " ";
            } else {
                std::cout << "\n" << std::setw(nameWidth + deadlineWidth + priorityWidth) << "" << std::setw(descriptionWidth) << std::left << line << " ";
            }
        }

        std::cout << "\n\n";
    }

    taskFile.close();
}

void deleteTask(const std::string& username) {
    std::string taskName;
    std::cout << "Enter the name of the task to delete: ";
    std::getline(std::cin, taskName);

    std::ifstream inFile(username + "_tasks.txt");
    std::ofstream outFile("temp.txt");

    Task task;
    bool taskFound = false;

    while (std::getline(inFile, task.name, '|') >> std::ws &&
           std::getline(inFile, task.deadline, '|') >> std::ws &&
           std::getline(inFile, task.priority, '|') >> std::ws &&
           std::getline(inFile, task.description)) {
        if (trim(task.name) == trim(taskName)) {
    taskFound = true;
    system("cls");
    std::cout << "Task deleted!\n";
} else {
    outFile << task.name << " | " << task.deadline << " | " << task.priority << " | " << task.description << "\n";
}
    }

    inFile.close();
    outFile.close();

    if (!taskFound) {
        system("cls");
        std::cout << "Task not found.\n";
    } else {
        remove((username + "_tasks.txt").c_str());
        rename("temp.txt", (username + "_tasks.txt").c_str());
    }
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return (first != std::string::npos && last != std::string::npos) ? str.substr(first, last - first + 1) : "";
}

//! 2. Expense Tracker
void f_wexpenseTracker(std::string username){
    system("cls");
                        
                        std::string password;
                        int choice = 0;

                        do{
                        password.clear();
                        std::cout << "\t\t\t\t\t\t\t\t\t\tPress 'B' to back\n";
                        std::cout << "Enter your password: ";

                        char ch;

                        do{

        
         ch = _getch();  // Use _getch() to get a character without echoing it to the console

        // Break the loop on Enter
        if (ch == 13) {
            break;
        } 
        // Handle backspace
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Move the cursor back, print a space, move the cursor back again
            }
        } 
        // Handle other characters
        else {
            password.push_back(ch);
            std::cout << '*';
        }

    }while(true);


                        if(password == "B" || password == "b"){
                            system("cls");
                            mainProgram(username);
                        }

                        if(login(username, password) != true){
                         system("cls");
                         std::cout << "Incorrect password. Please try again.\n";
                        }

                        }while(login(username, password) != true);

                        if (login(username, password)){
                            Task task;

        do {
            std::cout << "\n1. Add Expenses\n";
            std::cout << "2. View Expenses\n";
            std::cout << "3. Delete Expenses\n";
            std::cout << "4. Back\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
            std::cout << "\n";

            switch (choice) {
                case 1:
                    system("cls");
                    std::cout << username << "'s Expense\n\n";
                    do{
                        std::cout << "Enter the product: ";
                        std::getline(std::cin, task.product);

                        if(task.product.length() > 20){
                            system("cls");
                            std::cout << "Product can't exceed 20 characters\n\n";
                        }
                    } while(task.product.length() > 20);

                    do{
                        std::cout << "Enter the date: ";
                        std::getline(std::cin, task.date);

                        if(task.date.length() > 20){
                            system("cls");
                            std::cout << "Date can't exceed 20 characters\n\n";
                        }
                    } while(task.date.length() > 20);

                    do{
                        std::cout << "Enter the amount of the product: ";
                        std::getline(std::cin, task.cost);

                        if(task.cost.length() > 20){
                            system("cls");
                            std::cout << "Cost can't exceed 20 characters\n\n";
                        }
                    } while(task.cost.length() > 20);
                    
                    do{
                        std::cout << "Enter description: ";
                        std::getline(std::cin, task.description);

                        if(task.description.length() > 100){
                            system("cls");
                            std::cout << "Description can't exceed 100 characters\n\n";
                        }
                    } while(task.description.length() > 100);

                    addExpense(username, task);
                    break;

                case 2:
                    viewExpense(username);
                    break;

                case 3:
                    deleteExpense(username);
                    break;

                case 4:
                    system("cls");
                    mainProgram(username);
                    break;

                default:
                    system("cls");
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
    else{
        system("cls");
        std::cout << "Username/Password is incorrect. Please Try Again!" << "\t\tPress 'B' to go to the main menu\n\n";
        callLogIn();
    }
}

void addExpense(const std::string& username, const Task& task) {
    std::ofstream taskFile(username + "_expense.txt", std::ios::app);
    
    taskFile << task.product << " | " << task.date << " | " << task.cost << " | " << task.description << "\n";
    taskFile.close();
    system("cls");
    std::cout << "Expense added!\n";
}

void viewExpense(const std::string& username) {
    std::ifstream taskFile(username + "_expense.txt");
    system("cls");

    if (!taskFile.is_open()) {
        system("cls");
        std::cout << "No expense found.\n";
        return;
    }

    Task task;
    const int nameWidth = 30;
    const int deadlineWidth = 30;
    const int priorityWidth = 30;
    const int descriptionWidth = 70;

    std::cout << std::setw(nameWidth) << std::left << "Product:"
              << std::setw(deadlineWidth) << std::left << "Date:"
              << std::setw(priorityWidth) << std::left << "Cost:"
              << std::setw(descriptionWidth) << std::left << "Description:" << "\n";
    std::cout << std::setw(nameWidth + deadlineWidth + priorityWidth + descriptionWidth) << std::setfill('-') << "" << "\n";
    std::cout << std::setfill(' ');

    while (std::getline(taskFile, task.product, '|') >> std::ws &&
           std::getline(taskFile, task.date, '|') >> std::ws &&
           std::getline(taskFile, task.cost, '|') >> std::ws &&
           std::getline(taskFile, task.description)) {
        // Display task details
        std::cout << std::setw(nameWidth) << std::left << task.product
                  << std::setw(deadlineWidth) << std::left << task.date
                  << std::setw(priorityWidth) << std::left << task.cost;

        // Display description with line breaks for long descriptions
        std::istringstream descriptionStream(task.description);
        std::string line;
        while (std::getline(descriptionStream, line, ' ')) {
            if (line.length() + 1 + descriptionWidth < nameWidth + deadlineWidth + priorityWidth + descriptionWidth) {
                std::cout << line << " ";
            } else {
                std::cout << "\n" << std::setw(nameWidth + deadlineWidth + priorityWidth) << "" << std::setw(descriptionWidth) << std::left << line << " ";
            }
        }

        std::cout << "\n\n";
    }

    taskFile.close();
}

void deleteExpense(const std::string& username) {
    std::string taskName;
    std::cout << "Enter the name of the expense to delete: ";
    std::getline(std::cin, taskName);

    std::ifstream inFile(username + "_expense.txt");
    std::ofstream outFile("temp.txt");

    Task task;
    bool taskFound = false;

    while (std::getline(inFile, task.product, '|') >> std::ws &&
           std::getline(inFile, task.date, '|') >> std::ws &&
           std::getline(inFile, task.cost
           , '|') >> std::ws &&
           std::getline(inFile, task.description)) {
        if (trim(task.product) == trim(taskName)) {
    taskFound = true;
    system("cls");
    std::cout << "Expense deleted!\n";
} else {
    outFile << task.product << " | " << task.date << " | " << task.cost << " | " << task.description << "\n";
}
    }

    inFile.close();
    outFile.close();

    if (!taskFound) {
        system("cls");
        std::cout << "Expense not found.\n";
    } else {
        remove((username + "_expense.txt").c_str());
        rename("temp.txt", (username + "_expense.txt").c_str());
    }
}

//! 3. Password Manager
void f_wpasswordManager(std::string username){
    system("cls");

                        std::string password;
                        int choice = 0;

                        do{
                        password.clear();
                        std::cout << "\t\t\t\t\t\t\t\t\t\tPress 'B' to back\n";
                        std::cout << "Enter your password: ";

                        char ch;

                        do{

        
         ch = _getch();  // Use _getch() to get a character without echoing it to the console

        // Break the loop on Enter
        if (ch == 13) {
            break;
        } 
        // Handle backspace
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Move the cursor back, print a space, move the cursor back again
            }
        } 
        // Handle other characters
        else {
            password.push_back(ch);
            std::cout << '*';
        }

    }while(true);


                        if(password == "B" || password == "b"){
                            system("cls");
                            mainProgram(username);
                        }

                        if(login(username, password) != true){
                         system("cls");
                         std::cout << "Incorrect password. Please try again.\n";
                        }

                        }while(login(username, password) != true);

                        if (login(username, password)){
                            Task task;

        do {
            std::cout << "\n1. Store account information\n";
            std::cout << "2. View account\n";
            std::cout << "3. Delete account\n";
            std::cout << "4. Back\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
            std::cout << "\n";

            switch (choice) {
                case 1:
                    system("cls");
                    std::cout << username << "'s Account Manager\n\n";
                    do{
                        std::cout << "Enter the username: ";
                        std::getline(std::cin, task.name);

                        if(task.name.length() > 20){
                            system("cls");
                            std::cout << "Username can't exceed 20 characters\n\n";
                        }
                    } while(task.name.length() > 20);

                    do{
                        std::cout << "Enter the password: ";
                        std::getline(std::cin, task.password);

                        if(task.password.length() > 20){
                            system("cls");
                            std::cout << "Password can't exceed 20 characters\n\n";
                        }
                    } while(task.password.length() > 20);

                    addAccount(username, task);
                    break;

                case 2:
                    viewAccount(username);
                    break;

                case 3:
                    deleteAccount(username);
                    break;

                case 4:
                    system("cls");
                    mainProgram(username);
                    break;

                default:
                    system("cls");
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
    else{
        system("cls");
        std::cout << "Username/Password is incorrect. Please Try Again!" << "\t\tPress 'B' to go to the main menu\n\n";
        callLogIn();
    }
 }

void addAccount(const std::string& username, const Task& task) {
    std::ofstream taskFile(username + "_account.txt", std::ios::app);
    
    taskFile << task.name << " | " << task.password << "\n";
    taskFile.close();
    system("cls");
    std::cout << "Account added!\n";
}

void viewAccount(const std::string& username) {
    std::ifstream taskFile(username + "_account.txt");
    system("cls");

    if (!taskFile.is_open()) {
        system("cls");
        std::cout << "No accounts found.\n";
        return;
    }

    Task task;
    const int nameWidth = 40;
    const int deadlineWidth = 40;

   std::cout << std::setw(nameWidth) << std::left << "Name:"
              << std::setw(deadlineWidth) << std::left << "Password:" << "\n";
    std::cout << std::setw(nameWidth + deadlineWidth) << std::setfill('-') << "" << "\n";
    std::cout << std::setfill(' ');
    while (std::getline(taskFile, task.name, '|') >> std::ws &&
           std::getline(taskFile, task.password)) {
        // Display task details
        std::cout << std::setw(nameWidth) << std::left << task.name
                  << std::setw(deadlineWidth) << std::left << task.password;

        std::cout << "\n\n";
    }

    taskFile.close();
}

void deleteAccount(const std::string& username) {
    std::string taskName;
    std::cout << "Enter the name of the task to delete: ";
    std::getline(std::cin, taskName);

    std::ifstream inFile(username + "_account.txt");
    std::ofstream outFile("temp.txt");

    Task task;
    bool taskFound = false;

    while (std::getline(inFile, task.name, '|') >> std::ws &&
           std::getline(inFile, task.password)) {
        if (trim(task.name) == trim(taskName)) {
    taskFound = true;
    system("cls");
    std::cout << "Account deleted!\n";
} else {
    outFile << task.name << " | " << task.password << "\n";
}
    }

    inFile.close();
    outFile.close();

    if (!taskFound) {
        system("cls");
        std::cout << "Account not found.\n";
    } else {
        remove((username + "_account.txt").c_str());
        rename("temp.txt", (username + "_account.txt").c_str());
    }
}

//! 4. Reminder App
void f_reminder(std::string username){
                        system("cls");

                        std::string password;
                        int choice = 0;

                        do{
                        password.clear();
                        std::cout << "\t\t\t\t\t\t\t\t\t\tPress 'B' to back\n";
                        std::cout << "Enter your password: ";

         char ch;

                        do{

        
         ch = _getch();  // Use _getch() to get a character without echoing it to the console

        // Break the loop on Enter
        if (ch == 13) {
            break;
        } 
        // Handle backspace
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Move the cursor back, print a space, move the cursor back again
            }
        } 
        // Handle other characters
        else {
            password.push_back(ch);
            std::cout << '*';
        }

       

    }while(true);


                        if(password == "B" || password == "b"){
                            system("cls");
                            mainProgram("cls");
                        }

                        if(login(username, password) != true){
                         system("cls");
                         std::cout << "Incorrect password. Please try again.\n";
                        }

                        }while(login(username, password) != true);

                        if (login(username, password)) {
                            
        Task task;

        do {
            std::cout << "\n1. Add Reminder\n";
            std::cout << "2. View Reminder\n";
            std::cout << "3. Delete Reminder\n";
            std::cout << "4. Back\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
            std::cout << "\n";

            switch (choice) {
                case 1:
                    system("cls");
                    std::cout << username << "'s Reminders\n\n";
                    do{
                        std::cout << "Enter reminder name: ";
                        std::getline(std::cin, task.name);

                        if(task.name.length() > 20){
                            system("cls");
                            std::cout << "Reminder's name can't exceed 20 characters\n\n";
                        }
                    } while(task.name.length() > 20);

                    do{
                        std::cout << "Enter date: ";
                        std::getline(std::cin, task.date);

                        if(task.date.length() > 20){
                            system("cls");
                            std::cout << "Date can't exceed 20 characters\n\n";
                        }
                    } while(task.date.length() > 20);
                    
                    do{
                        std::cout << "Enter description: ";
                        std::getline(std::cin, task.description);

                        if(task.description.length() > 100){
                            system("cls");
                            std::cout << "Description can't exceed 100 characters\n\n";
                        }
                    } while(task.description.length() > 100);

                    addReminder(username, task);
                    break;

                case 2:
                 viewReminder(username);
                    break;

                case 3:
                    deleteReminder(username);
                    break;

                case 4:
                    system("cls");
                    mainProgram(username);
                    break;

                default:
                    system("cls");
                    std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
    else{
        system("cls");
        std::cout << "Username/Password is incorrect. Please Try Again!" << "\t\tPress 'B' to go to the main menu\n\n";
        callLogIn();
    }
}

void addReminder(const std::string& username, const Task& task) {
    std::ofstream taskFile(username + "_reminder.txt", std::ios::app);
    
    taskFile << task.name << " | " << task.date << " | " << task.description << "\n";
    taskFile.close();
    system("cls");
    std::cout << "Reminder added!\n";
}

void viewReminder(const std::string& username) {
    std::ifstream taskFile(username + "_reminder.txt");
    system("cls");

    if (!taskFile.is_open()) {
        system("cls");
        std::cout << "No reminder found.\n";
        return;
    }

    Task task;
    const int nameWidth = 30;
    const int deadlineWidth = 30;
    const int priorityWidth = 30;
    const int descriptionWidth = 70;

    std::cout << std::setw(nameWidth) << std::left << "Reminder:"
              << std::setw(deadlineWidth) << std::left << "Date:"
              << std::setw(descriptionWidth) << std::left << "Description:" << "\n";
    std::cout << std::setw(nameWidth + deadlineWidth + descriptionWidth) << std::setfill('-') << "" << "\n";
    std::cout << std::setfill(' ');

    while (std::getline(taskFile, task.name, '|') >> std::ws &&
           std::getline(taskFile, task.date, '|') >> std::ws &&
           std::getline(taskFile, task.description)) {
        // Display task details
        std::cout << std::setw(nameWidth) << std::left << task.name
                  << std::setw(deadlineWidth) << std::left << task.name;
                

        // Display description with line breaks for long descriptions
        std::istringstream descriptionStream(task.description);
        std::string line;
        while (std::getline(descriptionStream, line, ' ')) {
            if (line.length() + 1 + descriptionWidth < nameWidth + deadlineWidth + descriptionWidth) {
                std::cout << line << " ";
            } else {
                std::cout << "\n" << std::setw(nameWidth + deadlineWidth) << "" << std::setw(descriptionWidth) << std::left << line << " ";
            }
        }

        std::cout << "\n\n";
    }

    taskFile.close();
}

void deleteReminder(const std::string& username) {
    std::string taskName;
    std::cout << "Enter the name of the task to delete: ";
    std::getline(std::cin, taskName);

    std::ifstream inFile(username + "_reminder.txt");
    std::ofstream outFile("temp.txt");

    Task task;
    bool taskFound = false;

    while (std::getline(inFile, task.name, '|') >> std::ws &&
           std::getline(inFile, task.deadline, '|') >> std::ws &&
           std::getline(inFile, task.description)) {
        if (trim(task.name) == trim(taskName)) {
    taskFound = true;
    system("cls");
    std::cout << "Reminder deleted!\n";
} else {
    outFile << task.name << " | " << task.deadline << " | " << task.description << "\n";
}
    }

    inFile.close();
    outFile.close();

    if (!taskFound) {
        system("cls");
        std::cout << "Reminder not found.\n";
    } else {
        remove((username + "_reminder.txt").c_str());
        rename("temp.txt", (username + "_reminder.txt").c_str());
    }
}

//! 5. Bank Account Management
void f_bankAccount(const std::string username){

    system("cls");

                        std::string password;
                        int choice = 0;

                        do{
                        password.clear();
                        std::cout << "\t\t\t\t\t\t\t\t\t\tPress 'B' to back\n";
                        std::cout << "Enter your password: ";

         char ch;

                        do{

        
         ch = _getch();  // Use _getch() to get a character without echoing it to the console

        // Break the loop on Enter
        if (ch == 13) {
            break;
        } 
        // Handle backspace
        else if (ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";  // Move the cursor back, print a space, move the cursor back again
            }
        } 
        // Handle other characters
        else {
            password.push_back(ch);
            std::cout << '*';
        }

    }while(true);


                        if(password == "B" || password == "b"){
                            system("cls");
                            mainProgram(username);
                        }

                        if(login(username, password) != true){
                         system("cls");
                         std::cout << "Incorrect password. Please try again.\n";
                        }

                        }while(login(username, password) != true);

                        if (login(username, password)){

                            do{
                                std::cout << "\n1. Check Balance\n";
                                std::cout << "2. Deposit Money\n";
                                std::cout << "3. Withdraw Money\n";
                                std::cout << "4. Back\n";
                                std::cout << "Enter your choice: ";
                                std::cin >> choice;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                if (std::cin.fail()) {
                                std::cin.clear();  // Clear the error flag
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
                                system("cls");
                            }
                                std::cout << "\n";

                                switch(choice){
                                    
                                    case 1: 
                                            system("cls");
                                            checkBalance(username);
                                            break;
                                    
                                    case 2: 
                                            system("cls");
                                            deposit(username);
                                            break;

                                    case 3:  
                                            system("cls");
                                            withdraw(username);
                                            break;

                                    case 4: 
                                            system("cls");
                                            break;

                                }

                            }while(choice !=4);
          
                        }
                    else{
                        system("cls");
                        std::cout << "Username/Password is incorrect. Please Try Again!" << "\t\tPress 'B' to go to the main menu\n\n";
                        callLogIn();
                        }


}

void checkBalance(const std::string username) {
    std::ifstream taskFile(username + "_bank.txt");
    system("cls");

    if (!taskFile.is_open()) {
        std::cout << "Error opening file for reading.\n";
        return;
    }

    Task task;

    // Read the balance from the file
    taskFile >> task.balance;

    std::cout << "Balance: " << task.balance << std::endl;

    taskFile.close();
}

void deposit(const std::string& username) {
    Task task;

    // Attempt to open the existing bank file
    std::ifstream inFile(username + "_bank.txt");
    if (inFile.is_open()) {
        // Read the existing balance
        inFile >> task.balance;
        inFile.close();
    } else {
        // If the file doesn't exist, create it and initialize the balance to 0
        task.balance = 0;
        std::ofstream outFile(username + "_bank.txt");
        if (!outFile.is_open()) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }
        outFile << task.balance;
        outFile.close();
    }

    int deposit = 0;
    do {
        std::cout << "Enter the amount to be deposited: ";
        std::cin >> deposit;
    } while (deposit < 0);

    // Update the balance
    task.balance += deposit;

    // Write the updated balance back to the file
    std::ofstream outFile(username + "_bank.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << task.balance;
    outFile.close();

    system("cls");
    std::cout << "You have deposited successfully\n";
}

void withdraw(const std::string& username) {
    int withdraw = 0;
    std::cout << "Enter the amount to be withdrawn: ";
    std::cin >> withdraw;

    Task task;

    std::ifstream inFile(username + "_bank.txt");  // Correct the file name
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }

    // Read the current balance from the file
    inFile >> task.balance;

    // Check if there is sufficient balance
    if (withdraw <= task.balance) {
        task.balance -= withdraw;

        // Open the file for writing
        std::ofstream outFile(username + "_bank.txt");
        if (!outFile.is_open()) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        // Write the updated balance back to the file
        outFile << task.balance;

        std::cout << "Your new balance: " << task.balance << std::endl;
    } else {
        std::cout << "\nYou have insufficient funds.\n";
        std::cout << "Your current balance is: " << task.balance << std::endl;
    }

    inFile.close();
}


//? ENTERTAINMENT
//! 1. Riddle Game
void f_wriddleGame(){

    int terminalWidth = 200;
    std::cout << centerAlign("    --------RIDDLE GAME--------     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Read the instructions carefully:     ", terminalWidth) << "\n";
    std::cout << centerAlign("    Player has only 3 lives     ", terminalWidth) << "\n";
    std::cout << centerAlign("    Each game consists of a total of 10 riddles     ", terminalWidth) << "\n";
    std::cout << centerAlign("    The game have three difficulties: Easy, Medium, and Hard     ", terminalWidth) << "\n\n";

}

void f_chooseDificultiesRG(std::string username){

     int choice = 0;
    do{
    std::cout << "Difficulties:\n";
    std::cout << "1. Easy\n";
    std::cout << "2. Medium\n";
    std::cout << "3. Hard\n";
    std::cout << "4. Back\n";
    std::cout << "Choose difficulty: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    system("cls");
     switch(choice){
        case 1: 
            f_easyDifficultyRG(username);
            break;
        case 2: 
            f_mediumDifficultyRG(username);
            break;
        case 3: 
            f_hardDifficultyRG(username);
            break;

        case 4: 
            mainProgram(username);
            break;
        default: std::cout << "You did not enter a correct choice!\n";
    }

    }while(choice != 1 && choice != 2 && choice != 3);
    system("cls");
   


}

void f_easyDifficultyRG(std::string username){

    char answer;
    int answerHolder = 0;
    int correct = 0;
    int lives = 3;




    std::string gameRiddle[] = {

        "I'm tall when I'm young, and I'm short when I'm old. What am I?",
        "What month of the year has 28 days?",
        "What is full of holes but still holds water?",
        "What goes up but never comes down?",
        "What can't talk but will reply when spoken to?",
        "The more of this there is, the less you see. What is it?",
        "What is black when it's clean and white when it's dirty?",
        "It belongs to you, but other people use it more than you do. What is it?",
        "What goes up and down but doesn't move?",
        "If you're running in a race and you pass the person in second place, what place are you in?",

    };

int sizeGameRiddle = sizeof(gameRiddle) / sizeof(gameRiddle[0]);




    std::string riddleAnswer[sizeGameRiddle][4] = {

        

        {"a. Dog", "b. Apple", "c. Candle", "d. None of the above"},
        {"a. February", "b. November?", "c. January!", "d. All months"},
        {"a. Fishing Net", "b. Sponge", "c. Strainer", "d. Plastic bag"},
        {"a. Waterfall", "b. Age", "c. Balloon", "d. All of the above"},
        {"a. Echo", "b. Wind", "c. Spider", "d. Mirror"},
        {"a. Sunshine", "b. Money", "c. Flashlight", "d. Darkness"},
        {"a. Zebra", "b. Chalkboard", "c. Snow", "d. Mud"},
        {"a. Toothbrush", "b. Your name", "c. Slippers", "d. None of the above"},
        {"a. Elevator", "b. Staircase", "c. Balloon", "d. Wind"},
        {"a. First place", "b. Third place", "c. Second place", "d. Place?"}

    };

    for(int i = 0; i < sizeGameRiddle; ++i){
        
        system("cls");

        std::cout << "\t\t\t\t\t\t\tlives: " << lives << "\tcorrect: " << correct << "\n\n";

        std::cout << gameRiddle[i] << "\n";

        for(int j = 0; j < 4; ++j){

            std::cout << riddleAnswer[i][j] << "  ";
        }
        
        std::cout << "\n\n";

do{
        std::cout << "Enter your answer: ";
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            }
        answer = tolower(answer);

        if(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd'){
            std::cout << "Enter a valid option\n\n";
        }


}while(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd');


        if(answer == 'a'){
            answerHolder = 0;
        }
        else if(answer == 'b'){
            answerHolder = 1;
        }
        else if(answer == 'c'){
            answerHolder = 2;
        }
        else if(answer == 'd'){
            answerHolder = 3;
        }

        if(answerHolder == 2 && i == 0){
            correct++;
        }
        else if(answerHolder !=2 && i == 0){
            lives--;
        }

        if(answerHolder == 0 && i == 1){
            correct++;
        }
        else if(answerHolder != 0 && i == 1){
            lives--;
        } 

        if(answerHolder == 1 && i == 2){
            correct++;
        }
        else if(answerHolder != 1 && i == 2){
            lives--;
        }

        if(answerHolder == 1 && i == 3){
            correct++;
        }
        else if(answerHolder !=1 && i == 3){
            lives--;
        }

        if(answerHolder == 0 && i == 4){
            correct++;
        }
        else if(answerHolder !=0 && i == 4){
            lives--;
        }

        if(answerHolder == 3 && i == 5){
            correct++;
        }
        else if(answerHolder !=3 && i == 5){
            lives--;
        }

        if(answerHolder == 1 && i == 6){
            correct++;
        }
        else if(answerHolder !=1 && i == 6){
            lives--;
        }

        if(answerHolder == 1 && i == 7){
            correct++;
        }
        else if(answerHolder != 1 && i == 7){
            lives--;
        }

        if(answerHolder == 1 && i == 8){
            correct++;
        }
        else if(answerHolder != 1 && i == 8){
            lives--;
        }

        if(answerHolder == 2 && i == 9){
            correct++;
        }
        else if(answerHolder != 2 && i == 9){
            lives--;
        }
        

        if(lives == 0){
            system("cls");
            break;
        }



        std::cout << "\n";


    }
    
    f_displayResultRG(lives, correct, username);

}

void f_mediumDifficultyRG(std::string username){

    char answer;
    int answerHolder = 0;
    int correct = 0;
    int lives = 3;

    std::string gameRiddle[] = {

        "What five-letter word becomes shorter when you add two letters to it?",
        "What begins with an 'e' and only contains one letter?",
        "You see me once in June, twice in November and not at all in May. What am I?",
        "Forward I am heavy, but backward I am not. What am I?",
        "What word is pronounced the same if you take away four of its five letters?",
        "What is so fragile that saying its name breaks it?",
        "The more you take, the more you leave behind. What are they?",
        "I am always hungry and will die if not fed, but whatever I touch will soon turn red. What am I?",
        "People make me, save me, change me, raise me. What am I?",
        "If you drop me I'm sure to crack, but give me a smile and I'll always smile back. What am I?",

    };

int sizeGameRiddle = sizeof(gameRiddle) / sizeof(gameRiddle[0]);

    std::string riddleAnswer[sizeGameRiddle][4] = {
        {"a. Length", "b. Short", "c. Brief", "d. Small"},
        {"a. Echo", "b. Envelope", "c. Equador!", "d. Elevator"},
        {"a. Wind", "b. Air", "c. Future", "d. Letter E"},
        {"a. Stone", "b. Knot", "c. You are not", "d. All of the above"},
        {"a. Quiet", "b. Quick", "c. Queue", "d. Quirk"},
        {"a. Glass", "b. Diamond", "c. Silence", "d. Darkness"},
        {"a. Jacket", "b. Footsteps", "c. Snow", "d. Rain"},
        {"a. Fire", "b. Color", "c. Wood", "d. Matches"},
        {"a. Child", "b. Plant", "c. Animal", "d. Money"},
        {"a. A person", "b. Mirror", "c. Remote", "d. Egg"}
    };

    for(int i = 0; i < sizeGameRiddle; ++i){
        
        system("cls");

        std::cout << "\t\t\t\t\t\t\tlives: " << lives << "\tcorrect: " << correct << "\n\n";

        std::cout << gameRiddle[i] << "\n";

        for(int j = 0; j < 4; ++j){

            std::cout << riddleAnswer[i][j] << "  ";
        }
        
        std::cout << "\n\n";

do{
        std::cout << "Enter your answer: ";
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            }
        answer = tolower(answer);

        if(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd'){
            std::cout << "Enter a valid option\n\n";
        }


}while(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd');


        if(answer == 'a'){
            answerHolder = 0;
        }
        else if(answer == 'b'){
            answerHolder = 1;
        }
        else if(answer == 'c'){
            answerHolder = 2;
        }
        else if(answer == 'd'){
            answerHolder = 3;
        }

        if(answerHolder == 1 && i == 0){
            correct++;
        }
        else if(answerHolder !=1 && i == 0){
            lives--;
        }

        if(answerHolder == 1 && i == 1){
            correct++;
        }
        else if(answerHolder !=1 && i == 1){
            lives--;
        }

        if(answerHolder == 3 && i == 2){
            correct++;
        }
        else if(answerHolder !=3 && i == 2){
            lives--;
        }

        if(answerHolder == 2 && i == 3){
            correct++;
        }
        else if(answerHolder !=2 && i == 3){
            lives--;
        }

        if(answerHolder == 2 && i == 4){
            correct++;
        }
        else if(answerHolder !=2 && i == 4){
            lives--;
        }

        if(answerHolder == 2 && i == 5){
            correct++;
        }
        else if(answerHolder !=2 && i == 5){
            lives--;
        }

        if(answerHolder == 1 && i == 6){
            correct++;
        }
        else if(answerHolder !=1 && i == 6){
            lives--;
        }

        if(answerHolder == 0 && i == 7){
            correct++;
        }
        else if(answerHolder !=0 && i == 7){
            lives--;
        }

        if(answerHolder == 3 && i == 8){
            correct++;
        }
        else if(answerHolder !=3 && i == 8){
            lives--;
        }

        if(answerHolder == 1 && i == 9){
            correct++;
        }
        else if(answerHolder != 1 && i == 9){
            lives--;
        }
        

        if(lives == 0){
            system("cls");
            break;
        }



        std::cout << "\n";


    }
    
    f_displayResultRG(lives, correct, username);




}

void f_hardDifficultyRG(std::string username){

    char answer;
    int answerHolder = 0;
    int correct = 0;
    int lives = 3;



    std::string gameRiddle[] = {

        "If two's company, and three's a crowd, what are four and five?",
        "What three numbers, none of which is zero, give the same result whether they're added or multiplied?",
        "Mary has four daughters, and each of her daughters has a brother. How many children does Mary have?",
        "Three doctors said that Bill was their brother. Bill says he has no brothers. How many brothers does Bill actually have?",
        "The day before yesterday I was 21, and next year I will be 24. When is my birthday?",
        "Before Mt. Everest was discovered, what was the highest mountain in the world?",
        "You walk into a room that contains a match, a kerosene lamp, a candle, and a fireplace. What would you light first?",
        "No matter how little or how much you use me, you change me every month. What am I?",
        "I have branches, but no fruit, trunk, or leaves. What am I?",
        "If your uncle's sister is not your aunt, what relation is she to you?",

    };

int sizeGameRiddle = sizeof(gameRiddle) / sizeof(gameRiddle[0]);


    std::string riddleAnswer[sizeGameRiddle][4] = {
        {"a. Seven", "b. Still four", "c. Eight", "d. Nine"},
        {"a. One", "b. Three", "c. Two", "d. All of the above"},
        {"a. Four", "b. Five", "c. Six", "d. Eight"},
        {"a. Three", "b. Four", "c. Only one", "d. None"},
        {"a. November 27", "b. December 27", "c. December 31", "d. January 30"},
        {"a. Mt. Everest", "b. K2", "c. Mt. Fuji", "d. Mt. Killimanjaro"},
        {"a. Kerosene lamp", "b. Candle", "c. Fireplace", "d. Match"},
        {"a. Clothes", "b. Pillow", "c. Calendar", "d. Bag"},
        {"a. Bank", "b. River", "c. Mountain", "d. Still a tree"},
        {"a. Another uncle", "b. Aunt", "c. Mother", "d. Cousin"}
    };

    for(int i = 0; i < sizeGameRiddle; ++i){
        
        system("cls");

        std::cout << "\t\t\t\t\t\t\tlives: " << lives << "\tcorrect: " << correct << "\n\n";

        std::cout << gameRiddle[i] << "\n";

        for(int j = 0; j < 4; ++j){

            std::cout << riddleAnswer[i][j] << "  ";
        }
        
        std::cout << "\n\n";

do{
        std::cout << "Enter your answer: ";
        std::cin >> answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            }
        answer = tolower(answer);

        if(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd'){
            std::cout << "Enter a valid option\n\n";
        }


}while(answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd');


        if(answer == 'a'){
            answerHolder = 0;
        }
        else if(answer == 'b'){
            answerHolder = 1;
        }
        else if(answer == 'c'){
            answerHolder = 2;
        }
        else if(answer == 'd'){
            answerHolder = 3;
        }

        if(answerHolder == 3 && i == 0){
            correct++;
        }
        else if(answerHolder !=3 && i == 0){
            lives--;
        }

        if(answerHolder == 3 && i == 1){
            correct++;
        }
        else if(answerHolder !=3 && i == 1){
            lives--;
        }

        if(answerHolder == 1 && i == 2){
            correct++;
        }
        else if(answerHolder !=1 && i == 2){
            lives--;
        }

        if(answerHolder == 3 && i == 3){
            correct++;
        }
        else if(answerHolder !=3 && i == 3){
            lives--;
        }

        if(answerHolder == 2 && i == 4){
            correct++;
        }
        else if(answerHolder !=2 && i == 4){
            lives--;
        }

        if(answerHolder == 0 && i == 5){
            correct++;
        }
        else if(answerHolder !=0 && i == 5){
            lives--;
        }

        if(answerHolder == 3 && i == 6){
            correct++;
        }
        else if(answerHolder !=3 && i == 6){
            lives--;
        }

        if(answerHolder == 2 && i == 7){
            correct++;
        }
        else if(answerHolder !=2 && i == 7){
            lives--;
        }

        if(answerHolder == 0 && i == 8){
            correct++;
        }
        else if(answerHolder !=0 && i == 8){
            lives--;
        }

        if(answerHolder == 2 && i == 9){
            correct++;
        }
        else if(answerHolder !=2 && i == 9){
            lives--;
        }
        

        if(lives == 0){
            system("cls");
            break;
        }



        std::cout << "\n";


    }
    
    f_displayResultRG(lives, correct, username);
}

void f_displayResultRG(int lives, int correct, std::string username){

    int choice = 0;

    std::cout << "Game over!\n\n";

    if(correct <= 5){
        std::cout << "Oh no, you did not reach the passing score :(\n";
    }
    else{
        std::cout << "Congratulations, you passed! :)\n";
    }

    std::cout << "\nlives remaining: " << lives;
    std::cout << "\nnumber of correct: " << correct <<"/10";

do{
    std::cout << "\n\nWant to play again?\n";
    std::cout << "1. Yes, I want to play again!\n";
    std::cout << "2. No, I want to exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }

    if(choice != 1 || choice !=2){
        system("cls");
        std::cout << "Enter a valid choice";
    }


}while(choice != 1 && choice != 2);

    if(choice == 1){
        system("cls");
        f_chooseDificultiesRG(username);
    }
    else{
        system("cls");
        mainProgram(username);
    }
    

}

//! 2. Rock Paper Scissor
void f_wRockPaperScissor(std::string username){
        int playerChoice = 0;
    int computerChoice = 0;
    int termination = 0;
    int counterWin = 0;
    int counterLose = 0;

do{
    f_displayRPC(playerChoice);
    f_computerChoice(computerChoice);
    f_displayWeapon(playerChoice, computerChoice);
    f_winning(playerChoice, computerChoice, counterWin, counterLose);
    f_counter(counterWin, counterLose);
    f_termination(termination, username);
}while(termination != 0);

}

void f_displayRPC(int &playerChoice){

    int terminalWidth = 200;
    system("cls");
    std::cout << centerAlign("    --------Rock Paper Scissor--------     ", terminalWidth) << "\n";
    do{
    std::cout << "Press (1-3):\n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissor\n";
    std::cout << "Choose your weapon: ";
    std::cin >>playerChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }

        if(playerChoice != 1 || playerChoice !=2 || playerChoice != 3){
                system("cls");
        }



    std::cout << "\n";
    }while(playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
}

void f_computerChoice(int &computerChoice){
    computerChoice = std::rand() % 3 + 1;
}

void f_winning(int playerChoice, int computerChoice, int &counterWin, int &counterLose){

    switch(playerChoice){
        case 1: if(computerChoice == 1){
                std::cout << "It is a TIE\n";
        }
                else if(computerChoice == 2){
                std::cout << "You LOSE\n";
                counterLose++;
        }
                else{
                std::cout << "You WON\n";
                counterWin++;
                }
                break;
        case 2: if (computerChoice == 1){
                std::cout << "You WON\n";
                counterWin++;
        }
                else if(computerChoice == 2){
                std::cout << "It is a TIE\n";
                }
                else{
                std::cout << "You LOSE\n";
                counterLose++;
                }
                break;
        case 3: if(computerChoice == 1){
                std::cout << "You LOSE\n";
                counterLose++;
        }       
                else if(computerChoice == 2){
                std::cout << "You WON\n";
                counterWin++;
                }
                else{
                std::cout << "It is a TIE\n";
                }
                break;
                
    }
}

void f_displayWeapon(int playerChoice, int computerChoice){

    switch(playerChoice){
        case 1: std::cout << "Player: ROCK\n";
                break;
        case 2: std::cout << "Player: PAPER\n";
                break;
        case 3: std::cout << "Player: SCISSOR\n";
                break;
    }

    switch(computerChoice){
        case 1: std::cout << "Computer: ROCK\n";
                break;
        case 2: std::cout << "Computer: PAPER\n";
                break;
        case 3: std::cout << "Computer: SCISSOR\n";
                break;
    }



}

void f_termination(int &termination, std::string username){
    std::cout << "\nPlay again?\n";
    std::cout << "Press 1, to play again\n";
    std::cout << "Press 0, to exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> termination;
    if(termination == 0){
        system("cls");
        mainProgram(username);
    }
    std::cout << "\n";
}

void f_counter(int counterWin, int counterLose){

    std::cout << "\nWin record: " << counterWin << "\n";
    std::cout << "Loss record: "<< counterLose << "\n";
}

//! 3. Number Guessing Game
void f_wnumberGuess(std::string username){

    int guess = 0;
    int correctAnswer = 0;
    int range = 0;
    int attempt = 0;
    int termination = 0;
    

    do{
    f_numberGuess(range, attempt);
    do{
    f_answerNG(range, attempt, guess);
    std::cout << "\nWant to try again?\n";
    std::cout << "1. Try again\n";
    std::cout << "2. Change the range and attempt\n";
    std::cout << "3. Back\n"; 
    std::cout <<"Enter your choice: ";
    std::cin >> termination;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }

    std::cout << std::endl;

    if(termination == 2){
        system("cls");
        f_numberGuess(range, attempt);
    }

    if(termination == 3){
        system("cls");
        mainProgram(username);
    }

    system("cls");

    }while(termination != 0);

}while(termination != 0);
    
}

// Start of number Guess
void f_numberGuess(int &range, int &attempt){

    int terminalWidth = 200;

    std::cout << centerAlign("    --------Number Guessing Game--------     ", terminalWidth) << "\n";

    std::cout << "Enter the range of the number for you to guess: ";
    std::cin >> range;

    std::cout << "Enter the number of attempts: ";
    std::cin >> attempt;
}

// Process of number Guess Game
void f_answerNG(int range, int attempt, int guess){

    int counter = 0; 
    
    int correctAnswer = std::rand() % range + 1;

    

    do{
        std::cout << "\nEnter your guess: ";
        std::cin >> guess; 

        if(guess == correctAnswer){
            std::cout << "\nCongratulations, you guessed it!\n"; 
            std::cout << "Attempts: " << counter + 1 << "/" << attempt << std::endl;;
            break;
        }
        else{
            counter++;
            std::cout << "You have guess it wrong\n";
            std::cout << "Remaining Attempts: " << attempt - counter << std::endl;

        }
        
        if(attempt - counter == 0){
            std::cout << "Correct Answer: " << correctAnswer << std::endl;
        }


    }while(counter != attempt);

}

// ! 4. Coin Flip
void f_mcoinFlip(std::string username){
    int flip = 0;
    int counter = 0;
    int termination = 0;
    int countWin = 0;
    int countLose = 0;


    do{
    f_wcoinFlip(flip);
    f_coinSide(flip, countWin, countLose);
    f_showCounter(countWin, countLose);
    f_terminationCF(termination, username);
    
    }while(termination != 0);
}

void f_wcoinFlip (int &flip){
    int terminalWidth = 200;
    std::cout << centerAlign("    --------COIN FLIP--------     ", terminalWidth) << "\n\n";

    std::cout << "Heads or Tails?\n";
    std::cout << "1. Heads\n";
    std::cout << "2. Tails\n";
    std::cout << "Choose a side: ";
    std::cin >> flip;
}

void f_coinSide (int flip, int &counterWin, int &counterLose){

    int correctSide = std::rand() % 2 + 1;

    if(correctSide == flip){
        std::cout << "\nYou WON\n";
        counterWin++;
    }
    else{
        std::cout << "\nYou LOSE\n";
        counterLose++;
    }

}

void f_showCounter (int counterWin, int counterLose){
    std::cout << "\nNumber of wins: " << counterWin << "\n";
    std::cout << "Number of loses: " << counterLose << "\n";

}

void f_terminationCF (int &termination, std::string username){

    do{
    std::cout <<"\n1. Play again\n";
    std::cout <<"2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> termination;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    if(termination == 2){
        system("cls");
        mainProgram(username);
    }
    system("cls");
    }while(termination != 1 && termination != 2);
    
    std::cout << "\n";
}

//! 5. Guess the Word
void f_wGuessTheWord(){

    int terminalWidth = 200;
    std::cout << centerAlign("    --------GUESS THE WORD--------     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Read Carefully the instructions:     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Player has only 3 lives     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Each game allows the player to use 3 clues     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Each correct will add one clue     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Each game consists of a total of 10 questions     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    The game have three difficulties: Easy, Medium, and Hard     ", terminalWidth) << "\n\n";
}

void f_chooseDificulties(std::string username){
    
    int choice = 0;
    do{
    std::cout << "Difficulties:\n";
    std::cout << "1. Easy\n";
    std::cout << "2. Medium\n";
    std::cout << "3. Hard\n";
    std::cout << "Choose difficulty: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    system("cls");
     switch(choice){
        case 1: f_easyDifficulty(username);
            break;
        case 2: f_mediumDifficulty(username);
            break;
        case 3: f_hardDifficulty(username);
            break;
        default: std::cout << "You did not enter a correct choice!\n";
    }

    }while(choice != 1 && choice != 2 && choice != 3);
    system("cls");
   
    
}

void f_easyDifficulty(std::string username){

    int numClues = 3;
    int tempClues = numClues;
    int counter = 0;
    int level = 1;
    int lives = 3;
    int hintCounter = 0;
    int correctCounter = 0;
    std::string answer = "";


do{
    // First Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues<< "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'palpe'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "apple"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "apple"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It is red|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It is a fruit|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Can keeps the doctor away|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }
    
    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "apple");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Second Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues<< "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'okob'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "book"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "book"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It has 4 sides|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It can be use to study|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It can be found in library|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "book");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }
    hintCounter = 0;

    // Third Question 
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'odg'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "dog"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "dog"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It barks, Arf! Arf! Arf!!|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|has a 4 legs|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Can be a pet|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "dog");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Fourth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'owfrle'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "flower"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "flower"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Have a variety of colors|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        system("cls");
        std::cout << "|Can be receive on a Valentine's Day|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It has a petal and smells good|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "flower");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Fifth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'woairnb'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "rainbow"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "rainbow"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Consist of 7 colors|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Appear when sunlight with raindrops|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Appear in the sky|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "rainbow");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Sixth Question 
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'awtre'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "water"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "water"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|We drink it everyday|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It is important for our health|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|We need it to survive|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "water");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Seventh Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'hocltocea'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "chocolate"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "chocolate"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Sweet treat made from cocoa beans|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Its typical color is dark|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Toblerone? Goya? Hersheys?|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "chocolate");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Eight Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'eirc'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "rice"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "rice"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|We eat it everyday|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Ingredient to make a porridge|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Food that comes from tiny individual pieces|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "rice");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Ninth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'urtagi'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "guitar"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "guitar"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Musical Instrument|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Consist of six strings|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Can be strum or pluck|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "guitar");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Tenth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'thare'\n";
    std::cout << "Answer: ";
    std::cin >> answer;
    
    if(answer == "earth"){
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "earth"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It is where we live|\n\n";
        std::cout << level;
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Consist of only one moon|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Third planet from the sun|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }

    if(lives == 0){
        break;
    }


    }while(answer != "earth");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    if(level >= 10){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }
    


}while(lives != 0);
}

void f_mediumDifficulty(std::string username){

    int numClues = 3;
    int tempClues = numClues;
    int counter = 0;
    int level = 1;
    int lives = 3;
    int hintCounter = 0;
    int correctCounter = 0;
    std::string answer;


do{
    // First Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'edtievce'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    


    if(answer == "detective"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "detective"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|A person who question suspects to gather information|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Its stereotype is that he has a magnifying glass always|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Conan, Conan, Conan, Conan!!|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "detective");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    std::cout << "THis is sdaf" << numClues;

    // Second Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'nistuj reibbe'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "justin bieber"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "justin bieber"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|My number one crush!!|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Compose the song called 'one less lonely girl'|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|What do you mean, Hailey?|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "justin bieber");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Third Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'ltsatcya'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "catalyst"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "catalyst"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It triggers chain events|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|A force that sparks transformation|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It initiates reaction|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "catalyst");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Fourth Question

    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'prtsajcavi'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "javascript"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "javascript"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It was created in May 1995|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Its official name is ECMAScript|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It initiates reaction|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "javascript");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;
    
    // Fifth Question

    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'thrmys'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "rythms"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "rythms"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|A natural, recurring sequence in sound|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Longest word without a vowel|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It initiates reaction|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "rythms");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Sixth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'mcaidaob'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "cambodia"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "cambodia"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It is a country|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Its capital is Phnom Penh|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Mekong River Neighbor|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "cambodia");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;


    // Seventh Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'ghniirolmab'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "lamborghini"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "lamborghini"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Founded in 1963 by Ferruccio|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|The company's logo features a raging bull|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It is a brand of a car|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "lamborghini");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Eight Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'ololpilp'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "lollipop"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "lollipop"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Favorite by kids|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Sweet sugar on a stick|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Chupa Chups are well known in making this|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "lollipop");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;
    
    // Ninth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'otllofba'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "football"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "football"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Messi, Ronaldo, Pele, Ronaldinho|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|The most viewed sports gloablly |\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|This sports consist of 11 players in playing|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "football");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;


    // Tenth Question

    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'erpmnsiad'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "spiderman"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "spiderman"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|'With great power comes great responsibility'|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|He is a superhero|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Venom, Sandman, Green Goblin, The Lizard, Doctor Octopus|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    tempClues = numClues;

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && tempClues + 1 <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "spiderman");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    if(level >= 10){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }



}while(lives!=0);




}

void f_hardDifficulty(std::string username){

    int numClues = 4;
    int counter = 0;
    int level = 1;
    int lives = 3;
    int hintCounter = 0;
    int correctCounter = 0;
    std::string answer;


do{
    // First Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues - 1 << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'ckrema cisnarf nhguov ido'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "mearck francis voughn odi"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "mearck francis voughn odi"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Creator of AI OP|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|His crush is Justin Bieber|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Cknrf! Cknrf! Cknrf! Cknrf!|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "mearck francis voughn odi");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Second Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'dornaeol ad nciiv'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "leonardo da vinci"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "leonardo da vinci"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Born on April 15, 1452|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Painted the 'The Last Supper'|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Painted the 'Mona Lisa'|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "leonardo da vinci");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Third Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'oomnsmmrraici'\n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "microorganism"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "microorganism"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It may exist in its single-celled form or as a colony of cells|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It carry out almost half of the photosynthesis on our planet|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It is MIRCROORGANISM!|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "microorganism");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Fourth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'tunksip 1' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "sputnik 1"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "sputnik 1"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|The first Man-made Satellite|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Launched by the Soviet Union on October 4, 1957|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Emitting radio signals that could be received on Earth|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "sputnik 1");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Fifth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'lesrcah wriand' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "charles darwin"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "charles darwin"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Wrote the theory of evolution by natural selection|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Charles Darwin|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|I said he is Charles Darwin! Poor little guy|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "charles darwin");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Sixth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'eeooolgymtr' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "sputnik 1"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "sputnik 1"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Study of Earth's atmoshpehere|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It observe, analyze, and predict weather patterns|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Synoptic, Mesoscale, Microscale|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "sputnik 1");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Seventh Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'raernabc' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "canberra"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "canberra"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|The capital of Australia|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Known as Bush Capital|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It is a city that is centered around Lake Burley Griffin|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "canberra");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Eight Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'laense megoz' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "selena gomez"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "selena gomez"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Just think of it, this mode supposed to be hard|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|Composed a song called 'wolves'|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|Ex girlfriend of Justin Bieber|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "selena gomez");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Ninth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'llarrenittse' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "interstellar"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "insterstellar"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|It is a movie|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It is directed by Christopher Nolan|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It was released on November 6, 2014|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "interstellar");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    // Tenth Question
    do{
    std::cout << "Lives: " << lives << "\t\t\t\t\t Question no." << level << "\n";
    std::cout << "Clues: "<< numClues << "\t\t\t\t\t Correct: " << correctCounter << "\n";
    std::cout << "\t\tType 'hint' to get a clue\n";
    std::cout << "\nWord to guess:\n";
    std::cout << "'seeccnenioblumi' \n";
    std::cout << "Answer: ";
    std::getline(std::cin, answer);
    
    if(answer == "bioluminescence"){
        level+=1;
        correctCounter+=1;
        numClues+=1;
    }

    if(answer != "bioluminescence"){
        system("cls");
        lives-=1;
        std::cout << "(" << answer << " is wrong)\n\n";
    }

    if(answer == "hint"){
        lives+=1;
    }

    if(answer == "hint" && hintCounter == 0){

        system("cls");
        std::cout << "|Scientific term for the production of light by living organisms|\n\n";
        hintCounter+=1;
        numClues-=1;

    }
    else if(answer == "hint" && hintCounter == 1){
        
        system("cls");
        std::cout << "|It is a form of chemiluminescence|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter == 2){
        
        system("cls");
        std::cout << "|It is light emitted by living things through chemical reactions in their bodies|\n\n";
        hintCounter+=1;
        numClues-=1;
    }
    else if(answer == "hint" && hintCounter >=3){
        system("cls");
        std::cout << "Sorry, each word has only 3 clues\n\n";
    }

    if(numClues <= 0){
        numClues = 0;
    }
    
    if(answer == "hint" && numClues <= 0){
        system("cls");
        std::cout << "Sorry, you have run out of hints\n\n";
    }
    

    if(lives == 0){
        break;
    }


    }while(answer != "bioluminescence");
    system("cls");

     if(lives == 0){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }

    hintCounter = 0;

    if(level >= 10){
        f_displayResult(correctCounter, lives, numClues, level, username);
        break;
    }



}while(lives!=0);


}

void f_displayResult(int correctCounter, int lives, int numClues, int level, std::string username){

    int termination = 0;

    std::cout << "Game Over!\n";

    if(correctCounter >= 7){
        std::cout << "Congratulations!!\n\n";
        std::cout << "Results: \n";
        std::cout << "You got " << correctCounter << " out of 10\n";
        std::cout << "No. of questions answered: " << level << "\n";
        std::cout << "Remaining Lives: " << lives << "\n";
        std::cout << "Remaining Clues: " << numClues;
        }
        else{
        std::cout << ":( You didn't passed\n\n";
        std::cout << "Results: \n";
        std::cout << "You got " << correctCounter << " out of 10\n";
        std::cout << "Current Level: " << level << "\n"; 
        std::cout << "Remaining Lives: " << lives << "\n";
        std::cout << "Remaining Clues: " << numClues;
        }

    std::cout << "\n\nPress Enter to continue...";

    // Clear input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Wait for Enter key
    std::cin.get();

    // Continue with the rest of your program
do{
    system("cls");
    std::cout << "Want to play again?:\n";
    std::cout << "1. Yes, I'll play again!\n";
    std::cout << "2. No, I want to quit\n";
    std::cout << "Enter your choice: ";
    std::cin >> termination;

    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }


    if(termination == 1){
        system("cls");

        f_chooseDificulties(username);
    }   
    else if(termination == 2){
        system("cls");
        mainProgram(username);
    }
    else{
        system("cls");
        std::cout << "Please enter a correct choice\n\n";
        
    }
}while(termination != 1 && termination != 2); 

}

//! 6. Snake


//! 7. Tic-Tac-Toe
void display_board(char board[10]) {
    // Draw game board with numbers
    
    std::cout << "+---+---+---+ \n";
    std::cout << "| 1 | 2 | 3 |  \n";
    std::cout << "+---+---+---+ \n";
    std::cout << "| 4 | 5 | 6 |  \n";
    std::cout << "+---+---+---+ \n";
    std::cout << "| 7 | 8 | 9 |  \n";
    std::cout << "+---+---+---+ \n\n";
    std::cout << "Current Board:\n";
    std::cout << "+---+---+---+ \n";
    std::cout << "| " << board[1] << " | " << board[2] << " | " << board[3] << " |  \n";
    std::cout << "+---+---+---+ \n";
    std::cout << "| " << board[4] << " | " << board[5] << " | " << board[6] << " |  \n";
    std::cout << "+---+---+---+ \n";
    std::cout << "| " << board[7] << " | " << board[8] << " | " << board[9] << " |  \n";
    std::cout << "+---+---+---+ \n";
}

bool win_check(char board[10], char player) {
    // Win Check
    return ((board[1] == player && board[2] == player && board[3] == player) ||
            (board[4] == player && board[5] == player && board[6] == player) ||
            (board[7] == player && board[8] == player && board[9] == player) ||
            (board[1] == player && board[4] == player && board[7] == player) ||
            (board[2] == player && board[5] == player && board[8] == player) ||
            (board[3] == player && board[6] == player && board[9] == player) ||
            (board[1] == player && board[5] == player && board[9] == player) ||
            (board[3] == player && board[5] == player && board[7] == player));
}

bool draw_check(char board[10]) {
    // Draw Check
    return (board[1] != ' ' && board[2] != ' ' && board[3] != ' ' &&
            board[4] != ' ' && board[5] != ' ' && board[6] != ' ' &&
            board[7] != ' ' && board[8] != ' ' && board[9] != ' ');
}

void player_turn(char board[10], char player) {
    int choice;
    bool check_choice = true;

    do {
        std::cout << "Place " << player << " at (1-9): ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }

        if (choice < 1 || choice > 9 || board[choice] != ' ') {
            std::cout << "Invalid input! 1-9 only. \n\n";
        } else {
            board[choice] = player;
            check_choice = false;
        }
    } while (check_choice);
}

void ai_turn(char board[10], char ai) {
    int choice;
    bool check_choice = true;

    // Simple AI: Randomly choose an available spot
    do {
        choice = rand() % 9 + 1;
        if (board[choice] == ' ') {
            board[choice] = ai;
            check_choice = false;
        }
    } while (check_choice);
}

void f_ticTacToe(std::string username){
    char board[10];
    char player = 'X';
    char ai = 'O';
    char restart;
    char playChoice;

    srand(time(0));

    std::cout << "Welcome to Tic-Tac-Toe!\n";


        for (int i = 0; i < 10; i++) board[i] = ' ';

        bool gameover = false;

        do {

            display_board(board);
            


            if (player == 'X') {
                player_turn(board, player);
            } else {
                ai_turn(board, ai);
            }

            if (win_check(board, player)) {
                std::cout << "Congratulations! You win!\n";
                gameover = true;
            } else if (win_check(board, ai)) {
                std::cout << "Better luck next time! AI wins.\n";
                gameover = true;
            } else if (draw_check(board)) {
                std::cout << "Game Over - Draw\n";
                gameover = true;
            }

            if(!gameover){
                system("cls");
            }


            // Switch player
            player = (player == 'X') ? 'O' : 'X';

        } while (!gameover);

        display_board(board);

    do{
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> restart;
        std::cin.ignore();
        system("cls");
    }while(restart != 'y' && restart != 'Y' && restart != 'N' && restart != 'n');

        if(restart == 'Y' || restart == 'y'){
            system("cls");
            f_ticTacToe(username);
        }

        if(restart == 'N' || restart == 'n'){
            system("cls");
            mainProgram(username);
        }
}

//! 8. ChatBox
void f_chatBox(std::string username){
    std::string name;
    int age = 0;
    
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'B' to exit\n\n";
    std::cout << "Hello, this is a chatbox. My name is AI OP, how about you, What is your name?: ";
    std::cin >> name;

    if(name == "b" || name == "B"){
        system("cls");
        mainProgram(username);
    }

    std::cout << "Oh, so you are " << name << " it is my pleasure to know you\n";

    std::cout << "Before I forgot, how old are you " << name << "?: ";
    std::cin >> age;

    if(age >= 18){
        std::cout << "\nI see, you are already in a legal age\n";
        std::cout << "But, you should be careful with your action now you are already " << age << "\n"; 
        std::cout << "But anyway, I'm here to have a conversation with you\n";
    }
    else if(age < 18){
        std::cout << "You are just " << age << " years old? You still have remaining of " << 18 - age << " years before you turn into adult\n";
        std::cout << "Anyway, I'm here to have a converstaion with you\n";
    }

    std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            char anyKey;
            std::cin.get(anyKey); 

    system("cls");
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'B' to exit\n\n";
    std::cout << "For now, I have to get you know first\n";
    std::cout << "I have some few questions for you\n";
    std::cout << "It might be a personal questions or just random questions\n\n";
    std::cout << "Here we go! What is your favorite color\n";
    std::cout << "Let me guess it, is it Black? [y/n]: ";

    char choice;
    std::string color;

    std::cin >> choice;


    choice = toupper(choice);

    if(choice == 'B'){
        system("cls");
        mainProgram("cls");
    }

    if(choice == 'Y'){
        std::cout << "Hey, I'm right. That is because I am an intelligent AI\n";
    }
    else{
        std::cout << "I got it wrong, so what is your favorite color then?: ";
        std::cin >> color;

        std::cout << "Ohhhhh, so " << color << " is your favorite color, " << name;
        std::cout << "\nYou have a great taste in color\n\n";
    }


    int product;

    std::cout << "I will try to assess your intelligence\n\n";
    std::cout << "What is 7 x 8?: ";
    std::cin >> product;

    if(product == 56){
        std::cout << "You are right, you pass my initial assessment. Great Job!\n";
    }
    else{
        std::cout << "Oh no, where did you get " << product << "? Unfortunately, you are wrong\n";
        std::cout << "But that is alright, as time goes by, you will gain skills in math\n";
        std::cout << "But it is as long as you study, so make sure to study hard, " << name << "\n";  
    }

      std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            std::cin.get(anyKey); 

    system("cls");

    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'B' to exit\n\n";
    std::cout << "By the way, do you live in the Philippines? [y/n]: ";
    std::cin >> choice;

    

    choice = toupper(choice);

    if(choice == 'B'){
        system("cls");
        mainProgram("cls");
    }
    

    if(choice == 'Y'){
        std::cout << "So you live in the Philiipines too, that's wonderful!\n";
    }
    else{
        std::cout << "Well you are not from Philippines, but I hope you visit it\n";
    }

      std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            std::cin.get(anyKey); 

    system("cls");

    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tPress 'B' to exit\n\n";
    std::cout << "Do you have any pet? [y/n]: ";
    std::cin >> choice;

    choice = toupper(choice);
    if(choice = 'B'){
        system("cls");
        mainProgram("cls");
    }

    std::string pet;

    if(choice == 'Y'){
        std::cout << "Oh so sweet!, what kind of pet do you have?: ";
        std::cin >> pet;

        std::cout << pet << " huh? make sure to take care well of it\n";

    }
    else{
        std::cout << "Got it " << name << ", not everyone wants to have a pet\n";
        std::cout << "But I think you should try it, start with a dog\n";
    }

    std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            std::cin.get(anyKey); 
    
    system("cls");

    char answer;

    std::cout << "Here I go again, Another intelligence assessment\n";
    std::cout << "This is all about programming language C++\n\n";
    std::cout << "Now who develop c++?:\n";
    std::cout << "a. Batman\n";
    std::cout << "b. Bjarne Stroustrup\n";
    std::cout << "c. James Gosling Oc\n";
    std::cout << "d. Brendan Eich\n";
    std::cout << "Enter your answer: ";
    std::cin >> answer;

    system("cls");

    answer = tolower(answer);

    

    if(answer == 'b'){
        std::cout << "You are correct, I'm surprised that you know the answer. Great job!\n";
        std::cout << "Bjarne Stroustrup developed C++ in 1979 as an extension of C language\n\n";

        std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            std::cin.get(anyKey); 
    }
    else{
        std::cout << "You got it wrong :( \n";
        std::cout << "Want to improve your knowledge, you can take a quiz built within this AI OP\n";
        std::cout << "Enter your choice [y/n]: ";
        std::cin >> choice;

        choice = toupper(choice);

        if(choice == 'Y'){
            std::cout << "That's a great choice!\n\n";
            std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

            std::cin.get(anyKey); 
            
            system("cls");


        }
        else{
            std::cout << "Alright, let's continue our conversation\n";
            
            std::cin.get(anyKey); 
            system("cls");
            

        }
    }

    std::cout << "This is the end of our conversation\n";
    std::cout << "Make sure to visit sometime\n";
    std::cout << "AI OP chatbox will always have an update every week for a newer conversation\n\n";
    std::cout << "Thank you " << name << " for using ChatBox\n";
    std::cout << "\n\nPress any key to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();  
            std::cin.sync();  

    system("cls");
    mainProgram(username);


}

//? UTILITIES
//! 1. Simple Calculator
void f_simpleCalculator(std::string username){
    int operation;
    int numCount;
    std::vector<double> numbers;

    int terminalWidth = 200;
    std::cout << centerAlign("    --------SIMPLE CALCULATOR--------     ", terminalWidth) << "\n\n";



do{

    std::cout << "Following Options:\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Back\n";
    std::cout << "Enter your choice: ";
    std::cin >> operation;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    
    if(operation == 5){
        system("cls");
        mainProgram(username);
    }

    if(operation != 1 || operation != 2 || operation != 3 || operation !=4){
        system("cls");
    }
   
}while(operation != 1 && operation != 2 && operation != 3 && operation !=4);

do{
    std::cout << "Enter the number of integer: ";
    std::cin >> numCount;

    if (numCount <= 0) {
        system("cls");
        std::cout << "Error: Please enter a valid number of values." << std::endl;
    }
}while(numCount <=0);

    for (int i = 1; i <= numCount; ++i) {
        double num;
        std::cout << "Enter number " << i << ": ";   
        std::cin >> num;
        numbers.push_back(num);
    }


    switch (operation) {
        case 1: {
            double result = 0;
            for (double num : numbers) {
                result += num;
            }
            std::cout << "Sum: " << result << std::endl;
            break;
        }
        case 2: {
            double result = numbers[0];
            for (int i = 1; i < numCount; ++i) {
                result -= numbers[i];
            }
            std::cout << "Difference: " << result << std::endl;
            break;
        }
        case 3: {
            double result = 1;
            for (double num : numbers) {
                result *= num;
            }
            std::cout << "Product: " << result << std::endl;
            break;
        }
        case 4: {
            if (numbers[numCount - 1] != 0) {
                double result = numbers[0];
                for (int i = 1; i < numCount; ++i) {
                    result /= numbers[i];
                }
                std::cout << "Quotient: " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is undefined." << std::endl;
            }
            break;
        }
        default:
            std::cout << "Error: Invalid operator." << std::endl;
    }

    f_terminationSC(username);
}

void f_terminationSC(std::string username){

    int choice = 0;

do{
    std::cout << "\nWant to try again?:\n";
    std::cout << "1. Try again\n";
    std::cout << "2. Back\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    

}while(choice != 1 && choice != 2);

    switch(choice){
        case 1: 
            system("cls");
            f_simpleCalculator(username);
            break;
        
        case 2: 
            system("cls");
            mainProgram(username);
            break;
    }

}

//! 2. Student Grade Calculator
void f_mstudentCalculator(std::string username){
    int arraySize = 0;

    const int maxSize = 100;
    int array[maxSize];

    f_studentCalculator(arraySize, array);
    f_average(arraySize, array);
    f_highestLowest(arraySize, array);
    f_terminationGC(username);

}

void f_studentCalculator(int &arraySize, int array[]){

    int terminalWidth = 200;
    std::cout << centerAlign("    --------STUDENT GRADE CALCULATOR--------     ", terminalWidth) << "\n\n";
    std::cout << "Enter the number of subjects: ";
    std::cin >> arraySize;

    for(int i = 0; i < arraySize; i++){

        std::cout << "Enter your grade " << i + 1 << ": ";
        std::cin >> array[i];
    }


}

void f_average(int arraySize, int array[]){

    int result = 0; 

    for(int i = 0; i < arraySize; i++){

        result += array[i];

    }

    result /= arraySize;
    
    std::cout << "\nAverage: " << result << std::endl;

}

void f_highestLowest(int arraySize, int array[]){

    int result = 0;

    int highest = array[0];
    int lowest = 0;

    for(int i = 0; i < arraySize; i++){

        if(highest < array[i]){
            highest = array[i];
        }
        else{
            lowest = array[i];
        }


    }

    std::cout << "Highest: " << highest << "\n";
    std::cout << "Lowest: " << lowest << "\n";



}

void f_terminationGC(std::string username){

    int choice = 0;

    do{
    std::cout << "\n\nCalculate again?:\n";
    std::cout << "1. Calculate again\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    system("cls");

    switch(choice){
        case 1: 
            f_mstudentCalculator(username);
            break;
        
        case 2:
            mainProgram(username);
            break;
    }

    }while(choice != 1 && choice != 2);

    
}

//! 3. BMI Calculator
void f_wbmiCalculator(std::string username){

    double height = 0;
    double weight = 0;
    double bmi = 0;
    int termination = 0;


do{
    std::cout << "******BMI Calculator*******\n";
    std::cout << "Input your height(meter): ";
    std::cin >> height;
    std::cout << "Input your weight(kg): ";
    std::cin >> weight;

    bmi = weight / (height * height);

    std::cout << "\nYour BMI: " << bmi << "\n";

    if(bmi < 18.5){
        std::cout << "You are underweight ):";
    }
    else if(bmi >= 18.5 && bmi <= 24.9){
        std::cout << "Your weight is normal, Keep it up!";
    }
    else if(bmi >= 25 && bmi <= 29.9){
        std::cout << "You are overweight ):";
    }
    else if(bmi > 30){
        std::cout << "You are obese ):";
    }

    std::cout << "\n\nCalculate your BMI again?\n";
    std::cout << "1. Calculate again\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> termination;

    if(termination == 1){
        system("cls");
    }

    if(termination == 2){
        system("cls");
        mainProgram(username);
    }

}while(termination != 2);
    



}

//! 4. Tip Calculator
void f_wtipCalculator(std::string username){

    int amount = 0;
    int tipPercent = 0;
    double tip = 0;
    double totalPay = 0;
    int termination = 0;
    int terminalWidth = 200;

    std::cout << centerAlign("    --------TIP CALCULATOR--------     ", terminalWidth) << "\n\n";


    do{
    std::cout << "Enter the amount of expenses: ";
    std::cin >> amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    if(amount <= 0){
        system("cls");
        std::cout << "Invalid amount! Please enter valid amount\n\n";
    }
    }while(amount <=0);

    do{
    std::cout << "Enter tip percentage: ";
    std::cin >> tipPercent;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    if(tipPercent <=0){
        system("cls");
        std::cout << "Invalid tip! Please enter valid tip\n\n";
    }
    }while(tipPercent <= 0);

    tip = amount * (tipPercent / 100.0);
    totalPay = amount + tip;


    std::cout << "Tip amount: " << tip << "\n";
    std::cout << "Total amount pay: " << totalPay << "\n";

    do{
    std::cout << "\nTry again?\n";
    std::cout << "1. Try again\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> termination;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }

    if(termination == 1){
        system("cls");
        f_wtipCalculator(username);
    }
    else if(termination == 2){
        system("cls");
        mainProgram(username);
    }

    }while(termination != 1 && termination != 2);

    
}

//! 5. Unit Converter
void f_wunitConverter(std::string username){

    int choice = 0;
    int unitChoice = 0;
    int convertChoice = 0;
    int firstUnit = 0;
    int secondUnit = 0;
    double convertedValue = 0;
    int termination = 0;
    int terminalWidth = 200;
    

do{
    std::cout << centerAlign("    --------UNIT CONVERTER--------     ", terminalWidth) << "\n\n";
    std::cout << "Choose Unit Category:\n";
    std::cout << "1. Length\n";
    std::cout << "2. Weight\n";
    std::cout << "3. Temperature\n";
    std::cout << "4. Volume\n";
    std::cout << "5. Time\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    system("cls");

}while(choice <=1 && choice >= 5);
    std::cout << "\n";

    switch(choice){
        case 1: 
                system("cls");
                std::cout << "Choose unit to convert:\n";
                std::cout << "1. Millimeter\n";
                std::cout << "2. Centimeter\n";
                std::cout << "3. Inch\n";
                std::cout << "4. Foot\n";
                std::cout << "5. Meter\n";
                std::cout << "6. Kilometer\n";
                std::cout << "Enter your choice: ";
                std::cin >> unitChoice;

                system("cls");

                std::cout << "Convert it into:\n";
                std::cout << "1. Millimeter\n";
                std::cout << "2. Centimeter\n";
                std::cout << "3. Inch\n";
                std::cout << "4. Foot\n";
                std::cout << "5. Meter\n";
                std::cout << "6. Kilometer\n";
                std::cout << "Enter your choice: ";
                std::cin >>  convertChoice;

                std::cout << "\n";

                switch(unitChoice){
                    case 1: 
                            if(convertChoice != 1){
                            std::cout << "Enter the value:\n";
                            std::cout << "Millimeter: ";
                            std::cin >> firstUnit;
                            std::cout << "\n";
                            }
                            switch(convertChoice){
                                case 1: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                case 2: 
                                        convertedValue = firstUnit / 10.0;
                                        std::cout << "Centimeter: " << convertedValue; 
                                        break;
                                case 3: 
                                        convertedValue = firstUnit / 25.4;
                                        std::cout << "Inch: " << convertedValue;
                                        break;
                                case 4: 
                                        convertedValue = firstUnit / 304.8;
                                        std::cout << "Foot: " << convertedValue;
                                        break;
                                case 5: 
                                        convertedValue = firstUnit / 1000.0;
                                        std::cout << "Meter: " << convertedValue;
                                        break;
                                case 6: 
                                        convertedValue = firstUnit / 1000000.0;
                                        std::cout << "Kilometer: " << convertedValue;
                                        break;
                            }
                            break;
                    case 2: 
                            if(convertChoice != 2){
                            std::cout << "Enter the value:\n";
                            std::cout << "Centimeter: ";
                            std::cin >> firstUnit;
                            std::cout << "\n";
                            }
                            switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 10;
                                        std::cout << "Millimeter: " << convertedValue;
                                        break;
                                case 2: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                case 3: 
                                        convertedValue = firstUnit / 2.54;
                                        std::cout << "Inch: " << convertedValue;
                                        break;
                                case 4: 
                                        convertedValue = firstUnit / 30.48;
                                        std::cout << "Foot: " << convertedValue;
                                        break;
                                case 5:  
                                        convertedValue = firstUnit / 100.0;
                                        std::cout << "Meter: " << convertedValue;
                                        break;
                                case 6: 
                                        convertedValue = firstUnit / 100000.0;
                                        std::cout << "Kilometer: " << convertedValue;
                                        break;
                            }
                            break;
                    case 3: 
                            if(convertChoice != 3){
                                std::cout << "Enter the value:\n";
                                std::cout << "Inch: ";
                                std::cin >> firstUnit;
                                std::cout << "\n";
                            }
                         switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 25.4;
                                        std::cout << "Millimeter: " << convertedValue;
                                        break;
                                case 2: 
                                        convertedValue = firstUnit * 2.54;
                                        std::cout << "Centimeter: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                case 4: 
                                        convertedValue = firstUnit / 12,0;
                                        std::cout << "Foot: " << convertedValue;
                                        break;
                                case 5:  
                                        convertedValue = firstUnit / 39.37;
                                        std::cout << "Meter: " << convertedValue;
                                        break;
                                case 6: 
                                        convertedValue = firstUnit / 39370.0;
                                        std::cout << "Kilometer: " << convertedValue;
                                        break;
                                                
                                }
                                break;
                        case 4: 
                                if(convertChoice != 4){
                                        std::cout << "Enter the value:\n";
                                        std::cout << "Foot: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }
                                switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 304.8;
                                        std::cout << "Millimeter: " << convertedValue;
                                        break;
                                case 2: 
                                        convertedValue = firstUnit * 30.48;
                                        std::cout << "Centimeter: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit * 12;
                                        std::cout << "Inch: " << convertedValue;
                                        break;
                                        
                                case 4: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                case 5:  
                                        convertedValue = firstUnit * 0.3048;
                                        std::cout << "Meter: " << convertedValue;
                                        break;
                                case 6: 
                                        convertedValue = firstUnit / 3280.84;
                                        std::cout << "Kilometer: " << convertedValue;
                                        break;
                                                
                                }
                                break;
                        case 5: 
                                if(convertChoice != 5){
                                        std::cout << "Enter the value:\n";
                                        std::cout << "Meter: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }
                                switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 1000;
                                        std::cout << "Millimeter: " << convertedValue;
                                        break;
                                case 2: 
                                        convertedValue = firstUnit * 100;
                                        std::cout << "Centimeter: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit * 39.37;
                                        std::cout << "Inch: " << convertedValue;
                                        break;
                                        
                                case 4: 
                                        convertedValue = firstUnit * 3.281;
                                        std::cout << "Foot: " << convertedValue;
                                        break;
                                        
                                case 5:  
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                case 6: 
                                        convertedValue = firstUnit / 1000.0;
                                        std::cout << "Kilometer: " << convertedValue;
                                        break;
                                                
                                }
                                break;
                        case 6: 
                                if(convertChoice != 6){
                                        std::cout << "Enter the value:\n";
                                        std::cout << "Kilometer: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }
                                switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 1000000;
                                        std::cout << "Millimeter: " << convertedValue;
                                        break;
                                case 2: 
                                        convertedValue = firstUnit * 100000;
                                        std::cout << "Centimeter: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit * 39370.1;
                                        std::cout << "Inch: " << convertedValue;
                                        break;
                                        
                                case 4: 
                                        convertedValue = firstUnit * 3280.84;
                                        std::cout << "Foot: " << convertedValue;
                                        break;
                                        
                                case 5: 
                                        convertedValue = firstUnit * 1000;
                                        std::cout << "Meter: " << convertedValue;
                                        break; 
                                        
                                case 6: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                                
                                }
                                break;

                        
                        
                            
                            
                }
                break;
        case 2: 
                system("cls");
                std::cout << "Choose unit to convert:\n";
                std::cout << "1. Microgram\n";
                std::cout << "2. Milligram\n";
                std::cout << "3. Gram\n";
                std::cout << "4. Kilogram\n";
                std::cout << "Enter your choice: ";
                std::cin >> unitChoice;

                system("cls");

                std::cout << "Convert it into:\n";
                std::cout << "1. Microgram\n";
                std::cout << "2. Milligram\n";
                std::cout << "3. Gram\n";
                std::cout << "4. Kilogram\n";
                std::cout << "Enter your choice: ";
                std::cin >>  convertChoice;

                switch(unitChoice){
                        
                        case 1: 
                                if(convertChoice != 1){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Microgram: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                case 1: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                case 2: 
                                        convertedValue = firstUnit / 1000.0;
                                        std::cout << "Milligram: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit / 1000000.0;
                                        std::cout << "Gram: " << convertedValue;
                                        break;
                                        
                                case 4: 
                                        convertedValue = firstUnit / 1000000000.0;
                                        std::cout << "Kilogram: " << convertedValue;
                                        break;
                                        
                                }

                                break;
                        
                        case 2: 
                                if(convertChoice != 2){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Milligram: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 1000;
                                        std::cout << "Microgram: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit / 1000.0;
                                        std::cout << "Gram: " << convertedValue;
                                        break;
                                        
                                case 4: 
                                        convertedValue = firstUnit / 1000000000.0;
                                        std::cout << "Kilogram: " << convertedValue;
                                        break;
                                        
                                }
                                break;
                        
                        case 3: 
                                if(convertChoice != 3){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Gram: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";

                                }
                                switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 1000000;
                                        std::cout << "Microgram: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit * 1000;
                                        std::cout << "Milligram: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 4: 
                                        convertedValue = firstUnit / 1000.0;
                                        std::cout << "Kilogram: " << convertedValue;
                                        break;
                                        
                                }
                                break;
                                
                        case 4: 
                                if(convertChoice != 4){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Kilogram: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";

                                }
                                switch(convertChoice){
                                case 1: 
                                        convertedValue = firstUnit * 1000000000;
                                        std::cout << "Microgram: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit * 1000000;
                                        std::cout << "Milligram: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit * 1000;
                                        std::cout << "Gram: " << convertedValue;
                                        break;
                                        
                                case 4: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                }
                                break;

                                
                }
                break;
        
        case 3: 
                system("cls");
                std::cout << "Choose unit to convert:\n";
                std::cout << "1. Celcius\n";
                std::cout << "2. Fahrenheit\n";
                std::cout << "3. Kelvin\n";
                std::cout << "Enter your choice: ";
                std::cin >> unitChoice;

                system("cls");

                std::cout << "Convert it into:\n";
                std::cout << "1. Celcius\n";
                std::cout << "2. Fahrenheit\n";
                std::cout << "3. Kelvin\n";
                std::cout << "Enter your choice: ";
                std::cin >>  convertChoice;

                switch(unitChoice){
                        
                        case 1: 
                                if(convertChoice != 1){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Celcius: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 2: 
                                        convertedValue = (9/5.0) * (firstUnit) + 32;
                                        std::cout << "Fahrenheit: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit + 273.15;
                                        std::cout << "Kelvin: " << convertedValue;
                                        break;
                                }
                                break;
                        
                        case 2: 
                                if(convertChoice != 2){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Fahrenheit: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }
                                
                                switch(convertChoice){

                                case 1: 
                                        convertedValue = (5 / 9.0) * (firstUnit - 32);
                                        std::cout << "Celcius: " << convertedValue;
                                        break;
                                        
                                        
                                case 2: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 3: 
                                        convertedValue = (5 / 9.0) * (firstUnit - 32) + 273.15;
                                        std::cout << "Kelvin: " << convertedValue;
                                        break;
                                }
                                break;
                        
                        case 3: 
                                if(convertChoice != 3){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Kelvin: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                
                                switch(convertChoice){

                                case 1: 
                                        convertedValue = firstUnit - 273.15;
                                        std::cout << "Celcius: " << convertedValue;
                                        break;
                                        
                                        
                                case 2: 
                                        convertedValue = (9 / 5.0) * (firstUnit - 273.15) + 32;
                                        std::cout << "Celcius: " << convertedValue;
                                        break;
                                        
                                        
                                case 3: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                }
                                break;


                         }
        
        
                }
                break;
        
        case 4: 
                system("cls");
                std::cout << "Choose unit to convert:\n";
                std::cout << "1. Milliliter\n";
                std::cout << "2. Litter\n";
                std::cout << "3. Gallon\n";
                std::cout << "Enter your choice: ";
                std::cin >> unitChoice;

                system("cls");

                std::cout << "Convert it into:\n";
                std::cout << "1. Milliliter\n";
                std::cout << "2. Litter\n";
                std::cout << "3. Gallon\n";
                std::cout << "Enter your choice: ";
                std::cin >>  convertChoice;

                switch(unitChoice){
                        
                        case 1: 
                                if(convertChoice != 1){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Milliliter: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit / 1000.0;
                                        std::cout << "Litter: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit / 3785.41;
                                        std::cout << "Gallon: " << convertedValue;
                                        break;
                                }
                                break;
                        
                        case 2: 
                                if(convertChoice != 2){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Litter: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        convertedValue = firstUnit * 1000;
                                        std::cout << "Milliliter: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit * 0.264172;
                                        std::cout << "Gallon: " << convertedValue;
                                        break;
                                }
                                break;
                        
                        case 3: 
                                if(convertChoice != 3){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Gallon: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        convertedValue = firstUnit * 3785.41;
                                        std::cout << "Milliliter: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit * 3.78541;
                                        std::cout << "Litter: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                }
                                break;

                }
                break;
        
        case 5: 
                system("cls");
                std::cout << "Choose unit to convert:\n";
                std::cout << "1. Second\n";
                std::cout << "2. Minute\n";
                std::cout << "3. Hour\n";
                std::cout << "4. Day\n";
                std::cout << "Enter your choice: ";
                std::cin >> unitChoice;

                system("cls");

                std::cout << "Convert it into:\n";
                std::cout << "1. Second\n";
                std::cout << "2. Minute\n";
                std::cout << "3. Hour\n";
                std::cout << "4. Day\n";
                std::cout << "Enter your choice: ";
                std::cin >>  convertChoice;
                
                switch(unitChoice){

                        case 1: 
                                if(convertChoice != 1){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Second: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit / 60.0;
                                        std::cout << "Minute: " << convertedValue;
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit / 3600.0;
                                        std::cout << "Hour: " << convertedValue;
                                        break;
                                
                                case 4: 
                                        convertedValue = firstUnit / 86400.0;
                                        std::cout << "Day: " << convertedValue;
                                        break;

                                }
                                break;
                        
                        case 2: 
                                if(convertChoice != 2){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Minute: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        convertedValue = firstUnit * 60;
                                        std::cout << "Second: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                        
                                case 3: 
                                        convertedValue = firstUnit / 60.0;
                                        std::cout << "Hour: " << convertedValue;
                                        break;
                                
                                case 4: 
                                        convertedValue = firstUnit / 1440.0;
                                        std::cout << "Day: " << convertedValue;
                                        break;

                                }
                                break;
                        
                        case 3: 
                                if(convertChoice != 3){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Hour: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        convertedValue = firstUnit * 3600;
                                        std::cout << "Second: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit * 60;
                                        std::cout << "Minute: " << convertedValue;
                                        break;
                                        
                                        
                                case 3: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;
                                
                                case 4: 
                                        convertedValue = firstUnit / 24.0;
                                        std::cout << "Day: " << convertedValue;
                                        break;

                                }
                                break;
                        
                        case 4: 
                                if(convertChoice != 3){
                                        std::cout << "\nEnter the value:\n";
                                        std::cout << "Day: ";
                                        std::cin >> firstUnit;
                                        std::cout << "\n";
                                }

                                switch(convertChoice){
                                
                                case 1: 
                                        convertedValue = firstUnit * 86400;
                                        std::cout << "Second: " << convertedValue;
                                        break;
                                        
                                case 2: 
                                        convertedValue = firstUnit * 1440;
                                        std::cout << "Minute: " << convertedValue;
                                        break;
                                        
                                        
                                case 3: 
                                        convertedValue = firstUnit * 24;
                                        std::cout << "Hour: " << convertedValue;
                                        break;
                                
                                case 4: 
                                        system("cls");
                                        std::cout << "You chose the same unit. Invalid!\n";
                                        break;

                                }
                                break;



                                
                }
                break;


        }

        do{
        std::cout << "\n\nConvert again?:";
        std::cout << "1. Convert again\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> termination;

        if(termination == 1){
                system("cls");
                f_wunitConverter(username);
        }

        if(termination == 2){
                system("cls");
                mainProgram(username);

        }

        system("cls");

        }while(termination != 1 && termination != 2);


}

//! 6. Word Counter
void f_wdisplaywordCounter(){
    int terminalWidth = 200;
    std::cout << centerAlign("    --------WORD COUNTER--------     ", terminalWidth) << "\n\n";

}
void f_wwordCounter(std::string username){

    std::string fileName;
    int termination = 0;
    
    std::cout << "Enter the file name (it should be ended with .txt): ";
    std::cin >> fileName;

    
    // Open the file "file.txt"
    std::ifstream file(fileName);

    // Check if the file is opened successfully
    if (!file) {
        system("cls");
        std::cout << "Error opening file.\n";
        std::cout << "Either the file doesn't exist or you have entered a wrong spelling of a file\n\n";
        f_wwordCounter(username);
    }

    int totalLines = 0;
    int lineNumber = 0;
    int totalChars = 0;
    char c;

    // Loop through each character in the file
    while (file.get(c)) {
        // Check for newline character
        if (c == '\n') {
            totalLines++;
            lineNumber++;
            std::cout << "line " << lineNumber << ": number of char: " << totalChars << std::endl;
            totalChars = 0;
        } else {
            totalChars++;
        }
    }

    // Check if there are characters left in the last line
    if (totalChars > 0) {
        totalLines++;
        std::cout << "line " << totalLines << ": number of char: " << totalChars << std::endl;
    }

    std::cout << "\ntotal lines: " << totalLines << std::endl;

do{
    std::cout << "\n\nTry again?:\n";
    std::cout << "1. Try again\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> termination;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    
    if(termination == 1){
        system("cls");
        f_wwordCounter(username);
    }

    if(termination == 2){
        system("cls");
        mainProgram(username);
    }

    system("cls");


}while(termination != 1 && termination != 2);


}

//! 7. Dice Roller
void f_wdiceRoller(std::string username){

    int choice = 0;
    int side = 0;
    int termination = 0;
    int terminalWidth = 200;

do{
    system("cls");
    std::cout << centerAlign("    --------DICE ROLLER--------     ", terminalWidth) << "\n\n";
    std::cout << "1. Roll the dice\n";
    std::cout << "2. Exit\n";
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    system("cls");
}while(choice != 1 && choice != 2);


    switch(choice){
        case 1: 
        
        do{
        system("cls");
        side = 6;
        side = std::rand() % side + 1;
        std::cout << "Dice value: " << side << "\n";
        
        std::string dare[] = {

            "Send a funny meme or joke to the third person in your contact list.",
            "Send a text message to the third person in your contact list saying, 'I love pickles'.",
            "Do 10 jumping jacks while reciting your favorite movie quote.",
            "Put on socks on your hands and try to type a silly sentence on your phone.",
            "Take a selfie with a funny facial expression and set it as your profile picture on a social media platform for the next 30 minutes.",
            "Find a random object in the room and create a 1-minute commercial for it.",
            "Perform a short interpretative dance to the theme song of your favorite TV show.",
            "Draw a funny doodle on your face using a washable marker.",
            "Record a video of yourself singing a nursery rhyme in a heavy metal style.",
            "Take a silly photo with a prop of your choice and make it your phone wallpaper for the next hour.",
            "Text a friend and tell them a completely made-up, outrageous story about your day.",
            "Put on a blindfold and attempt to draw a simple object within one minute.",
            "Balance a book on your head and walk around the room while reciting a tongue twister.",
            "Create a short rap about your favorite snack and perform it for everyone.",
            "Speak in an accent (of your choice) for the next 3 rounds of the game.",
        };

        std::cout << "Dare: " << dare[side];
        std::cout << "\n\nWant to roll again?\n";
        std::cout << "1. Yes, Roll again\n";
        std::cout << "2. No, I want to quit\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> termination;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
        if(termination == 2){
            system("cls");
            mainProgram(username);
            break;
        }


        }while(termination != 2);
        break;
        
        case 2: system("cls");
        mainProgram(username);
        break;
    }
        
}

//! 8. Currency Converter
void f_wcurrencyConverter(std::string username){

    int choice = 0;
    int convertedChoice = 0;
    int firstCurrency = 0;
    double convertedValue = 0;
    int terminalWidth = 200;
    
    std::cout << centerAlign("    --------Currency Converter--------     ", terminalWidth) << "\n\n";
    std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to exit\n";
    do{
    std::cout << "Choose following currency to convert:\n";
    std::cout << "1. Philippines Peso (PHP)\n";
    std::cout << "2. US Dollar (USD)\n";
    std::cout << "3. Euro (EUR)\n";
    std::cout << "4. Japanese Yen (JPY)\n";
    std::cout << "5. Chinese Yuan (CNY)\n";
    std::cout << "6. British Pound (GBP)\n\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if(choice == 0){
        system("cls");
        mainProgram(username);
        
    }

    if(choice < 0 || choice > 6){
        system("cls");
        std::cout << "Please enter a valid choice\n\n";
    }

    }while(!(choice >= 1 && choice <= 8) && choice != 0);

    system("cls");

    do{
    std::cout << "Convert it into:\n";
    std::cout << "1. Philippines Peso (PHP)\n";
    std::cout << "2. US Dollar (USD)\n";
    std::cout << "3. Euro (EUR)\n";
    std::cout << "4. Japanese Yen (JPY)\n";
    std::cout << "5. Chinese Yuan (CNY)\n";
    std::cout << "6. British Pound (GBP)\n";
    std::cout << "Enter your choice: ";
    std::cin >> convertedChoice;

    std::cout << "\n";

    if(convertedChoice <= 0 || convertedChoice >= 7){
        system("cls");
        std::cout << "Please enter a valid choice\n\n";
    }

    }while(convertedChoice <= 0 || convertedChoice >= 7);

    switch(choice){
        case 1: 
                if(convertedChoice != 1){
                    std::cout << "Enter the value:\n";
                    std::cout << "PHP: ";
                    std::cin >> firstCurrency;
                    std::cout << "\n";
                }

                switch(convertedChoice){

                    case 1: 
                        system("cls");
                        std::cout << "You chose the same currency. Invalid!\n";
                        break;
                                        
                    case 2: 
                        convertedValue = firstCurrency / 55.0;
                        std::cout << "USD: " << convertedValue;
                        break;
                                        
                    case 3: 
                        convertedValue = firstCurrency / 61.02;
                        std::cout << "EUR: " << convertedValue;
                        break;
                    case 4: 
                        convertedValue = firstCurrency / 0.39;
                        std::cout << "JPY: " << convertedValue;
                        break;
                    case 5: 
                        convertedValue = firstCurrency / 7.80;
                        std::cout << "CNY: " << convertedValue;
                        break;
                    case 6: 
                        convertedValue = firstCurrency / 70.427827;
                        std::cout << "GBP: " << convertedValue;
                        break;

                    
                }
                break;
        
        case 2: 
                if(convertedChoice != 2){
                    std::cout << "Enter the value:\n";
                    std::cout << "USD: ";
                    std::cin >> firstCurrency;
                    std::cout << "\n";
                }

                switch(convertedChoice){

                    case 1: 
                        convertedValue = firstCurrency * 55;
                        std::cout << "PHP: " << convertedValue;
                        break;
                                        
                    case 2: 
                        system("cls");
                        std::cout << "You chose the same currency. Invalid!\n";
                        break;
                                        
                    case 3: 
                        convertedValue = firstCurrency / 1.10;
                        std::cout << "EUR: " << convertedValue;
                        break;
                    case 4: 
                        convertedValue = firstCurrency / 0.0070;
                        std::cout << "JPY: " << convertedValue;
                        break;
                    case 5: 
                        convertedValue = firstCurrency / 0.14;
                        std::cout << "CNY: " << convertedValue;
                        break;
                    case 6: 
                        convertedValue = firstCurrency / 1.27;
                        std::cout << "GBP: " << convertedValue;
                        break;

                    
                }
                break;
            
        case 3: 
                if(convertedChoice != 3){
                    std::cout << "Enter the value:\n";
                    std::cout << "EUR: ";
                    std::cin >> firstCurrency;
                    std::cout << "\n";
                }

                switch(convertedChoice){

                    case 1: 
                        convertedValue = firstCurrency * 61.02;
                        std::cout << "PHP: " << convertedValue;
                        break;        
                    case 2: 
                        convertedValue = firstCurrency / 0.91;
                        std::cout << "USD: " << convertedValue;
                        break;
                    case 3: 
                        system("cls");
                        std::cout << "You chose the same currency. Invalid!\n";
                        break;
                    case 4: 
                        convertedValue = firstCurrency / 0.0064;
                        std::cout << "JPY: " << convertedValue;
                        break;
                    case 5: 
                        convertedValue = firstCurrency / 0.13;
                        std::cout << "CNY: " << convertedValue;
                        break;
                    case 6: 
                        convertedValue = firstCurrency / 1.15;
                        std::cout << "GBP: " << convertedValue;
                        break;

                    
                }
                break;
        case 4: 
                if(convertedChoice != 4){
                    std::cout << "Enter the value:\n";
                    std::cout << "JPY: ";
                    std::cin >> firstCurrency;
                    std::cout << "\n";
                }

                switch(convertedChoice){

                    case 1: 
                        convertedValue = firstCurrency / 2.57;
                        std::cout << "PHP: " << convertedValue;
                        break;        
                    case 2: 
                        convertedValue = firstCurrency / 142.41;
                        std::cout << "USD: " << convertedValue;
                        break;
                    case 3: 
                        convertedValue = firstCurrency / 157.03;
                        std::cout << "EUR: " << convertedValue;
                        break;
                    case 4: 
                        system("cls");
                        std::cout << "You chose the same currency. Invalid!\n";
                        break;
                    case 5: 
                        convertedValue = firstCurrency / 20.08;
                        std::cout << "CNY: " << convertedValue;
                        break;
                    case 6: 
                        convertedValue = firstCurrency / 180.84;
                        std::cout << "GBP: " << convertedValue;
                        break;

                    
                }
                break;
        
        case 5:
                if(convertedChoice != 5){
                    std::cout << "Enter the value:\n";
                    std::cout << "CNY: ";
                    std::cin >> firstCurrency;
                    std::cout << "\n";
                }

                switch(convertedChoice){

                    case 1: 
                        convertedValue = firstCurrency / 0.13;
                        std::cout << "PHP: " << convertedValue;
                        break;        
                    case 2: 
                        convertedValue = firstCurrency / 7.09;
                        std::cout << "USD: " << convertedValue;
                        break;
                    case 3: 
                        convertedValue = firstCurrency / 7.82;
                        std::cout << "EUR: " << convertedValue;
                        break;
                    case 4: 
                        convertedValue = firstCurrency / 0.050;
                        std::cout << "JPY: " << convertedValue;
                        break;
                        
                    case 5: 
                        system("cls");
                        std::cout << "You chose the same currency. Invalid!\n";
                        break;
                    case 6: 
                        convertedValue = firstCurrency / 9.01;
                        std::cout << "GBP: " << convertedValue;
                        break;
                }
                break;
        case 6: 
                if(convertedChoice != 6){
                    std::cout << "Enter the value:\n";
                    std::cout << "GBP: ";
                    std::cin >> firstCurrency;
                    std::cout << "\n";
                }

                switch(convertedChoice){

                    case 1: 
                        convertedValue = firstCurrency / 0.014;
                        std::cout << "PHP: " << convertedValue;
                        break;        
                    case 2: 
                        convertedValue = firstCurrency / 0.79;
                        std::cout << "USD: " << convertedValue;
                        break;
                    case 3: 
                        convertedValue = firstCurrency / 0.87;
                        std::cout << "EUR: " << convertedValue;
                        break;
                    case 4: 
                        convertedValue = firstCurrency / 0.0055;
                        std::cout << "JPY: " << convertedValue;
                        break;
                        
                    case 5: 
                        convertedValue = firstCurrency / 0.11;
                        std::cout << "CNY: " << convertedValue;
                        break;
                        
                    case 6: 
                        system("cls");
                        std::cout << "You chose the same currency. Invalid!\n";
                        break;
                }
                break;



                


                
    }


    char choiceConvert;

    do{
    std::cout << "\n\nWant to convert again? [y/n]: ";
    std::cin >> choiceConvert;

    choiceConvert = toupper(choiceConvert);

     if(choiceConvert == 'B'){
        system("cls");
        f_wcurrencyConverter(username);
    }
    else{
       system("cls"); 
       mainProgram(username);    
    }


    }while(choiceConvert != 'Y' || choiceConvert !='N');

}

//! 9. Pattern Maker
void f_wpatternMaker(std::string username){

    int choice = 0;
    int choicePattern = 0;
    int row = 0;
    int column = 0;
    char character = 0;

do{

    int terminalWidth = 200;
    std::cout << centerAlign("    --------Pattern Maker--------     ", terminalWidth) << "\n\n";
    
    std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
    std::cout << "Choose a pattern:\n";
    std::cout << "1. Triangle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "3. Diamond\n";
    std::cout << "4. Pyramid\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
            choice = 10;
        }
    system("cls");
}while(!(choice >= 1 && choice <= 4) && choice != 0);

    switch(choice){

        case 0:
                system("cls");
                mainProgram(username);
                break;

        case 1: 
                do{
                std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
                std::cout << "Choose triangle pattern:\n";
                std::cout << "1. Normal Triangle\n";
                std::cout << "2. Pascal Triangle\n";
                std::cout << "3. Inverted Triangle\n";
                std::cout << "Enter your choice: ";
                std::cin >> choicePattern;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
                choicePattern = 10;
                system("cls");
        }

                }while(!(choicePattern >= 1 && choicePattern <= 3) && choicePattern != 0);

                switch(choicePattern){
                        
                        case 0:
                                system("cls");
                                mainProgram(username);
                                break;

                        case 1: 
                                std::cout << "Enter the number of rows: ";
                                std::cin >> row;
                                std::cout << "Enter the character symbol: ";
                                std::cin >> character;
                                std::cout << "\n";

                                for (int i = 1; i <= row; ++i) {
                                for (int j = 1; j <= i; ++j) {
                                    std::cout << character;
                                }
                                std::cout << std::endl;
                            }
                                break;
                        
                        case 2:
                                std::cout << "Enter the number of rows: ";
                                std::cin >> row;
                                for (int i = 0; i < row; i++) {
                                int coefficient = 1;
                                for (int j = 0; j <= i; j++) {
                                    std::cout << coefficient << " ";
                                    coefficient = coefficient * (i - j) / (j + 1);
                                }
                                std::cout << std::endl;
                            }
                                break;

                        case 3: 
                                std::cout << "Enter the number of rows: ";
                                std::cin >> row;
                                std::cout << "Enter the character symbol: ";
                                std::cin >> character;
                                for (int i = row; i >= 1; --i) {
                                for (int j = 1; j <= i; ++j) {
                                    std::cout << character;
                                }
                                std::cout << std::endl;
                            }
                                break;





                }
                break;

        case 2: 
                std::cout << "Enter the number of row: ";
                std::cin >> row;
                std::cout << "Enter the number of column: ";
                std::cin >> column;
                std::cout << "Enter the character symbol: ";
                std::cin >> character;

                for (int i = 1; i <= row; ++i) {
                for (int j = 1; j <= column; ++j) {
                    std::cout << character;
                }
                std::cout << std::endl;


                }
                break;

        case 3: 
                do{
                std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
                std::cout << "Choose diamond pattern:\n";
                std::cout << "1. Solid Diamond\n";
                std::cout << "2. Hollow Diamond\n";
                std::cout << "3. Solid Hollow Diamond\n";
                std::cout << "Enter your choice: ";
                std::cin >> choicePattern;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
                choicePattern = 10;
                system("cls");
            }

                }while(!(choicePattern >= 1 && choicePattern <= 3) && choicePattern != 0);

                switch(choicePattern){

                    case 0:
                            system("cls");
                            mainProgram(username);
                            break;
                    
                    case 1: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = 1; i <= row; ++i) {
                                // Print spaces
                                for (int j = 1; j <= row - i; ++j) {
                                    std::cout << " ";
                                }

                                for (int k = 1; k <= 2 * i - 1; ++k) {
                                    std::cout << character;
                                }

                                std::cout << std::endl;
                            }

                            for (int i = row - 1; i >= 1; --i) {
                                // Print spaces
                                for (int j = 1; j <= row - i; ++j) {
                                    std::cout << " ";
                                }

                                for (int k = 1; k <= 2 * i - 1; ++k) {
                                    std::cout << character;
                                }

                                std::cout << std::endl;
                            }

                            break;

                    case 2: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = 1; i <= row; ++i) {
                            for (int j = 1; j <= row - i; ++j) {
                                std::cout << " ";
                            }
                            for (int k = 1; k <= 2 * i - 1; ++k) {
                                if (k == 1 || k == 2 * i - 1) {
                                    std::cout << character;
                                } else {
                                    std::cout << " ";
                                }
                            }
                            std::cout << std::endl;
                        }
                            for (int i = row - 1; i >= 1; --i) {
                                for (int j = 1; j <= row - i; ++j) {
                                    std::cout << " ";
                                }
                            for (int k = 1; k <= 2 * i - 1; ++k) {
                                if (k == 1 || k == 2 * i - 1) {
                                        std::cout << character;
                                } else {
                                        std::cout << " ";
                                    }
                                }

                                std::cout << std::endl;
                        }
                        break;


                    case 3: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = 1; i <= row; ++i) {
                            for (int k = 1; k <= i; ++k) {
                                std::cout << character;
                            }

                            std::cout << std::endl;
                        }

                        for (int i = row - 1; i >= 1; --i) {
                            for (int k = 1; k <= i; ++k) {
                                std::cout << character;
                            }

                            std::cout << std::endl;
                        }
                        break;




                }
                break;
        
        case 4: 

                do{
                std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress '0' to go back to main menu\n";
                std::cout << "Choose pyramid pattern:\n";
                std::cout << "1. Full Pyramid\n";
                std::cout << "2. Inverted Full Pyramid\n";
                std::cout << "3. Hollow Full Pyramid\n";
                std::cout << "4. Hollow Inverted Full Pyramid\n";
                std::cout << "Enter your choice: ";
                std::cin >> choicePattern;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
                choicePattern = 10;
                system("cls");
            }

                }while(!(choicePattern >= 1 && choicePattern <= 4) && choicePattern != 0);

                switch(choicePattern){

                    case 0: 
                            system("cls");
                            mainProgram(username);
                            break;

                    case 1: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = 1; i <= row; ++i) {
                            for (int j = 1; j <= row - i; ++j) {
                                std::cout << " ";
                            }
                            for (int k = 1; k <= 2 * i - 1; ++k) {
                                std::cout << character;
                            }
                            std::cout << std::endl;
                        }
                            break;

                    case 2: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = row; i >= 1; --i) {
                            for (int j = 1; j <= row - i; ++j) {
                                std::cout << " ";
                            }
                            for (int k = 1; k <= 2 * i - 1; ++k) {
                                std::cout << character;
                            }
                            std::cout << std::endl;
                        }
                            break;

                    case 3: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = 1; i <= row; ++i) {
                            for (int j = 1; j <= row - i; ++j) {
                                std::cout << " ";
                            }
                            for (int k = 1; k <= 2 * i - 1; ++k) {
                                if (k == 1 || k == 2 * i - 1) {
                                    std::cout << character;
                                } else {
                                    std::cout << " ";
                                }
                            }
                            std::cout << std::endl;
                        }
                            break;
                    
                    case 4: 
                            std::cout << "Enter the number of row: ";
                            std::cin >> row;
                            std::cout << "Enter the character symbol: ";
                            std::cin >> character;

                            for (int i = row; i >= 1; --i) {
                            for (int j = 1; j <= row - i; ++j) {
                                std::cout << " ";
                            }
                            for (int k = 1; k <= 2 * i - 1; ++k) {
                                if (k == 1 || k == 2 * i - 1) {
                                    std::cout << "*";
                                } else {
                                    std::cout << " ";
                                }
                            }
                            std::cout << std::endl;
                        }
                }
                break;

    }

    do{
    std::cout << "\nWant to try again?\n";
    std::cout << "1. Try again\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if(choice == 2){
        system("cls");
        mainProgram(username);
    }

    if(choice == 1){
        system("cls");
        f_wpatternMaker(username);
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            choice = 10;
            system("cls");
        }

    }while(choice != 1 && choice !=2);

}

//? STUDIES
//! 1. Random Fact Generator
void f_wrandomFact(std::string username){

    int numFacts = 0;
    int counter = 0;

    const std::string randomFact[] = {
    "Honey never spoils. Archaeologists have found pots of honey in ancient Egyptian tombs that are over 3,000 years old and still perfectly edible.",
    "The Eiffel Tower can be 15 cm taller during the summer due to the expansion of the iron in the heat.",
    "Bananas are berries, but strawberries aren't.",
    "The shortest war in history was between Britain and Zanzibar on August 27, 1896. Zanzibar surrendered after 38 minutes.",
    "The Great Wall of China is not visible from the moon with the naked eye.",
    "The dot over the letters 'i' and 'j' is called a tittle.",
    "Octopuses have three hearts. Two pump blood to the gills, and one pumps it to the rest of the body.",
    "A group of flamingos is called a 'flamboyance.'",
    "The world's largest desert is Antarctica.",
    "Wombat poop is cube-shaped.",
    "Cows have best friends and can become stressed when they are separated.",
    "The word 'nerd' was first coined by Dr. Seuss in 'If I Ran the Zoo' in 1950.",
    "Honeybees can recognize human faces.",
    "The longest word without a vowel is 'rhythms.'",
    "The inventor of the frisbee was turned into a frisbee. Walter Morrison's ashes were turned into a limited edition of frisbees after he died.",
    "The shortest war in history lasted only 38 to 45 minutes between Britain and Zanzibar in 1896.",
    "A group of owls is called a 'parliament.'",
    "The world's largest snowflake was 15 inches in diameter.",
    "The first recorded game of baseball was played in 1846 in Hoboken, New Jersey.",
    "The fingerprints of a koala are so indistinguishable from humans that they have on occasion been confused at a crime scene.",
    "The Great Wall of China is not visible from the moon with the naked eye.",
    "The first computer programmer was a woman named Ada Lovelace.",
    "The oldest known recipe is for beer.",
    "In 1923, jockeys in Australia went on strike, demanding better pay. In response, race organizers replaced them with apprentice boys, one of whom was 13 years old.",
    "The first recorded game of golf was played on March 26, 1297, in Scotland.",
    "The original name for Bank of America was 'Bank of Italy.'",
    "The world's largest desert is Antarctica.",
    "The average person will spend six months of their life waiting for red lights to turn green.",
    "The shortest war in history lasted between Britain and Zanzibar on August 27, 1896. Zanzibar surrendered after 38 minutes.",
    "A group of flamingos is called a 'flamboyance.'",
    "The average person walks the equivalent of three times around the world in a lifetime.",
    "The word 'nerd' was first coined by Dr. Seuss in 'If I Ran the Zoo' in 1950.",
    "Honey never spoils. Archaeologists have found pots of honey in ancient Egyptian tombs that are over 3,000 years old and still perfectly edible.",
    "The Eiffel Tower can be 15 cm taller during the summer due to the expansion of the iron in the heat.",
    "Bananas are berries, but strawberries aren't.",
    "The shortest war in history was between Britain and Zanzibar on August 27, 1896. Zanzibar surrendered after 38 minutes.",
    "The Great Wall of China is not visible from the moon with the naked eye.",
    "The dot over the letters 'i' and 'j' is called a tittle.",
    "Octopuses have three hearts. Two pump blood to the gills, and one pumps it to the rest of the body.",
    "Cknrf is the name of the creator of AI OP"
};



    numFacts = sizeof(randomFact) / sizeof(randomFact[0]);

    int terminalWidth = 200;
    std::cout << centerAlign("    --------RANDOM FACT GENERATOR--------     ", terminalWidth) << "\n\n";


    std::cout << "Just press enter to continue or any key to exit: ";


    do{


        if(std::cin.get() == '\n'){
            system("cls");
            std::cout << "Random Fact:\n";
            std::cout << randomFact[std::rand() % 40];
            counter++;

            if(counter > 0){
            std::cout << "\n\nPress Enter for the next fact or Enter any other key to exit: ";
        }

            
            continue;
        }
        else{
            system("cls");
            mainProgram(username);
            
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();

        break;

    }while(true);

    mainProgram(username);


}

//! 2. Quiz
void f_wquizGame(){

    int terminalWidth = 200;
    std::cout << centerAlign("    --------QUIZ--------     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Read the instructions carefully:     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Each quiz consist of 10 questions     ", terminalWidth) << "\n\n";
    std::cout << centerAlign("    Quiz consist of three difficulties: Easy, Medium, and Hard     ", terminalWidth) << "\n\n";

}

void f_chooseDifficultyQG(std::string username){

    int choice = 0;
    do{
    std::cout << "Difficulties:\n";
    std::cout << "1. Easy\n";
    std::cout << "2. Medium\n";
    std::cout << "3. Hard\n";
    std::cout << "Choose difficulty: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    system("cls");
     switch(choice){
        case 1: 
            f_easyDifficultyQG(username);
            break;
        case 2: 
            f_mediumDifficultyQG(username);
            break;
        case 3: 
            f_hardDifficultyQG(username);
            break;
        default: std::cout << "You did not enter a correct choice!\n";
    }

    }while(choice != 1 && choice != 2 && choice != 3);
    system("cls");
   

}

void f_easyDifficultyQG(std::string username){

    char answer;
    int correct = 0;
    

    std::srand(static_cast<unsigned int>(std::time(0)));

    int myArray[] = {0, 1, 2, 3, 4, 5, 7, 8, 6, 9};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    std::shuffle(myArray, myArray + arraySize, std::default_random_engine(std::rand()));

    std::string quizQuestion[] = {
        "What does the acronym 'C++' stand for?",
        "In C++, what is the purpose of the cin object?",
        "What is the correct syntax for a single-line comment in C++?",
        "Which keyword is used to dynamically allocate memory in C++?",
        "How do you declare a constant in C++?",
        "What is the purpose of the endl in C++?",
        "In C++, what does the sizeof operator return?",
        "How do you create a function in C++?",
        "What is the purpose of the static keyword in C++?",
        "What is a pointer in C++?",


    };

    std::string quizChoice[] = {
        "a) Central Plus Plus  b) C Plus Point  c) C Plus Plus  d) Computer Programming Language",
        "a) Output data to the console  b) Input data from the console  c) Perform mathematical calculations  d) Define a constant variable",
        "a) // Comment goes here  b) /* Comment goes here */  c) # Comment goes here  d) -- Comment goes here",
        "a) malloc  b) new  c) allocate  d) create",
        "a) const int x;  b) constant x;  c) int constant x;  d) int x const;",
        "a) End the program  b) End the current loop  c) Insert a newline character and flush the output buffer  d) Display an error message",
        "a) The size of a data type in bytes  b) The value of a variable  c) The number of elements in an array  d) The address of a variable",
        "a) function myFunction() {}  b) void myFunction() {}  c) def myFunction() {}  d) subroutine myFunction() {}",
        "a) Specify a constant value  b) Make a variable accessible only within the current file  c) Indicate that a function cannot be overridden  d) Allocate memory for a variable at compile-time",
        "a) A variable that cannot be modified  b) A variable that holds the memory address of another variable  c) A variable that stores multiple values  d) A variable used to perform mathematical operations",

    };

    char answerKey[] = {
        'c',
        'b',
        'a',
        'b',
        'a',
        'c',
        'a',
        'b',
        'b',
        'b',
    };

    for(int i = 0; i < arraySize; ++i) {

        system("cls");
        
        std::cout << "\t\t\t\t\t\tcorrect: " << correct << "\tquestion: " << i + 1 << "\n\n";

        std::cout << quizQuestion[myArray[i]] << "\n";
        std::cout << quizChoice[myArray[i]] << "\n\n";

        std::cout << "Enter your answer: ";
        std::cin >> answer;

        answer = tolower(answer);

        if(answer == answerKey[myArray[i]]){
            correct++;
        }


    }

    f_displayResultQG(correct, username);




}

void f_mediumDifficultyQG(std::string username){

    char answer;
    int correct = 0;
    

    std::srand(static_cast<unsigned int>(std::time(0)));

    int myArray[] = {0, 1, 2, 3, 4, 5, 7, 8, 6, 9};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    std::shuffle(myArray, myArray + arraySize, std::default_random_engine(std::rand()));

    std::string quizQuestion[] = {
        "C++ is an alias of C#",
        "Which method can be used to find the length of a string?",
        "Who invented C++?",
        "Which of the following is the correct syntax of including a user defined header files in C++?",
        "Which of the following is a correct identifier in C++?",
        "Which of the following is not a type of Constructor in C++?",
        "Which of the following approach is used by C++?",
        "Which is more effective while calling the C++ functions?",
        "What is the size of wchar_t in C++?",
        "By default, all the files in C++ are opened in _________ mode.",


    };

    std::string quizChoice[] = {
        "a) True  b) False  c) It is an alias of C  d) None of the above",
        "a) len()  b) size()  c) length()  d) count()",
        "a) Dennis Ritchie  b) Ken Thompson  c) Brian Kernighan  d) Bjarne Stroustrup",
        "a) #include [userdefined]  b) #include “userdefined”  c) #include <userdefined.h>  d) #include <userdefined>",
        "a) VAR_1234  b) $var_name  c) 7VARNAME  d) 7var_name",
        "a) Default constructor  b) Parameterized constructor  c) Copy constructor  d) Friend constructor",
        "a) Left-right  b) Right-left  c) Bottom-up  d) Top-down",
        "a) Call by object  b) Call by pointer  c) Call by value  d) Call by reference",
        "a) Based on the number of bits in the system  b) 2 or 4  c) 4  d) 2",
        "a) Binary  b) VTC  c) Text  d) ISCII",

    };

    char answerKey[] = {
        'b',
        'c',
        'a',
        'b',
        'a',
        'd',
        'c',
        'd',
        'a',
        'c',
    };

    for(int i = 0; i < arraySize; ++i) {

        system("cls");
        
        std::cout << "\t\t\t\t\t\tcorrect: " << correct << "\tquestion: " << i + 1 << "\n\n";

        std::cout << quizQuestion[myArray[i]] << "\n";
        std::cout << quizChoice[myArray[i]] << "\n\n";

        std::cout << "Enter your answer: ";
        std::cin >> answer;

        answer = tolower(answer);

        if(answer == answerKey[myArray[i]]){
            correct++;
        }


    }

    f_displayResultQG(correct, username);


}

void f_hardDifficultyQG(std::string username){

    char answer;
    int correct = 0;
    

    std::srand(static_cast<unsigned int>(std::time(0)));

    int myArray[] = {0, 1, 2, 3, 4, 5, 7, 8, 6, 9};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    std::shuffle(myArray, myArray + arraySize, std::default_random_engine(std::rand()));

    std::string quizQuestion[] = {
        "What is the use of the indentation in c++?",
        "Which keyword is used to define the macros in c++?",
        "What is Inheritance in C++?",
        "The C++ code which causes abnormal termination/behaviour of a program should be written under _________ block.",
        "Which of the following symbol is used to declare the preprocessor directives in C++?",
        "What is meant by a polymorphism in C++?",
        "Which of the following constructors are provided by the C++ compiler if not defined in a class?",
        "Which concept allows you to reuse the written code in C++?",
        "What is the benefit of c++ input and output over c input and output?",
        "Which of the following correctly declares an array in C++?",


    };
    


    std::string quizChoice[] = {
        "a) Distinguishes between comments and inner data  b) Distinguishes between comments and outer data  c) Distinguishes between comments and code  d) None of the above",
        "a) #macro  b) #define  c) macro  d) define",
        "a) Deriving new classes from existing classes  b) Overloading of classes  c) Classes with same names  d) Wrapping of data into a single class",
        "a) catch  b) throw  c) try  d) finally",
        "a) $  b) ^  c) #  d) *",
        "a) class having only single form  b) class having four forms  c) class having many forms  d) class that has no form",
        "a) Copy constructor  b) Default constructor  c) Assignment constructor  d) All of the mentioned",
        "a) Inheritance  b) Polymorphism  c) Abstraction  d) Encapsulation",
        "a) Both Type safety & Exception  b) Sequence container  c) Exception  d) Type safety",
        "a) array{10};  b) array array[10];  c) int array;  d) int array[10];",

    };

    char answerKey[] = {
        'c',
        'b',
        'a',
        'c',
        'c',
        'c',
        'd',
        'a',
        'd',
        'd',
    };

    for(int i = 0; i < arraySize; ++i) {

        system("cls");
        
        std::cout << "\t\t\t\t\t\tcorrect: " << correct << "\tquestion: " << i + 1 << "\n\n";

        std::cout << quizQuestion[myArray[i]] << "\n";
        std::cout << quizChoice[myArray[i]] << "\n\n";

        std::cout << "Enter your answer: ";
        std::cin >> answer;

        answer = tolower(answer);

        if(answer == answerKey[myArray[i]]){
            correct++;
        }


    }

    f_displayResultQG(correct, username);




}

void f_displayResultQG(int correct, std::string username){

    int choice = 0;

    system("cls");

    std::cout << "Quiz is done\n\n";
    
    if(correct == 10){
        std::cout << "Wow!! You got a perfect score (:\n";
    }
    else if(correct >= 7 && correct < 10){
        std::cout << "Congratulations, you passed the quiz (:\n";
    }
    else{
        std::cout << "Oh no, you didn't passed the quiz ):\n";
    }

    std::cout << "Number of correct: " << correct << "\n";

    do{
    std::cout << "\n\nWant to play again?\n";
    std::cout << "1. Yes, I want to play again!\n";
    std::cout << "2. No, I want to exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }

    if(choice != 1 || choice !=2){
        system("cls");
        std::cout << "Enter a valid choice";
    }


}while(choice != 1 && choice != 2);

    if(choice == 1){
        system("cls");
        f_chooseDifficultyQG(username);
    }
    else{
        system("cls");
        mainProgram(username);
    }


}

//? SECURITY
//! 1. Password Generator
void f_wpasswordGenerator(std::string username){

    int passwordLength = 0;
    int termination = 0;
    int terminalWidth = 200;

    std::cout << centerAlign("    --------PASSWORD GENERATOR--------     ", terminalWidth) << "\n\n";

    do{
    std::cout << "Enter the length of the password: ";
    std::cin >> passwordLength;

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>?/";
    const int charsetSize = sizeof(charset) - 1;

    std::string password;
    password.reserve();

    for (int i = 0; i < passwordLength; ++i) {
        password += charset[std::rand() % charsetSize];
    }

    std::cout << "Generated Password: " << password;

    do{
    std::cout << "\n\nGenerate password again?\n";
    std::cout << "1. Generate Again\n";
    std::cout << "2. No, I want to exit\n";
    std::cout << "Enter your option: ";
    std::cin >> termination;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the invalid input
        }
    system("cls");

    }while(termination != 1 && termination !=2);

    if(termination == 2){
        system("cls");
        mainProgram(username);
        break;
    }

    system("cls");
    
    }while(termination != 2);

}









