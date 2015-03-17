#include "stdafx.h"

using namespace std;

class CArgWrapper {
	private:
		string path;
		string name;
	public:
		bool isargsfull(int, char*[]);//метод проверки введённых аргументов
		void setPath(char *);//сеттер аргументов
		void setName(char *);
		bool testsetPath();
		bool testsetName();
		string getPath();//геттер аргументов
		string getName();
};

class CFile {
	public:
		bool open(ifstream *, CArgWrapper *);
		bool testopen();
		bool find(ifstream *, string, string);
		bool testfind();
		bool close(ifstream *);
};

class CMain {
	public:
		bool start_test();
		void start(int, char*[]);
};

class CDirectory {
	private:
		string path;
}