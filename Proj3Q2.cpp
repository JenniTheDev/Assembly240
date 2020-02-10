#include <iostream>

using namespace std;

short score, avg, total=0;

void displayText() {
	cout << "Let's compute your score's average:  " << endl;
}

void readScore() {
	cout << "Enter your score (-1) to stop: ";
	cin >> score;
}

int main() {

	_asm {
		call displayText;  //function that asks for scores
		mov ax, total;  //total of scores
		mov bx, 0; //counter of scores
		
	WhileLoop:
		call readScore;  //asks user for one score

		cmp score, -1;  //compare score to -1
		je ExitLoop;   //if -1, exit loop

		add ax, score;   //add score to the running total
		inc bx;          //inc the counter
		jmp WhileLoop;     //jump to start of loop

	ExitLoop:
		//cwd;
		//idiv bx;   //divide the total by the count of scores

		mov avg, ax;
	}

	cout << "Average Score: " << avg << endl;
	
	return 0;

}
