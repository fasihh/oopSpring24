#include <iostream>
#include <vector>

#define spcr "  "

using namespace std;

class ChessPiece {
public:
	string name, color;

	ChessPiece() : name("p"), color("w") {}
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
        for (int i = 0; i < 8; i++) board[1][i] = ChessPiece("P", "white");

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
		ChessPiece piece = board[source[1]-'0'][source[0]-'a'];

		if (piece.name == "n" || piece.name == "N") {
			bool vertical = (source[1]+2 == destination[1] || source[1]-2 == destination[1]) 
						&& (source[0]+1 == destination[0] || source[0]-1 == destination[0]);

			bool horizontal = (source[0]+2 == destination[0] || source[0]-2 == destination[0]) 
						&& (source[1]+1 == destination[1] || source[1]-1 == destination[1]);

			return vertical || horizontal && board[destination[1]-'0'][destination[0]-'a'].name == ".";
		} else if (piece.name == "p" || piece.name == "P") {
			return source[1] == destination[1] && (source[0]+1 == destination[0] || source[0]+2 == destination[0]);
		}

		return false;
	}
};

int main()
{
	ChessBoard board;
	board.display();
	cout << endl << endl;

	cout << board.movePiece("b8", "d7") << endl;
	return 0;
}