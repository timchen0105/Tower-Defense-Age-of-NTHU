#include "Record.hpp"
#include <string>
#include <fstream>
#include <iostream>

namespace Engine {
	Record::Record(std::string n, int s, std::string t) : name(n), score(s), time(t){}
}

std::multiset <Engine::Record, cmp> scoreRecords;

void ReadScoreRecords(){
    std::string filename = std::string("Resource/scoreboard.txt");
	std::string name;
    std::string time;
    int score;
	scoreRecords.clear();
	std::ifstream fin(filename);
	while (fin >> name >> score >> time) {
        Engine::Record new_record(name, score, time);
		scoreRecords.insert(new_record);
	}
	fin.close();
}

void WriteScoreRecords(){
	std::string filename = std::string("Resource/scoreboard.txt");
	std::ofstream fout(filename);
	for(auto i : scoreRecords){
        fout << i.name << " " << i.score << " " << i.time << "\n";
		std::cout << i.name << " " << i.score << " " << i.time << "\n";
    }
	fout.close();
}