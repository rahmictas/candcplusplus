#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
int main() {	
	setlocale(LC_ALL,"turkish");
	int satirSayac,sutunSayac,satirRandom,sutunRandom,sayac=3,satir=1,sutun=1,satirYon=1,sutunYon=2,duvar,sayac2,sayac3,zaman,saniye;
	char yem,imlec='X',yon,sag='d',sol='a',yukari='w',asagi='s',nokta = '.',bitir,bitir2;
	clock_t start, end; // bu s�reyi ba�latma kodumuz.


	// Burada tahta ad�n� verdi�imiz matrisimizi tan�ml�yoruz.
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
	
	
						
							srand((unsigned) time(NULL)); // rastgele say� olu�turmak i�in verdi�imiz komut.
							satirRandom = (rand()%10)+1;	// Burada yemin sat�r� i�in rastgele bir sayi olu�turuyoruz. +1 olma sebebi duvarlara de�memesi.
							sutunRandom = (rand()%10)+1;	// Burada da yemin s�tunu i�in rastgele say� olu�turuyoruz.						
							tahta[1][2] = imlec;  // burada imlec ad�n� verdi�im y�lan�n konumunu belirtiyorum.
							tahta[satirRandom][sutunRandom] = '*'; // Burada yemin koordinatlar�na yemi tan�ml�yorum.
							
				while (sayac>0){
						
						start=clock(); // Burada s�remiz ba�l�yor.
						
							for(sayac2=0;sayac2<11;sayac2++){	
									if( imlec == tahta[0][sayac2] || imlec == tahta[sayac2][0]  || imlec == tahta[11][sayac2] || imlec == tahta[sayac2][11])
									{
										saniye = zaman; // e�er buraya girerse program�m�z s�reyi s�f�rlamas� i�in verdi�im bir komut.
										sayac-=1; // saya�� bir azaltarak 3 hakk�m�z� geriye do�ru say�yoruz.
										/* Alttaki sat�rlarda duvara de�di�imiz durum oldu�u i�in �nce yemin eski konumunu . yap�yorum daha sonra imlec ad�n� verdi�im y�lan�m ilk konumuna d�n�yor,hareket ettirmek i�in kulland���m
										satirYon ve sutunYon de�i�kenlerini s�f�rl�yorum ��nk� di�er t�rl� hareket yine eski konumundan devam edecektir ve rastgele say�lar olu�turarak yeni yemin konumunu belirliyorum.  */ 
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
										// Burada sayac 0 oldu�unda yap�lmas�n� istedi�im komutlar mevcut.
										if(sayac==0){										
																				
												printf("\nBa�ar�s�z, �� hakk�n�z� tamamlad�n�z. ��k�� yapmak i�in q tu�una, devam etmek i�in herhangi bir tu�a basabilirsiniz.\n");
												bitir = getche();
												sayac=3; // oyun bitti�i i�in sayac� s�f�rl�yoruz.
												
												switch(bitir){
												case 'q':
												case 'Q':
													printf("\nOyunu Bitirdiniz.");
													return 0;
												}
											}		
								}
								
								end = clock(); // burada s�reyi kontrol ediyorum.
								zaman = (end)/1000; // burada milisaniyeyi saniyeye �eviriyorum.
								
								if(zaman>=saniye+120){									
									saniye = zaman; // burada  s�re bitti�inde nas�l s�f�rlayaca��m� bilmedi�im i�in b�yle bir �ey yapt�m. amac�m s�re 2 dk yani 120 sn oldu�unda saniyeye bunu eklemek.
									/* Burada yine oyunu yeniden ba�latmak isterseniz diye yine duvara �arpma durumundaki gibi her�eyi s�f�rl�yorum. */ 
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
									printf("\nSize verilen s�rede oyunu tamamlayamad�n�z");
									printf("\n��k�� yapmak i�in q tu�una, devam etmek i�in herhangi bir tu�a basabilirsiniz.");
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
										printf("Y�lan Oyununa Ho� geldiniz. hareket i�in wasd tu�lar�n�, oyunu bitirmek i�in q tu�unu kullan�n�z.\nOyunumuzda b�y�k-k���k harf hassasiyeti yoktur.");
										
										// Burada oyun alan�n� tekrar yazd�rmam�n sebebi oyunu kazan�rken son hamleyi g�stermemesiydi, onun i�in ekran� tekrar yazd�r�p son konumunu da g�stermek istedim.
									for(satir=0;satir<12;satir++){			
										printf("\n");	
											for(sutun=0;sutun<12;sutun++)			
												printf("%c",tahta[satir][sutun]);}
												printf("\n");
									
										saniye = zaman; // burada yine s�reyi s�f�rlamak i�in kendi geli�tirdi�im pek sa�l�kl� olmad���n� d���nd���m kod par�as�.
										tahta[satirRandom][sutunRandom]='.';
										printf("\nOyun ba�ar�l� bir �ekilde tamamland�, Oyunu bitirmek i�in q tu�una,\nOyuna devam etmek i�in herhangi bir tu�a basabilirsiniz.\n");										
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
							// Buran�n yap�l�� amac� e�er duvara de�ersek de�di�im yer '.' i�areti olarak kal�yordu onu d�zeltmek i�in.
							for(sayac3=0;sayac3<10;sayac3++){
											tahta[0][sayac3] = '_';
											tahta[11][sayac3+1] = '_';
											tahta[sayac3+1][0] = '|';
											tahta[sayac3+1][11] = '|';
										}
							system("CLS");
							printf("Y�lan Oyununa Ho� geldiniz. hareket i�in wasd tu�lar�n�, oyunu bitirmek i�in Q tu�unu kullan�n�z.\nOyunumuzda b�y�k-k���k harf hassasiyeti yoktur.");
							// Burada ekrana oyun alan�m�z� yazd�r�yoruz.
							for(satir=0;satir<12;satir++){			
								printf("\n");	
								for(sutun=0;sutun<12;sutun++)			
										printf("%c",tahta[satir][sutun]);}
										printf("\n");										
										yon = getche();
									/* case i�indeki komutlar�n amac� :
									nokta de�i�keniyle ama�lad���m o an y�lan�n bulundu�u konumu . i�aretine �evirmek.
									imlec de�i�keniyle ise gitmesini istedi�im konuma X e �evirip y�lan� oraya g�t�rmek.	 */	
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
