#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream myfile;
	myfile.open("text.txt", ios::in);
	if (!myfile)
	{
		cout << "No such file";
	}
	else
	{
		char ch;
		string keyword = "";
		while (!myfile.eof())
		{
			myfile.get(ch);
			if (isalpha(ch)) {
				keyword += ch;
				while (isalpha(ch)) {
					myfile.get(ch);
					keyword += ch;
				}
				if (keyword == "int " || keyword == "using ") {
					cout << "Keyword" << endl;
					keyword = "";
				}
				else {
				 cout << "Variable" << endl;
				 keyword = "";
				}
			}
			if (isdigit(ch)) {
					while (isdigit(ch)) {
						myfile.get(ch);
					}
					cout << "Num" << endl;
			}
			else if (ch == '#') {
				cout << "Hash" << endl;
			}
			else if (ch == '/')
			{
				myfile.get(ch);
				if (ch == '/')
				{
					cout << "Comment" << endl;
				}
				else if (ch == '=')
				{
					cout << "FarwardSlashEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "FarwardSlash" << endl;
				}

			}
			else if (ch == '%')
			{
				myfile.get(ch);
				if (ch == '=')
				{
					cout << "PercentEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "Percentage" << endl;
				}

			}
			else if (ch == '|')
			{
				myfile.get(ch);
				if (ch == '=')
				{
					cout << "PipeEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "Pipe" << endl;
				}

			}

			else if (ch == '&')
			{
				myfile.get(ch);
				if (ch == '=')
				{
					cout << "AndEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "And" << endl;
				}

			}
			else if (ch == '^')
			{
				myfile.get(ch);
				if (ch == '=')
				{
					cout << "PowerEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "Power" << endl;
				}

			}

			else if (ch == '*')
			{
				myfile.get(ch);
				if (ch == '=')
				{
					cout << "MultipyEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "Multiply" << endl;
				}
			}
			else if (ch == '-')
			{
				myfile.get(ch);
				if (ch == '-')
				{
					cout << "Decrement" << endl;
				}
				else if (ch == '=')
				{
					cout << "MinusEqual" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "Minus" << endl;
				}
			}

			else if (ch == '+')
			{
				myfile.get(ch);
					if (ch == '+')
					{
						cout << "Increment" << endl;
					}
					else if (ch == '=')
					{
						cout << "PlusEqual" << endl;
					}
					else {
						myfile.putback(ch);
						cout << "Plus" << endl;
					}
				
			}
			else if (ch == '=')
			{
			cout << "Equal" << endl;
				//myfile.get(ch);
				//if (ch == ' ') {
				//	cout << "Space" << endl;
				//}
				//else {
				//	myfile.putback(ch);
				//	cout << "Equal" << endl;
				//}
			}
			else if (ch == ';')
			{
				cout << "Semicolan" << endl;
			}
			else if (ch == '(')
			{
				cout << "Farward Bracket" << endl;
			}
			else if (ch == ')')
			{
				cout << "Backward bracket" << endl;
			}
			else if (ch == '{')
			{
			cout << "Farward Curly Bracket" << endl;
			}
			else if (ch == '}')
			{
			cout << "Backward Curly bracket" << endl;
			}
			else if (ch == '>')
			{
			myfile.get(ch);
			if (ch == '>') {
				myfile.get(ch);
				if (ch == '=') {
					cout << ">>=" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "cin" << endl;
				}
			 }			
			else {
				myfile.putback(ch);
				cout << "Grater" << endl;
			}
			}
			else if (ch == '<')
			{
			myfile.get(ch);
			if (ch == '<') {
				myfile.get(ch);
				if (ch == '=') {
					cout << "<<=" << endl;
				}
				else {
					myfile.putback(ch);
					cout << "cout" << endl;
				}
			}
			else {
				myfile.putback(ch);
				cout << "less" << endl;

			}
			}
		}
	}
	myfile.close();
}
