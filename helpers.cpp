#include "declarations.hpp"

int getLength(std::string line) {
    int length = 0;

    while (line[length] != '\0') {
        length++;
    }

    return length;
}

bool isAlpha(std::string input) {
    if (input == "") {
        return false;
    }

    int length = getLength(input);

    for (int i = 0; i < length; i++) {
        if ( !((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) ) {
            return false;
        }
    }
    return true;
}

bool isNumeric(std::string input) {
    if ( input == "") {
        return false;
    }

    int length = getLength(input);

    for (int i = 0; i < length; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
    }

    return true;
}

int toInt(std::string input) {
    int n = 0, length = getLength(input);

    for (int i = 0; i < length; i++) {
        int digit = input[i] - '0';
        n = (n * 10) + digit;
    }

    return n;
}

std::string toString(int number, int digits) {
    if (number < 0) {
        return "ERR";
    }

    std::string result = "";

    if (number == 0) {
        result = "0";
    } else {
        int temp = number;
        while (temp > 0) {
            char c = (temp % 10) + '0';
            result = c + result;
            temp /= 10;
        }
    }

    while (getLength(result) < digits) {
        result = '0' + result;
    }

    return result;
}

std::string formatPlayerName(std::string name) {
    std::string limitedName = "";

    int length = getLength(name);

    for (int i = 0; i < 4; i++) {
        if (i < length) {
            limitedName += name[i];
        } else {
            break;
        }
    }

    while (getLength(limitedName) < 4) {
        limitedName += " ";
    }

    return limitedName;
}

std::string formatString(std::string line, int characters) {
    if (line == "" ) {
        return line;
    }
    while (getLength(line) < characters) {
        line += " ";
    }
    return line;
}
