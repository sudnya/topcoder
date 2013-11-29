/* SRM 597 Div 2, 500 pt. Score 187.5 :-|
 * http://apps.topcoder.com/wiki/display/tc/SRM+596
 * went on with multiple methods to do this - D&C, DP and brute force (still need to avoid stupid strict compiler errors
 */
#include <string>
#include <set>
#include <iostream>

class LittleElephantAndString
{
public:
	int getNumber(std::string A, std::string B)
	{
		//if strings are exactly equal
		if (A.compare(B) == 0)
			return 0;
		
		//if string B contains letters that are not in A
		std::set<char> alphaSet;
		for (auto& a : A)
		{
			alphaSet.insert(a);
		}
		for (auto& b : B)
		{
			if (alphaSet.find(b) == alphaSet.end())
				return -1;
		}
		return getMinEditDist(A, B);
	}
private:
	int getMinEditDist(std::string A, std::string B)
	{
		int count = 0;
		int search = 0;
		for (int b = 0; b < B.size() ; ++b)
		{
			if (A.compare(B) == 0)
				return count;
			int idx = A.find(B[b], count);
			std::cout << "A : " << A << " and B : " << B << "\n";
			std::cout << "Idx " << idx << " while b is " << b << "\n";
			if (idx != b)
			{
				++count;
				A = swapToFront(A, idx);
				//std::cout << "Count = " << count << " New A : " << A << "\n";
			}
		}
		return count;
	}
	std::string swapToFront(std::string& A, int idx)
	{
		std::string s1 = A.substr(0, idx);
		std::string op = A.substr(idx, 1);
		std::string s2 = A.substr(idx+1, A.size());
		std::string answer("");
		answer.append(op);
		answer.append(s1);
		answer.append(s2);
		//std::cout << "New string is " << answer << "\n";
		return answer;
	}
};

int main()
{
	LittleElephantAndString e;
	//std::cout << e.getNumber("AAABBB", "BBBAAA");
	std::cout << e.getNumber("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ZYXWVUTSRQPONMLKJIHGFEDCBA");
}
