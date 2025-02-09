#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <cstring>


void Generate_Password(std::vector<std::string>& passwords, int length, bool hasUpperCase, bool hasNumbers, bool hasSpecialCharacters, int noPasswords = 1)
{
 
    std::srand(std::time(0));
    const char lcLetters[] = "abcdefghijklmnopqrstuvwxyz";
    const char ucLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char sCharacters[] = "!@#$%^&*()-_=+[]{};:'\",.<>?/|`~";
    // Total 26 + 26 + 10 + 32 = 94
    std::string availableCharacters = lcLetters;
    if(hasUpperCase) availableCharacters += ucLetters;
    if(hasNumbers) availableCharacters += digits;
    if(hasSpecialCharacters) availableCharacters += sCharacters;
    int size = availableCharacters.length();
    for(int i=0; i<noPasswords; i++)
    {
        passwords.resize(length);
        for(int j=0; j<length; j++) 
        {
            passwords[i] += availableCharacters[std::rand()%(size-1)];
        }
    }
}

int main()
{
    std::vector<std::string> passwords(64);
    Generate_Password(passwords, 128, 1, 1, 1, 64);
    for(int i=0; i<64; i++)
    {
        std::cout << passwords[i] << '\n';
    }
    return 0;
}