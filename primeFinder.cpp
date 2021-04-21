#include "bigInt.h"
/*
    bool primeProbability(int certainity);
*/

bool bigInt::primeProbability(int certainity) throw (bigIntException){
    if(certainity<0 || certainity>100) throw bigIntException("certainity limit exceedeed");
    string cert=to_string(certainity);
    string root_s=big_root(integer,"2");
    string a=big_mul(root_s,cert);
    string limit=big_div(a,"100");

    string i="2";
    string j="0";
    while(big_compare(big_mul(i,i),integer)<=0){
        if(big_mod(integer,i)=="0") return false;
        if(certainity<100 && big_compare(j,limit)>0) return true;
        i=big_sum(i,"1");
        j=big_sum(j,"1");
    }
    return true;
}