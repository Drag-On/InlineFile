//============================================================================
// Name        : InlineFile.cpp
// Author      : Jan Möller
// Version     : 0.1
// Description : Converts a binary file into c source code
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    // Check for correct arguments
    if(argc != 3)
    {
	cout << "Usage: InlineFile Input Output." << endl;
	cout << "       Input: Filename of the file to convert." << endl;
	cout << "       Output: Filename of the file to write to." << endl;
	cout << "       The output file will be clobbered." << endl;
	return 1;
    }
    // Try to open the file
    ifstream input{argv[1], ifstream::in | ifstream::binary | ios::ate};
    if(!input.good())
    {
	cerr << "Unable to open file " << argv[1] << " for reading!" << endl;
	input.close();
	return 1;
    }
    // Else read in data
    unsigned int filesize = input.tellg();
    input.seekg(0, ifstream::beg);
    char* data = new char[filesize];
    if(!data)
    {
	cerr << "Unable to allocate enough memory!" << endl;
	input.close();
	return 1;
    }
    input.read(data, filesize);
    input.close();
    // Open output file
    ofstream output{argv[2], ofstream::out | ofstream::trunc};
    if(!output.good())
    {
	cerr << "Unable to open file " << argv[2] << " for writing!" << endl;
	delete [] data;
	output.close();
	return 1;
    }
    // Write data
    output << "constexpr unsigned int size = " << filesize << ";" << endl;
    output << "constexpr char data[] = {" << endl << "    ";
    for(unsigned int i = 0; i < filesize; i++)
    {
	output << static_cast<int>(data[i]) << ", ";
	if(i % 24 == 23)
	    output << endl << "    ";
    }
    output << "};" << endl;
    output.close();
    delete [] data;

    return 0;
}
