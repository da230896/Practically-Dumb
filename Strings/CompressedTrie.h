/*
space complexity can become (in best case) linear in (number of words)
time complexity is same O(tagert string length)
    insertion:
        1.no prefix
        2.partial prefix
        3.fully prefix

    searching:
        1.no string
        2.partial target
        3.proper prefix of some string
        4.exists

    Deletion:
    algo
        1.find the node delete it
        2.if the p.node now has only one child
            The grand parent become parent of "p.node + p.child" string
*/

#include <unordered_map>
#include <utility>
#include <sstream>

using namespace std;

class compressedTrie
{
    int word,prefixes;
    unordered_map<char,pair<stringstream,compressedTrie*> >children;
    /*
    unordered_map<char,pair<stringstream,compressedTrie> >children;
        Above Line is classic example of standard container with 
        incomplete Type.
    */
public:
    int getPrefixCount()
    {
        return prefixes;
    }
    string getZerothChild()
    {
        if(children.size() == 0)
            return "";
        else
            return children.begin()->second.first.str();
    }
    int getWordCount()
    {
        return word;
    }
    bool addBlock(string s,compressedTrie *block)
    {
        if(s.length() > 0 && children.find(s[0]) == children.end())
        {
            children[s[0]].first.str(s);
            children[s[0]].second = block;
            return true;
        }
        cout << "Please add via insert_word\n";
        return false;
    }
    void initialise()
    {
        word = prefixes = 0;
        children.clear();
    }
    void clearChld()
    {
        children.clear();
    }

    bool insertWord(const char* wrd)
    {
        prefixes++;
        if(*wrd == '\0')
        {
            word++;
            return true;
        }

        if(children.find(*wrd) == children.end())
        {
            children[*wrd].first.str(wrd);
            children[*wrd].second = new compressedTrie();
            children[*wrd].second->initialise();
            return children[*wrd].second->insertWord("");
        }else{
            string edgeLabel = children[*wrd].first.str();
            int j = 0;
            while(*wrd != '\0' && j < edgeLabel.length() && *wrd == edgeLabel[j])
            {
                wrd++;
                j++;
            }
            if(j < edgeLabel.length() && *wrd == '\0')
            {
                //case of complete Prefix
                children[edgeLabel[0]].first.str(children[edgeLabel[0]].first.str().substr(0,j));
                return children[edgeLabel[0]].second->insertWord("") & children[edgeLabel[0]].
                                                                        second->insertWord(edgeLabel.substr(j).c_str());

            }else if(j == edgeLabel.length() && *wrd != '\0')
            {
                //csae of edgeLabel = "facebook" and wrd = "facebooker"
                stringstream ss;
                ss << wrd;
                return children[edgeLabel[0]].second->insertWord(ss.str().c_str());

            }else if(j == edgeLabel.length() && *wrd == '\0')
            {
                //case of edgeLabel = "facebook" and wrd = "facebook" only
                return children[edgeLabel[0]].second->insertWord("");
            }else{
                //case of partial prefix
                compressedTrie *temp = children[edgeLabel[0]].second;
                children.erase(edgeLabel[0]);
                children[edgeLabel[0]].first.str(edgeLabel.substr(0,j));
                children[edgeLabel[0]].second = new compressedTrie;
                children[edgeLabel[0]].second->initialise();
                return children[edgeLabel[0]].second->addBlock(edgeLabel.substr(j).c_str(),temp) & 
                                                    children[edgeLabel[0]].second->insertWord(wrd);
            }
            return false;
        }
    }
    int countWord(const char* wrd)
    {
        if(*wrd == '\0')
            return word;
        if(children.find(wrd[0]) == children.end())
            return 0;
        else{
            string edge = children[wrd[0]].first.str();
            int i = 0;
            while(i < edge.length() && *wrd != '\0' && edge[i] == *wrd)
            {
                ++i,++wrd;
            }
            if(i == edge.length())
                return children[edge[0]].second->countWord(wrd);
            else
                return 0;
        }
    }
    bool deleteWord(const char* wrd)
    {
        /*
            1.when word is not present
            2.edge partial match 
            3.edge complete match
                insert thereafter
                insert therefore
                insert this
                delete this
                    personally i dont think there is any need to merge to gp(grand Parent)
                    if parent has two or more nodes . Like in this case 'ere' can be picked 
                    into gp node , but that is redundant.
                    Rather we should merge only if there is one child of p node.

                insert this
                insert thisis
                insert thisare
                delete this
        */
        if(prefixes > 0)
            prefixes--;
        else
            return false;
        if(*wrd == '\0')
        {
            if(word > 0)
            {
                word--;
                return true;
            }else{
                prefixes++;
                return false;
            }
        }
        if(children.find(wrd[0]) == children.end())
        {
            prefixes++;
            return false;
        }
        string edgeLabel = children[wrd[0]].first.str();
        int j = 0;
        while(j < edgeLabel.length() && *wrd != '\0' && *wrd == edgeLabel[j])
            ++j,++wrd;
        if(j != edgeLabel.length() || *wrd != '\0')
        {
            prefixes++;
            return false;
        }else{
            if(children[edgeLabel[0]].second->deleteWord(wrd))
            {
                int x = children[edgeLabel[0]].second->getPrefixCount();
                if(x == 0)
                {
                    children.erase(edgeLabel[0]);
                }
                if(x == 1)
                {
                    children[edgeLabel[0]].first << children[edgeLabel[0]].second->getZerothChild();
                    children[edgeLabel[0]].second->clearChld();
                }
                return true;
            }else{
                prefixes++;
                return false;
            }
        }
    }
};