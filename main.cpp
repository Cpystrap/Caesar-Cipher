#include <iostream>
#include <string>
using namespace std;
int main() {
    int order, k;
    string sentence;
    cin >> order >> k >> sentence;
    int n = sentence.length();
    if (order == 1) {   //we want to code this sentence
        for (int i = 0; i < n; ++i) {
            char character;
            int kod;
            character = sentence[i];
            kod = character;
            if ((kod >= 65 && kod <= 90) || (kod >= 97 && kod <= 122)) { //if letter
                int kod2;
                character = (char)(sentence[i] + k);
                kod2 = (unsigned char)character;
                if (kod >= 65 && kod <= 90 && kod2 > 90) {  //if we go beyond Z
                    int over, x = 1;
                    over = kod2 - 91;
                    x += over / 26;
                    character = (char) (character - 26 * x);
                    cout << character;
                }
                else if (kod >= 97 && kod <= 122 && kod2>122) {  //if we go beyond z
                    int over, x = 1;
                    over = kod2 - 123;
                    x += over / 26;
                    character = (char) (character - 26 * x);
                    cout << character;
                }
                else {  //if we don't go beyond Z or z
                    cout<<character;
                }
            }
            else {  //if character is special
                cout << character;
            }
        }
    }
    if (order == 2) {   //we want to decode this sentence
        for (int i = 0; i < n; ++i) {
            char character;
            int kod;
            character = sentence[i];
            kod = character;
            if ((kod >= 65 && kod <= 90) || (kod >= 97 && kod <= 122)) { //if letter
                int kod2;
                character = (char)(sentence[i] - k);
                kod2 = character;
                if (kod >= 65 && kod <= 90 && kod2 < 65) {  //if we go beyond A
                    int over, x = 1;
                    over = 64-kod2;
                    x += over / 26;
                    character = (char) (character + 26 * x);
                    cout << character;
                }
                else if (kod >= 97 && kod <= 122 && kod2 < 97) {  //if we go beyond a
                    int over, x = 1;
                    over = 96-kod2;
                    x += over / 26;
                    character = (char) (character + 26 * x);
                    cout << character;
                }
                else {  //if we go beyond A or a
                    cout<<character;
                }
            }
            else {  //if character is special
                cout << character;
            }
        }
    }
}