#include <fstream>
#include <iostream>
using namespace std;
int main() {
  fstream myfile;
  myfile.open("text.txt", ios::in);
  if (!myfile) {
    cout << "No such file";
  } else {
    char ch;
    string keyword = "";
    string digit = "";
    while (!myfile.eof()) {
      myfile.get(ch);
      if (myfile.eof()) {
        break;
      } else if (isalpha(ch)) {
        keyword += ch;
        while (true) {
          myfile.get(ch);
          if (isalpha(ch)) {
            keyword += ch;
          } else {
            myfile.putback(ch);
            break;
          }
        }
        if (keyword == "int" || keyword == "using" || keyword == "auto" ||
            keyword == "double" || keyword == "int" || keyword == "struct" ||
            keyword == "break" || keyword == "else" || keyword == "long" ||
            keyword == "switch" || keyword == "case" || keyword == "enum" ||
            keyword == "register" || keyword == "typedef" ||
            keyword == "char" || keyword == "extern" || keyword == "return" ||
            keyword == "union" || keyword == "return" ||
            keyword == "continue" || keyword == "for" || keyword == "signed" ||
            keyword == "void" || keyword == "do" || keyword == "if" ||
            keyword == "while" || keyword == "default" || keyword == "goto" ||
            keyword == "sizeof" || keyword == "volatile" ||
            keyword == "const" || keyword == "float" || keyword == "short" ||
            keyword == "unsigned" || keyword == "Public" ||
            keyword == "Private" || keyword == "namespace" ||
            keyword == "include" || keyword == "iostream" || keyword == "std" ||
            keyword == "main" || keyword == "fstream"

        ) {
          cout << "Keyword" << endl;
          keyword = "";
        } else {
          cout << "Variable" << endl;
          keyword = "";
        }
      } else if (isdigit(ch)) {
        digit += ch;
        while (true) {
          myfile.get(ch);
          if (isdigit(ch)) {
            digit += ch;
          } else {
            myfile.putback(ch);
            break;
          }
        }
        cout << "Number" << endl;
      } else if (ch == '#') {
        cout << "Hash" << endl;
      } else if (ch == '!') {
        cout << "Not" << endl;
      } else if (ch == '.') {
        cout << "Dot" << endl;
      } else if (ch == '"') {
        cout << "Double Qoute" << endl;
      } else if (ch == '/') {
        myfile.get(ch);
        if (ch == '/') {
          cout << "Comment" << endl;
        } else if (ch == '=') {
          cout << "FarwardSlashEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "FarwardSlash" << endl;
        }

      } else if (ch == '%') {
        myfile.get(ch);
        if (ch == '=') {
          cout << "PercentEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "Percentage" << endl;
        }

      } else if (ch == '|') {
        myfile.get(ch);
        if (ch == '=') {
          cout << "PipeEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "Pipe" << endl;
        }

      }

      else if (ch == '&') {
        myfile.get(ch);
        if (ch == '=') {
          cout << "AndEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "And" << endl;
        }

      } else if (ch == '^') {
        myfile.get(ch);
        if (ch == '=') {
          cout << "PowerEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "Power" << endl;
        }

      }

      else if (ch == '*') {
        myfile.get(ch);
        if (ch == '=') {
          cout << "MultipyEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "Multiply" << endl;
        }
      } else if (ch == '-') {
        myfile.get(ch);
        if (ch == '-') {
          cout << "Decrement" << endl;
        } else if (ch == '=') {
          cout << "MinusEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "Minus" << endl;
        }
      }

      else if (ch == '+') {
        myfile.get(ch);
        if (ch == '+') {
          cout << "Increment" << endl;
        } else if (ch == '=') {
          cout << "PlusEqual" << endl;
        } else {
          myfile.putback(ch);
          cout << "Plus" << endl;
        }

      } else if (ch == ':') {
        myfile.get(ch);
        if (ch == ':') {
          cout << "Double Qoulan" << endl;
        } else {
          myfile.putback(ch);
          cout << "Colan" << endl;
        }
      } else if (ch == ' ') {
        cout << "Space" << endl;
      } else if (ch == '\n') {
        cout << "NewLine" << endl;
      } else if (ch == '\t') {
        cout << "Tab" << endl;
      } else if (ch == '=') {
        cout << "Equal" << endl;
      } else if (ch == ';') {
        cout << "Semicolan" << endl;
      } else if (ch == '?') {
        cout << "Question Mark" << endl;
      } else if (ch == '[') {
        cout << "Farward Squar Bracket" << endl;
      } else if (ch == ']') {
        cout << "Backward Squar Bracket" << endl;
      } else if (ch == ',') {
        cout << "Qomma" << endl;
      } else if (ch == '~') {
        cout << "Tilda" << endl;
      } else if (ch == '\\') {
        cout << "Backward Curly Bracket" << endl;
      } else if (ch == '_') {
        cout << "Under Score" << endl;
      } else if (ch == '$') {
        cout << "Dollar" << endl;
      } else if (ch == '\'') {
        cout << "Single Qoute" << endl;
      } else if (ch == '(') {
        cout << "Farward Small Bracket" << endl;
      } else if (ch == ')') {
        cout << "Backward Small bracket" << endl;
      } else if (ch == '{') {
        cout << "Farward Curly Bracket" << endl;
      } else if (ch == '}') {
        cout << "Backward Curly bracket" << endl;
      } else if (ch == '>') {
        myfile.get(ch);
        if (ch == '>') {
          myfile.get(ch);
          if (ch == '=') {
            cout << ">>=" << endl;
          } else {
            myfile.putback(ch);
            cout << "cin" << endl;
          }
        } else {
          myfile.putback(ch);
          cout << "Grater" << endl;
        }
      } else if (ch == '<') {
        myfile.get(ch);
        if (ch == '<') {
          myfile.get(ch);
          if (ch == '=') {
            cout << "<<=" << endl;
          } else {
            myfile.putback(ch);
            cout << "cout" << endl;
          }
        } else {
          myfile.putback(ch);
          cout << "less" << endl;
        }
      }
    }
  }
  myfile.close();
}
