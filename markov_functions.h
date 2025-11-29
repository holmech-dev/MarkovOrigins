#include <cctype>

/********************
Program    - Markov Chains
Maintainer - C.Holmes
File       - Program Functions
Version    - 0
    - Release Notes:
        - Version 0   - Initial functions created
********************/

// Class for program functions
class markovChain {
    public:
    char c;

    // Function to detect if c is vowel
    bool vowelDetector(char c) {
        // Ensure lower case input
        // Markov used y as a vowel
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u' || c == 'y';
    };

    // Use vowelDetector output to set state
    int cToState(char c) {
        return vowelDetector(c) ? 1 : 0;
    }

};