#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double aylik(double krediTutari, double faizOrani,double taksitSayisi){

	double aylikTaksit,toplamBorc,taksit=0,faizKalan,anaPara,kalanPara,odenenPara,kalanTaksit,toplamPara;	
	aylikTaksit = (krediTutari*(faizOrani/100*(pow(1+(faizOrani/100),taksitSayisi))))/ ((pow((1+(faizOrani/100)),taksitSayisi))-1); // Buras� ana form�l�m�z.
	
	
	
	toplamBorc = aylikTaksit * taksitSayisi; // Burada toplam borcu bulmak i�in taksit sayisi ile aylik taksiti carpip sonucu buluyoruz.
	
	// Burada while icine ald�g�m de�erleri de�istirmek icin esitledim.
	anaPara = krediTutari;
	kalanTaksit = taksitSayisi;
	faizKalan = faizOrani;
	kalanPara = krediTutari;
	
	printf("\n%s\t%10s\t%s\t%s\t%s","Taksit No","Taksit Tutari","Odenen Faiz Tutari","Odenen Ana Para Tutari","Kalan Ana Para Borcu\n");
	while(kalanTaksit>0){
		kalanTaksit-=1; // Burada sayac� azaltmak i�in taksit say�s�ndan d���r�yorum.
		faizKalan = kalanPara * (faizOrani/100); // Burada faiz miktarini bulmak i�in bu form�l� yaz�yoruz.		
		odenenPara = aylikTaksit - faizKalan;	 // Burada �denen ayl�k ana para miktar�n� buluyoruz.
		kalanPara -= odenenPara;				// Burada kalan paray� bulmak i�in d�ng� her d�nd���nde kalan anaparay� odenen ana para miktar�ndan ��kar�yorum.
		taksit++; // Burada Taksit sayisini hesapl�yorum.
			
		if (kalanPara < 0 && kalanPara >= -0.01 )   // Bazen kalan paray� -0.00 olarak verdi�i i�in burada - i�aretini d�zeltemek i�in bu e�er
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
