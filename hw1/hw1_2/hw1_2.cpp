/*
 * Title: hw1_2.cpp
 * Abstract: This program determines whether or not two words are anagrams
 * Author: Lindsey Reynolds
 * ID: 5571
 * Date: 11/03/2020
 */

#include <iostream>
#include <map>
using namespace std;


int main()
{
    bool isAnagram = true;
    
    //read in two strings
    string word1, word2;
    cin >> word1 >> word2;
    
    //check if the two words are the same size
    if(word1.length() != word2.length()){
        isAnagram = false;
    }
    
    //create maps to store each letter and the 
    //number of times it occurs for each string
    map<char, int> map1;
    map<char, int> map2;
    
    int index = 0;
    
    while(isAnagram && index < word1.length()){
        map1[word1[index]] = map1[word1[index]] + 1;
        map2[word2[index]] = map2[word2[index]] + 1;
        index++;
    }
    
    if(map1 == map2 && isAnagram){
        cout << "ANAGRAM" << endl;
        // Loop through elements in the map 
        for (pair<char, int> c : map1) {
            cout << c.first << ": " << c.second << endl;
        }
    } else {
        cout << "NO ANAGRAM" << endl;
    }
    
    return 0;
}