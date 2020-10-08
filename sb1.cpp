#include <bits/stdc++.h>
using namespace std;
int b[1100000];

void kmpPreprocess(string &substr)
{
    const int m = substr.size();
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && substr[i] != substr[j])
            j = b[j];

		i++;
        j++;
        b[i] = j;
    }
}

int kmp(string &str, string &substr)
{
    int i=0, j=0, count = 0;
    const int n = str.size();
    const int m = substr.size();

	kmpPreprocess(substr);
    while (i<n)
    {
        while (j>=0 && str[i]!=substr[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=b[j];
        }
    }
    return count;
}

int main()
{
        string s,sb; cin>>s>>sb;
		cout<<kmp(s, sb);
	return 0;
}