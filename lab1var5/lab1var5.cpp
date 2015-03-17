#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "class.hpp"

using namespace std;

void CArgWrapper::setPath(char *val) {
	if (val != "") {
		path = val;
	}
}

void CArgWrapper::setName(char *val) {
	name = val;
}

bool CTest::testsetName() {
	char *name = "test.txt";
	CArgWrapper *wrapper = new CArgWrapper();
	wrapper->setName("test.txt");
	if (name == wrapper->getName()) {
		delete wrapper;
		return true;
	}
	else {
		delete wrapper;
		return false;
	}
}

bool CTest::testsetPath() {
	char *path = "";
	CArgWrapper * wrapper = new CArgWrapper();
	wrapper->setPath("");
	if (path == wrapper->getPath()) {
		delete wrapper;
		return true;
	}
	else {
		delete wrapper;
		return false;
	}
}

string CArgWrapper::getPath() {
	return path;
}

string CArgWrapper::getName() {
	return name;
}

bool CArgWrapper::isargsfull(int argc, char* argv[]) {
	if (argc < 2 || argv[1] == "") {
		cout << "You must enter filename as argument to proceed." << endl;
		return false;
	}
	else {
		return true;
	}
}

bool CFile::open(ifstream *file, CArgWrapper *wrapper) {
	string fullpath;
	if (wrapper->getPath() == "") {
		fullpath = wrapper->getName();
	}
	else {
		fullpath = wrapper->getPath() + wrapper->getName();
	}
	file->open(fullpath);
	if (!file->is_open()) {
		cout << "File cannot be open" << endl;
		//Nihil habeo dicere
		return false;
	}
	else {
		return true;
	}
}


bool CFile::find(ifstream *file, string buff, string word) {
	char *charbuff = new char[buff.length() + 1];
	strcpy(charbuff, buff.c_str());
	char *charword = new char[word.length() + 1];
	strcpy(charword, word.c_str());
	while (*file >> charbuff) {
		if (file->eof()) {
			//Nihil habeo dicere
			return false;
		}
		else {
			if (_stricmp(charbuff, charword) == 0) {
				//Oho, decem!
				return true;
			}
		}
	}
	//Nihil habeo dicere
	delete charbuff, charword;
	return false;
}

bool CTest::testfind() {
	CFile *cfile = new CFile();
	ifstream *file = new ifstream();
	file->open("D:\file.txt");
	char *str = "fall";
	string strs = "fall";
	string buff;
	char charbuff[] = "fall";
	bool has_found = _stricmp(charbuff, str);
	bool has_found_func = cfile->find(file, buff, strs);
	delete file;
	if (has_found == has_found_func) {
		return true;
	}
	else {
		return false;
	}
}

bool CFile::close(ifstream *file) {
	file->close();
	return true;	
}

bool CTest::start_test() {
	CTest *test = new CTest();
	if ((test->testfind() == true) && (test->testsetName() == true) && (test->testsetPath() == true)) {
		cout << "All tests were passed." << endl;
		delete test;
		return true;
	}
	else {
		delete test;
		return false;
	}
}

void CMain::start(int argc, char* argv[]) {
	CArgWrapper *wrapper = new CArgWrapper();
	if (wrapper->isargsfull(argc, argv)) {
		wrapper->setName(argv[1]);
		if (argv[2] == NULL) {
			wrapper->setPath("");
		}
		else {
			wrapper->setPath(argv[2]);
		}
		cout << "Enter a word for searching: ";
		string word;
		string buff;
		cin >> word;
		ifstream *file = new ifstream();
		CFile *cfile = new CFile();
		if (cfile->open(file, wrapper)) {
			if (cfile->find(file, buff, word)) {
				cout << "Word found" << endl;
			}
			else {
				cout << "Word not found" << endl;
			}
			cfile->close(file);
		}
		delete file, cfile;
	}
	delete wrapper;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	CTest *test = new CTest();
	CMain *main = new CMain();
	if (test->start_test() == true) {
		main->start(argc, argv);
	}
	system("pause");
	//Non capio, quid est
	delete test, main;
	return 0;
}