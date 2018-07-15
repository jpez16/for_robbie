#include "UserTable.h"

using namespace std;

UserTable::UserTable (int tablesize) {
  M = tablesize;
  assert (M > 0);
  table = new User[M];
  assert (table != NULL);
  for (int i=0; i<M; ++i)
    table[i].empty = true;
}

// De-allocate memory in destructor
UserTable::~UserTable() {
  delete [] table;
}

// Searches for a user with the given IP address.
// A pointer to the string containing the username is returned,
// or NULL is returned if the IP address is not found.
const string* UserTable::search (const IP &k) const {
  int hash1_ = k.hash1(M);
  if (!table[hash1_].empty && table[hash1_].ipaddr.sameIP(k)) return (&table[hash1_].username);
  int hash2_ = k.hash2(M);
  if (!table[hash2_].empty && table[hash2_].ipaddr.sameIP(k)) return (&table[hash2_].username);
  int hash3_ = k.hash3(M);
  if (!table[hash3_].empty && table[hash3_].ipaddr.sameIP(k)) return (&table[hash3_].username);


  return NULL;
}

// Inserts a new user into the hash table.
// The return value is "true" if the new item was successfully
// inserted, or "false" if an infinite loop was found.
bool UserTable::insert (const IP &ipaddr, const string username) {
  // TODO
  User user;
  user.ipaddr = ipaddr;
  user.username = username;
  user.empty = false;

  int i = ipaddr.hash1(M);
  int n = 0;
  while (n < 10*M) {

    User temp_user = table[i];

    table[i] = user;
    user = temp_user;
    if (temp_user.empty) return true;
    if (i == temp_user.ipaddr.hash1(M)) i = temp_user.ipaddr.hash2(M);
    else if (i == temp_user.ipaddr.hash2(M)) i = temp_user.ipaddr.hash3(M);
    else i = temp_user.ipaddr.hash1(M);
    n++;
  }

  return false;
}
// Searches for a user with the given IP address in the table,
// and if found, removes that user from the table.
void UserTable::remove (const IP &k) {
  User user;
  user.empty = true;
  int hash1_ = k.hash1(M);
  if (!table[hash1_].empty && table[hash1_].ipaddr.sameIP(k)) table[hash1_] = user;
  int hash2_ = k.hash2(M);
  if (!table[hash2_].empty && table[hash2_].ipaddr.sameIP(k)) table[hash2_] = user;
  int hash3_ = k.hash3(M);
  if (!table[hash2_].empty && table[hash3_].ipaddr.sameIP(k)) table[hash3_] = user;
}

// Prints out all the contents of this table to out.
void UserTable::dump (ostream &out) {
  for (int i = 0; i < M; ++i) {
    out << i << '\t';
    if (table[i].empty) out << "(empty)";
    else out << table[i].ipaddr.getIPString()
             << ' ' << table[i].username;
    out << endl;
  }
}

