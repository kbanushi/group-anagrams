#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

//This function serves to find the "key" to the unordered map by sorting the words in alphabetical order.
//Takes one string input and returns the sorted string as output
std::string findKey(std::string unsorted){
    std::string sorted = unsorted;
    char tempSort;

    for(int i = 0; i < unsorted.length(); i++){
        for(int j = 0; j < unsorted.length(); j++){
            if (sorted[i] < sorted[j]){
                tempSort = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tempSort;
            }
        }
    }
    
    return sorted;
}

//This function will group the anagrams based on if they are anagrams of each other.
//Takes in the input anagrams in a string array and the length of the array.
void groupAnagrams(std::string strs[], int strsLen){
    std::string anagramKey;
    std::unordered_map<std::string, std::vector<std::string>> vectorMap;  //Compex data structure of an unordered map where the key is a string and the element is a vector of type string.

    for(int i = 0; i < strsLen; i++){
        anagramKey = findKey(strs[i]);  //Find key

        auto search = vectorMap.find(anagramKey);
        if (search != vectorMap.end()){  // FOUND
            vectorMap[anagramKey].push_back(strs[i]); //Group at the found key
        }else{
            vectorMap.insert({anagramKey, {strs[i]}});  //INSERT IF NOT FOUND
        }
    }    

    for(auto const &pair: vectorMap){  //Loop used to output the final results
        for (int i = 0; i < pair.second.size(); i++){
            std::cout << pair.second[i] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::string strs[] = {"eat","tea","tan","ate","nat","bat"};
    int strsLength = sizeof(strs)/sizeof(strs[0]);
    
    groupAnagrams(strs, strsLength);

    return 0;
}