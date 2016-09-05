#include <string>
#include <iostream>
   
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    while (n--)
    {
		string nickName;
		getline(cin, nickName);
		nickName.replace(0, nickName.find(" "), "god");
		int pos;
		while((pos = nickName.find(" ")) != string::npos)
		{
			nickName.erase(pos, 1);
		}
		cout << nickName << endl;
    }
    return 0;
}
