#pragma once

class Spot {

private:
    //Here x and y represent the cooridnates of the piece.
    Piece piece;
    int x;
    int y;

public:
    //Constructor
    Spot(int x, int y, Piece piece)
    {
        this->setPiece(piece);
        this->setX(x);
        this->setY(y);
    }

    Piece getPiece()
    {
        return this->piece;
    }

    void setPiece(Piece p)
    {
        this->piece = p;
    }

    int getX()
    {
        return this->x;
    }

    void setX(int x)
    {
        this->x = x;
    }

    int getY()
    {
        return this->y;
    }

    void setY(int y)
    {
        this->y = y;
    }
};

class Pawn : public Piece {

private:
    //This variable stores if a pawn has made even a single move or not.
    //Because they can move two places on their first move.
    bool firstMove = false;

public:
    Pawn(bool white) : Piece(white) {

    }

    bool isFirstMove() {
        return firstMove;
    }

    bool canMove(Board board, Spot start, Spot end) {
        if (end.getPiece().isWhite() == this->isWhite()) {
            return false;
        }
        //More logic to be added.


    }

};
