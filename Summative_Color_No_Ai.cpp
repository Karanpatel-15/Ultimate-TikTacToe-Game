/*  
  ..................................................
.   o   \ o /  _ o        __|     o _  \ o /   o   .
.  /|\    |     /\   __\o   \o    /\     |    /|\  .
.  / \   / \   | \  /) |    ( \   / |   / \   / \  .
.       ....................................       .
. \ o / .                                  . \ o / .
.   |   .                                  .   |   .
.  / \  .                                  .  / \  .
.       .                                  .       .
.  _ o  .                                  .  _ o  .
.   /\  .                                  .   /\  .
.  | \  .                                  .  | \  .
.       .           KARAN PATEL            .       .
.       .                                  .       .
.  __\o .           Jan, 6 2020            .  __\o .
. /) |  .                                  . /) |  .
.       .       	 Summative    	   .       .
. __|   .         	                   . __|   .
.   \o  .           Tic Tac Toe            .    \o .
.   ( \ .                                  .   ( \ .
.       .           Dev c++ 5.11           .       .
.  \ /  .                                  .  \ /  .
.   |   .                     		       .   |   .
.  /o\  .                                  .  /o\  .
.       .                                  .       .
.       ....................................       .
.   o   \ o /  _ o        __|     o _  \ o /   o   .
.  /|\    |     /\   __\o   \o    /\     |    /|\  .
.  / \   / \   | \  /) |    ( \   / |   / \   / \  .
....................................................

	Data dictionary:
			i.........is used throughout the program acting as a counter
			
			mainMenu Function:
				int option..................user chooses 1 of 5 option to start playing (2 Rule Books, 2 games and Quit)
				
			Rules Function:
				int ruleNumber..............used to determine which rule book to display (1 or 2)
				
			NormalTTT Function:
				char normalBoard[9].........array for normal tic tac toe board, [0] = position  1 on the TTT board...
				int player..................player number, 1 or 2
				char mark...................mark for the player, 1 = 'X',  2 = 'O'
				int gameStatus..............current status of the game -1 = Game in Progress, 0 = Draw, 1 = Someone won
				int choice..................the player's move such as player 1 'X' wants to go on position 2
				
	  		normalBoardDisplay Function:
	  			normalBoard[9]..............same array passed on from the NormalTTT Function but used to draw the board (No changes made here)
	  			
	  		ultimateTTT Function: 
	  			char board[9][9]............array for ultimate tic tac toe board, [0][0] = quadrant 1 and position 1 on the TTT board...
			    char masterBoard[1][9]......array for ultimate tic tac toe board but is used for the winning of the quadrant, [0] means quadrant 1 has been won or drawn
			    int quad....................is the final and valid move that the player has choosin 
			    int newQuad.................is the temporary move that the player has chosen that need to be checked and if valid moved into quad
				int pos.....................is the final and valid move that the player has choosin 
				int newPos..................is the temporary move that the player has chosen that need to be checked and if valid moved into pos
			    bool validMove..............this will indicate if the move is valid, true = valid, false = invalid
			    bool gameEnd................this will indicate if the game is over, true = game over, false = game in progress
			    int player..................player number, 1 or 2
			    char mark...................mark for the player, 1 = 'X',  2 = 'O'
			    int mbStatus................current Masterboard status, -1 = Game in Progress, 0 = Draw, 1 = Someone won
					    
	  		displayBoard Function: 
	  			char board[9][9]............same array passed on from the UltimateTTT Function but used to draw the board (No changes made here)
	  			int quad....................The current quadrant in play
	  			int q,p,t...................counters for printing the board
	  			
	  		checkValidMove Function: 
	  			int quad....................check for valid or invalid move in the quad entered 
	  			int pos.....................check for valid or invalid move in the pos entered
	  			char board[9][9]............same array passed on from the UltimateTTT Function but used to draw the board (No changes made here)
				char masterBoard[1][9]......same array passed on from the UltimateTTT Function but used to draw the board (No changes made here)
				
	  		checkWin Function:
	  			char quadBoard[9]...........used to check the win of any of the board arrays(board[9][9], masterBoard[1][9], board[9][9], normalBoard)
*/

#include <iostream>

#include <windows.h>

#include <conio.h>

using namespace std;

//For color in the program
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

// Menu and Rules Function
void mainMenu();
void rules(int ruleNumber);

// Normal Tic TAc Toe Function
void normalTTT();
void normalBoardDisplay(char normalBoard[9]);

// Ultimate  Tic TAc Toe Function
void ultimateTTT();
void displayBoard(char board[9][9], int quad, char masterBoard[0][9]);
bool checkValidMove(int quad, int pos, char board[9][9], char masterBoard[1][9]);
int checkWin(char board[9]);

/////////////////////////////////////// Main Function /////////////////////////////////////////////////////////////////////////////

int main() {
    //call main menu
    mainMenu();
}

/////////////////////////////////////// Menu and Rules ////////////////////////////////////////////////////////////////////////////

void mainMenu() {
    int option = 1;

    //loop until user want to quit	
    while (option != 5) {
        //print options
        cout << "\tWelcome to Ultimate Tic Tac Toe" << endl << endl;
        cout << "   1.  Normal Tic Tac Toe Rules" << endl;
        cout << "   2.  Play Normal Tic Tac Toe" << endl;
        cout << "   3.  Utimate Tic Tac Toe Rules" << endl;
        cout << "   4.  Play Ultimate Tic Tac Toe" << endl;
        cout << "   5.  Quit" << endl;

        //ask for option
        cout << "\n\tChoose an Option : ";
        cin >> option;

        //clear Screen
        system("cls");

        //run the users option
        switch (option) {

        case (1):
            //Normal Tic Tac Toe Rules
            rules(1);

            //return to main menu
            cout << "\n Press any key to continue...";
            getch();
            break;
        case (2):
            //run normal Tic Tac Toe
            normalTTT();
            //return to main menu
            cout << "\n Press any key to continue...";
            getch();
            break;
        case (3):
            //Ultimate Tic Tac Toe Rules
            rules(2);
            //return to main menu
            cout << "\n Press any key to continue...";
            getch();
            break;
        case (4):
            //run Ultimate Tic Tac Toe
            ultimateTTT();
            //return to main menu
            cout << "\n Press any key to continue...";
            getch();
            break;
        }

        //clear screen 
        system("cls");
    }
    //ending message
    cout << "Have a nice Day";

}

void rules(int ruleNumber) {

    if (ruleNumber == 1) {
        cout << "\n\tNormal Tic Tac Toe Rules" << endl << endl;
        cout << "   1. The game is played on a grid that's 3 squares by 3 squares." << endl;
        cout << "   2. You are X, your friend (or the computer in this case) is O. Players take turns putting their marks in empty squares." << endl;
        cout << "   3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner." << endl;
        cout << "   4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie." << endl << endl;
        cout << "\t   Postion Numbers" << endl;
        cout << "\t.  .  .       1  2  3" << endl;
        cout << "\t.  .  .  -->  4  5  6" << endl;
        cout << "\t.  .  .       7  8  9" << endl;
    } else if (ruleNumber == 2) {
        cout << "\nUltimate Tic Tac Toe Rules" << endl << endl;
        cout << "   1. Set up the tic-tac-toe board if ones not available by drawing a large tic-tac-toe board and then drawing a smaller board in each square. " << endl;
        cout << "   2. Each turn, mark one of the small boards. " << endl;
        cout << "   3. When you win three in a row, you\'ve won that board. " << endl;
        cout << "   4. *The board you play on is determined by your opponents previous move. Whatever square was picked will determine the board you play on. For example, if your opponent placed an X on the middle square, you may place an O anywhere on the middle board.*" << endl;
        cout << "   5. If the board you must play on is already won, then you may go wherever you would like. " << endl;
        cout << "   6. If there is a tie, then count the board as neither an X or an O" << endl;
        cout << "   7. The first person to win three small tic tac toe boards in row wins the game!" << endl << endl;
        cout << "\t   Postion Numbers" << endl;
        cout << "\t.  .  .       1  2  3" << endl;
        cout << "\t.  .  .  -->  4  5  6" << endl;
        cout << "\t.  .  .       7  8  9" << endl << endl;
        SetConsoleTextAttribute(color, 14);
        cout << "   Yellow = Next Quad to Enter" << endl;
        SetConsoleTextAttribute(color, 1);
        cout << "   Blue = Player 1 \'X\' won that quad" << endl;
        SetConsoleTextAttribute(color, 2);
        cout << "   Green = Player 2 \'O\' won that quad" << endl;
        SetConsoleTextAttribute(color, 4);
        cout << "   Draw = Both Players Drawed that Quad" << endl;
        SetConsoleTextAttribute(color, 7);

    }

}

/////////////////////////////////////// Normal Tic Tac Toe ////////////////////////////////////////////////////////////////////////

void normalTTT() {

    char normalBoard[9];
    int player = 1, gameStatus, choice;
    char mark;
    bool validMove = true;

    //set all array values to '.'
    for (int i = 0; i < 9; i++) {
        normalBoard[i] = '.';
    }

    //loop until a player won or there is a draw
    do {
        //display board
        normalBoardDisplay(normalBoard);

        //player 1 or 2
        player = (player % 2) ? 1 : 2;

        //set mark to player number;
        mark = (player == 1) ? 'X' : 'O';

        if (!validMove) {
            SetConsoleTextAttribute(color, 4);
            cout << "Invalid move" << endl;
            SetConsoleTextAttribute(color, 7);
        }

        //display player and ask for there move
        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        //check if the position is not already taken
        if (choice >= 1 && choice <= 9 && normalBoard[choice - 1] == '.') {
            validMove = true;
            normalBoard[choice - 1] = mark;
        } else {
            validMove = false;
            player--;
        }

        //check game status (win or draw)
        gameStatus = checkWin(normalBoard);
        player++;

    } while (gameStatus == -1);

    //display board
    normalBoardDisplay(normalBoard);

    //print game result
    if (gameStatus == 1)
        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";

}

void normalBoardDisplay(char normalBoard[9]) {
    //clear screen
    system("cls");

    //print board
    cout << "\n\n\t   Tic Tac Toe\n\n";

    cout << "  Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "\t     |     |     " << endl;
    cout << "\t  " << normalBoard[0] << "  |  " << normalBoard[1] << "  |  " << normalBoard[2] << endl;

    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    cout << "\t  " << normalBoard[3] << "  |  " << normalBoard[4] << "  |  " << normalBoard[5] << endl;

    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    cout << "\t  " << normalBoard[6] << "  |  " << normalBoard[7] << "  |  " << normalBoard[8] << endl;

    cout << "\t     |     |     " << endl << endl;
}

/////////////////////////////////////// Ultimate Tic Tac Toe //////////////////////////////////////////////////////////////////////

void ultimateTTT() {
    char board[9][9];
    char masterBoard[1][9];
    int quad = -1, pos = -1;
    int newQuad = -1, newPos = -1;
    bool validMove = true;
    bool gameEnd = false;
    int player = 0;
    char mark;
    int mbStatus = -1;
    int i = 0;

    // set default mark '.' at each position in board and master board
    for (int q = 0; q < 9; q++) {
        for (int p = 0; p < 9; p++) {
            board[q][p] = '.';
        }
        masterBoard[0][q] = '.';
    }

    // Until the end of game
    while (!gameEnd) {

        // set player number
        player++;

        do {
            // Set player number to 1 or 2 and set mark 'X' or 'O'
            player = (player % 2) ? 1 : 2;
            mark = (player == 1) ? 'X' : 'O';

            // Display board
            displayBoard(board, pos, masterBoard);

            // Check move is valid or not
            // It always valid on first attempt
            if (!validMove) {
                cout << "Invalid Move Try again!\n";
            }

            // print player number

            cout << "Player " << player << " ( ";
            if (mark == 'X')
                SetConsoleTextAttribute(color, 1);
            else if (mark == 'O')
                SetConsoleTextAttribute(color, 2);
            cout << mark;
            SetConsoleTextAttribute(color, 7);
            cout << " )" << endl;

            // quad = -1 means user required to choose the quad
            if (quad == -1) {

                // The first time it wont say 'The Quad..'
                if (i != 0) {
                    SetConsoleTextAttribute(color, 14);
                    cout << "That Quad Has Already been completed" << endl;
                }
                i++;
                SetConsoleTextAttribute(color, 7);
                cout << "Choose a Quad : ";
                cin >> newQuad;
            } else {
                // Set next quad as per the previous position
                newQuad = pos;
            }

            // Ask for position to play
            cout << "Choose a Position : ";
            cin >> newPos;

            // Check valid move or not as per user requested
            validMove = checkValidMove(newQuad, newPos, board, masterBoard);

            // Update quad and pos if valid move
            if (validMove) {
                quad = newQuad;
                pos = newPos;
            }

        } while (!validMove);

        // It is valid move. Mark position in current quad
        board[quad - 1][pos - 1] = mark;

        // check current quad status and update Master Board accordingly
        int quadStatus = checkWin(board[quad - 1]);

        if (quadStatus != -1) {
            if (quadStatus == 1)
                masterBoard[0][quad - 1] = mark;
            else if (quadStatus == 0)
                masterBoard[0][quad - 1] = '-';
            mbStatus = checkWin(masterBoard[0]);
            if (mbStatus != -1)
                gameEnd = true;
        }

        // if game is not end then check status of next quad in masterboard
        if (!gameEnd) {
            // if next quad already completed then set quad and position to -1
            if (masterBoard[0][pos - 1] != '.') {
                quad = -1;
                pos = -1;
            }
        }

    }

    // Game End. Display Board and Result
    displayBoard(board, pos, masterBoard);

    if (mbStatus == 1)
        cout << "Player " << player << " wins";
    else
        cout << "Game Draw";
}

void displayBoard(char board[9][9], int quad, char masterBoard[0][9]) {

    // Clear Screen
    system("cls");

    // Set default color to white
    SetConsoleTextAttribute(color, 7);

    cout << "\n\t    Ultimate Tic Tac Toe\n\t\t Karan Patel\n\n";

    // For each quad
    for (int q = 0; q < 9; q += 3) {
        // For each position
        for (int p = 0; p < 9; p += 3) {
            cout << "\t";
            //For the three quad rants in each row
            for (int t = 0; t < 3; t++) {

                for (int print = 0; print < 3; print++) {

                    //print different colors for each situation

                    //if this is the next quad that will be forced make it yellow
                    if (q == quad - 1) {
                        SetConsoleTextAttribute(color, 14);

                        //if the quad has already been won by X,O or draw then it make the whole quad a corresponding color
                    } else if (masterBoard[0][q] == 'X') {
                        SetConsoleTextAttribute(color, 1);
                    } else if (masterBoard[0][q] == 'O') {
                        SetConsoleTextAttribute(color, 2);
                    } else if (masterBoard[0][q] == '-') {
                        SetConsoleTextAttribute(color, 4);

                        //if the postion in the quad is X or 0 make it the corresponding color
                    } else if (board[q][p + print] == 'X') {
                        SetConsoleTextAttribute(color, 1);
                    } else if (board[q][p + print] == 'O') {
                        SetConsoleTextAttribute(color, 2);

                        //if none of those if statements are true make the postion white 
                    } else {
                        SetConsoleTextAttribute(color, 7);
                    }
                    //Print board 
                    cout << board[q][p + print] << "  ";
                }
                //change to next quadrant 
                q++;
            }
            //reset to the first quadrant in the row
            q -= 3;
            cout << "\n";
        }
        cout << "\n";
    }
    //set color back to white
    SetConsoleTextAttribute(color, 7);
}

bool checkValidMove(int quad, int pos, char board[9][9], char masterBoard[1][9]) {

    // if invalid quad or position 
    if (quad > 9 || quad < 1 || pos > 9 || pos < 1) {
        return false;
    }
    // if alreqy quad completed (win or draw)
    else if (masterBoard[0][quad - 1] == 'X' || masterBoard[0][quad - 1] == 'O' || masterBoard[0][quad - 1] == '-') {
        return false;
    }
    // if position in quad already marked by any player
    else if (board[quad - 1][pos - 1] == 'X' || board[quad - 1][pos - 1] == 'O') {
        return false;
    }

    // Here meand valid move. Return true.
    return true;

}

//Quad STATUS
//1  = Quad Win, O  = Quad Draw, -1 = Qaud in progress

int checkWin(char quadBoard[9]) {

    // check all combinations for quad win
    if (quadBoard[0] != '.' && quadBoard[0] == quadBoard[1] && quadBoard[1] == quadBoard[2])
        return 1;
    else if (quadBoard[3] != '.' && quadBoard[3] == quadBoard[4] && quadBoard[4] == quadBoard[5])
        return 1;
    else if (quadBoard[6] != '.' && quadBoard[6] == quadBoard[7] && quadBoard[7] == quadBoard[8])
        return 1;
    else if (quadBoard[0] != '.' && quadBoard[0] == quadBoard[3] && quadBoard[3] == quadBoard[6])
        return 1;
    else if (quadBoard[1] != '.' && quadBoard[1] == quadBoard[4] && quadBoard[4] == quadBoard[7])
        return 1;
    else if (quadBoard[2] != '.' && quadBoard[2] == quadBoard[5] && quadBoard[5] == quadBoard[8])
        return 1;
    else if (quadBoard[0] != '.' && quadBoard[0] == quadBoard[4] && quadBoard[4] == quadBoard[8])
        return 1;
    else if (quadBoard[2] != '.' && quadBoard[2] == quadBoard[4] && quadBoard[4] == quadBoard[6])
        return 1;
    // check condition for draw
    else if (quadBoard[0] != '.' && quadBoard[1] != '.' && quadBoard[2] != '.' &&
        quadBoard[3] != '.' && quadBoard[4] != '.' && quadBoard[5] != '.' &&
        quadBoard[6] != '.' && quadBoard[7] != '.' && quadBoard[8] != '.')
        return 0;
    // Quad still in progress
    else
        return -1;
}
