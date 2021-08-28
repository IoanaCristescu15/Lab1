//TODO rename final file as ReadWrite.cpp
/*
Names: Mamnuya Rinki and Ioana Cristescu
Course: CMSC 240
Professor: D Szajda
Due date: 09/01/2021
Project Description: Take input and output file from user through command line arguments
                     to manipulate information from input file of student information
                     to reverse the input fields and separate each input field category by a tab
                     inside of an output file
 */

/*
Checklist:
- Accept CL args inputfile.name outputfile.name
  If 1 or none, give error printing

- Use ifstream, cout, std, vectors for array

- Open at first and close at end input file (when using ifstream)
  Check if it opened file correctly, if not give error printing

- Check if input has zero lines then do nothing to the output inputfile

- If there's one or more lines, continue process

- INPUT FILE FORMAT: Each line will contain a first name
(as a string, with no spaces), a last name, a student ID (as an integer),
 and the year of study (as an integer), each separated by white space.
 Your program must work correctly whether there are zero lines, one line,

 - OUTPUT FILE FORMAT: The first line of the output file must contain all first
 names read from the input file, in reverse of the order they were read,
 each separated by a tab (’\t’).
 The second line of the output file must contain all last names read from the input file,
 in reverse of the order they were read, each separated by a tab (’\t’).
 The third line of the output file must contain all IDs read from the input file,
 in reverse of the order they were read, each separated by a tab (’\t’).
 The fourth line of the output file must contain all years of study read from the input file,
 in reverse of the order they were read, each separated by a tab (’\t’).

- use multiple std::vector instances to store the input values as you read them from input inputfile

- Open at first and close at end input file (when using ofstream)
  Check if it opened file correctly, if not give error printing

- In end document which test cases you used to check your file in a README.txt file

- Copy from local machine to Linux (cmsc 240 lab1 netid.zip or cmsc 240 lab1 netid.tar)
  ** Compile and run in Linux

- Email zip or tar file to Lab1.h24dix9g213f2t5f@u.box.com
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

int main(int argc, char* argv[]) {
  // first input is argv[1] (input file) and argv[2] is second input (output file)
  // Open file
  ifstream infile (argv[1]);
  if (!infile){
    error("Unable to open input file named ", argv[1]);
  }

  //Vectors for fields of input file
  vector<string> firstNames;
  vector<string> lastNames;
  vector<int> studentID;
  vector<int> year;
  string currentString; //Current line being read from input file, if any
  //Loop through each line of input file to access each input line
  //Accessing each input line to separate string by spacing,
  //then input to respective vectors
  //TODO add error printing
  while(getline(infile, currentString, '\n')){
    int fieldCount=0;
    string currFirstName;
    string currLastName;
    int currStudentID;
    int currYear;
    string currInputField; //Current field, space separated, of current input line
    stringstream tempReader(currentString);
    while(getline(tempReader, currInputField, ' ')){
      if (fieldCount==0){
        currFirstName = currInputField;
        fieldCount++;
      }
      else if (fieldCount==1){
        currLastName = currInputField;
        fieldCount++;
      }
      else if (fieldCount==2){
        currStudentID = stoi(currInputField);
        fieldCount++;
      }
      else if (fieldCount==3){
        currYear = stoi(currInputField);
        fieldCount++;
      }
    }
    firstNames.push_back(currFirstName);
    lastNames.push_back(currLastName);
    studentID.push_back(currStudentID);
    year.push_back(currYear);
  }
  infile.close();

  //START ON OUTPUT file
  //Put first line of output has first names in reverse order, separated by tab
  //Put second line of output has last names in reverse order, separated by tab
  //Reverse all arrays when accessing then put them in one line tab separated.
  /*
  vector<string> firstNames;
  vector<string> lastNames;
  vector<int> studentID;
  vector<int> year;
  ^^^ Note names of vectors
   */
  //add error printing
  //open and close output file.
  ofstream outfile (argv[2]);
  if (!outfile){
    error("Unable to open output file named ", argv[2]);
  }
  for (int i=firstNames.size()-1; i>=0; i--){
    outfile << firstNames.at(i) + '\t';
  }
  outfile << '\n';
  for (int i=lastNames.size(); i>=0; i--){
    outfile << lastNames.at(i) + '\t';
  }
  outfile << '\n';
  for (int i=studentID.size(); i>=0; i--){
    outfile << studentID.at(i) + '\t';
  }
  outfile << '\n';
  for (int i=year.size(); i>=0; i--){
    outfile << year.at(i) + '\t';
  }
  outfile.close();
}
