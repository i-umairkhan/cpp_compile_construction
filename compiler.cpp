#include <fstream>
#include <iostream>
using namespace std;

fstream myfile;
char ch;

enum TokenType {
  KeywordToken,
  VariableToken,
  DigitToken,
  SymbaolTokan,
};

struct Token {
  TokenType type;
  string val;
};
Token Lexical() {
  Token t;
  string keyword = "";
  string digit = "";
  if (isalpha(ch)) {
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
        keyword == "register" || keyword == "typedef" || keyword == "char" ||
        keyword == "extern" || keyword == "return" || keyword == "union" ||
        keyword == "return" || keyword == "continue" || keyword == "for" ||
        keyword == "signed" || keyword == "void" || keyword == "do" ||
        keyword == "if" || keyword == "while" || keyword == "default" ||
        keyword == "goto" || keyword == "sizeof" || keyword == "volatile" ||
        keyword == "const" || keyword == "float" || keyword == "short" ||
        keyword == "unsigned" || keyword == "Public" || keyword == "Private" ||
        keyword == "namespace" || keyword == "include" ||
        keyword == "iostream" || keyword == "std" || keyword == "main" ||
        keyword == "fstream"

    ) {
      // cout << "Keyword" << endl;
      t.type = KeywordToken;
      t.val = keyword;
      return t;
      keyword = "";
    } else {
      // cout << "Variable" << endl;
      t.type = VariableToken;
      t.val = keyword;
      return t;
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
    // cout << "Number" << endl;
    t.type = DigitToken;
    t.val = digit;
    return t;

  } else if (ch == '#') {
    // cout << "Hash" << endl;
    t.type = SymbaolTokan;
    t.val = "#";
    return t;

  } else if (ch == '!') {
    // cout << "Not" << endl;
    t.type = SymbaolTokan;
    t.val = "!";
    return t;
  } else if (ch == '.') {
    // cout << "Dot" << endl;
    t.type = SymbaolTokan;
    t.val = ".";
    return t;
  } else if (ch == '"') {
    // cout << "Double Qoute" << endl;
    t.type = SymbaolTokan;
    t.val = "\"";
    return t;
  } else if (ch == '/') {
    myfile.get(ch);
    if (ch == '/') {
      // cout << "Comment" << endl;
      t.type = SymbaolTokan;
      t.val = "//";
      return t;
    } else if (ch == '=') {
      // cout << "FarwardSlashEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "/=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "FarwardSlash" << endl;
      t.type = VariableToken;
      t.val = "/";
      return t;
    }

  } else if (ch == '%') {
    myfile.get(ch);
    if (ch == '=') {
      // cout << "PercentEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "%=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Percentage" << endl;
      t.type = SymbaolTokan;
      t.val = "%";
      return t;
    }

  } else if (ch == '|') {
    myfile.get(ch);
    if (ch == '=') {
      // cout << "PipeEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "|=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Pipe" << endl;
      t.type = SymbaolTokan;
      t.val = "|";
      return t;
    }

  }

  else if (ch == '&') {
    myfile.get(ch);
    if (ch == '=') {
      // cout << "AndEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "&=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "And" << endl;
      t.type = SymbaolTokan;
      t.val = "&";
      return t;
    }

  } else if (ch == '^') {
    myfile.get(ch);
    if (ch == '=') {
      // cout << "PowerEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "^=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Power" << endl;
      t.type = SymbaolTokan;
      t.val = "^";
      return t;
    }

  }

  else if (ch == '*') {
    myfile.get(ch);
    if (ch == '=') {
      // cout << "MultipyEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "*=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Multiply" << endl;
      t.type = SymbaolTokan;
      t.val = "*";
      return t;
    }
  } else if (ch == '-') {
    myfile.get(ch);
    if (ch == '-') {
      // cout << "Decrement" << endl;
      t.type = SymbaolTokan;
      t.val = "--";
      return t;
    } else if (ch == '=') {
      // cout << "MinusEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "-=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Minus" << endl;
      t.type = SymbaolTokan;
      t.val = "-";
      return t;
    }
  }

  else if (ch == '+') {
    myfile.get(ch);
    if (ch == '+') {
      // cout << "Increment" << endl;
      t.type = SymbaolTokan;
      t.val = "++";
      return t;
    } else if (ch == '=') {
      // cout << "PlusEqual" << endl;
      t.type = SymbaolTokan;
      t.val = "+=";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Plus" << endl;
      t.type = SymbaolTokan;
      t.val = "+";
      return t;
    }

  } else if (ch == ':') {
    myfile.get(ch);
    if (ch == ':') {
      // cout << "DoubleQoulan" << endl;
      t.type = SymbaolTokan;
      t.val = "::";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Colan" << endl;
      t.type = SymbaolTokan;
      t.val = ":";
      return t;
    }
  } else if (ch == '=') {
    myfile.get(ch);
    if (ch == '=') {
      // cout << "Comparison" << endl;
      t.type = SymbaolTokan;
      t.val = "==";
      return t;
    } else {
      myfile.putback(ch);
      // cout << "Equal" << endl;
      t.type = SymbaolTokan;
      t.val = "=";
      return t;
    }
  }

  else if (ch == ' ') {
    // cout << "Space" << endl;
    t.type = SymbaolTokan;
    t.val = " ";
    return t;
  } else if (ch == '\n') {
    // cout << "NewLine" << endl;
    t.type = SymbaolTokan;
    t.val = "\n";
    return t;
  } else if (ch == '\t') {
    // cout << "Tab" << endl;
    t.type = SymbaolTokan;
    t.val = "\t";
    return t;
  } else if (ch == ';') {
    // cout << "Semicolan" << endl;
    t.type = SymbaolTokan;
    t.val = ";";
    return t;
  } else if (ch == '?') {
    // cout << "QuestionMark" << endl;
    t.type = SymbaolTokan;
    t.val = "?";
    return t;
  } else if (ch == '[') {
    // cout << "FarwardSquarBracket" << endl;
    t.type = SymbaolTokan;
    t.val = "[";
    return t;
  } else if (ch == ']') {
    // cout << "BackwardSquarBracket" << endl;
    t.type = SymbaolTokan;
    t.val = "]";
    return t;
  } else if (ch == ',') {
    // cout << "Qomma" << endl;
    t.type = SymbaolTokan;
    t.val = ",";
    return t;
  } else if (ch == '~') {
    // cout << "Tilda" << endl;
    t.type = SymbaolTokan;
    t.val = "~";
    return t;
  } else if (ch == '\\') {
    // cout << "BackSlash" << endl;
    t.type = SymbaolTokan;
    t.val = "\\";
    return t;
  } else if (ch == '_') {
    // cout << "UnderScore" << endl;
    t.type = SymbaolTokan;
    t.val = "_";
    return t;
  } else if (ch == '$') {
    // cout << "Dollar" << endl;
    t.type = SymbaolTokan;
    t.val = "$";
    return t;
  } else if (ch == '\'') {
    // cout << "SingleQoute" << endl;
    t.type = SymbaolTokan;
    t.val = "\'";
    return t;
  } else if (ch == '(') {
    // cout << "FarwardSmallBracket" << endl;
    t.type = SymbaolTokan;
    t.val = "(";
    return t;
  } else if (ch == ')') {
    // cout << "BackwardSmallBracket" << endl;
    t.type = SymbaolTokan;
    t.val = ")";
    return t;
  } else if (ch == '{') {
    // cout << "FarwardCurlyBracket" << endl;
    t.type = SymbaolTokan;
    t.val = "{";
    return t;
  } else if (ch == '}') {
    // cout << "BackwardCurlyBracket" << endl;
    t.type = SymbaolTokan;
    t.val = "}";
    return t;
  } else if (ch == '>') {
    myfile.get(ch);
    if (ch == '>') {
      myfile.get(ch);
      if (ch == '=') {
        // cout << ">>=" << endl;
        t.type = SymbaolTokan;
        t.val = ">>=";
        return t;
      } else {
        myfile.putback(ch);
        // cout << "Cin" << endl;
        t.type = SymbaolTokan;
        t.val = ">>";
        return t;
      }
    } else {
      myfile.putback(ch);
      // cout << "Grater" << endl;
      t.type = SymbaolTokan;
      t.val = ">";
      return t;
    }
  } else if (ch == '<') {
    myfile.get(ch);
    if (ch == '<') {
      myfile.get(ch);
      if (ch == '=') {
        // cout << "<<=" << endl;
        t.type = SymbaolTokan;
        t.val = "<<=";
        return t;
      } else {
        myfile.putback(ch);
        // cout << "Cout" << endl;
        t.type = SymbaolTokan;
        t.val = "<<";
        return t;
      }
    } else {
      myfile.putback(ch);
      // cout << "less" << endl;
      t.type = SymbaolTokan;
      t.val = "<";
      return t;
    }
  }
	return t;
}

bool T(){
	Token t;
	myfile.get(ch);
	t = Lexical();
	if(t.type == 2){
		return true;
	}
	else return false;
}

bool F(){
	Token t;
	myfile.get(ch);
	t = Lexical();
	if(t.val == "*"){
		return T();
	}
	else return false;
}
		
bool E(){
	Token t;
	myfile.get(ch);
	t = Lexical();
	if(t.type == 2){
		return F();
	}
	else return false;
}

int main() {
  myfile.open("text.txt", ios::in);
	cout<<E();
}
