
// find the longest palindromic substring
#include <bits/stdc++.h>
using namespace std;

int longestPalSubstr(char* str)
{
	
	int maxLength = 1;

	int start = 0;
	int len = strlen(str);

	int low, high;

	for (int i = 1; i < len; ++i) {
		// Find the longest even length palindrome
		// with center points as i-1 and i.
		low = i - 1;
		high = i;
		while (low >= 0 && high < len
			&& str[low] == str[high]) {
			--low;
			++high;
		}

		++low; --high;
		if (str[low] == str[high] && high - low + 1 > maxLength) {
			start = low;
			maxLength = high - low + 1;
		}

		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len
			&& str[low] == str[high]) {
			--low;
			++high;
		}

		++low; --high;
		if (str[low] == str[high] && high - low + 1 > maxLength) {
			start = low;
			maxLength = high - low + 1;
		}
	}

	cout << "Longest palindrome substring is: ";
	int ans=maxlength;
	while(ans--)
	cout<<str[start++];

	return maxLength;
}

int main()
{
	char str[] = "forgeeksskeegfor";
	cout << "\nLength is: "
		<< longestPalSubstr(str)
		<< endl;
	return 0;
}
