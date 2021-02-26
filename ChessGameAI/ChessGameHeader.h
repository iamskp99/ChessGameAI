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
        int start_x = start.getX();
        int start_y = start.getY();
        int end_x = end.getX();
        int end_y = end.getY();
        int abs_diffof_x = abs(end_x - start_x);
        if(abs_diffof_x > 1) {
            return false;
        }
          
        if (this->isFirstMove() == true) {
            if (abs_diffof_x == 0) {
                //We will have to define isEmpty() for the spot.
                if (end.isEmpty() == false) {
                    return false;
                }
                else {
                    if (this->isWhite() == true) {
                        if (start_y + 1 != end_y || start_y + 2 != end_y) {
                            return false;
                        }
                    }
                    else {
                        if (start_y - 1 != end_y || start_y - 2 != end_y) {
                            return false;
                        }
                    }
                }
            }
            else {
                //Now for the Kill move.
                if (end.isEmpty() == true) {
                    return false;
                }
                else {
                    if (this->isWhite() == true) {
                        if (start_y + 1 != end_y || end.getPiece().isWhite() == true) {
                            return false;
                        }
                    }
                    else {
                        if (start_y - 1 != end_y || end.getPiece().isWhite() == false) {
                            return false;
                        }
                    }
                }
            }
        }
        else {
            if (abs_diffof_x == 0) {
                //We will have to define isEmpty() for the spot.
                if (end.isEmpty() == false) {
                    return false;
                }
                else {
                    if (this->isWhite() == true) {
                        if (start_y + 1 != end_y) {
                            return false;
                        }
                    }
                    else {
                        if (start_y - 1 != end_y) {
                            return false;
                        }
                    }
                }
            }
            else {
                //Now for the Kill move.
                if (end.isEmpty() == true) {
                    return false;
                }
                else {
                    if (this->isWhite() == true) {
                        if (start_y + 1 != end_y || end.getPiece().isWhite() == true) {
                            return false;
                        }
                    }
                    else {
                        if (start_y - 1 != end_y || end.getPiece().isWhite() == false) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

class Rook :public Piece {
private:
    //Will have to check what to store in private.

public:
    Rook(bool white) : Rook(white) {

    }
    bool canMove(Board board, Spot start, Spot end) {
        if (end.getPiece().isWhite() == this->isWhite()) {
            return false;
        }
        int start_x = start.getX();
        int start_y = start.getY();
        int end_x = end.getX();
        int end_y = end.getY();
        if (start_x != end_x && start_y != end_y) {
            return false;
        }
        //Now to check if there is a piece blocking our way or not.
        int flag = 0;
        if (start_x != end_x) {
            if (end_y > start_y) {
                int i = start_y;
                while (i < end_y && flag == 0) {
                    //We will have to define a getBox() method such that we can check if there is a piece or not on that spot.
                    if (getBox(start_x, i).isEmpty() == false) {
                        flag = 1;
                    }
                    i = i + 1;
                }
                if (flag == 1) {
                    return false;
                }
            }
            else {
                int i = start_y;
                while (i > end_y && flag == 0) {
                    //We will have to define a getBox() method such that we can check if there is a piece or not on that spot.
                    if (getBox(start_x, i).isEmpty() == false) {
                        flag = 1;
                    }
                    i = i - 1;
                }
                if (flag == 1) {
                    return false;
                }
            }
        }
        else {
            if (end_x > start_x) {
                int i = start_x;
                while (i < end_x && flag == 0) {
                    //We will have to define a getBox() method such that we can check if there is a piece or not on that spot.
                    if (getBox(i, start_y).isEmpty() == false) {
                        flag = 1;
                    }
                    i = i + 1;
                }
                if (flag == 1) {
                    return false;
                }
            }
            else {
                int i = start_x;
                while (i > end_x && flag == 0) {
                    //We will have to define a getBox() method such that we can check if there is a piece or not on that spot.
                    if (getBox(i, start_y).isEmpty() == false) {
                        flag = 1;
                    }
                    i = i - 1;
                }
                if (flag == 1) {
                    return false;
                }
            }
        }
        return true;
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
        int start_x = start.getX();
        int start_y = start.getY();
        int end_x = end.getX();
        int end_y = end.getY();
        int x = abs(start.getX() - end.getX());
        int y = abs(start.getY() - end.getY());
        if (x != y) {
            return false;
        }
        else{
            // check if there is a piece blocking the way
            int flag = 0;
            if (start_x < end_x) {
                if (start_y < end_y) {
                    int i_x = start_x;
                    int i_y = start_y;
                    while (i_x < end_x) {
                        if (getBox(i_x, i_y).isEmpty() == false) {
                            flag = 1;
                        }
                        i_x += 1;
                        i_y += 1;
                    }
                }
                else {
                   //To be added. 
                }
            }
            else {
                //To be added.
            }
            if (flag == 1) {
                return false;
            }
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
