#include "bigInt.h"
/*
	
		bigInt big_substract(int number);
		bigInt big_substract(long number);
		bigInt big_substract(long long number);
		bigInt big_substract(string input_string) throw (bigIntException);
		bigInt big_substract(bigInt another);
		//----------------------------------------------------------
		bigInt big_add(int number);
		bigInt big_add(long number);
		bigInt big_add(long long number);
		bigInt big_add(string input_string) throw (bigIntException);
		bigInt big_add(bigInt another);
		//-------------------------------------------
		static string helper_sub(string s1,string s2);
		static string big_sub(string s1,string s2);
		static string big_sum(string s1,string s2);
*/
bigInt bigInt::big_substract(int number){
	return bigInt(big_sub(integer,to_string(number)));
}
bigInt bigInt::big_substract(long number){
	return bigInt(big_sub(integer,to_string(number)));
}
bigInt bigInt::big_substract(long long number){
	return bigInt(big_sub(integer,to_string(number)));
}
bigInt bigInt::big_substract(bigInt another){
	return bigInt(big_sub(integer,another.integer));
}
bigInt bigInt::big_substract(string input_string) throw(bigIntException){
	if(checkValidInt(input_string))
		return bigInt(big_sub(integer,input_string));
	else throw bigIntException();
}
//-------------------------------------------------------
bigInt bigInt::big_add(int number){
	return bigInt(big_sum(integer,to_string(number)));
}
bigInt bigInt::big_add(long number){
	return bigInt(big_sum(integer,to_string(number)));
}
bigInt bigInt::big_add(long long number){
	return bigInt(big_sum(integer,to_string(number)));
}
bigInt bigInt::big_add(bigInt another){
	return bigInt(big_sum(integer,another.integer));
}
bigInt bigInt::big_add(string input_string) throw(bigIntException){
	if(checkValidInt(input_string))
		return bigInt(big_sum(integer,input_string));
	else throw bigIntException();
}
//-----------------------------------------------------------
string bigInt::big_sub(string s1,string s2){
	if(!big_compare(s1,s2)) return "0"; // if a and b both equal 
	string ans="";
	if(s1[0]!='-' && s2[0]=='-') return big_sum(s1,s2.substr(1,s2.length()-1)); // a-(-b) => a+b
	else if(s1[0]=='-' && s2[0]!='-') return big_sum(s1,"-"+s2); // -a - (b) => -a + -b => -(a+b)
	else if(s1[0]=='-' && s2[0]=='-'){
		// -a - (-b)
		ans=helper_sub(s1.substr(1,s1.length()-1),s2.substr(1,s2.length()-1));
		ans = ans[0]=='-'? ans.substr(1,s1.length()-1) : '-'+ans;
	}
	else if(s1[0]!='-' && s2[0]!='-'){
		ans=helper_sub(s1,s2);
	}
	return ans;
}

string bigInt::big_sum(string s1,string s2){
	if(s1[0]=='-' && s2[0]!='-') return big_sub(s2,s1.substr(1,s1.length()-1));
	if(s1[0]!='-' && s2[0]=='-') return big_sub(s1,s2.substr(1,s2.length()-1));
	bool both_negative=(s1[0]=='-' && s2[0]=='-')?true:false; //-a + -b => -(a+b)
	if(both_negative){
		s1=s1.substr(1,s1.length()-1);
		s2=s2.substr(1,s2.length()-1);
	}
	if(big_compare(s1,s2)==1) swap(s1,s2); //s2 should be large 
	string s="";
	int s1_len=s1.length();
	int s2_len=s2.length();
	int diff=s2_len-s1_len;
	int carry=0;
	int ans=0;
	for(int i=s1_len-1;i>=0;i--){
		ans=(s1[i]-'0')+(s2[i+diff]-'0')+carry;
		s.push_back(ans%10 +'0');
		carry=ans/10;
	}
	for(int i=diff-1;i>=0;i--){
		ans=(s2[i]-'0')+carry;
		s.push_back(ans%10 +'0');
		carry=ans/10;
	}
	if(carry) s.push_back(carry+'0');
	if(both_negative) s.push_back('-');
	reverse(s.begin(),s.end());
	return s;
}

string bigInt::helper_sub(string s1,string s2){
	// always keep s1 > s2
	bool s1_gt_s2= big_compare(s1,s2) > 0 ? true : false;
	if(!s1_gt_s2) swap(s1,s2);
	string s="";
	int s1_len=s1.length();
	int s2_len=s2.length();
	int diff=s1_len-s2_len;
	int borrow=0;
	int ans=0;
	for(int i=s2_len-1;i>=0;i--){
		ans=(s1[i+diff]-'0')-(s2[i]-'0')-borrow;
		if(ans<0){
			ans+=10;
			borrow=1;
		}else{
			borrow=0;
		}
		s.push_back(ans +'0');
	}
	for(int i=diff-1;i>=0;i--){
		ans=(s1[i]-'0')-borrow;
		s.push_back(ans +'0');
		borrow=0;
	}
	if(!s1_gt_s2){
		s.push_back('-');
	}
	reverse(s.begin(),s.end());
	return s;
}