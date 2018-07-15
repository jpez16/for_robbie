#ifndef IP_H
#define IP_H

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

class IP {
  private:
    int a3, a2, a1, a0;

  public:
    // This is called a "default constructor"
    // The goal is to make an empty object that shouldn't be equal to
    // any legitimate IP address.
    IP ();

    // Constructor from a string of the form a3.a2.a1.a0
    IP (const std::string ip);

    void setIPString(const std::string ip);

    // Returns the IP address formatted as a string a3.a2.a1.a0
    std::string getIPString() const;

    // Returns true iff this IP address is the same as the one in other.
    bool sameIP (const IP &other) const;

    // Compute the hash of the IP address into the range {0,1,...,M-1}.
    // Use the division method on the integer value k.
    int hash1 (int M) const;

    // Compute the hash of the IP address into the range {0,1,...,M-1}.
    // Use the multiplication on the integer value k, and using the
    // constant multiplier PHI as given.
    // HINT: use the cmath (aka math.h) standard library
    int hash2 (int M) const;

    // Compute the hash of the IP address into the range {0,1,...,M-1}.
    // Use your own custom-designed hash function.
    int hash3 (int M) const;
};

#endif // IP_H
