#include "ladder.h"

int main() {
    string start_word, end_word;
    set<string> word_list;
    
    load_words(word_list, "words.txt");
    
    cout << "Enter start word: ";
    cin >> start_word;
    cout << "Enter end word: ";
    cin >> end_word;
    
    if (start_word == end_word) {
        error(start_word, end_word, "Start and end words must be different.");
        return 1;
    }
    
    if (word_list.find(end_word) == word_list.end()) {
        error(start_word, end_word, "End word is not in the dictionary.");
        return 1;
    }
    
    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);
    
    return 0;
}