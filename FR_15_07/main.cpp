#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool checkAnagram(std::string first, std::string second) {

    if (first.size() != second.size()) { return false; }//Check different size both words

    //Sort both words
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    
    //Check anagram
    for (int x=0; x<first.size(); x++) {
        if (first[x] != second[x]) {
            return false;
        }
    }

    return true;

}

//Function find number index for anagram
int findAnagramInArray(std::vector <std::vector <std::string>> array, std::string txt) {

    if (array.size() <= 0) { return -1; }

    for (int x=0; x<array.size(); x++) {
        if (checkAnagram(array[x][0], txt)) {
            return x;
        }
    }
    return -1;
}

//Function who prepared indexes words
std::vector <std::vector <std::string>> friends(std::vector <std::string> indexes) {
    
    std::vector <std::vector <std::string>> bufor;

    for (int x=0; x<indexes.size(); x++) {
            
        int position = findAnagramInArray(bufor, indexes[x]);
        if (position != -1) {
            bufor[position].push_back(indexes[x]);//Add under word another anagram
        }else {
            std::vector <std::string> buforFast; buforFast.push_back(indexes[x]);//Create new position for word
            bufor.push_back(buforFast);
        }
    }

    return bufor;

}

//Function who search longest array with anagrams
int findIndexLongest(std::vector <std::vector <std::string>> friendsResult) {
    int longest = 0;
    int index = -1;

    for (int x=0; x< friendsResult.size(); x++) {
        if (friendsResult[x].size() > longest) {
            index = x;
            longest = friendsResult[x].size();
        }
    }
    return index;
}

int main() {

    int ile;
    std::string bufor;
    std::vector <std::string> index;
    std::vector <std::vector <std::string>> friendsResult;

    std::cin >>ile;
    std::cin.ignore();
   
    for (int x=0; x<ile; x++) {
        std::getline(std::cin, bufor);
        index.push_back(bufor);
    }

    friendsResult = friends(index);
    int indexBuf = findIndexLongest(friendsResult);

    for (int x=0; x<friendsResult[indexBuf].size(); x++) {
        std::cout << friendsResult[indexBuf][x]<<std::endl;
    }

    return 0;

}
