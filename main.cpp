#include <iostream>
#include <fstream>

#include "markov_functions.h"

/********************
Program    - Markov Chains
Maintainer - C.Holmes
File       - Program Functions
Version    - 0
    - Release Notes:
        - Version 0   - Initial functions created
        - Version 0.1 - First iteration of complete program
********************/

// Namespace
markovChain MC;

int main() {
    std::cout << "Markov Origins Program Entry..." << std::endl;

    // Read in text file
    std::ifstream file("../pushkin_eugene_onegin.txt");
    // file read error check
    if (!file.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    // Read file characters, one by one
    std::string text;
    char c;
    while (file.get(c)) {
        // Consider only alphabetic characters
        if (std::isalpha(c)) {
            // convert to lowercase and append to text
            text += std::tolower(c);
        }
    }
    file.close();

    // Convert letters to binary state
    // 0 = consonent, 1 = vowel
    std::vector<int> states;
    for (char c : text) {
        states.push_back((MC.cToState(c)));
    }

    // Count state transitions C[from][to]
    //C[0][0] = transitions from consonant → consonant  
    //C[0][1] = consonant → vowel  
    //C[1][0] = vowel → consonant  
    //C[1][1] = vowel → vowel

    // Initialize 2x2 transition count matrix
    int C[2][2] = {0};

    // Count transitions between states
    for (size_t i = 0; i + 1 < states.size(); ++i) {
        // Current state
        int from = states[i];
        // Next state
        int to = states[i + 1];
        // Incremental transition count
        C[from][to]++;
    }

    // Output transition counts
    std::cout << "Transition Counts:\n";
    std::cout << "From\\To     Consonant  Vowel\n";
    std::cout << "Consonant  " << std::setw(10) << C[0][0] << "  " << std::setw(5) << C[0][1] << "\n";
    std::cout << "Vowel      " << std::setw(10) << C[1][0] << "  " << std::setw(5) << C[1][1] << "\n";

    // Compute transition probability Matrix
    double P[2][2];
    for (int i = 0; i < 2; ++i) {
        // Total transitions from state i
        int row_sum = C[i][0] + C[i][1];
        // P[i][0] = i -> 0
        P[i][0] = static_cast<double>(C[i][0]) / row_sum;
        // P[i][0] = i -> 1
        P[i][0] = static_cast<double>(C[i][1]) / row_sum;
    }

    // Out the transition probabilities
    std::cout << "\nTransition Probability Matrix:\n";
    std::cout << "From\\To    Consonant   Vowel\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Consonant  " << std::setw(10) << P[0][0] << "  " << std::setw(6) << P[0][1] << "\n";
    std::cout << "Vowel      " << std::setw(10) << P[1][0] << "  " << std::setw(6) << P[1][1] << "\n";

    return 0;
}