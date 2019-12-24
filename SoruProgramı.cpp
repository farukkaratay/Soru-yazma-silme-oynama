#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 50  				//  boyutu 50 olarak sabitlendi 

int fonk1 (void);               /* Menü seçeneði belirleme    */
void fonk2 (void);              /* Soru Ekle                  */
void fonk3 (void);              /* Soru id ye göre arama  ve silme          */
void fonk4 (void);              /* Oyun oyna         */
void fonk5 (void);              /* En yüksek 3 skor   */
void fonk6 (int id1);  			/* Bilgileri ekranda gösterme id ye göre*/
void fonk7 (void);              /* Bütün kayýtlarýn listelenmesi */
void fonk8 (void);              /* Dosyaya kaydetme              */
void fonk9 (void);              /* Dosyadan yükleme              */
void skor_kaydet(void);			/*Skorlarý dosyaya kaydetme*/
void skor_al(void);				/*Skorlarý dosyayan yükleme*/

struct soru {
	 int soru_id;
	 char soru_metni[100];
	 char cevap_A[50];
	 char cevap_B[50];
	 char cevap_C[50];
	 char cevap_D[50];
	 char dogru_cevap[1];
	 } ydizi[BOYUT];
	 
struct secilen_sorular {
	 int soru_id;
	 char soru_metni[100];
	 char cevap_A[50];
	 char cevap_B[50];
	 char cevap_C[50];
	 char cevap_D[50];
	 char dogru_cevap[1];	 
	 } secilen[BOYUT];
	 	 
struct cevaplar {
	 int soru_id;
	 char dogru_cevap[1];	 
	 }cevap[BOYUT] ;
	 
struct skorlar {
	 int skor_id;
	 char kullanici_adi[75];	 
	 int skor;
	 } puan[BOYUT];
	 
int igd1=0;     //kayýtlý soru adeti
int skor_id=0;  // kayýtlý skor adeti

int main (void)
{
  	int id1;
 	fonk9(); /* Sorularýn Dosyadan yükleme */
  	skor_al (); /*skorlarýn dosyadan yükleme*/
//	printf("%d skor:",skor_id);
 do {
     printf("\n");
     id1 = fonk1();
     switch (id1) {
        case 1 : fonk2(); //  soru ekle
           	break;
      	case 2 : fonk3(); //id ye göre arama ve silme
        	break;
       	case 3 : fonk7();  //bütün kayýtlarý listele 
        	break;
        case 4 : fonk4(); //Oyun oyna
            break;
        case 5 : fonk5();  // en yüksek skorlar 
         break;
		}
 	 } while (id1!=6);
}

	/* Bir menü seçeneði seçmenizi saðlar. */
int fonk1 (void){
  	int secim;
  	printf("        TEST OYUNU\n");
   	printf("[1]. Soru Ekle\n");
  	printf("[2]. Soru Sil\n");  
  	printf("[3]. Sorulari Goster ve Guncelle\n");
  	printf("[4]. Oyun Oyna\n");
  	printf("[5]. En Yuksek Skorlar\n");
  	printf("[6]. Cikis\n");

  	do {
     printf("\nSeceneginizi giriniz [1-6]: ");
     secim = getche()-'0';
     printf("\n");
  	} while (secim<1 || secim>6);
  	return secim;
}

/* Veritabanýna bilgi giriþi */
void fonk2 (void)
{
  int 	id1;
  char	sec[1];
 	system("CLS"); 	
  for 	(id1=igd1; id1<BOYUT; id1++) {  	 
  	   	ydizi[id1].soru_id=id1; 
  	   	printf("\n");
  	   	printf("(Cikis icin Enter tusuna basiniz)\n");
  	   	printf("\n");
  	   	printf("Soruyu Girin:"); 
       	gets(ydizi[id1].soru_metni);
       	if (!*ydizi[id1].soru_metni) {system("CLS"); 	break;   }	
		printf("A Secenegi: ");
      	gets(ydizi[id1].cevap_A);
       	printf("B Secenegi: ");
       	gets(ydizi[id1].cevap_B);
       	printf("C Secenegi: ");
       	gets(ydizi[id1].cevap_C);
      	 printf("D Secenegi: ");
       	gets(ydizi[id1].cevap_D);
       dongu:	
	   	printf("Dogru Secenek: [A-D] ");
		gets(ydizi[id1].dogru_cevap);  		  
		  } 
  igd1 = id1;                //kaç soru girildiyse son id yi igd1 e atýyor. tekrar soru girilirken kaldýðý yerden devam ediyor
  fonk8();				
} 


/* id ye göre arama ve silme */
void fonk3 (void){
  int aranan;
  int id1, id2;
  char sec;
  		printf("Silmek istediginiz sorunun id numarasini giriniz: ");
 		 scanf("%d",&aranan);
 		 id2 = 0;
  			for (id1=0; id1<igd1; id1++) {
        		if (aranan==ydizi[id1].soru_id) { 
        		id2 = 1;
            	fonk6 (aranan);
        		printf("Bu soru silinecek! Emin misiniz? [E-H]\n");
		 		sec=getche();
  				if(sec=='e' || sec=='E'){
	  		while(id1<=igd1){
		   		ydizi[id1].soru_id=ydizi[id1+1].soru_id-1;
           		strcpy(ydizi[id1].soru_metni,ydizi[id1+1].soru_metni);
           		strcpy(ydizi[id1].cevap_A,ydizi[id1+1].cevap_A);
           		strcpy(ydizi[id1].cevap_B,ydizi[id1+1].cevap_B);
           		strcpy(ydizi[id1].cevap_C,ydizi[id1+1].cevap_C);
           		strcpy(ydizi[id1].cevap_D,ydizi[id1+1].cevap_D);
           		strcpy(ydizi[id1].dogru_cevap,ydizi[id1+1].dogru_cevap);
           		id1++;
				}
	        	igd1--;
	        	printf("Soru basariyla silindi!");
               	printf("\n");
               } else {
               	printf("Soru silinmedi!");
               	printf("\n");
			   }
               
			  
			}}if (!id2) printf("Bulunamadi!\n");
  
  fonk8();
  getchar();
}

//random sayý üretiyor
random_id(){                                 
int sonuc;
srand(time(NULL));
sonuc=rand()%igd1;
return sonuc;		
}

//oyun oyna
void fonk4 (void)
 {
  int i,secilen_id,skor;
  char ad_soyad[75];
  char sec;
  
  	system("CLS");    
  	if (igd1<5) {
	printf("Oyun oynamak icin en az 5 soru eklemelisiniz!\n");
	printf("toplam soru adedi %d\n ",igd1);
	}
	else{	  
	secilen_id=random_id();   
 
 		for (i=0; i<5; i++ )   {   //5 soru  sormak  için döngü
			secilen[i].soru_id=secilen_id;									
			strcpy (secilen[i].soru_metni,ydizi[secilen_id].soru_metni);	
			strcpy (secilen[i].cevap_A,ydizi[secilen_id].cevap_A);
			strcpy (secilen[i].cevap_B,ydizi[secilen_id].cevap_B);
			strcpy (secilen[i].cevap_C,ydizi[secilen_id].cevap_C);
			strcpy (secilen[i].cevap_D,ydizi[secilen_id].cevap_D);
			strcpy (secilen[i].dogru_cevap,ydizi[secilen_id].dogru_cevap);		
			fonk6(secilen_id);														
			printf("\Cevap Giriniz: [A-D]: \n");
			gets(cevap[i].dogru_cevap); 										
			secilen_id++;														
			if (secilen_id==igd1){ 											
			secilen_id=0;}
	 };
	skor=0;																	
	  for (i=0; i<5; i++ ){	
	   	if (!strcmp (cevap[i].dogru_cevap, secilen[i].dogru_cevap)){		
	    skor=skor+1;}														
	 	 }
printf("\n");
 printf("Soru No   Cevabiniz   Dogru Cevap \n");
 printf("========  =========   ===========\n");    							
 for (i=0; i<5; i++ ){ 
 	printf("   %-10d ",i+1);
  	printf("%-10s  ",cevap[i].dogru_cevap);
  	printf("%-5s  \n",secilen[i].dogru_cevap);
    }
    printf("\n");
    printf("  Skor: %-3d  \n",skor);
     printf("\n");
    printf("Lutfen Adinizi giriniz: ");							
	skor_id++;								          	     		
    gets(puan[skor_id].kullanici_adi);							
 	puan[skor_id].skor=skor;
 	puan[skor_id].skor_id=skor_id;
    skor_kaydet();											   														
}
}
//en yüksek 3 skor listele
void fonk5(void){
	int _skor,_skorid,i,j;
	char _ad[75];
 	skor_id++;										
	 for(int i=0; i<skor_id;i++){ 							
        for(int j=i+1; j<skor_id; j++){						// bubble sort 		
            if(puan[i].skor < puan[j].skor){
                _skor = puan[i].skor; 						
                puan[i].skor = puan[j].skor; 				
                puan[j].skor = _skor; 						
				             
                strcpy(_ad, puan[i].kullanici_adi); 			
                strcpy(puan[i].kullanici_adi, puan[j].kullanici_adi);
                strcpy(puan[j].kullanici_adi, _ad); 
                
                _skorid= puan[i].skor_id; 																
                puan[i].skor_id = puan[j].skor_id; 
                puan[j].skor_id = _skorid;
                
            }
        }
    }
    system("CLS");
    printf("Sira    Ad Soyad     Skor\n");
    printf("----   ----------   ------\n");
   for(i=0; i<3;i++){			
   		printf("  %-6d %-10s %3d",i+1,puan[i].kullanici_adi,puan[i].skor);
     	printf("\n");	
     	
}getchar();system("CLS");
	}
     

/* Bilgileri ekranda gösterme */
void fonk6 (int id1)
{
  
	 printf("Soru id:%-3d  \n", ydizi[id1].soru_id);
	 printf("Soru: %-15s\n", ydizi[id1].soru_metni);
     printf("A) %-15s\n", ydizi[id1].cevap_A);
     printf("B) %-15s\n", ydizi[id1].cevap_B);
     printf("C) %-15s\n", ydizi[id1].cevap_C);
     printf("D) %-15s\n", ydizi[id1].cevap_D);
   
}

/* Bütün kayýtlarýn listelenmesi */
void fonk7 (void)
{
  int id1;
  char sec;
  id1 = 0;
  if (igd1==0) {
  	system("CLS");
  	printf("Suan kayitli soru bulunmamakta\n");
  }else 
  {  
  do {
   
  	 printf("Soru id:%-3d  \n", ydizi[id1].soru_id);
     printf("Soru: %-15s  \n", ydizi[id1].soru_metni);
     printf("A) %-15s \n", ydizi[id1].cevap_A);
     printf("B) %-15s \n", ydizi[id1].cevap_B);
     printf("C) %-15s\n", ydizi[id1].cevap_C);
     printf("D) %-15s \n", ydizi[id1].cevap_D);
     printf("Dogru Cevap:%-15s \n", ydizi[id1].dogru_cevap);     
     printf("\n");
     id1++;
  } while (*ydizi[id1].soru_metni);
  

printf("Degistirmek istediginiz soru var mi?(e)(h)");
  //scanf("%c" , &sec);
  sec=getche();
  if(sec=='e' || sec=='E'){
  
  	printf("\nDegistirmek istediginiz sorunun id'sini giriniz:");
  	scanf("%d" , &id1);
  	system("CLS");
	fonk6(id1);
  	printf("Bu soru icin yeni bilgileri giriniz");
  	printf("\n");
 
  		printf("Soruyu Girin:"); 
      	gets(ydizi[id1].soru_metni);  
		gets(ydizi[id1].soru_metni);    	
       	printf("A Secenegi: ");
      	gets(ydizi[id1].cevap_A);
       	printf("B Secenegi: ");
       	gets(ydizi[id1].cevap_B);
       	printf("C Secenegi: ");
       	gets(ydizi[id1].cevap_C);
      	printf("D Secenegi: ");
       	gets(ydizi[id1].cevap_D);
       	printf("Dogru Secenek: [A-D] ");
       	gets(ydizi[id1].dogru_cevap);
       	fonk8();
}system("CLS");
}
}
/* Kayýtlarýn dosyaya kaydedilmesi */
void fonk8 (void)
{
  FILE *fp1;

  if ((fp1=fopen ("Sorular.txt", "w")) == NULL) {
      printf("Dosya açýlamadý!\n");
      exit(1);
  }

  fwrite (&igd1, sizeof igd1, 1, fp1);
  fwrite (ydizi, sizeof ydizi, 1, fp1);

  fclose (fp1);
}

//skorlar Dosyaya kaydediliyor
void skor_kaydet(void){
	
	FILE *fp1;
	if ((fp1=fopen ("Skorlar.txt", "w")) == NULL) {
    printf("Dosya açýlamadý!\n");
    exit(1);
  }
	
  fwrite (&skor_id, sizeof skor_id, 1, fp1);
  fwrite (puan, sizeof puan, 1, fp1);
  fclose (fp1);

}

/* Kayýtlarýn dosyadan yüklenmesi */
void fonk9 (void)
{
  FILE *fp1;

  if ((fp1=fopen ("Sorular.txt", "r")) == NULL) {
      printf("Sorular dosyasi mevcut degil!\n");
      return;
  }

  fread (&igd1, sizeof igd1, 1, fp1);
  fread (ydizi, sizeof ydizi, 1, fp1);

  fclose (fp1);
}
//skorlarýn Dosyayan yüklenmesi
void skor_al (void)
{
  FILE *fp1;

  if ((fp1=fopen ("Skorlar.txt", "r")) == NULL) {
      printf("Skor dosyasi mevcut degil!\n");
      return;
  }

  fread (&skor_id, sizeof skor_id, 1, fp1);
  fread (puan, sizeof puan, 1, fp1);

  fclose (fp1);
}
