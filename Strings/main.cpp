#include <iostream>
#include <string>
#include "compressedTrie.h"
using namespace std;

int main()
{
    compressedTrie root;
    root.initialise();
    root.insertWord("");
    root.insertWord("facebook");
    root.insertWord("doing");
    root.insertWord("face");
    root.insertWord("facebooker");
    root.insertWord("facepalm");

    root.insertWord("thereafter");
    root.insertWord("thereis");
    root.insertWord("this");

    cout << root.countWord("this") << '\n';

    root.deleteWord("doing");

    cout << root.countWord("doing") << '\n';    

    root.deleteWord("this");
    root.deleteWord("thereis");

    cout << root.countWord("thereafter") << '\n';

    // root.deleteWord((string ("deer").c_str()));
    // //root.deleteWord((string("dog")).c_str());
    // cout << root.countPrefix("de") << '\n';
}