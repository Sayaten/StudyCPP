#include <cstdio>
#include <map>
#include <string>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	std::map< int, std::string > k;
	std::map< std::string, int > v;
	for(int i = 1; i <= n ; ++i)
	{
		char name[21];
		scanf( "%s", name );
		k.insert( std::make_pair( i, std::string( name ) ) );
		v.insert( std::make_pair( std::string( name ), i ) );
	}

	while(m--)
	{
		char input[21];
		scanf( "%s", input );
		if('0' <= input[0] && input[0] <= '9')
			printf( "%s\n", ( k.find( std::stoi( input ) ) ) -> second.data() );
		else
			printf( "%d\n", ( v.find( std::string( input ) ) ) -> second );
	}

	return 0;
}
