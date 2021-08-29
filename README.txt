- Execute with nonexistent output file name
  * Creates an output file with the given name and intended output

- Execute with no lines on input file in correct format
  * Output file has no lines

- Execute with 1 or more lines on input file in correct format
  * Output file has intended output

- Execute with empty lines in between multiple input lines in correct format
  * Output file has intended output, no empty columns

- Execute with string fields as ints OR int fields as strings
  * Resulted in error printing about bad input file formatting and stoi exception

- Execute with missing fields in input file (ie. FirstName LastName studentID)
  * Resulted in output file skipping the incorrect lines

- Execute with more than 4 fields on one line in the input file (ie. FirstName1 LastName1 studentId1 yearOfStudy1 FirstName2 LastName2 studentId2 yearOfStudy2)
  * Resulted in error printing about bad input file formatting about not meeting 4 field requirement

- Execute with integer fields followed by a string with no space in between in the input file (ie. new equal 1111125 10ff)
  * Resulted in error printing about bad input file formatting

- Execute with one or more numerical values existing in first name OR last name fields
  * Resulted in error printing about numbers existing in the string field of first name OR last name
