#pragma once
#include<cstdlib>
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
		if (end.getPiece.isWhite() == this->isWhite()) {
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