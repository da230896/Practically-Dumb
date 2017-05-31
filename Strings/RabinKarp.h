int find_pattern(char text[],char pattern[])
{
    int d = 26;
    long q = 1e9+7;
    long p = 0,t = 0;
    int h = 1;
    int m = strlen(pattern),l = strlen(text);
    if(m > l)
    {
        return -1;
    }
    for(int i = 0;i < m-1;++i)
    {
        h = (h*1ll*d)%q;
    }
    for(int i = 0;i < m;++i)
    {
        p = (p*1ll*d + pattern[i])%q;
        t = (t*1ll*d + text[i])%q;
    }

        /*
            If all the characters of the pattern ar different then 
            we can slide first j matches as first char of pattern 
            wont match any other j matches
                
    for(int i = 0;i <= (l-m);)
    {
        if(p == t)
        {
            int j;
            for(j = 0;j < m;++j)
            {
                if(pattern[j] != text[i+j])
                    break;
            }
            if(j == m)
            {
                return i+1;
            }
            if(j == 0)
                i += 1;
            else
                i += j;
        }
        //without if future extension is difficult
        if(i < l-m)
            t = (d*1ll*(t - (h*1ll*text[i])%q)%q + text[i+m])%q;

        if(t < 0)
            t += q;
    }
        */

    for(int i = 0;i <= (l-m);++i)
    {
        if(p == t)
        {
            int j;
            for(j = 0;j < m;++j)
            {
                if(pattern[j] != text[i+j])
                    break;
            }
            if(j == m)
            {
                return i+1;
            }
        }
        //without if future extension is difficult
        if(i < l-m)
            t = (d*1ll*(t - (h*1ll*text[i])%q)%q + text[i+m])%q;

        if(t < 0)
            t += q;
    }
    return -1;
}