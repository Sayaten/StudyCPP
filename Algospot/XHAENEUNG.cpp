#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
int main()
{
	int test_case, length;
	int value_a, value_b, value_answer, check_c, check_answer;
	char A[6], *oper, B[6], C[11], answer[6], sentence[30];
	char number[11][6] = {
							"zero", "one", "two",
							"three", "four", "five",
							"six", "seven", "eight",
							"nine", "ten"
						};
	int prime[26] = {
						2, 	3, 	5, 	7, 	11, 13, 17, 19, 23, 29,
						31, 37, 41, 43, 47, 53, 57, 61, 67, 71,
						73, 79, 83, 89, 97, 101
					};

	std::cin >> test_case;
	std::cin.ignore(1, '\n');

	for(int i = 0 ; i < test_case ; ++i)
	{
		std::cin.getline(sentence, 30);
		strcpy(A, std::strtok(sentence, " "));
		oper = strtok(NULL, " ");
		strcpy(B, std::strtok(NULL, " "));
		std::strtok(NULL, " "); // ignore '='
		strcpy(C, std::strtok(NULL, " "));

		// find value
		for(value_a = 0 ; value_a <= 10 ; ++value_a)
		{
			if(strcmp(A, number[value_a]) == 0) break;
		}
		for(value_b = 0 ; value_b <= 10 ; ++value_b)
		{
			if(strcmp(B, number[value_b]) == 0) break;
		}

		// calculate
		switch(oper[0])
		{
			case '+':
				value_answer = value_a + value_b;
				break;
			case '-':
				value_answer = value_a - value_b;
				break;
			case '*':
				value_answer = value_a * value_b;
				break;
		}

		// compare length
		length = strlen(number[value_answer]);
		if(length != strlen(C)) 
		{
			std::cout << "No" << std::endl;
			continue;
		}

		// compre answer and C with prime factorization.
		check_c = check_answer = 1;
		for(int j = 0 ; j < length; ++j)
		{
			check_c *= prime[C[j] - 'a'];
			check_answer *= prime[number[value_answer][j] - 'a'];
		}
		if(check_c == check_answer) std::cout << "Yes" << std::endl;
		else std::cout << "No" << std::endl;
	}

	return 0;
}
