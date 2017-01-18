//
//  main.cpp
//  longestSentence
//
//  Created by William Brubaker on 1/17/17.
//  Copyright © 2017 William Brubaker. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


const char SPACE = ' ';
bool isPunctuation(char c){
    switch (c) {
        case '.':
            return true;
            break;
        case '?':
            return true;
            break;
        case '!':
            return true;
            break;
        case '\0':
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool isSpace(char c){
    return c == SPACE;
}

bool isEndOfString(char c1, char c2){
    return isalpha(c1) &&  c2 == '\0';
}

bool isCharThenSpace(char c1, char c2){
    return isalpha(c1) && isSpace(c2);
}

bool isCharThenPunctuation(char c1, char c2){
    return isalpha(c1) && isPunctuation(c2);
}

bool endOfWord(char c1, char c2){
    if(c1 == '\0'){
        return false;
    }
    return (isCharThenSpace(c1, c2))? true : (isCharThenPunctuation(c1, c2)) ? true : (isEndOfString(c1, c2))? true : false;
}

bool endOfSentence(char c){
    return isPunctuation(c);
}

bool lValGreaterThanRVal(int lVal, int rVal){
    return lVal > rVal;
}

int solution(std::string &S){
    int words = 0;
    int mostWords = 0;
    
    for(int i=0;i<S.length()-1;++i){
        if(endOfWord(S[i], S[i+1])){
            ++words;
        }
        if(lValGreaterThanRVal(words, mostWords)){
            mostWords = words;
        }
        if(endOfSentence(S[i])){
            words = 0;
        }
        
        
    }
    return mostWords;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::string> sentences;
    sentences.push_back("We test coders. Try us!");
    sentences.push_back("Stop CVs.. x x. Use us");
    sentences.push_back(".....");
    //std::cout << "Hello, World!\n" << std::endl;
    for(auto s: sentences){
        std::cout << s << std::endl;

    }
    std::cout << "longest sentence is: ";
    for(auto s: sentences){
        std::cout << "Sentence x: ";
        std::cout << solution(s) << std::endl;
    }
    return 0;
}
