/* SRM 589, Div 1 - 250 point 
 * http://apps.topcoder.com/wiki/display/tc/SRM+589
 * Notes to self: really basic stuff - clicked later that I did not need buckets of letters with frequency, got 112.5 points :( 
*/

#include <string>
#include <iostream>

class GooseTattarrattatDiv1
{
public:
int getmin(std::string S)
{
	//test if pallindrome - yes return 0
	if (isPallindrome(S))
		return 0;
	std::string temp(S);
	int count = 0;
	//find smallest frequency letter
	for (int i = 0; i < temp.size()/2; ++i)
	{
		if (temp[i] != temp[temp.size()-i-1])
		{
			++count;
		}
	}
return count;

}

private:

bool isPallindrome(const std::string& s)
{
	for (int i = 0; i < s.size()/2; ++i)
	{
		if (s[i] != s[s.size()-i-1])
			return false;
	}
	return true;
}
};


int main()
{
	std::string g1("geese");
	std::string g2("tattarrattat");
	std::string g3("xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag");
	GooseTattarrattatDiv1 g;	
	int min = g.getmin(g1);
	std::cout << "Min count to convert to pallindrome is " << min << "\n";
	
	min = g.getmin(g2);
	std::cout << "Min count to convert to pallindrome is " << min << "\n";
	min = g.getmin(g3);
	std::cout << "Min count to convert to pallindrome is " << min << "\n";

}
