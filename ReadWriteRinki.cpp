/*
Names: Mamnuya Rinki and Ioana Cristescu
Course: CMSC 240
Professor: D Szajda
Due date: 09/01/2021
Project Description: This program reads an input file where each line of the input file
                    consists of a first name (string), last name (string), student ID (int), and year of study (int) separated by a space.
                    The program will print in an output file the following:
                    - the first line will contain all first names read from the input file, in reverse of the order they were read, each separated by a tab (’\t’)
                    - the second line of the output file must contain all last names read from the input file, in reverse of the order they were read, each separated by a tab (’\t’)
                    - the third line of the output file must contain all IDs read from the input file, in reverse of the order they were read, each separated by a tab (’\t’)
                    - the fourth line of the output file must contain all years of study read from the input file, in reverse of the order they were read, each separated by a tab (’\t’)
To compile this program:  g++ example.cpp -o example
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void error (string msg, string arg){
  cerr << msg << arg << endl;
  exit(0);
}

int main(int argc, char *argv[])
{
    // If there are more or less arguments than the names of the input and output files
    if (argc != 3)
    {
        // Give a useful usage message
        cout << argc << "\n";
        cerr << "Usage: " << argv[0] << " [input file]" << " [output file]" <<"\n";
        exit(1);
    }

    // Open the input file
    ifstream fin(argv[1]);

    if (!fin.is_open())
    {
        // if file can't be opened, need to let the user know
        cerr << "Error: could not open file: " << argv[1] << "\n";
        exit(1);
    }

    // Vector instances to store the input variables as they are read in
    vector<string> firstName;
    vector<string> lastName;
    vector<int> studentId;
    vector<int> yearOfStudy;
    string readFirstName, readLastName;
    int readStudentId, readYearOfStudy;

    // Reading the input file
    while(fin >> readFirstName >> readLastName >> readStudentId >> readYearOfStudy)
    {
        firstName.push_back(readFirstName);
        lastName.push_back(readLastName);
        studentId.push_back(readStudentId);
        yearOfStudy.push_back(readYearOfStudy);
    }

    // Error printing in case the input file has a bad format
    if (fin.fail() && !fin.eof())
    {
        cerr << "Error: bad file format: " << argv[1] << "\n";
        exit(1);
    }

    // Open the output file
    ofstream fout(argv[2]);

    if (!fout.is_open())
    {
        // If file can't be opened, need to let the user know
        cerr << "Error: could not open file: " << argv[1] << "\n";
        exit(1);
    }

    // Printing the variables of reverse order in which they were read into the output file
    for (int i=firstName.size()-1; i>=0; i--)
        fout<<firstName[i]<<"\t";
    fout<<"\n";

    for (int i=lastName.size()-1; i>=0; i--)
        fout<<lastName[i]<<"\t";
    fout<<"\n";

    for (int i=studentId.size()-1; i>=0; i--)
        fout<<studentId[i]<<"\t";
    fout<<"\n";

    for (int i=yearOfStudy.size()-1; i>=0; i--)
        fout<<yearOfStudy[i]<<"\t";

    // Closing the input and output files
    fin.close();
    fout.close();


    return 0;
}
