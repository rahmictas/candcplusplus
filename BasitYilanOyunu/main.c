#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
int main() {	
	setlocale(LC_ALL,"turkish");
	int satirSayac,sutunSayac,satirRandom,sutunRandom,sayac=3,satir=1,sutun=1,satirYon=1,sutunYon=2,duvar,sayac2,sayac3,zaman,saniye;
	char yem,imlec='X',yon,sag='d',sol='a',yukari='w',asagi='s',nokta = '.',bitir,bitir2;
	clock_t start, end; // bu süreyi baþlatma kodumuz.


	// Burada tahta adýný verdiðimiz matrisimizi tanýmlýyoruz.
	int tahta[12][12]=
	{{'_','_','_','_','_','_','_','_','_','_','_','_'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','.','.','.','.','.','.','.','.','.','.','|'},
	{'|','_','_','_','_','_','_','_','_','_','_','|'},};
	
	
						
							srand((unsigned) time(NULL)); // rastgele sayý oluþturmak için verdiðimiz komut.
							satirRandom = (rand()%10)+1;	// Burada yemin satýrý için rastgele bir sayi oluþturuyoruz. +1 olma sebebi duvarlara deðmemesi.
							sutunRandom = (rand()%10)+1;	// Burada da yemin sütunu için rastgele sayý oluþturuyoruz.						
							tahta[1][2] = imlec;  // burada imlec adýný verdiðim yýlanýn konumunu belirtiyorum.
							tahta[satirRandom][sutunRandom] = '*'; // Burada yemin koordinatlarýna yemi tanýmlýyorum.
							
				while (sayac>0){
						
						start=clock(); // Burada süremiz baþlýyor.
						
							for(sayac2=0;sayac2<11;sayac2++){	
									if( imlec == tahta[0][sayac2] || imlec == tahta[sayac2][0]  || imlec == tahta[11][sayac2] || imlec == tahta[sayac2][11])
									{
										saniye = zaman; // eðer buraya girerse programýmýz süreyi sýfýrlamasý için verdiðim bir komut.
										sayac-=1; // sayaçý bir azaltarak 3 hakkýmýzý geriye doðru sayýyoruz.
										/* Alttaki satýrlarda duvara deðdiðimiz durum olduðu için önce yemin eski konumunu . yapýyorum daha sonra imlec adýný verdiðim yýlaným ilk konumuna dönüyor,hareket ettirmek için kullandýðým
										satirYon ve sutunYon deðiþkenlerini sýfýrlýyorum çünkü diðer türlü hareket yine eski konumundan devam edecektir ve rastgele sayýlar oluþturarak yeni yemin konumunu belirliyorum.  */ 
										tahta[satirRandom][sutunRandom]='.'; 										
										tahta[1][2] = imlec;										
										satirYon=1;
										sutunYon=2;
										srand((unsigned) time(NULL));
										satirRandom = (rand()%10)+1;
										sutunRandom = (rand()%10)+1;
										if(tahta[satirRandom][sutunRandom] == tahta[1][2]){
											srand((unsigned) time(NULL));
											satirRandom = (rand()%10)+1;
											sutunRandom = (rand()%10)+1;											
										}
										tahta[satirRandom][sutunRandom] = '*';
										// Burada sayac 0 olduðunda yapýlmasýný istediðim komutlar mevcut.
										if(sayac==0){										
																				
												printf("\nBaþarýsýz, üç hakkýnýzý tamamladýnýz. Çýkýþ yapmak için q tuþuna, devam etmek için herhangi bir tuþa basabilirsiniz.\n");
												bitir = getche();
												sayac=3; // oyun bittiði için sayacý sýfýrlýyoruz.
												
												switch(bitir){
												case 'q':
												case 'Q':
													printf("\nOyunu Bitirdiniz.");
													return 0;
												}
											}		
								}
								
								end = clock(); // burada süreyi kontrol ediyorum.
								zaman = (end)/1000; // burada milisaniyeyi saniyeye çeviriyorum.
								
								if(zaman>=saniye+120){									
									saniye = zaman; // burada  süre bittiðinde nasýl sýfýrlayacaðýmý bilmediðim için böyle bir þey yaptým. amacým süre 2 dk yani 120 sn olduðunda saniyeye bunu eklemek.
									/* Burada yine oyunu yeniden baþlatmak isterseniz diye yine duvara çarpma durumundaki gibi herþeyi sýfýrlýyorum. */ 
									tahta[1][2] = imlec;
									tahta[satirYon][sutunYon]='.';
									satirYon=1;
									sutunYon=2;	
									tahta[satirRandom][sutunRandom]='.';
									tahta[satirYon][sutunYon]=tahta[1][2];
									srand((unsigned) time(NULL));
									satirRandom = (rand()%10)+1;
									sutunRandom = (rand()%10)+1;
									tahta[satirRandom][sutunRandom] = '*';									
									printf("\nSize verilen sürede oyunu tamamlayamadýnýz");
									printf("\nÇýkýþ yapmak için q tuþuna, devam etmek için herhangi bir tuþa basabilirsiniz.");
									bitir2 = getche();
										sayac=3;
										switch(bitir2){
												case 'q':
												case 'Q':
												printf("\nOyunu Bitirdiniz.");													
													return 0;
								}
							}
							if(tahta[satirRandom][sutunRandom]==imlec){
										system("CLS");
										printf("Yýlan Oyununa Hoþ geldiniz. hareket için wasd tuþlarýný, oyunu bitirmek için q tuþunu kullanýnýz.\nOyunumuzda büyük-küçük harf hassasiyeti yoktur.");
										
										// Burada oyun alanýný tekrar yazdýrmamýn sebebi oyunu kazanýrken son hamleyi göstermemesiydi, onun için ekraný tekrar yazdýrýp son konumunu da göstermek istedim.
									for(satir=0;satir<12;satir++){			
										printf("\n");	
											for(sutun=0;sutun<12;sutun++)			
												printf("%c",tahta[satir][sutun]);}
												printf("\n");
									
										saniye = zaman; // burada yine süreyi sýfýrlamak için kendi geliþtirdiðim pek saðlýklý olmadýðýný düþündüðüm kod parçasý.
										tahta[satirRandom][sutunRandom]='.';
										printf("\nOyun baþarýlý bir þekilde tamamlandý, Oyunu bitirmek için q tuþuna,\nOyuna devam etmek için herhangi bir tuþa basabilirsiniz.\n");										
										bitir2 = getche();
										switch(bitir2){
												case 'q':
												case 'Q':
												printf("\nOyunu Bitirdiniz.");													
													return 0;
								}
										tahta[1][2] = imlec;
										satirYon=1;
										sutunYon=2;										
										tahta[satirYon][sutunYon]=tahta[1][2];
										srand((unsigned) time(NULL));
										satirRandom = (rand()%10)+1;
										sutunRandom = (rand()%10)+1;
										if(tahta[satirRandom][sutunRandom] == tahta[1][2]){
											srand((unsigned) time(NULL));
											satirRandom = (rand()%10)+1;
											sutunRandom = (rand()%10)+1;											
										}	
										tahta[satirRandom][sutunRandom] = '*';	
										sayac = 3;
								}
							}	
							// Buranýn yapýlýþ amacý eðer duvara deðersek deðdiðim yer '.' iþareti olarak kalýyordu onu düzeltmek için.
							for(sayac3=0;sayac3<10;sayac3++){
											tahta[0][sayac3] = '_';
											tahta[11][sayac3+1] = '_';
											tahta[sayac3+1][0] = '|';
											tahta[sayac3+1][11] = '|';
										}
							system("CLS");
							printf("Yýlan Oyununa Hoþ geldiniz. hareket için wasd tuþlarýný, oyunu bitirmek için Q tuþunu kullanýnýz.\nOyunumuzda büyük-küçük harf hassasiyeti yoktur.");
							// Burada ekrana oyun alanýmýzý yazdýrýyoruz.
							for(satir=0;satir<12;satir++){			
								printf("\n");	
								for(sutun=0;sutun<12;sutun++)			
										printf("%c",tahta[satir][sutun]);}
										printf("\n");										
										yon = getche();
									/* case içindeki komutlarýn amacý :
									nokta deðiþkeniyle amaçladýðým o an yýlanýn bulunduðu konumu . iþaretine çevirmek.
									imlec deðiþkeniyle ise gitmesini istediðim konuma X e çevirip yýlaný oraya götürmek.	 */	
									switch (yon){						
								case 'w':
								case 'W':	
									tahta[satirYon][sutunYon] = nokta;
									tahta[satirYon-1][sutunYon] = imlec;
									satirYon-=1;									
									break;	
								case 'A':							
								case 'a':
									tahta[satirYon][sutunYon] = nokta;
									tahta[satirYon][sutunYon-1] = imlec;								
									sutunYon-=1;									
									break;
								case 'S':				
								case 's':
									tahta[satirYon][sutunYon] = nokta;
									tahta[satirYon+1][sutunYon] = imlec ;
									satirYon+=1;									
									break;
								case 'D':					
								case 'd':
									tahta[satirYon][sutunYon] = nokta;
									tahta[satirYon][sutunYon+1] = imlec ;
									sutunYon+=1;									
									break;
								case 'q':
								case  'Q':
									printf("\nOyunu bitirdiniz");
									return 0;
									break;
							}
				}
return 0;
}
