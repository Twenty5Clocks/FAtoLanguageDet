//------------------------------------------------------------------------------------------
//          Name		Jeremy Driesler & Candelario "Daniel" Eguia
//          Course		CMPS-455
//          Project		No.3
//			Part		No. 3
//          Due date	Mar. 4, 2015
//          Professor	Ray Ahmadnia
//
// This program displays:
//       Check if words in a file are included in the language L = aa*b + bb*
//------------------------------------------------------------------------------------------
/*
Given L write a program to determine whether the word w is accepted or rejected by L.
L = a*b*+c*
Create a complete FA then find table
a	b	c
0	3	4	1
1	2	2	1
2	2	2	2
3	3	4	2
4	2	4	2
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	//Array containg table:
	int Table[5][3] = { { 3,4,1 },{ 2,2,1 },{ 2,2,2 },{ 3,4,2 },{ 2,4,2 } };

	string w = "aabbb";
	int i = 0, col, state = 0;
	while (i < w.length()) {
		switch (w[i]) {
		case 'a':
			col = 0; break;
		case 'b':
			col = 1; break;
		case 'c':
			col = 2; break;
		}
		state = Table[state][col];

		i++;
	}
	if (state == 2) cout << w << "is rejected";
	else cout << w << "is accepted";
	system("pause");
	return 0;
}
/*-----------------output---------------------
aaab is accepted
bcbbca is not accepted
Press any key to continue . . .
---------------------------------------------*/