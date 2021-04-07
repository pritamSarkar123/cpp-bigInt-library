bigInt();<br />
bigInt(int number);<br />
bigInt(long number);<br />
bigInt(long long number);<br />
bigInt(string input_string) throw (bigIntException);<br />
string get();<br />
string big_abs();<br />
bigInt operator ! ();<br />
void operator = (const bigInt &another);<br />
//--------------------------------------------------------------<br />
static bool checkValidInt(string input_string);<br />
static string value(int number);<br />
static string value(long number);<br />
static string value(long long number);<br />
//-------------------------------------------------------<br />
static bool big_even (const bigInt &another);<br /> 
static bool big_even (const string &input_string) throw (bigIntException);<br />
static bool big_even (const int &number);<br />
static bool big_even (const long &number);<br />
static bool big_even (const long long &number);<br />
static bool if_even(const string &s);<br />
//---------------------------------------------------------------<br />
bool operator > (const bigInt &another);<br /> 
bool operator > (const string &input_string) throw (bigIntException);<br />
bool operator > (const int &number);<br />
bool operator > (const long &number);<br />
bool operator > (const long long &number);<br />
//--------------------------------------------------------------<br />
bool operator < (const bigInt &another); <br />
bool operator < (const string &input_string) throw (bigIntException);<br />
bool operator < (const int &number);<br />
bool operator < (const long &number);<br />
bool operator < (const long long &number);<br />
static int big_compare(const string &s1,const string &s2);<br />
//---------------------------------------------------------------<br />
bool operator == (const bigInt &another);<br />
bool operator == (const string &input_string) throw (bigIntException);<br />
bool operator == (const int &number);<br />
bool operator == (const long &number);<br />
bool operator == (const long long &number);<br />
//------------------------------------------------------------<br />
static bigInt big_min(const vector<bigInt> &v);<br />
static bigInt big_max(const vector<bigInt> &v);<br />
//-------------------------------<br />
bigInt big_max(const bigInt &another);<br />
bigInt big_max(const string &input_string) throw (bigIntException);<br />
bigInt big_max(const int &number);<br />
bigInt big_max(const long &number);<br />
bigInt big_max(const long long &number);<br />
//-----------------------------------<br />
bigInt big_min(const bigInt &another);<br />
bigInt big_min(const string &input_string) throw (bigIntException);<br />
bigInt big_min(const int &number);<br />
bigInt big_min(const long &number);<br />
bigInt big_min(const long long &number);<br />
//-----------------------------------------------------------------<br />
static string helper_sub(string s1,string s2);<br />
static string big_sub(string s1,string s2);<br />
static string big_sum(string s1,string s2);<br />
static string big_mul(string s1, string s2);<br />
static string big_fact(string s1);<br />
//-----------------------------------------------------------<br />
bigInt operator - (int number);<br />
bigInt operator - (long number);<br />
bigInt operator - (long long number);<br />
bigInt operator - (string input_string) throw (bigIntException);<br />
bigInt operator - (bigInt another);<br />
//----------------------------------------------------------<br />
bigInt operator + (int number);<br />
bigInt operator + (long number);<br />
bigInt operator + (long long number);<br />
bigInt operator + (string input_string) throw (bigIntException);<br />
bigInt operator + (bigInt another);<br />
//-------------------------------------------<br />
void operator ++ ();<br />
void operator -- ();<br />
//---------------------------------------------<br />
void operator += (int number);<br />
void operator += (long number);<br />
void operator += (long long number);<br />
void operator += (string input_string) throw (bigIntException);<br />
void operator += (bigInt another);<br />
//------------------------------------------------------<br />
void operator -= (int number);<br />
void operator -= (long number);<br />
void operator -= (long long number);<br />
void operator -= (string input_string) throw (bigIntException);<br />
void operator -= (bigInt another);<br />
//------------------------------------------------------<br />
bigInt operator * (int number);<br />
bigInt operator * (long number);<br />
bigInt operator * (long long number);<br />
bigInt operator * (string input_string) throw (bigIntException);<br />
bigInt operator * (bigInt another);<br />
//-------------------------------------------------------------<br />
void operator *= (int number);<br />
void operator *= (long number);<br />
void operator *= (long long number);<br />
void operator *= (string input_string) throw (bigIntException);<br />
void operator *= (bigInt another);<br />
//--------------------------------------------------------------------<br />
//----------------------------------------------------------------------<br />
static string big_div(string s1,string s2);<br />
static string big_mod(string s1,string s2);<br />
//------------------------------<br />
bigInt operator / (int number) throw (bigIntException);<br />
bigInt operator / (string input_string) throw (bigIntException);<br />
bigInt operator / (long number) throw (bigIntException);<br />
bigInt operator / (long long number) throw (bigIntException);<br />
bigInt operator / (bigInt another) throw (bigIntException);<br />
//-------------------------------------------------------------<br />
void operator /= (int number) throw (bigIntException);<br />
void operator /= (long number) throw (bigIntException);<br />
void operator /= (long long number) throw (bigIntException);<br />
void operator /= (string input_string) throw (bigIntException);<br />
void operator /= (bigInt another) throw (bigIntException);<br />	
//--------------------------------------------------------------<br />
bigInt operator % (bigInt another) throw (bigIntException);<br />
bigInt operator % (string input_string) throw (bigIntException);<br />
bigInt operator % (int number) throw (bigIntException);<br />
bigInt operator % (long number) throw (bigIntException);<br />
bigInt operator % (long long number) throw (bigIntException);<br />
//-------------------------------------------------------------<br />
void operator %= (bigInt another) throw (bigIntException);<br />
void operator %= (string input_string) throw (bigIntException);<br />
void operator %= (int number) throw (bigIntException);<br />
void operator %= (long number) throw (bigIntException);<br />
void operator %= (long long number) throw (bigIntException);<br />
//----------------------------------------------------------------<br />
vector<bigInt> big_divide_and_remainder(int number) throw (bigIntException);<br />
vector<bigInt> big_divide_and_remainder(string input_string) throw (bigIntException);<br />
vector<bigInt> big_divide_and_remainder(long number) throw (bigIntException);<br />
vector<bigInt> big_divide_and_remainder(bigInt another) throw (bigIntException);<br />
vector<bigInt> big_divide_and_remainder(long long number) throw (bigIntException);<br />
//-----------------------------------------------------------------<br />
bigInt big_pow(bigInt another);<br />
bigInt big_pow(string input_string) throw (bigIntException);<br />
bigInt big_pow(int number);<br />
bigInt big_pow(long number);<br />
bigInt big_pow(long long number);<br />
static string big_power(string s1,string s2);<br />
//----------------------------------------------------------------<br />
static bigInt big_factorial(int number);<br />
static bigInt big_factorial(long number);<br />
static bigInt big_factorial(long long number);<br />
static bigInt big_factorial(string input_string) throw (bigIntException);<br />
static bigInt big_factorial(bigInt another);<br />
//--------------------------------------------------------------<br />
//--------------------------------------------------------------<br />
double toDouble(); // making the bigInt to double<br />
float toFloat(); //making the bigint into float<br />
int toInt();// bigInt to int<br />
long toLong();//  bigInt to long<br />
long long toLongLong();// bigInt to long<br />
//----------------------------------------------------------------<br />
//TODO: remaining<br />
//-------------------------------------------------------------------<br />
//NEXT DAY<br />
bigInt big_gcd(bigInt another);<br />
bigInt big_gcd(string input_string) throw (bigIntException);<br />
bigInt big_gcd(int number);<br />
bigInt big_gcd(long number);<br />
bigInt big_gcd(long long number);<br />
//--------------------------------------------------------------------------<br />
bigInt big_lcm(bigInt another);<br />
bigInt big_lcm(string input_string) throw (bigIntException);<br />
bigInt big_lcm(int number);<br />
bigInt big_lcm(long number);<br />
bigInt big_lcm(long long number);<br />
//------------------------------------------------------------------------<br />
int hashCode();<br />
int bit_length();<br />
int bit_count();<br />
bool primeProbability(int certainly);<br />
//----------------------------------<br />
string bit_clear(int position);<br />
bigInt bit_flip(int position);<br />
//------------------------------------<br />
bigInt big_mod_inverse(bigInt another);<br />
bigInt big_mod_inverse(string input_string);<br />
bigInt big_mod_inverse(int number);<br />
bigInt big_mod_inverse(long number);<br />
bigInt big_mod_inverse(long long number);<br />
//-----------------------------------------<br />
bigInt big_mod_pow(bigInt exponent,bigInt another);<br />
bigInt big_mod_pow(string exponent,string input_string);<br />
bigInt big_mod_pow(int exponent,int number);<br />
bigInt big_mod_pow(long exponent,long number);<br />
bigInt big_mod_pow(long long exponent,long long number);<br />
//---------------------------------------<br />
bigInt big_set_bit(int n);//Returns a BigInteger whose value is equivalent to this BigInteger with the designated bit set.<br />
bigInt big_shift_left(int n);<br />
bigInt big_shift_right(int n);<br />
int getLowestSetBit();// returns the inde of the lowest set bit in the bigint<br />
int big_signum();//Returns the signum function of this BigInteger.<br />
bool big_test_bit(int n); //Returns true if and only if the designated bit is set.<br />
vector<int> big_byte_array(); //Returns a byte array containing the two's-complement representation of this BigInteger.<br />
//----------------------------------------------------  <br />
static bigInt big_bitwise_not(bigInt b); //~b  <br />
static bigInt big_bitwise_and(bigInt b1,bigInt b2); // b1 & b2  <br />
static bigInt big_bitwise_and_not(bigInt b1,bigInt b2); //b1 & ~b2  <br />
static bigInt big_bitwise_or(bigInt b1,bigInt b2); // b1 | b2  <br />
static bigInt big_bitwise_or_not(bigInt b1,bigInt b2); //b1 | ~b2  <br />
static bigInt big_bitwise_xor(bigInt b1,bigInt b2); // b1 ^ b2  <br />
static bigInt big_bitwise_xor_not(bigInt b1,bigInt b2); //b1 ^ ~b2  <br />
//-----------------------------------------------<br />
