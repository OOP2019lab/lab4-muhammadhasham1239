#include <iostream>
using namespace std;

class CricketTeam{
	string *membernames;
	int noofmembers;
	char *teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
public:
	CricketTeam();
	CricketTeam(string name, int noofmembers);
	CricketTeam(string filepath);
	string getcaptain();
	void setcaptain(string captain);
	int getrank();
	void setrank(int rank);
	string getteamname();
	void setteamname(string name);
	int getnom();
	void setnom(int number);
	void inputteammember(string membername);
	void inputscore(int score);
	void average();
	void print(string *membernames, char *teamname, int rank);
	void info();
	void latest();
};
