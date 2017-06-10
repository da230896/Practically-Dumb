#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

int main()
{
    Trie root;
    root.initialise();
    root.insertWord((string ("cat")).c_str());
    root.insertWord((string ("ball")).c_str());
    root.insertWord((string ("dog")).c_str());
    root.insertWord((string ("deer")).c_str());

    //cout << root.countWord("ball") << '\n';
    root.deleteWord((string ("deer").c_str()));
    //root.deleteWord((string("dog")).c_str());
    cout << root.countPrefix("de") << '\n';
}