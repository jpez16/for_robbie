#include "IP.h"
#include "math.h"
#include "stdio.h"

using std::string;

// This is called a "default constructor"
// The goal is to make an empty object that shouldn't be equal to
// any legitimate IP address.
IP::IP () {
  a3 = -1;
  a2 = -1;
  a1 = -1;
  a0 = -1;
}

// Constructor from a string of the form a3.a2.a1.a0
IP::IP (const string ip) {
  setIPString(ip);
}

void IP::setIPString(const string ip) {
  // Parse the components of the IP address
  char ipcopy[16], *ipnum;
  strncpy(ipcopy, ip.c_str(), 15);
  ipcopy[15] = '\0';

  ipnum = strtok(ipcopy,".");
  assert (ipnum != NULL);
  a3 = atoi(ipnum);
  assert (0 <= a3 && a3 <= 255);

  ipnum = strtok(NULL,".");
  assert (ipnum != NULL);
  a2 = atoi(ipnum);
  assert (0 <= a2 && a2 <= 255);

  ipnum = strtok(NULL,".");
  assert (ipnum != NULL);
  a1 = atoi(ipnum);
  assert (0 <= a1 && a1 <= 255);

  ipnum = strtok(NULL,".");
  assert (ipnum != NULL);
  a0 = atoi(ipnum);
  assert (0 <= a0 && a0 <= 255);
}


// Returns the IP address formatted as a string a3.a2.a1.a0
string IP::getIPString() const {
  std::ostringstream sout;
  sout << a3 << '.' << a2 << '.' << a1 << '.' << a0;
  sout.flush();
  return sout.str();
}

// Returns true iff this IP address is the same as the one in other.
bool IP::sameIP (const IP &other) const {
  return ((a3 == other.a3) &&
          (a2 == other.a2) &&
          (a1 == other.a1) &&
          (a0 == other.a0));
}

// Compute the hash of the IP address into the range {0,1,...,M-1}.
// Use the division method on the integer value k.
int IP::hash1 (int M) const {
  /* k = a0 + a1*256 + a2*(256^2) + a3*(256^3)
   * Computed using the shift operator "<<", which adds trailing
   * zeros in binary.
   * We store k as a 64-bit long long because it might have 32 bits.
   */
  long long k = a0 + (a1 << 8) + (a2 << 16) + (((long long)a3) << 24);
  // TODO
  return k % M; // Change this line to the actual return value.
}

// Compute the hash of the IP address into the range {0,1,...,M-1}.
// Use the multiplication on the integer value k, and using the
// constant multiplier PHI as given.
// HINT: use the cmath (aka math.h) standard library
int IP::hash2 (int M) const {
  static const double PHI = 0.6180339887498948;
  long long k = a0 + (a1 << 8) + (a2 << 16) + (((long long)a3) << 24);
  // TODO
  return floor(M*(k*PHI - floor(k*PHI))); // Change this line to the actual return value.
}

// Compute the hash of the IP address into the range {0,1,...,M-1}.
// Use your own custom-designed hash function.
int IP::hash3 (int M) const {
  /* k = a0 + a1*256 + a2*(256^2) + a3*(256^3)
   * Computed using the shift operator "<<", which adds trailing
   * zeros in binary.
   * We store k as a 64-bit long long because it might have 32 bits.
   */
  long long k = a0 + (a1 << 8) + (a2 << 16) + (((long long)a3) << 24);
  // Utilizes the division method, yet shifts the index of where k could originally be stored, by 420 % M.
  return (k+420) % M; // Change this line to the actual return value.
}
