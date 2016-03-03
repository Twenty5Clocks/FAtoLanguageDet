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
/*				c/any other letter always goes to the non-inclusion state
	a	b	c
0	1	3	4
1	1	2	4
2	4	4	4
3	4	3	4
4	4	4	4
*/
//------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//table of the language
	//the starting state is 0
	int table[5][3] = { {1,3,4}, {1,2,4}, {4,4,4}, {4,3,4}, {4,4,4} };
	//w will hold the string of the individual words to check
	string w;
	fstream inp;
	//open the file that includes the strings to check
	inp.open("data.txt", ios::in);
	//get the first word in the file
	getline(inp, w);
	//loop through the words in the text file
	while (!inp.eof())
	{
		//initialize values		
		int i = 0, col, state = 0;
		//will loop through the letters in the word until it encounters a '$'
		while (w[i] != '$')
		{
			//print the word letter by letter to prevent printing the '$' at the end
			cout << w[i];
			switch (w[i])
			{
			case 'a':col = 0; break;
			case 'b':col = 1; break;
			default:col = 2;		//is used for any letter not in the lanuage
			}
			//move to the new state
			state = table[state][col];
			i++;
		}
		//output the result to the user
		if (state == 4)
			cout << " is not accepted\n";
		else
			cout << " is accepted\n";
		//get the next word
		getline(inp, w);
	}
	//close the file stream
	inp.close();
	//terminate the program
	system("pause");
	return 0;
}
/*-----------------output---------------------
aaab is accepted
bcbbca is not accepted
Press any key to continue . . .
---------------------------------------------*/