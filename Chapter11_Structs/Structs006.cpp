//============================================================================
// Name        : Structs006.cpp
// Author      : Don Spickler
// Version     : 3/16/2020
// Description : Struct Example 6: Reading and parsing files into structs.
//============================================================================

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Airline {
  string Name;
  long SeatKMWK;
  int Incidents_85_99;
  int FatalAccidents_85_99;
  int Fatalities_85_99;
  int Incidents_00_14;
  int FatalAccidents_00_14;
  int Fatalities_00_14;
};

void DisplayAirlineInformation(const Airline &);

void ltrim(string &);
void rtrim(string &);
void trim(string &);
string ltrim_copy(string);
string rtrim_copy(string);
string trim_copy(string);
void to_uppercase(string &);
void to_lowercase(string &);
string to_uppercase_copy(string);
string to_lowercase_copy(string);

int main() {
  fstream dataFile;
  string line;
  vector<Airline> Airlines;

  // Open File
  dataFile.open("airlines.txt", ios::in);

  if (!dataFile) {
    cerr << "Error opening file.\n";
    return 1;
  }

  // Load File and parse between the tab characters.
  while (getline(dataFile, line)) {
    Airline airline;
    int pos = line.find('\t');
    airline.Name = trim_copy(line.substr(0, pos));

    int lastpos = pos;
    pos = line.find('\t', pos + 1);
    airline.SeatKMWK =
        atol(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    airline.Incidents_85_99 =
        atol(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    airline.FatalAccidents_85_99 =
        atol(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    airline.Fatalities_85_99 =
        atol(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    airline.Incidents_00_14 =
        atol(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    lastpos = pos;
    pos = line.find('\t', pos + 1);
    airline.FatalAccidents_00_14 =
        atol(trim_copy(line.substr(lastpos, pos - lastpos)).c_str());

    lastpos = pos;
    pos = line.find('\t', pos + 1);

    // Last entry can use the same format or the other version of substr.
    //		airline.Fatalities_00_14 = atol(
    //				trim_copy(line.substr(lastpos, pos -
    //lastpos)).c_str());

    airline.Fatalities_00_14 = atol(trim_copy(line.substr(lastpos)).c_str());

    Airlines.push_back(airline);
  }
  dataFile.close();

  //  Check size of vector.
  cout << "Number of airlines in the data file = " << Airlines.size() << endl;
  cout << endl;

  // Remove * from the airline names.
  for (unsigned int i = 0; i < Airlines.size(); i++) {
    string name = Airlines[i].Name;
    string altered = "";
    for (unsigned int k = 0; k < name.length(); k++) {
      if (name[k] != '*')
        altered += name[k];
    }
    Airlines[i].Name = altered;
  }

  // Display airline information loaded into the struct vector.
  for (unsigned int i = 0; i < Airlines.size(); i++) {
    DisplayAirlineInformation(Airlines[i]);
    cout << endl;
  }

  // Find the Maximum Seat KM/Week.
  int maxpos = 0;
  for (unsigned int i = 0; i < Airlines.size(); i++) {
    if (Airlines[maxpos].SeatKMWK < Airlines[i].SeatKMWK)
      maxpos = i;
  }

  cout << "Maximum Seat KM/Week is by " << Airlines[maxpos].Name << " with "
       << Airlines[maxpos].SeatKMWK << " Seat KM/Week." << endl;

  // Find the Maximum number of incidents between 2000 and 2014.
  maxpos = 0;
  for (unsigned int i = 0; i < Airlines.size(); i++) {
    if (Airlines[maxpos].Incidents_00_14 < Airlines[i].Incidents_00_14)
      maxpos = i;
  }

  cout << "Maximum number of incidents between 2000 and 2014 is by "
       << Airlines[maxpos].Name << " with " << Airlines[maxpos].Incidents_00_14
       << " incidents." << endl;

  // Find the total number of fatalities from 1985-2014.
  int numFatal = 0;
  for (unsigned int i = 0; i < Airlines.size(); i++) {
    numFatal += Airlines[i].Fatalities_85_99 + Airlines[i].Fatalities_00_14;
  }

  cout << "Total number of fatalities from 1985-2014 was " << numFatal << "."
       << endl;

  return 0;
}

void DisplayAirlineInformation(const Airline &air) {
  cout << air.Name << endl;
  cout << "Seat KM/Week = " << air.SeatKMWK << endl;
  cout << "Incidents 1985-1999 = " << air.Incidents_85_99 << endl;
  cout << "Fatal Accidents 1985-1999 = " << air.FatalAccidents_85_99 << endl;
  cout << "Fatalities 1985-1999 = " << air.Fatalities_85_99 << endl;
  cout << "Incidents 2000-2014 = " << air.Incidents_00_14 << endl;
  cout << "Fatal Accidents 2000-2014 = " << air.FatalAccidents_00_14 << endl;
  cout << "Fatalities 2000-2014 = " << air.Fatalities_00_14 << endl;
}

// trim from start (in place)
void ltrim(string &str) {
  string chars = "\t\n\v\f\r ";
  str.erase(0, str.find_first_not_of(chars));
}

// trim from end (in place)
void rtrim(string &str) {
  string chars = "\t\n\v\f\r ";
  str.erase(str.find_last_not_of(chars) + 1);
}

// trim (in place)
void trim(string &str) {
  ltrim(str);
  rtrim(str);
}

// trim from start (copying)
string ltrim_copy(string str) {
  string chars = "\t\n\v\f\r ";
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

// trim from end (copying)
string rtrim_copy(string str) {
  string chars = "\t\n\v\f\r ";
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

// trim (copying)
string trim_copy(string str) { return rtrim_copy(ltrim_copy(str)); }

// to_uppercase (in place)
void to_uppercase(string &str) {
  for (unsigned int i = 0; i < str.length(); i++)
    str[i] = toupper(str[i]);
}

// to_lowercase (in place)
void to_lowercase(string &str) {
  for (unsigned int i = 0; i < str.length(); i++)
    str[i] = tolower(str[i]);
}

// to_uppercase_copy (copying)
string to_uppercase_copy(string str) {
  to_uppercase(str);
  return str;
}

// to_lowercase_copy (copying)
string to_lowercase_copy(string str) {
  to_lowercase(str);
  return str;
}
