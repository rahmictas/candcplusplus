#include <vector>
#include <iostream> 
#include <string>  
#include <sstream>  
#include <fstream>
using namespace std;
class Sehir
{
	
	public:
	Sehir();
	int VektoreAtama(string );
	void Arama();
	void Yazdir(string);
		
	private:
	vector<vector<int> > mesafe;
	vector<vector<int> > mesafeUzak;
	vector<int> m2,mKisa,m1;	
	vector<string> sehirler;
	
	string satir,sutun,s1,s2,s3,s4;
	
	
	int i,j,sehirSatir,k,t1,t2,t3,t4,t5,a1,a2;	
};
