#include <iostream>
#include <string>  
#include <sstream>  
#include <fstream>  
#include "Sehir.h"
#include <locale.h>
using namespace std;
int main()
{

setlocale(LC_ALL, "Turkish"); 
string dosyaAdi,ciktiAdi;

cout << "Dosya adýný giriniz"<<endl;
cin >> dosyaAdi;
cout << "Çýktý dosyasýný adýný giriniz"<<endl;
cin >> ciktiAdi;
ciktiAdi.append(".dat");


Sehir y;

y.VektoreAtama(dosyaAdi);
y.Arama();
y.Yazdir(ciktiAdi);
return 0;
}





