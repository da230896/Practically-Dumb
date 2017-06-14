/*
space complexity linear in (number of words*length) 
while time complexity is linear in length
    initialise()
    insertWord(word)
    countWord(word)
    coutPrefix(word)
    DeleteWord(word)
*/
#include <map>
using namespace std;

class Trie{
    int word;
    int prefixes;
    map<char,Trie> children;
public:
    void initialise()
    {
        word = prefixes = 0;
        children.clear();
    }     
    bool insertWord(const char* ptr)
    {
        prefixes++;
        if(*ptr == '\0')
        {
            word++;
            return true;
        }
        char x = *ptr;
        if(this->children.find(x) == this->children.end())
        {
            (this->children[x]).initialise();
        }
        return this->children[x].insertWord(++ptr);
    }
    int countWord(const char *ptr)
    {
        if(*ptr == '\0')
            return word;
        int x = *ptr;
        if(this->children.find(x) == this->children.end())
            return 0;
        else
            return this->children[x].countWord(++ptr);
    }
    int countPrefix(const char *ptr)
    {
        if(*ptr == '\0')
            return prefixes;
        int x = *ptr;
        if(this->children.find(x) == this->children.end())
            return 0;
        else
            return this->children[x].countPrefix(++ptr);
    }
    bool deleteWord(const char *wrd)
    {
        if(prefixes > 0)
        {
            prefixes--;
        }else{
            return false;
        }
        if(*wrd == '\0')
        {
            if(word > 0)
            {    
                word = word-1;
                return true;
            }else
            {
                prefixes++;
                return false;
            }
        }
        if(children.find(*wrd) == children.end())
        {
            prefixes++;
            return false;
        }
        if(!children[*wrd].deleteWord(wrd+1))
        {
            prefixes++;
            return false;
        }else{
            return true;
        }
    }
};
