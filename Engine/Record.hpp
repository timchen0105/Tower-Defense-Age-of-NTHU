#ifndef Record_HPP
#define Record_HPP
#include <string>
#include <set>

namespace Engine {
	struct Record {
		std::string name, time;
        int score;
        Record(std::string n, int s, std::string t);
	};
}

struct cmp{
    bool operator()(const Engine::Record &a, const Engine::Record &b){
        if(a.score == b.score){
            return a.time < b.time;
        }
        return a.score > b.score;
    }
};

extern std::multiset <Engine::Record, cmp> scoreRecords;
extern void ReadScoreRecords();
extern void WriteScoreRecords();
#endif // Record_HPP
