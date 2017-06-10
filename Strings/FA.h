#include <strings.h>
#define NO_OF_CHARS 256
using namespace std;

//Complexity O((m^3)*NO_OF_CHARS)

// int findNextState(string S,int state,int x)
// {
//     //trivial case when next char is 'x'
//     if(state < S.length() && S[state] == x)
//         return state+1;

//     for(int i = state-1;i >= 0;--i)
//     {
//         int j;
//         if(S[i] == x)
//         {
//             for(j = 0;j < i;++j)
//             {
//                 if(S[j] != S[state-i+j])
//                     break;
//             }
//             if(j == i)
//                 return i+1;
//         }
//     }
//     return 0;
// }

// void computeTF(string S,int TF[][NO_OF_CHARS])
// {
//     for(int i = 0;i <= S.length();++i)
//     {
//         for(int j = 0;j < NO_OF_CHARS;++j)
//         {
//             TF[i][j] = findNextState(S,i,j);
//         }
//     }
// }

//complexity now O(m*NO_OF_CHARS)

void computeTF(string S,int TF[][NO_OF_CHARS])
{
    if(S.length() == 0)
        return;
    TF[0][S[0]] = 1;
    int lps = 0;
    for(int i = 1;i <= S.length();++i)
    {
        for(int j = 0;j < NO_OF_CHARS;++j)
        {
            TF[i][j] = TF[lps][j];
        }
        if(i < S.length())
        {    
            TF[i][S[i]] = i+1;
            lps = TF[lps][S[i]];
        }
    }

}

void search(string text,string pattern)
{
    int m = pattern.length();
    int TF[m+1][NO_OF_CHARS];
    memset(TF,0,sizeof(TF));
    computeTF(pattern,TF);

    int s = 0;
    for(int i = 0;i < text.length();++i)
    {
        s = TF[s][text[i]];
        if(s == m)
        {
            cout << "Pattern Found at " << i-m+1 << '\n';
        }
    }
}