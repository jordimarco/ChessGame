#include <iostream>
#include <string>
#include "ChessGame.h"
using namespace std;

int main() {
	ChessGame chessGame;
	chessGame.play();
	int ro,co,rd,cd;
	while(cin>>ro>>co>>rd>>cd) {
		chessGame.move(ro,co,rd,cd);
		chessGame.play();
	}
}
