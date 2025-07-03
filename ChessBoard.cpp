//#include "ChessBoard.h"
//#include <iostream>
//
//using namespace std;
//
//ChessBoard::ChessBoard() {
//    currentPlayer = WHITE;
//    initializeBoard();
//}
//
//void ChessBoard::initializeBoard() {
//    for (int i = 0; i < 8; ++i)
//        for (int j = 0; j < 8; ++j)
//            board[i][j] = nullptr;
//
//    board[7][0] = new Rook('R'); board[7][1] = new Knight('N');
//    board[7][2] = new Bishop('B'); board[7][3] = new Queen('Q');
//    board[7][4] = new King('K'); board[7][5] = new Bishop('B');
//    board[7][6] = new Knight('N'); board[7][7] = new Rook('R');
//    for (int j = 0; j < 8; ++j) board[6][j] = new Pawn('P');
//
//    board[0][0] = new Rook('r'); board[0][1] = new Knight('n');
//    board[0][2] = new Bishop('b'); board[0][3] = new Queen('q');
//    board[0][4] = new King('k'); board[0][5] = new Bishop('b');
//    board[0][6] = new Knight('n'); board[0][7] = new Rook('r');
//    for (int j = 0; j < 8; ++j) board[1][j] = new Pawn('p');
//}
//
//void ChessBoard::displayBoard() {
//	cout<<"\n\n"<<endl;
//	cout<<"\t\t\t\t      ***************************************"<<endl;
//	cout<<"\t\t\t\t   **********************************************"<<endl;
//	cout<<"\t\t\t\t*****************************************************"<<endl;
//	cout<<"\t\t\t     **********************QUEENS GAMBIT************************"<<endl;
//	cout<<"\n"<<endl;
//	cout<<"\t\t\t\t\t\t";
//    cout << "  a b c d e f g h" << endl;
//    for (int i = 0; i < 8; ++i) {
//        cout << "\t\t\t\t\t\t"<<8 - i << " ";
//        for (int j = 0; j < 8; ++j) {
//            cout << (board[i][j] ? board[i][j]->symbol : '-') << " ";
//        }
//        cout << 8 - i << endl;
//    }
//    cout<<"\t\t\t\t\t\t"<< "  a b c d e f g h" << endl;
//}
//
//bool ChessBoard::Turn(Piece* p) {
//    return p && ((currentPlayer == WHITE && isupper(p->symbol)) ||
//                 (currentPlayer == BLACK && islower(p->symbol)));
//}
//
//void ChessBoard::switchh() {
//    currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
//}
//
//void ChessBoard::getMove(int &startX, int &startY, int &endX, int &endY) {
//    string move;
//    cout<<"\t\t\t\t\t\t"<<(currentPlayer == WHITE ? "White's" : "Black's") << " turn" << endl;
//    cout<<"\t\t\t\t\t\t"<<"Enter move (e.g., e2 e4): ";
//    cin >> move;
//    startY = move[0] - 'a'; startX = 8 - (move[1] - '0');
//    cin >> move;
//    endY = move[0] - 'a'; endX = 8 - (move[1] - '0');
//}
//
//void ChessBoard::play() {
//    while (true) {
//        displayBoard();
//        int startX, startY, endX, endY;
//        getMove(startX, startY, endX, endY);
//
//        if (!Turn(board[startX][startY])) {
//            cout << "Invalid move: not your piece." << endl;
//            continue;
//        }
//
//        Piece* movingPiece = board[startX][startY];
//        if (movingPiece && movingPiece->isValidMove(startX, startY, endX, endY)) {
//            delete board[endX][endY];
//            board[endX][endY] = board[startX][startY];
//            board[startX][startY] = nullptr;
//            switchh();
//        } else {
//            cout << "Invalid move format." << endl;
//        }
//        
//    }
//}
//
//ChessBoard::~ChessBoard() {
//    for (int i = 0; i < 8; ++i)
//        for (int j = 0; j < 8; ++j)
//            delete board[i][j];
//}


#include "ChessBoard.h"
#include <iostream>

using namespace std;

ChessBoard::ChessBoard() {
    currentPlayer = WHITE;
    initializeBoard();
}

void ChessBoard::initializeBoard() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = nullptr;

    board[7][0] = new Rook('R'); board[7][1] = new Knight('N');
    board[7][2] = new Bishop('B'); board[7][3] = new Queen('Q');
    board[7][4] = new King('K'); board[7][5] = new Bishop('B');
    board[7][6] = new Knight('N'); board[7][7] = new Rook('R');
    for (int j = 0; j < 8; ++j) board[6][j] = new Pawn('P');

    board[0][0] = new Rook('r'); board[0][1] = new Knight('n');
    board[0][2] = new Bishop('b'); board[0][3] = new Queen('q');
    board[0][4] = new King('k'); board[0][5] = new Bishop('b');
    board[0][6] = new Knight('n'); board[0][7] = new Rook('r');
    for (int j = 0; j < 8; ++j) board[1][j] = new Pawn('p');
}

void ChessBoard::displayBoard() {
    cout<<"\n\n"<<endl;
    cout<<"\t\t\t\t      ***************************************"<<endl;
    cout<<"\t\t\t\t   **********************************************"<<endl;
    cout<<"\t\t\t\t*****************************************************"<<endl;
    cout<<"\t\t\t     **********************QUEENS GAMBIT************************"<<endl;
    cout<<"\n"<<endl;
    cout<<"\t\t\t\t\t\t";
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "\t\t\t\t\t\t"<<8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << (board[i][j] ? board[i][j]->symbol : '-') << " ";
        }
        cout << 8 - i << endl;
    }
    cout<<"\t\t\t\t\t\t"<< "  a b c d e f g h" << endl;
}

bool ChessBoard::Turn(Piece* p) {
    return p && ((currentPlayer == WHITE && isupper(p->symbol)) ||
                 (currentPlayer == BLACK && islower(p->symbol)));
}

void ChessBoard::switchh() {
    currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
}

void ChessBoard::getMove(int &startX, int &startY, int &endX, int &endY) {
    string move;
    cout<<"\t\t\t\t\t\t"<<(currentPlayer == WHITE ? "White's" : "Black's") << " turn" << endl;
    cout<<"\t\t\t\t\t\t"<<"Enter move (e.g., e2 e4): ";
    cin >> move;
    startY = move[0] - 'a'; startX = 8 - (move[1] - '0');
    cin >> move;
    endY = move[0] - 'a'; endX = 8 - (move[1] - '0');
}

void ChessBoard::play() {
    while (true) {
        displayBoard();
        int startX, startY, endX, endY;
        getMove(startX, startY, endX, endY);

        if (!Turn(board[startX][startY])) {
            cout << "Invalid move: Not your piece." << endl;
            continue;
        }


        if (board[endX][endY] != nullptr &&
            ((currentPlayer == WHITE && isupper(board[endX][endY]->symbol)) ||
             (currentPlayer == BLACK && islower(board[endX][endY]->symbol)))) {
            cout << "Illegal capture: You are not allowed to capture your own piece!" << endl;
            continue;
        }

        Piece* movingPiece = board[startX][startY];
        if (movingPiece && movingPiece->isValidMove(startX, startY, endX, endY)) {
            delete board[endX][endY]; // Capture opponent piece
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = nullptr;
            switchh();
        } else {
            cout << "Invalid move format." << endl;
        }
    }
}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            delete board[i][j];
}
