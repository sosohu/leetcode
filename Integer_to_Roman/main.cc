#include <iostream>
#include <string>

using namespace std;


class Solution {

public:

	string 	intToRoman(int num) {
		string str;
		if(num > 999){
			while(num > 999){
				str = str + "M";
				num = num - 1000;
			}
			return str + intToRoman(num);
		}
		if(num > 899){
			str = str + "CM";
			num = num - 900;
			return str + intToRoman(num);
		}
		if(num > 499){
			str = str + "D";
			num = num - 500;
			while(num > 99){
				str = str + "C";
				num = num - 100;
			}
			return str + intToRoman(num);
		}
		if(num > 399){
			str = str + "CD";
			num = num - 400;
			return str + intToRoman(num);
		}
		if(num > 99){
			while(num > 99){
				str = str + "C";
				num = num - 100;
			}
			return str + intToRoman(num);
		}
		if(num > 89){
			str = str + "XC";
			num = num - 90;
			return str + intToRoman(num);
		}
		if(num > 49){
			str = str + "L";
			num = num - 50;
			while(num > 9){
				str = str + "X";
				num = num - 10;
			}
			return str + intToRoman(num);
		}
		if(num > 39){
			str = str + "XL";
			num = num - 40;
			return str + intToRoman(num);
		}
		if(num > 9){
			while(num > 9){
				str = str + "X";
				num = num - 10;
			}
			return str + intToRoman(num);
		}
		switch(num){
			case 9: return "IX";
			case 8: return "VIII";
			case 7: return "VII";
			case 6: return "VI";
			case 5: return "V";
			case 4: return "IV";
			case 3: return "III";
			case 2: return "II";
			case 1: return "I";
			default: return "";
		}
    }

};

int main(int argc, char** argv)
{
	Solution sl;

    string ret = sl.intToRoman(35);
	
	cout<<"Result  :("<<ret<<")"<<endl;

	return 0;

}
