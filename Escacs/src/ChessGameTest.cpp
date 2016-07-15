#include <iostream>
#include <string>
#include "ChessGame.h"
using namespace std;

int main() {
	ChessGame chessGame;
	cout << chessGame << endl;
	int ro,co,rd,cd;
	while(!chessGame.isCheckmate()) {
		cin>>ro>>co>>rd>>cd;
		chessGame.move(ro,co,rd,cd);
		cout << chessGame << endl;
	}
	cout << "Check Mate! Player " << chessGame.currentPlayer() <<  " wins!" << endl;
}
