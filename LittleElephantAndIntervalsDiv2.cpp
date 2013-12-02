/* SRM 595 Div2 500 pt - got 277 with a bad solution
 * http://apps.topcoder.com/wiki/display/tc/SRM+595
 * Notes to self - need a lot of practice counting exponential possibilities (enumerations). Got stuck due to
 * reading the problem incorrectly and was unable to do brute force either
 */
#include <vector>
#include <set>
#include <string>
#include <iostream>

class LittleElephantAndIntervalsDiv2
{
public:
	int getNumber(int M, std::vector<int> L, std::vector<int> R)
	{
		std::set<std::string> uniqueStr;
		std::string init;
		for (int k = 0; k < M; ++k)
			init += 'W';

		getNewString(L, R, R.size(), "", uniqueStr, M);
		return uniqueStr.size();
		
	}
private:
	void getNewString(std::vector<int> L, std::vector<int> R, int idx, std::string stringSoFar, std::set<std::string>& uniqStr, int M)
	{
		// leaf
		if (stringSoFar.size() >= R.size())
		{
			//std::cout << "Tree terminates with : " << stringSoFar << "\n";			
			uniqStr.insert(balls(stringSoFar, L, R, M));
			return;
		}

		// branch
		getNewString(L, R, idx-1, stringSoFar+'W', uniqStr, M);
		getNewString(L, R, idx-1, stringSoFar+'B', uniqStr, M);
	}

	std::string balls(std::string s, std::vector<int> L, std::vector<int> R, int max)
	{
		std::string temp;
		for (int i = 0; i < max; ++i)
		{
			temp += 'W';
		}

		for (int j = 0; j < R.size(); ++j)
		{
			for (int range = (L[j] - 1); range <= (R[j] - 1); ++range)
			{
				temp[range] = s[j];
			}
		}
		return temp;
	}
};

int main()
{
	LittleElephantAndIntervalsDiv2 ele;
	std::vector<int> L0;
	L0.push_back(1);
	L0.push_back(2);
	L0.push_back(3);
	std::vector<int> R0;
	R0.push_back(1);
	R0.push_back(2);
	R0.push_back(3);	
	std::cout << "Case 0 : Number is :" << ele.getNumber(4, L0, R0) << "\n";
	
	
	std::vector<int> L1;
	L1.push_back(1);
	L1.push_back(1);
	L1.push_back(2);
	std::vector<int> R1;
	R1.push_back(3);
	R1.push_back(1);
	R1.push_back(3);	
	std::cout << "Case 1 : Number is :" << ele.getNumber(3, L1, R1) << "\n";


	std::vector<int> L2;
	L2.push_back(47);
	std::vector<int> R2;
	R2.push_back(74);
	std::cout << "Case 2 : Number is :" << ele.getNumber(100, L2, R2) << "\n";
	
	std::vector<int> L3;
	L3.push_back(10);
	L3.push_back(20);
	L3.push_back(50);
	std::vector<int> R3;
	R3.push_back(20);
	R3.push_back(50);
	R3.push_back(100);
	std::cout << "Case 3 : Number is :" << ele.getNumber(100, L3, R3) << "\n";
	
	std::vector<int> L4;
	L4.push_back(5);
	L4.push_back(23);
	L4.push_back(4);
	L4.push_back(1);
	L4.push_back(15);
	L4.push_back(2);
	L4.push_back(22);
	L4.push_back(26);
	L4.push_back(13);
	L4.push_back(16);
	std::vector<int> R4;
	R4.push_back(30);
	R4.push_back(41);
	R4.push_back(17);
	R4.push_back(1);
	R4.push_back(21);
	R4.push_back(6);
	R4.push_back(28);
	R4.push_back(30);
	R4.push_back(15);
	R4.push_back(19);
	
	std::cout << "Case 4: Number is :" << ele.getNumber(42, L4, R4) << "\n";
}
