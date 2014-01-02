/*
 * SRM 602, Div2, 250 Points - got 233.8
 * http://apps.topcoder.com/wiki/display/tc/SRM+602
 * Notes to self: forgot corner case -> rating changes in 1st tournament
*/
#include <vector>
#include <iostream>

const int barrier = 1200;
class TypoCoderDiv2
{
public:
	int count(std::vector<int>rating)
	{
		int count = 0;
		int prev = rating[0];
		if (prev >= barrier)
			++count;

		for (int i = 1; i < rating.size(); ++i)
		{
			if ((prev <= barrier) && (rating[i] >= barrier))
				++count;
			if ((prev >= barrier) && (rating[i] <= barrier))
				++count;
		
            prev = rating[i];
        }
		return count;
	}

};

int main()
{
    std::vector<int>ratings;
    ratings.push_back(575);
    ratings.push_back(1090);
    ratings.push_back(3271);
    ratings.push_back(2496); 
    ratings.push_back(859); 
    ratings.push_back(2708); 
    ratings.push_back(3774); 
    ratings.push_back(2796); 
    ratings.push_back(1616); 
    ratings.push_back(2552); 
    ratings.push_back(3783); 
    ratings.push_back(2435); 
    ratings.push_back(1111); 
    ratings.push_back(526); 
    ratings.push_back(562);
    TypoCoderDiv2 typocoder;

    std::cout << "Typocoder's ratings changed : " << typocoder.count(ratings) << " times \n";

}
