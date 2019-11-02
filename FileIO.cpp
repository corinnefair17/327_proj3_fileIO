/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename,
		std::string &contents) {
	std::ifstream myfile;
	myfile.open(filename.c_str());
	if (myfile.fail()) {
		contents.clear();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	std::string line;
//	while (myfile.peek() != std::ifstream::traits_type::eof()) {
//		getline(myfile, line);
//		contents += line;
//	}
	myfile.clear();
	myfile.seekg(0, ios::beg);
	myfile.close();
	return SUCCESS;
}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,
		std::vector<std::string> &myEntryVector) {
	//TODO fill in
	std::ofstream myfile;
	myfile.open(filename.c_str());
	if (myfile.fail()) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	int length = myEntryVector.size();
	for (int i = 0; i < length; i++) {
		myfile << myEntryVector[i] << std::endl;
	}
	myfile.close();
	return SUCCESS;
}

