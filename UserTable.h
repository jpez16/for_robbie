#ifndef USERTABLE_H
#define USERTABLE_H

#include <cassert>
#include <iostream>
#include <string>

#include "IP.h"

class UserTable {
  private:
    class User {
     public:
      IP ipaddr;
      std::string username;
      bool empty;
    };

    int M;
    User *table;

    // Make copying impossible
    UserTable (const UserTable&);
    UserTable& operator=(const UserTable&);

  public:
    UserTable (int tablesize);

    // De-allocate memory in destructor
    ~UserTable();

    // Searches for a user with the given IP address.
    // A pointer to the string containing the username is returned,
    // or NULL is returned if the IP address is not found.
    const std::string* search (const IP &k) const;

    // Inserts a new user into the hash table.
    // The return value is "true" if the new item was successfully
    // inserted, or "false" if an infinite loop was found.
    bool insert (const IP &ipaddr, const std::string username);

    // Searches for a user with the given IP address in the table,
    // and if found, removes that user from the table.
    void remove (const IP &k);

    // Prints out all the contents of this table to out.
    void dump (std::ostream &out=std::cout);
};

#endif // USERTABLE_H
