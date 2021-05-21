# include<fstream>
# include<iostream>

using namespace std;

void MatrisOku(char[],int[][100],int&,int&);
void SonucYaz(char[],int[][2],int);
int Arama(const int [][100],const int[][100],int[][2],int,int,int,int); 



int main()
{
  char dosyaAdi1[]="AnaMatris.txt";
  char dosyaAdi2[]="ArananMatris.txt";
  char dosyaAdi3[]="Sonuc.txt";
  int anaMatris[100][100]; // maksimum 100*100 boyutunda oldugunu varsayin
  int arananMatris[100][100]; //// maksimum 100*100 boyutunda oldugunu varsayin
  int sonuclar[100][2]={{11,2},{2,3}}; // aranan Matrisin maksimum 100 defa bulunabilecegini varsayin
  
  int satir,sutun; //ana Matrisin satir ve sutun degerleri
  int arananSatir, arananSutun; // aranan Matrisin satir ve sutun degerleri
  int sonucSayisi;
  
  
  MatrisOku(dosyaAdi1,anaMatris,satir,sutun); // Dosyadan Ana Matrisi oku
  MatrisOku(dosyaAdi2,arananMatris,arananSatir,arananSutun); // Dosyadan Aranan Matrisi oku
  
  sonucSayisi=Arama(anaMatris,arananMatris,sonuclar,satir,sutun,arananSatir,arananSutun); // Arama Islemi
  
  SonucYaz(dosyaAdi3,sonuclar,sonucSayisi);
  
  
  
}



void MatrisOku(char dosyaAdi[],int Matris[][100],int &satir,int &sutun)
{ 
int a,b;
ifstream oku;
oku.open(dosyaAdi);
oku >> satir;
oku >> sutun;
//cout << satir << " " << sutun << endl;
for(a=0;a<satir;a++){
	//printf("\n");
	for(b=0;b<sutun;b++){		
		oku >> Matris[a][b];
		//cout << Matris[a][b];	
	}
	//cout << endl;	
}
oku.close();
}


	



void SonucYaz(char dosyaAdi[],int sonuclar[][2],int sonucSayisi)
{
	int a,b;
	
	ofstream yaz;
	yaz.open(dosyaAdi);
	yaz << sonucSayisi;
	for(a=0;a<sonucSayisi;a++){
		yaz << endl;
		for(b=0;b<2;b++){
		 yaz << sonuclar[a][b] << " ";
		}
	}
	yaz.close();
}
int Arama(const int anaMatris[][100],const int arananMatris[][100],int sonuc[][2],int satir,int sutun,int arananSatir,int arananSutun)
{
	
	int dogrulama,a,b,c,d,sayac=0,e,f;

		for(a=0; a<=(satir-arananSatir);a++)
		{
		   for(b=0; b<=(sutun-arananSutun);b++)
		   {
		      dogrulama=0;
		      for(c=0; c<arananSatir; c++)
		      {
		         for(d=0; d<arananSutun; d++)
		         {
		            if(anaMatris[a+c][b+d] != arananMatris[c][d])
		            {
		               dogrulama=1;		
		               break;
		            }
		         }
		      }
		      if(dogrulama==0)
		      {
		      	sayac++;
		      	//printf("%d %d %d\n",a,b,sayac);		      	
				f=0;				
		    	sonuc[e][f] = a;
			   	sonuc[e][f+1] = b;
				e++;			
		    }
		   }		   
		}		
return sayac;
	
}
