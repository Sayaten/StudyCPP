#include <cstdio>
#include <set>
int main()
{
    int n;
    std::set<int> s;
    scanf("%d", &n);
    while(n--)
    {
        char c[7];
        scanf("%s", c);
        if(c[1] == 'l') for(int i = 1 ; i <= 20 ; ++i) s.insert(i);
        else if(c[1] == 'm') s.clear();
        else
        {
            int i;
            scanf("%d\n", &i);
            switch(c[1])
            {
                case 'd':
                    s.insert(i);
                    break;
                case 'e':
                    s.erase(i);
                    break;
                case 'h':
                    printf("%d\n", s.find(i) == s.end() ? 0 : 1);
                    break;
                case 'o':
                    if(s.find(i) == s.end()) s.insert(i);
                    else s.erase(i);
                    break;
            }
        }
    }
    return 0;
}
