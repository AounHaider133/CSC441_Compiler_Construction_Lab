#include <iostream>
#include <string>
#include <cctype>

bool isValidIdentifier(const std::string& identifier) {
    // Check if the identifier is non-empty and starts with an alphabetic character or underscore
    if (identifier.empty() || !(isalpha(identifier[0]) || identifier[0] == '_'))
        return false;

    // Check the remaining characters of the identifier
    for (size_t i = 1; i < identifier.size(); ++i) {
        if (!(isalnum(identifier[i]) || identifier[i] == '_'))
            return false;
    }

    return true;
}

void printIdentifiers(const std::string& str) {
    std::string identifier;
    bool inIdentifier = false;

    for (char c : str) {
        if (isalnum(c) || c == '_') {
            if (!inIdentifier) {
                inIdentifier = true;
                identifier.clear();
            }
            identifier += c;
        } else {
            if (inIdentifier) {
                if (isValidIdentifier(identifier)) {
                    std::cout << "Identifier found: " << identifier << std::endl;
                }
                inIdentifier = false;
            }
        }
    }

    // Check if the last identifier is valid
    if (inIdentifier && isValidIdentifier(identifier)) {
        std::cout << "Identifier found: " << identifier << std::endl;
    }
}

int main() {
    std::string str = "int x = 5; string uni = 'Comsats';";
    printIdentifiers(str);
    return 0;
}
