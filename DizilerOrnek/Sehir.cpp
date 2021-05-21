#include "Sehir.h"
#include <iostream> 
#include <string>   
#include <sstream>  
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
Sehir::Sehir(){
	
}

int Sehir::VektoreAtama(string dosyaAdi){
	
	ifstream girisDosyasi;
	girisDosyasi.open(dosyaAdi.c_str());
	if(girisDosyasi.fail()){
		cout << "Hatali Dosya adi girdiniz";
		return 0;
	}
	getline(girisDosyasi,s1);	
	getline(girisDosyasi,s2,'-');	
	getline(girisDosyasi,s3);
	
	
	while(girisDosyasi.eof()==0){
					
			while(getline(girisDosyasi,satir)){
				istringstream satirStream(satir);
				getline(satirStream,sutun,'#');
				sehirler.push_back(sutun);
				while(getline(satirStream,s4,' ')){
					t3 = atoi(s4.c_str());
					m2.push_back(t3);				
				}
			mesafe.push_back(m2);
			m2.clear();		
				}
			}			
	girisDosyasi.close();
}

void Sehir::Arama(){
	for(i=0;i<sehirler.size();i++){ // Yaz�lan ile en yak�n ili bulaca��m�z olan il
		if(s1 == sehirler[i]){
			sehirSatir = i;
		}		
	}
	for(j=0;j<sehirler.size();j++){ // Burada 500 ve daha az mesafe olan illeri bulma
		if(mesafe[sehirSatir][j]<=500 && mesafe[sehirSatir][j]>1){			
			mKisa.push_back(j);
		}			
	}
	
	for(k=0;k<sehirler.size();k++){ // burada aralar�ndaki mesafeyi bulaca��m�z iller
		
		if(sehirler[k] == s2){
			t1 = k;
		}
		if(sehirler[k] == s3){
			t2 = k;
		}
		
	}

	for(i=0;i<sehirler.size();i++){	// Buras� da 1400den daha uzak olan illeri bulmak i�in.	
			for(j=i;j<sehirler.size();j++){
				if(mesafe[i][j]>1400){
					t4 = i;
					t5 = j;
					m1.push_back(t4);
					m1.push_back(t5);
					mesafeUzak.push_back(m1);
					m1.clear();	
																	
			}									
		}							
	}
	
	
}

void Sehir::Yazdir(string cikti){
		
		ofstream yazdir;
		yazdir.open(cikti.c_str());
		yazdir << s1 << " iline 500 km s�n�r i�inde en yak�n iller: "<<endl;
		for(i=0;i<mKisa.size();i++){
		yazdir << sehirler[mKisa[i]]<<endl;
		}
		yazdir<<endl;
		yazdir << s2 << "-" << s3 <<" aras� mesafe:"<<endl<<mesafe[t1][t2]<<" km"<<endl<<endl;
		yazdir << "Birbirine 1400 km'den daha uzak olan iller:"<<endl<<endl;
		
		
		for(i=0;i<mesafeUzak.size();i++){
			for(j=0;j<1;j++){			
			a1 = mesafeUzak[i][j];
			a2 = mesafeUzak[i][j+1];
			yazdir << sehirler[a1]<<"-"<<sehirler[a2]<<endl;
			}
			
		}
		yazdir.close();
	}



