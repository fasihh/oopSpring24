#include <iostream>
#include <vector>
#include <cmath>

#define spcr "  "

using namespace std;

class ChessPiece {
public:
	string name, color;

	// default constructor for white pawns 
	ChessPiece() : name("P"), color("white") {}
	ChessPiece(string name, string color) : name(name), color(color) {}

	string getColor() { return color; }
	string getName() { return name; }

	void setColor(string color) { this->color = color; }
	void setName(string name) { this->name = name; }
};

class ChessBoard {
public:
	vector<vector<ChessPiece>> board;

	ChessBoard() {
		// board size defining
		board.resize(8, vector<ChessPiece>(8));

		// init white pieces
        board[0][0] = ChessPiece("R", "white");
        board[0][1] = ChessPiece("N", "white");
        board[0][2] = ChessPiece("B", "white");
        board[0][3] = ChessPiece("K", "white");
        board[0][4] = ChessPiece("Q", "white");
        board[0][5] = ChessPiece("B", "white");
        board[0][6] = ChessPiece("N", "white");
        board[0][7] = ChessPiece("R", "white");

        // init white pawns
        for (int i = 0; i < 8; i++) board[1][i] = ChessPiece();

        // init black pieces
        board[7][0] = ChessPiece("r", "black");
        board[7][1] = ChessPiece("n", "black");
        board[7][2] = ChessPiece("b", "black");
        board[7][3] = ChessPiece("k", "black");
        board[7][4] = ChessPiece("q", "black");
        board[7][5] = ChessPiece("b", "black");
        board[7][6] = ChessPiece("n", "black");
        board[7][7] = ChessPiece("r", "black");

        // init black pawns
        for (int i = 0; i < 8; i++) board[6][i] = ChessPiece("p", "black");

        // empty slots
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = ChessPiece(".", "none");
            }
        }
	}

	void display() {
		int c = 8;
		// print the board header
		cout << spcr << " ";
		for (char h = 'a'; h < 'i'; h++) cout << h << spcr;
		cout << endl;
		// print pieces
		for (vector<ChessPiece> row : board) {
			// row num - start
			cout << c << spcr;
			for (ChessPiece piece : row) cout << piece.name << spcr;
			// row num - end
			cout << c--;
			cout << endl;
		}
		// print the board footer
		cout << spcr << " ";
		for (char h = 'a'; h < 'i'; h++) cout << h << spcr;
	}

	bool movePiece(string source, string destination) {
		// getting all positions from string
		int dest_r = 7-(destination[1]-'1'), dest_c = destination[0]-'a', src_r = 7-(source[1]-'1'), src_c = source[0]-'a';
		string src_name = board[src_r][src_c].name, dest_name = board[dest_r][dest_c].name; // chess piece name
		cout << "validating move for '" << src_name << "' from " << source << " to " << destination << ":" << endl;

		if (src_name == "n" || src_name == "N") {
			bool vertical = abs(dest_r - src_r) == 2 && abs(dest_c - src_c) == 1;
			bool horizontal = abs(dest_r - src_r) == 1 && abs(dest_c - src_c) == 2;

			// check for any of the cases and also make sure dest is empty
			return vertical || horizontal && dest_name == ".";
		} else if (src_name == "p" || src_name == "P") {
			return src_c == dest_c && // checking if same column
				// checking  upward  movement and obstacle
				((src_r - dest_r == 1 || src_r - dest_r == 2) && board[src_r-1][src_c].name == ".") || 
				// checking downward movement and onstacle
				((dest_r - src_r == 1 || dest_r - src_r == 2) && board[src_r+1][src_c].name == ".");
		}

		return false;
	}
};

int main()
{
	ChessBoard board;
	board.display();
	cout << endl << endl;

	// invalid move - knight
	cout << (board.movePiece("b8", "c7") ? "valid" : "not valid") << endl << endl;
	// valid move - knight
	cout << (board.movePiece("b8", "c6") ? "valid" : "not valid") << endl << endl;

	// invalid move - pawn
	cout << (board.movePiece("b7", "b4") ? "valid" : "not valid") << endl << endl;
	// valid move - pawn
	cout << (board.movePiece("b7", "b5") ? "valid" : "not valid") << endl << endl;

	return 0;
}