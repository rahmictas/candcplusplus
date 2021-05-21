#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double aylik(double krediTutari, double faizOrani,double taksitSayisi){

	double aylikTaksit,toplamBorc,taksit=0,faizKalan,anaPara,kalanPara,odenenPara,kalanTaksit,toplamPara;	
	aylikTaksit = (krediTutari*(faizOrani/100*(pow(1+(faizOrani/100),taksitSayisi))))/ ((pow((1+(faizOrani/100)),taksitSayisi))-1); // Burasý ana formülümüz.
	
	
	
	toplamBorc = aylikTaksit * taksitSayisi; // Burada toplam borcu bulmak için taksit sayisi ile aylik taksiti carpip sonucu buluyoruz.
	
	// Burada while icine aldýgým deðerleri deðistirmek icin esitledim.
	anaPara = krediTutari;
	kalanTaksit = taksitSayisi;
	faizKalan = faizOrani;
	kalanPara = krediTutari;
	
	printf("\n%s\t%10s\t%s\t%s\t%s","Taksit No","Taksit Tutari","Odenen Faiz Tutari","Odenen Ana Para Tutari","Kalan Ana Para Borcu\n");
	while(kalanTaksit>0){
		kalanTaksit-=1; // Burada sayacý azaltmak için taksit sayýsýndan düþürüyorum.
		faizKalan = kalanPara * (faizOrani/100); // Burada faiz miktarini bulmak için bu formülü yazýyoruz.		
		odenenPara = aylikTaksit - faizKalan;	 // Burada ödenen aylýk ana para miktarýný buluyoruz.
		kalanPara -= odenenPara;				// Burada kalan parayý bulmak için döngü her döndüðünde kalan anaparayý odenen ana para miktarýndan çýkarýyorum.
		taksit++; // Burada Taksit sayisini hesaplýyorum.
			
		if (kalanPara < 0 && kalanPara >= -0.01 )   // Bazen kalan parayý -0.00 olarak verdiði için burada - iþaretini düzeltemek için bu eðer
			kalanPara = +0.00;
			
		printf("%.0lf\t%15.2lf\t%20.2lf\t%20.2lf\t%20.2lf\t\n",taksit,aylikTaksit,faizKalan,odenenPara,kalanPara);				
}
			printf("\nAylik Odemeniz : %8.2lf\n",aylikTaksit);
			printf("Toplam Borcunuz : %8.2lf\n",toplamBorc);
			return aylikTaksit;
}
void main() {
	
	double sonuc;
	double miktar,faiz,taksit;
	printf("Toplam Kredi Miktari: ");
	scanf("%lf",&miktar);
	printf("Faiz Orani: ");
	scanf("%lf",&faiz);
	printf("Taksit Sayisi: ");
	scanf("%lf",&taksit);	
	sonuc = aylik(miktar,faiz,taksit);
	
}
