#include "bigInt.h"
/*
	bool operator > (const bigInt &another); 
	bool operator > (const string &input_string) throw (bigIntException);
	bool operator > (const long long &number);


	bool operator < (const bigInt &another); 
	bool operator < (const string &input_string) throw (bigIntException);
	bool operator < (const long long &number);

	static int big_compare(const string &s1,const string &s2);
	//-------------------------------------------------
	bool operator == (const bigInt &another);
	bool operator == (const string &input_string) throw (bigIntException);
	bool operator == (const long long &number);

	//-------------------------------
	bigInt big_max(const bigInt &another);
	bigInt big_max(const string &input_string) throw (bigIntException);
	bigInt big_max(const long long &number);
	//-----------------------------------
	bigInt big_min(const bigInt &another);
	bigInt big_min(const string &input_string) throw (bigIntException);
	bigInt big_min(const long long &number);
	//------------------------------------------------
	static bigInt big_min(const vector<bigInt> &v);
	static bigInt big_max(const vector<bigInt> &v);
*/
/*
	s1 > s2 return 1
	s1 < s2 return -1
	s1 == s2 return 0  then is_equal true
*/

bigInt bigInt::big_max(const long long &number){
	return big_compare(integer,to_string(number)) > 0 ? bigInt(integer) : bigInt(number); 
}
bigInt bigInt::big_max(const bigInt &another){
	return big_compare(integer,another.integer) > 0 ? bigInt(integer) : another; 
}
bigInt bigInt::big_max(const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string) > 0 ? bigInt(integer) : bigInt(input_string); 
	}else throw bigIntException();
}

bigInt bigInt::big_max(const vector<bigInt> &v){
	if(v.size()==0) return bigInt();
	bigInt ans(v[0]);
	for(int i = 1; i < v.size();i++){
		if(big_compare(ans.integer,v[i].integer) < 0) ans.integer=v[i].integer;
	}
	return ans;
}

//-------------------------------------------------------------------------------------------

bigInt bigInt::big_min(const long long &number){
	return big_compare(integer,to_string(number)) < 0 ? bigInt(integer) : bigInt(number); 
}
bigInt bigInt::big_min(const bigInt &another){
	return big_compare(integer,another.integer) < 0 ? bigInt(integer) : another; 
}
bigInt bigInt::big_min(const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string) < 0 ? bigInt(integer) : bigInt(input_string); 
	}else throw bigIntException();
}
bigInt bigInt::big_min(const vector<bigInt> &v){
	if(v.size()==0) return bigInt();
	bigInt ans(v[0]);
	for(int i = 1; i < v.size();i++){
		if(big_compare(ans.integer,v[i].integer) > 0) ans.integer=v[i].integer;
	}
	return ans;
}
//------------------------------------------------------------------------------------


bool bigInt::operator == (const bigInt &another){
	return big_compare(integer,another.integer)==0?true:false;
}
bool bigInt::operator == (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)==0?true:false;
	}else throw bigIntException();
}
bool bigInt::operator == (const long long &number){
	return big_compare(integer,to_string(number))==0?true:false;
}
bool bigInt::operator > (const bigInt &another){
	return big_compare(integer, another.integer)>0?true:false;
}
bool bigInt::operator > (const long long &number){
	return big_compare(integer,to_string(number))>0?true:false;
}
bool bigInt::operator > (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)>0?true:false;
	}else throw bigIntException();
}
//---------------------------------------------------------------------
bool bigInt::operator < (const bigInt &another){
	return big_compare(integer, another.integer)<0?true:false;
}
bool bigInt::operator < (const long long &number){
	return big_compare(integer,to_string(number))<0?true:false;
}
bool bigInt::operator < (const string &input_string) throw (bigIntException){
	if(checkValidInt(input_string)){
		return big_compare(integer,input_string)<0?true:false;
	}else throw bigIntException();
}
int bigInt::big_compare(const string &s1,const string &s2){
	if(s1[0]!='-' && s2[0]=='-') return 1;
	else if(s1[0]=='-' && s2[0]!='-') return -1;
	else if(s1[0]=='-' && s2[0]=='-') return - big_compare(s1.substr(1,s1.length()-1),s2.substr(1,s2.length()-1)); // a >b then -a < -b
	else{ // a b
		if(s1.length() > s2.length()) return 1; //s1 > s2
		else if(s1.length() < s2.length()) return -1; //s2 < s1
		else{ // both length equal 
			for(int i=0; i<s1.length();i++){
				if(s1[i] > s2[i]) return 1; //s1 >s2
				if(s1[i] < s2[i]) return -1; // s1 < s2
			}
			return 0; //s1 == s2
		}
	}
}