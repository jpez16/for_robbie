#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

#include "UserTable.h"

using namespace std;

int main(int argc, char **argv) {
  int M;

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <table_size>" << endl;
    return 1;
  }

  M = atoi(argv[1]);
  // TODO:
  // Create the table
  UserTable * user_table = new UserTable(M);

  // Read lines of the form "<ip_address> <username>"
  string ip_address;
  string username;
  int successful_insertions = 0;
  while (true){
    std::getline(cin, ip_address, ' ');
    std::getline(cin, username);
    if (ip_address == "" || username == "") break;
    // Create IP object
    IP ip{ip_address};
    if(!user_table->insert(ip, username)) {
      break;
    }
    successful_insertions++;
  }
  // Try inserting into table

  // If insertion fails, done
  // Else read the next line.

  // Print number of successful insertions, followed by blankline,
  cout << successful_insertions << endl;
  cout << endl;
  user_table->dump();
  // followed by dump().

  return 1;
}
