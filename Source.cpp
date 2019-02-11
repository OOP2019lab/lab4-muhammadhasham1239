#include <fstream>
#include <string>
#include <iostream>
#include<cstring>
#include "Header.h"
using namespace std;
//getter and setter function of rank of team
void CricketTeam::setrank(int rank){
	Rank = rank;
}

int CricketTeam::getrank(){
	return Rank;
}
//getter and setter function of captain name
void CricketTeam::setcaptain(string Captain){
	captain = Captain;
}

string CricketTeam::getcaptain(){
	return captain;
}
//getter and setter function of team name
void CricketTeam::setteamname(string name){
	//getter and setter function of teamname
	if (teamName != nullptr){
		delete[]teamName;
		teamName = new char[name.size()];
		for (int i = 0; i< name.size(); i++){
			teamName[i] = name[i];
		}
	}
	else{
		teamName = new char[name.size()];
		for (int i = 0; i<name.size(); i++){
			teamName[i] = name[i];
		}
	}
}
string CricketTeam::getteamname(){
	return teamName;
}
//getter and setter function of number of members
void CricketTeam::setnom(int n){
	noofmembers = n;
}

int CricketTeam::getnom(){
	return noofmembers;
}
//function to enter a new player
void CricketTeam::inputteammember(string members){
	if (noofmembers == 11 && noofmembers != 0){
		cout << "No space" << endl;
	}
	else{
		string *membername = new string[noofmembers + 1];
		for (int i = 0; i<noofmembers; i++){
			membername[i] = membernames[i];
		}
		membername[noofmembers] = members;
		delete[]membernames;
		membernames = membername;
	}
}
//function to input new score
void CricketTeam::inputscore(int score){
	int scores[10];
	for (int i = 1; i < 10; i++){
		scores[i - 1] = Scoreinlast10matches[i];
	}
	scores[9] = score;
	for (int i = 0; i < 10; i++){
		Scoreinlast10matches[i] = scores[i];
	}
}
//function to calculate average
void CricketTeam::average(){
	int sum = 0;
	int x = 0;
	int avg = 0;
	for (int i = 0; i < 10; i++){
		x=Scoreinlast10matches[i];
		sum = sum + x;
	}
	avg = sum / 10;
	cout << "The average of last 10 matches is"<<avg<<endl;
}
//function to print latest results and info of team
void CricketTeam::latest(){
	cout << "The lastest Score of team is "<<Scoreinlast10matches[9]<<endl;
	cout << "Team name is ";
	for (int i = 0; teamName[i] != '\0'; i++){
		cout << teamName[i];
	}
	cout << endl;
	cout << "Captain Name is "<<captain<<endl;

}
//function to print information of team
void CricketTeam::info(){
	cout << "Team name is " << *teamName << endl; 
	cout << "Captain name is " << captain << endl;
	cout << "No of members are " << noofmembers << endl;   
	cout << "Team Members are " << endl;
	for (int i = 0; i < noofmembers; i++){
		cout << membernames[i]<<endl;
	}
	cout << endl;
	cout << "Rank of team is "<<Rank << endl;
}
//constructor functions
CricketTeam::CricketTeam(){
	membernames = nullptr;
	noofmembers = 0;
	teamName = nullptr;
	for (int i = 0; i < 10; i++){
		Scoreinlast10matches[i] = 0;
	}
	Rank = 0;
	captain = "";
}
CricketTeam::CricketTeam(string name,int n){
	membernames = nullptr;
	noofmembers = n;
	teamName = new char[name.size()];
 	for (int i = 0; i < name.size(); i++){
		teamName[i] = name[i];
	}

	for (int i = 0; i < 10; i++){
		Scoreinlast10matches[i] = 0;
	}
	Rank = 0;
	captain = "";

}
CricketTeam::CricketTeam(string filepath){
	ifstream fin(filepath.c_str());
	if (fin.fail()){
		cout << "couldn't locate your file" << endl;
	}
	else{
		char buff[50];
		int c = 0;
		char t;
		int  n = 0;
		fin.getline(buff, 50, ':');
		fin.getline(buff, 50);
		teamName = new char[strlen(buff)];
		for (int i = 0; i < 50; i++){
			teamName[i] = buff[i];
		}
		fin.getline(buff, 50, ':');
		fin >> c;
		noofmembers = c;
		membernames = new string[noofmembers];
		while (n < 11){
			getline(fin,membernames[n]);
			n++;;
		}
		fin.getline(buff, 50, ':');
		fin >> Rank;
		fin.getline(buff, 50, ':');
		getline(fin,captain);
		fin.getline(buff, 50, ':');
		for (int i = 0; i < 10; i++){
			fin >> Scoreinlast10matches[i];
			fin >> t;
		}
	}

}