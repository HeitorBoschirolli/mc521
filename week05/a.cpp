#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

bool value_comparer(map <string, pair<int, int> >::iterator i1, map <string, 
pair<int, int> > ::iterator i2){
    if ((i1->second).first < (i2->second).first) {
        return true;
    }
    else if (i1->second.first > i2->second.first) {
        return false;
    }
    else if (i1->second.second < i2->second.second){
        return true;
    }
    else {
        return false;
    }
}

int main() {
    
    map <string, pair<int, int> > text;
    string word;
    char character;
    int index = 1;
    bool done = false;
    while (true) {
        do {
            
            if (scanf("%c", &character) == EOF) {
                done = true;
                break;
            }
                
            if ((character >= 'a') && (character <= 'z')) {
                word.push_back(character);
            }
            else if ((character >= 'A') && (character <= 'Z')) {
                character = character + ('a' - 'A');
                word.push_back(character);
            }
            else if (word.size() == 0) {
                ;
            }
            else if (text.find(word) == text.end()){
                pair <int, int> temp = make_pair(1, index);
                text[word] = temp;
                word.clear();
                index++;
            }
            else {
                map<string, pair<int, int> > ::iterator it = text.find(word);
                pair <int, int> temp = it->second;
                pair <int, int> new_info = make_pair(temp.first + 1, index);
                it->second = new_info;
                word.clear();
                index++;
            }
        } while (character != '#');
        
        if (done) {
            break;
        }
        
        int currentMax = 0;
        int currentIndex = -1;
        string arg_max;
        for(map <string, pair<int, int> >:: iterator it = text.begin(); it != 
    text.end(); it++){
            if ((it ->second).first > currentMax) {
                arg_max = it->first;
                currentMax = (it->second).first;
                currentIndex = (it->second).second;
            }
            else if ((it ->second).first == currentMax) {
                if ((it->second).second < currentIndex) {
                    arg_max = it->first;
                    currentMax = (it->second).first;
                    currentIndex = (it->second).second;
                }
            }
        }
        
        if (currentMax > 0) {
            printf("%4d ",currentMax);
            cout << arg_max << endl;
        }
        
        text.clear();
    }


    
        
    return 0;
}