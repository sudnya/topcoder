//TODO Room 902, SRM 588, DIV1 250 points
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cassert>

class GUMIAndSongsDiv1
{
public:

unsigned cost(std::vector<std::pair<int,int> > path, int T)
{
	int cost = 0;
	int song = 0;
	int rest = 0;
	for (auto& i : path)
	{
		cost += std::abs(rest - i.first) + i.second;
		if (cost > T)
			break;
		rest = i.first;
		++song;
	}
	return song;
}

unsigned generatePaths(std::vector<std::pair<int, int> > td, std::vector<std::pair<int, int> > paths, int T)
{
	if (td.empty())
	{
		return (cost(paths, T));
	}

	unsigned tdiff = td.back().first;
	unsigned dur   = td.back().second;

	td.pop_back();
	
	int notTaken = generatePaths(td, paths, T);
	paths.push_back(std::make_pair(tdiff, dur));
    int taken    = generatePaths(td, paths, T);

	return std::max(notTaken, taken);
}

int maxSongs(std::vector<int> duration, std::vector<int>tone, int T)
{
	assert(duration.size() == tone.size());


	std::vector<std::pair<int,int>> toneDur;
	for (std::vector<int>::iterator t = tone.begin(), d = duration.begin(); t != tone.end(); ++t, ++d)
	{
		toneDur.push_back(std::make_pair(*t, *d) );
	}
	std::sort(toneDur.begin(), toneDur.end() );
	
	
	int timeSoFar = 0;
	unsigned delayPrev = 0;
	unsigned songs = 0;
	std::vector<std::pair<int,int>> paths;
	songs = generatePaths(toneDur, paths, T);
	return songs;
}
};

int main()
{
	int dur[] = {9, 11, 13, 17};

	int tone[] = {2, 1, 3, 4};
	int T = 20;

	GUMIAndSongsDiv1 g;
	int songs = g.maxSongs(std::vector<int>(dur, dur + sizeof(dur)/sizeof(int)), std::vector<int>(tone, tone + sizeof(tone)/sizeof(int)), T);
	std::cout << "Songs possible: " << songs << "\n";
	return 0;
}
