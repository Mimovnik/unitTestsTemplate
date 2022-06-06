#include "main.h"
// #define MAX_LINE_LENGTH 64

#include <string.h>
#include <unistd.h>
#include <iostream>

bool equals(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) {
        return true;
    }
    return false;
}

int MYmain() {
    char* command = new char[MAX_LINE_LENGTH];

    while (std::cin >> command) {
        if (equals(command, "Hello")) {
            std::cout << "You typed: Hello" << std::endl;
        } else if (equals(command, "Goodbye")) {
            std::cout << "You typed: Goodbye" << std::endl;
        } else if (equals(command, "Test")) {
            std::cout << "You typed: Test" << std::endl;
        }
    }

    return 0;
}
