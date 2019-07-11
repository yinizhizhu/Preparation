#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void permutation2(char* pStr, char* pBegin) {
	if (*pBegin == '\0') printf("%s\n", pStr);
	else {
		char tmp;
		for (char* step = pBegin; *step != '\0'; step++) {
			tmp = *step;
			*step = *pBegin;
			*pBegin = tmp;

			permutation2(pStr, pBegin + 1);

			tmp = *step;
			*step = *pBegin;
			*pBegin = tmp;
		}
	}
}

void permutation(char* pStr) {
	if (pStr) permutation2(pStr, pStr);
	return;
}

int main() {
	char str[6] = "abcd";
	permutation(str);
	return 0;
}

#include <stdio.h>
#include <string.h>
#define MAXSIZE 1024
#define MAXLENGTH 64

void CombineRecursiveImpl(const char *str, char *begin, char *end)
{
	if (*str == 0)
	{
		*end = 0;
		if (begin != end)
			printf("%s ", begin);
		return;
	}
	CombineRecursiveImpl(str + 1, begin, end);
	*end = *str;
	CombineRecursiveImpl(str + 1, begin, end + 1);
}

void CombineRecursive(const char str[])
{
	if (str == NULL)
		return;
	char result[MAXLENGTH];
	CombineRecursiveImpl(str, result, result);
}

int main()
{
	char str[MAXSIZE] = "abcde";
	CombineRecursive(str);
	return 0;
}