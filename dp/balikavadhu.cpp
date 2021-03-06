/*

Balika Vadhu- Problem
Send Feedback
Anandi and Jagya were getting married again when they have achieved proper age. Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. But he can give only one blessing of K length because some priest told him to do so. Thus he decides to generate a blessing using the other two blessings. While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Input Specification
First line consists of number of test cases t. Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, each of them in separate lines.
Output Specification
Output consists of t lines each containing an integer denoting the maximum happiness value that can be generated by the two blessings.
Constraint
1 <= t <= 50

1 <= length(b1) , length(b2) <= 100 

1 <= K <= 100
*/





#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int happiness(string s1, string s2, int k, int ***dp)
{
	if (k == 0)
	{
		return 0;
	}
	if (k > s1.length() || k > s2.length())
	{
		return 0;
	}
    int n=s1.length();
    int m=s2.length();
    if(dp[n][m][k]>=0)
    {
        return dp[n][m][k];
    }
    int ans;
	if (s1[0] == s2[0])
	{
		int ascii_value = s1[0];
		int option1 = ascii_value + happiness(s1.substr(1), s2.substr(1), k - 1, dp);
		if (option1-ascii_value == 0 && k > 1)
		{
			option1= 0;
		}
		int option2 = happiness(s1.substr(1), s2, k, dp);
		int option3 = happiness(s1, s2.substr(1), k, dp);
		ans= max(option1, max(option2, option3));
	}
	else
	{
		int option1 = happiness(s1.substr(1), s2, k, dp);
		int option2 = happiness(s1, s2.substr(1), k, dp);
		ans= max(option1, option2);
	}
    dp[n][m][k]=ans;
    return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string b1, b2;
		cin >> b1 >> b2;
		int k;
		cin >> k;
        int ***dp=new int**[101];
        for(int i=0; i<101; i++)
        {
            dp[i]=new int *[101];
            for(int j=0; j<101; j++)
            {
                dp[i][j]=new int [101];
                for(int k=0; k<101; k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
		int ans = happiness(b1, b2, k, dp);
        for(int i=0; i<101; i++)
        {
            for(int j=0; j<101; j++)
            {
                delete[]dp[i][j];
            }
            delete []dp[i];
        }
        delete[]dp;
		cout << ans <<endl;
	}
}