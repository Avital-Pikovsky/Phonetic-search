#include "PhoneticFinder.hpp"
#include <iostream>

#include <string>
using namespace std;

namespace phonetic
{
/* A function that finds a word in the text,
even if the word is written in text with misspellings.
The function should return the word as it is written in the text. */

std::string find(std::string text, std::string word)
{
    int i = 0, j = 0;
    string answer = "";

    while ((i < text.length()) && (text.at(i) != ' '))
    {
        if ((j < word.length()) && (sameLetter(text.at(i), word.at(j))))
        {
            answer += text.at(i);
            i++;
            j++;
        }

        else if ((j < word.length()) && (friends(text.at(i), word.at(j))))
        {
            answer += text.at(i);
            i++;
            j++;
        }

        else
        {
            answer = "";
            j = 0;
            while ((text.at(i) != ' ') && (i < text.length() - 1))
            {
                i++;
            }
            i++;
        }
    }
    if (j == word.length())

        return answer;

    else

        throw runtime_error("Did not find the word: '" + word + "' in the text!");

} // namespace phonetic

/* A function that checks if it is the same letter,
 uppercase letter or lowercase letter.*/

bool sameLetter(char a, char b)
{
    a = tolower(a);
    b = tolower(b);

    if (a == b)

        return true;

    else
        return false;
}

/* A function that checks for letters that have been confused but considered proper, 
uppercase letter or lowercase letter.*/

bool friends(char a, char b)
{
    a = tolower(a);
    b = tolower(b);

    bool flag = false;
    if ((a == 'v' || a == 'w') && (b == 'v' || b == 'w')) //v,w
        flag = true;
    if ((a == 'b' || a == 'f' || a == 'p') && (b == 'b' || b == 'f' || b == 'p')) //b,f,p
        flag = true;
    if ((a == 'g' || a == 'j') && (b == 'g' || b == 'j')) //g,j
        flag = true;
    if ((a == 'c' || a == 'k' || a == 'q') && (b == 'c' || b == 'k' || b == 'q')) //c,k,q
        flag = true;
    if ((a == 's' || a == 'z') && (b == 's' || b == 'z')) //s,z
        flag = true;
    if ((a == 'd' || a == 't') && (b == 'd' || b == 't')) //d,t
        flag = true;
    if ((a == 'o' || a == 'u') && (b == 'o' || b == 'u')) //o,u
        flag = true;
    if ((a == 'i' || a == 'y') && (b == 'i' || b == 'y')) //i,y
        flag = true;

    //printf(" %b", flag);
    return flag;
}

} // namespace phonetic
