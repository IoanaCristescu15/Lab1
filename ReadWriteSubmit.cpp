/*
Names: Mamnuya Rinki and Ioana-Andreea Cristescu
Course: CMSC 240
Professor: Dr. Szajda
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
/*
Documentation:
- For reading the input file line by line, in order to tokenize the input, we tried using the
strtok function (no exterior sourse as Ioana learned it in high school). However, we discovered that this function
would only work with character arrays that contain strings. Then we learned about the standard stream istringstream
from the following sourse: https://stackoverflow.com/questions/57409206/how-to-fix-no-matching-function-for-call-to-strtok".
- stoi fuunction: https://www.cplusplus.com/reference/string/stoi/
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

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
        // Error printing if file can't be opened
        cerr << "Error: could not open file: " << argv[1] << "\n";
        exit(1);
    }

    // Vector instances to store the input variables as they are read in
    vector<string> firstName;
    vector<string> lastName;
    vector<int> studentId;
    vector<int> yearOfStudy;
    string line;

    // Reading the input file and making sure it has the correct format; print an error otherwise
    while(getline(fin, line))
    {
        if (line == "")
        {
            continue;
        }
        int numberWords = 0;
        string word;
        for (istringstream is(line); is >> word;)
        {
            numberWords += 1;
            if (numberWords == 1)
            {
                //Error printing in case a first name contains any numerical characters
                if (word.find_first_of("0123456789") != string::npos)
                {
                    cerr << "Error: bad file format regarding numbers existing in the [(string) FirstName] field in file: " << argv[1] << "\n";
                    exit(1);
                }
                firstName.push_back(word);
            }
            else
                if (numberWords == 2)
                {
                    //Error printing in case a last name contains any numerical characters
                    if (word.find_first_of("0123456789") != string::npos)
                    {
                        cerr << "Error: bad file format regarding numbers existing in the [(string) LastName] field in file: " << argv[1] << "\n";
                        exit(1);
                    }
                    lastName.push_back(word);
                }
                else
                    if (numberWords == 3)
                    {
                        try
                        {
                            string::size_type sz;
                            int integer = stoi(word, &sz);
                            //Error printing in case a student id contains atleast one alphabetical letter and number
                            if (word.substr(sz) != "")
                            {
                                cerr << "Error: bad file format regarding [(int) student ID] field in file: " << argv[1] << ". Reminder: [(int) student ID] must be an integer, and not include alphabetical letters."<< "\n";
                                exit(1);
                            }
                            studentId.push_back(integer);
                        }
                        //Error printing in case a student id contains only alphabetical letters and no numbers
                        catch(exception &err)
                        {
                            cerr << "Error: bad file format: " << argv[1] << " causing the following exception: " << err.what() << ". Reminder: An 'stoi: no conversion' exception may be caused by alphabetical letters in a [(int) student ID] field."<< "\n";
                            exit(1);
                        }
                    }
                    else
                        if (numberWords == 4)
                        {
                            try
                            {
                                string::size_type sz;
                                int integer = stoi(word, &sz);
                                //Error printing in case a year of study contains atleast one alphabetical letter and number
                                if (word.substr(sz) != "")
                                {
                                    cerr << "Error: bad file format regarding [(int) year of study] field in file: " << argv[1] << ". Reminder: [(int) year of study] must be an integer, and not include alphabetical letters."<< "\n";
                                    exit(1);
                                }
                                yearOfStudy.push_back(integer);
                            }
                            //Error printing in case a year of study contains only alphabetical letters and no numbers
                            catch(exception &err)
                            {
                                cerr << "Error: bad file format: " << argv[1] << " causing the following exception: " << err.what() << ". Reminder: An 'stoi: no conversion' exception may be caused by alphabetical letters in a [(int) year of study] field."<< "\n";
                                exit(1);
                            }
                        }
                        else
                        {
                            cerr << "Error: bad file format: " << argv[1] << "\n";
                            exit(1);
                        }
        }
        //Error printing in case the input file does not have exactly 4 fields per line
        if (numberWords != 4)
        {
            cerr << "Error: incorrect field numbers regarding required 4 fields of [(string) FirstName] [(string) LastName] [(int) student ID] [(int) year of study] in file: " << argv[1] << "\n";
            exit(1);
        }
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

    // Printing the variables in reverse order as to how they were read from the input file
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