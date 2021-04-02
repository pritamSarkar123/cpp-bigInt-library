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
int operator > (bigInt another); <br />
int operator > (string input_string) throw (bigIntException);<br />
int operator > (int number);<br />
int operator > (long number);<br />
int operator > (long long number);<br />
static int big_compare(string s1,string s2);<br />
//-------------------------------------------------------------<br />
bool operator == (bigInt another);<br />
bool operator == (string input_string) throw (bigIntException);<br />
bool operator == (int number);<br />
bool operator == (long number);<br />
bool operator == (long long number);<br />
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
int hashCode();<br />
int bit_length();<br />
int bit_count();<br />
bool primeProbability(int certainly);<br />
//----------------------------------<br />
		
bigInt big_gcd(bigInt another);<br />
bigInt big_gcd(string input_string);<br />
bigInt big_gcd(int number);<br />
bigInt big_gcd(long number);<br />
bigInt big_gcd(long long number);<br />
//-------------------------------
string bit_clear(int position);<br />
bigInt bit_flip(int position);<br />
//--------------------------------<br />
bigInt big_max(bigInt another);<br />
bigInt big_max(string input_string);<br />
bigInt big_max(int number);<br />
bigInt big_max(long number);<br />
bigInt big_max(long long number);<br />
//-----------------------------------<br />
bigInt big_min(bigInt another);<br />
bigInt big_min(string input_string);<br />
bigInt big_min(int number);<br />
bigInt big_min(long number);<br />
bigInt big_min(long long number);<br />
//----------------------------------------<br />
bigInt big_mod(bigInt another);<br />
bigInt big_mod(string input_string);<br />
bigInt big_mod(int number);<br />
bigInt big_mod(long number);<br />
bigInt big_mod(long long number);<br />
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
//---------------------------------------------<br />

//--------------------------------------------<br />
bigInt big_pow(bigInt another);<br />
bigInt big_pow(string input_string);<br />
bigInt big_pow(int number);<br />
bigInt big_pow(long number);<br />
bigInt big_pow(long long number);<br />
//------------------------------------------<br />
bigInt big_remainder(bigInt another);<br />
bigInt big_remainder(string input_string);<br />
bigInt big_remainder(int number);<br />
bigInt big_remainder(long number);<br />
bigInt big_remainder(long long number);<br />
//---------------------------------------<br />
bigInt big_set_bit(int n);//Returns a BigInteger whose value is equivalent to this BigInteger with the designated bit set.<br />
bigInt big_shift_left(int n);<br />
bigInt big_shift_right(int n);<br />
int getLowestSetBit();// returns the inde of the lowest set bit in the bigint<br />
int big_signum();//Returns the signum function of this BigInteger.<br />
bool big_test_bit(int n); //Returns true if and only if the designated bit is set.<br />
vector<int> big_byte_array(); //Returns a byte array containing the two's-complement representation of this BigInteger.<br />
		
//--------------------------------------------------------<br />
bigInt big_divide(int number);<br />
bigInt big_divide(string input_string);<br />
bigInt big_divide(long number);<br />
bigInt big_divide(long long number);<br />
bigInt big_divide(bigInt another);<br />
//------------------------------------------------------<br />
vector<bigInt> big_divide_and_remainder(int number);<br />
vector<bigInt> big_divide_and_remainder(string input_string);<br />
vector<bigInt> big_divide_and_remainder(long number);<br />
vector<bigInt> big_divide_and_remainder(bigInt another);<br />
vector<bigInt> big_divide_and_remainder(long long number);<br />
//-------------------------------------------------------------  <br />
//----------------------------------------------------  <br />
static bigInt big_bitwise_not(bigInt b); //~b  <br />
static bigInt big_bitwise_and(bigInt b1,bigInt b2); // b1 & b2  <br />
static bigInt big_bitwise_and_not(bigInt b1,bigInt b2); //b1 & ~b2  <br />
static bigInt big_bitwise_or(bigInt b1,bigInt b2); // b1 | b2  <br />
static bigInt big_bitwise_or_not(bigInt b1,bigInt b2); //b1 | ~b2  <br />
static bigInt big_bitwise_xor(bigInt b1,bigInt b2); // b1 ^ b2  <br />
static bigInt big_bitwise_xor_not(bigInt b1,bigInt b2); //b1 ^ ~b2  <br />
//-----------------------------------------------
