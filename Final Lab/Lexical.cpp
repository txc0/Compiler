#include <iostream>
#include <cctype>
#include <cstring>

#define MAX_LENGTH 100000

bool isDelimiter(char chr) {
    return (chr == ' ' || chr == '+' || chr == '-' ||
            chr == '*' || chr == '/' || chr == ',' ||
            chr == ';' || chr == '%' || chr == '>' ||
            chr == '<' || chr == '=' || chr == '(' ||
            chr == ')' || chr == '[' || chr == ']' ||
            chr == '{' || chr == '}');
}

bool isOperator(char chr) {
    return (chr == '+' || chr == '-' || chr == '*' ||
            chr == '/' || chr == '>' || chr == '<' ||
            chr == '=');
}

bool isValidIdentifier(const char* str) {
    return (str[0] != '0' && str[0] != '1' && str[0] != '2' &&
            str[0] != '3' && str[0] != '4' && str[0] != '5' &&
            str[0] != '6' && str[0] != '7' && str[0] != '8' &&
            str[0] != '9' && !isDelimiter(str[0]));
}

bool isKeyword(const char* str) {
    const char* keywords[] = { "auto",  "break", "case",    "char",
                                "const", "continue", "default", "do",
                                "double", "else",   "enum",    "extern",
                                "float", "for",    "goto",    "if",
                                "int",   "long",   "register", "return",
                                "short", "signed", "sizeof",  "static",
                                "struct","switch", "typedef", "union",
                                "unsigned", "void",  "volatile", "while"
                                ,"cout", "main", "include", "using", "namespace", "std",
                                "iostream" };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isInteger(const char* str) {
    if (str == nullptr || *str == '\0') {
        return false;
    }
    int i = 0;
    while (std::isdigit(str[i])) {
        i++;
    }
    return str[i] == '\0';
}

char* getSubstring(const char* str, int start, int end) {
    int length = std::strlen(str);
    int subLength = end - start + 1;
    char* subStr = new char[subLength + 1];
    std::strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}

int lexicalAnalyzer(const char* input) {
    int left = 0, right = 0;
    int len = std::strlen(input);

    while (right <= len && left <= right) {
        if (!isDelimiter(input[right])) {
            right++;
        }

        if (isDelimiter(input[right]) && left == right) {
            if (isOperator(input[right])) {
                std::cout << "Token: Operator, Value: " << input[right] << std::endl;
            }
            right++;
            left = right;
        } else if (isDelimiter(input[right]) && left != right ||
                    (right == len && left != right)) {
            char* subStr = getSubstring(input, left, right - 1);
            if (isKeyword(subStr)) {
                std::cout << "Token: Keyword, Value: " << subStr << std::endl;
            } else if (isInteger(subStr)) {
                std::cout << "Token: Integer, Value: " << subStr << std::endl;
            } else if (isValidIdentifier(subStr) &&
                        !isDelimiter(input[right - 1])) {
                std::cout << "Token: Identifier, Value: " << subStr << std::endl;
            } else if (!isValidIdentifier(subStr) &&
                        !isDelimiter(input[right - 1])) {
                std::cout << "Token: Unidentified, Value: " << subStr << std::endl;
            }
            delete[] subStr;
            left = right;
        }
    }
    return 0;
}

int main() {
    // Input 01
    const char lex_input[MAX_LENGTH] = "#include <iostream> using namespace std; int main() { cout << ""Welcome""; int x = 24 % 10; if (x == 4) { x = 40;} itn y = 50; int #z = 60; return 0;}";
    std::cout << "For Expression \"" << lex_input << "\":\n";
    lexicalAnalyzer(lex_input);
    std::cout << std::endl;

    return 0;
}

