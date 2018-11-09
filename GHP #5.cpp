 /*  GHP #5 code

    Read in a string of characters, push each character onto a stack as it is being read
    and simultaneously add it to a queue. Once the end of the string is encountered,
    determine if the string is a palindrome.

    Written by Nicole Maiello
        This program runs with the code handed out with program, Queue.cpp, Queue.h,
        Stack.cpp and Stack.h.
    April 3, 2017
    Language: c++ (Written in Code::Blocks, g++ target)
*/
#include <iostream>
#include <string>

using namespace std;

#include "Stack.h"
#include "Queue.h"

int main(void)
{
    string sentence;
    int i;
    int sizeOf;
    bool same = true;                   //assume true until determined to be wrong
    Stack backwards;
    Queue forwards;

    cout<<"Please enter a sentence or word to determine if it is a palindrome."<<endl<<"(Spaces, special characters, and numbers will be ignored.)"<<endl;
    getline(std::cin, sentence);        //takes in the entire line of input

    sizeOf = sentence.size();           //gets the size of the entire line
    for(i = 0; i < sizeOf; i++)
    {
        if(isalpha(sentence[i])){       //ignores spaces, special characters and numbers
            forwards.enqueue(sentence[i]);
            backwards.push(sentence[i]);
        }
    }

    while(((!backwards.empty() && !forwards.empty()) && (same))){    //the loop ends when same becomes false or when either of the lists are empty
        if(tolower(forwards.front()) != tolower(backwards.top()))
            same = false;
        forwards.dequeue();
        backwards.pop();
    }

    if(same)
        cout<<sentence<<" is a palindrome!"<<endl;
    else
        cout<<sentence<<" is not a palindrome."<<endl;
    return 0;
}
