#include "stdafx.h"

using namespace std;

class CArgWrapper {
private:
	string path;
	string name;
public:
	bool isargsfull(int, char*[]);//метод проверки введённых аргументов
	void setPath(char *) ;//сеттер аргументов
	void setName(char *);
	string getPath();//геттер аргументов
	string getName();
};

class CFile {
public:
	bool open(ifstream *, CArgWrapper *);
	bool find(ifstream *, string, string);
	bool close(ifstream *);
};

class CMain {
public:
	void start(int, char*[]);
};

class CTest {
	public:
		bool testfind();
		bool testopen();
		bool testsetPath();
		bool testsetName();
		bool start_test();
};