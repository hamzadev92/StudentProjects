#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"

class ChessBoard {
private:
    Piece* board[8][8] = {nullptr};
    enum Player{ WHITE, BLACK };
    Player currentPlayer;

public:
    ChessBoard();
    ~ChessBoard();
    void initializeBoard();
    void displayBoard();
    bool Turn(Piece* p);
    void switchh();
    void getMove(int &startX, int &startY, int &endX, int &endY);
    void play();
};

#endif
