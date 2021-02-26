#pragma once
#include<cstdlib>
class Spot {

private:
    //Here x and y represent the cooridnates of the piece.
    Piece piece;
    int x;
    int y;
public:
    //Constructor
    Spot(int x, int y, Piece p): piece(p)
    {
        this->setPiece(p);
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
        int start_x = start.getX();
        int start_y = start.getY();
        int end_x = end.getX();
        int end_y = end.getY();
        int abs_diffof_x = abs(end_x - start_x);
        if(abs_diffof_x > 1) {
            return false;
        }
        if (start_y + 1 != end_y) {
            return false;
        }
        //This needs to be checked.
        if (end.getPiece() != NULL && abs_diffof_x == 0) {
            return false;
        }
        return true;
    }

};
class Piece {
private:
	bool killed = false;
	bool white = false;
public:
	Piece(bool white) {
		this->setWhite(white);
	}
	bool isWhite() {
		return this->white;
	}
	void setWhite(bool white) {
		this->white = white;
	}
	bool isKilled() {
		return this->killed;
	}
	void setKilled(bool killed) {
		this->killed = killed;
	}
	//virtual bool canMove(Borad board, Spot start, Spot end) = 0;
};


class King : public Piece {
private:
	bool castlingDone = false;
	bool isValidCastling(Board board, Spot start, Spot end) {
		if (this->isCastlingDone()) {
			return false;
		}
		//logic to return true of false here
	}
public:
	King(bool white) : Piece(white) {

	}
	bool isCastlingDone() {
		return castlingDone;
	}
	void setCastlingDone(bool castlingDone) {
		this->castlingDone = castlingDone;
	}
	bool canMove(Board board, Spot start, Spot end) {
		if (end.getPiece().isWhite() == this->isWhite()) {
			return false;
		}
		int x = abs(start.getX() - end.getX());
		int y = abs(start.getY() - end.getY());
		if (x + y == 1) {
			//implement logic to check if king not attacked otherwise game over
			return true;
		}
		return this->isValidCastling(board, start, end);
	}
	bool isCastlingMove(Spot start, Spot end) {
		//Check if value of start and end are valid
	}

};

class Knight : public Piece {
public:
	Knight(bool white) : Piece(white) {

	}
	bool canMove(Board board, Spot start, Spot end) {
		if (end.getPiece().isWhite() == this->isWhite()) {
			return false;
		}
		int x = abs(start.getX() - end.getX());
		int y = abs(start.getY() - end.getY());
		return x * y == 2;
	}
};

class Bishop : public Piece {
public:
    Bishop(bool white) : Piece(white) {

    }
    bool canMove(Board board, Spot start, Spot end) {
        if (end.getPiece().isWhite() == this->isWhite()) {
            return false;
        }
        int x = abs(start.getX() - end.getX());
        int y = abs(start.getY() - end.getY());
        if (x == y) {
            // check if there is a piece blocking the way
        }
    }

};

class Rook :public Piece {

};