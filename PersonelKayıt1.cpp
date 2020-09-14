#include <stdio.h>
#include <string.h>
#include <conio.h>

struct kayit{
  char isim[15];
  char soyisim[15];
  char tel[13];
  char tcNo[12];
  char bolum [30];
};

void menuHazirla();
int kayitListele();
int kayitAra(char *);
int kayitEkle();
int kayitSil();
int kayitGuncellestir();

void menuHazirla(){
  printf("--------------------------------------\n");
  printf("*                                    *\n");
  printf("*    PERSONEL KAYIT PROGRAMI         *\n");
  printf("*                                    *\n");
  printf("*        1- Kayit Listele            *\n");
  printf("*        2- Kayit Ara                *\n");
  printf("*        3- Kayit Ekle               *\n");
  printf("*        4- Kayit Sil                *\n");
  printf("*        5- Kayit Guncellestir       *\n");
  printf("*        6- Programdan Cikis         *\n");
  printf("--------------------------------------\n");
}

int kayitEkle(){
  struct kayit yeniKayit;
  FILE *ptVeritabani;
 
  
  ptVeritabani=fopen("veritabani.txt","a");
  
  
  printf("\n\n");
  printf("Isim Giriniz: ");
  scanf("%s",yeniKayit.isim);
 
  printf("Soyisim Giriniz: ");
  scanf("%s",yeniKayit.soyisim);
 
  printf("Telefon Numarasini Giriniz: ");
  scanf("%s",yeniKayit.tel);
  
printf("TC Kimlik numarasini giriniz:");
  scanf("%s",yeniKayit.tcNo);
  
  printf("Calistigi Bolumu Giriniz:");
  scanf("%s", yeniKayit.bolum);
  
  
  fprintf(ptVeritabani,"%s\t%s\t%s \t%s \t%s", yeniKayit.isim, yeniKayit.soyisim, yeniKayit.tel, yeniKayit.tcNo, yeniKayit.bolum);
 
  fclose(ptVeritabani);
  return 0;
}

int kayitListele(){
 
 
  FILE *ptVeritabani;
  struct kayit aktifKayit;
 ptVeritabani=fopen("veritabani.txt","r");
  
  
 
  printf("\nIsim\t\t\tSoyisim\t\t\tTel No\t\t\tTC\t\t\tBolumu\n");
  printf("------\t\t\t----\t\t\t------\t\t\t-----\t\t\t------\n\n");
   
  
 
 
  while(!feof(ptVeritabani))
  {
   fscanf(ptVeritabani,"%s%s%s%s%s",&aktifKayit.isim, &aktifKayit.soyisim, &aktifKayit.tel , &aktifKayit.tcNo, &aktifKayit.bolum);
    printf("%s\t\t",aktifKayit.tcNo);
     printf("%s\t\t\t\t",aktifKayit.isim);
    printf("%s\t\t\t",aktifKayit.soyisim);
   printf("%s\t\t\t",aktifKayit.tel);
   printf("%s\n",aktifKayit.bolum);
    
  }
 
  fclose(ptVeritabani);
  return 0;
}

int kayitAra(char *arananIsim){
 
  FILE *ptVeritabani;
  struct kayit aktifKayit;
  int bulunan=0;
 
  ptVeritabani=fopen("veritabani.txt","r");
   
  
 
 
  while(!feof(ptVeritabani)){
   fscanf(ptVeritabani,"%s%s%s%s%s",&aktifKayit.isim, &aktifKayit.soyisim,&aktifKayit.tel, &aktifKayit.tcNo, &aktifKayit.bolum);
 
    if(!strcmp(arananIsim, aktifKayit.isim)){ 
      printf("%s\t\t\t",aktifKayit.isim);
      printf("%s\t\t\t",aktifKayit.soyisim);
      printf("%s\t\t\t",aktifKayit.tel);
      printf("%s\t\t\t",aktifKayit.tcNo);
      printf("%s\t\t\t",aktifKayit.bolum);
     
      bulunan++;
    }
  }
 
  fclose(ptVeritabani);
  return bulunan;
}

int kayitSil(){
	  FILE *ptVeritabani;
	   FILE *ptVeritabani1;
	    struct kayit aktifKayit;
char silinecekIsim[15];
printf("\nSilinecek personelin ismini giriniz :");
scanf("%s", &silinecekIsim);
ptVeritabani=fopen("veritabani.txt","r");
ptVeritabani1=fopen("veritabani1","w");

while(!feof(ptVeritabani)){
	fscanf(ptVeritabani,"%s %s %s %s %s",&aktifKayit.isim, &aktifKayit.soyisim, &aktifKayit.tel , &aktifKayit.tcNo, &aktifKayit.bolum);
	if(strstr(aktifKayit.isim,silinecekIsim)){
		fscanf(ptVeritabani1,"%s %s % s%s % s",&aktifKayit.isim, &aktifKayit.soyisim, &aktifKayit.tel , &aktifKayit.tcNo, &aktifKayit.bolum);
	}
	fprintf(ptVeritabani1,"%s %s % s%s % s",aktifKayit.isim, aktifKayit.soyisim, aktifKayit.tel , aktifKayit.tcNo, aktifKayit.bolum);
	printf("Kayýt silindi");
}
fclose(ptVeritabani);
fclose(ptVeritabani1);
remove("veritabani.txt");
rename("veritabani1.txt","veritabani.txt");
}

int kayitGuncellestir(){
FILE *ptVeritabani,*ptVeritabani1;
char guncellenicekIsim[15];
struct kayit aktifKayit;

      printf("\nGuncellenecek Personelin Adini Giriniz: \n"); 
      scanf("%s",&guncellenicekIsim);

                ptVeritabani=fopen("veritabani.txt","r");
               ptVeritabani1=fopen("veritabani1.txt","w");


while(!feof(ptVeritabani)){
 
 fscanf(ptVeritabani,"%s%s%s%s%s",&aktifKayit.isim, &aktifKayit.soyisim,&aktifKayit.tel, &aktifKayit.tcNo, &aktifKayit.bolum);

if(strstr(aktifKayit.isim,guncellenicekIsim)){
                printf("---|Yeni Bilgiler|---:\n\n");//yeni bilgileri al.
             
			 
             
			   printf("Personelin Adi: \n"); 
             scanf("%s",&aktifKayit.isim);
             
			 printf("Personelin Soyadi: \n "); 
             scanf("%s",aktifKayit.soyisim);
              
			   printf("Personelin Telefon Numarasi: \n "); 
               scanf("%s",&aktifKayit.tel);
              
			   printf("Personelin T.C Kimlik Numarasi: \n ");
               scanf("%s",&aktifKayit.tcNo);
			   
			   printf("Personelin Calistigi Bolum: \n "); 
              scanf("%s",&aktifKayit.bolum);
}


        fprintf(ptVeritabani1,"%s\t%s\t%s\t%s\t%s \n ",aktifKayit.isim,aktifKayit.soyisim,aktifKayit.tel,aktifKayit.tcNo,aktifKayit.bolum);
}
           fclose(ptVeritabani);
           fclose(ptVeritabani1);
          remove("veritabani.txt");
        rename("veritabani1.txt","veritabani.txt");
}

  
	 





int main(){
		char secim='0';
  char aranacakIsim[16];
  int isimAra=-1;
 
  // menu hazirla:
  menuHazirla();
 
  do{
    printf("\n\nSeciminiz ? ");
    secim = putch(getch());
 
    switch (secim){
      case '1':
        kayitListele();
        break;
      case '2':
       printf("\naranacak ismi giriniz:");
        scanf("%s",aranacakIsim);
 
        isimAra = kayitAra(aranacakIsim);
        if (isimAra == 0){ 
          printf("\naranan isim kayitlarda bulunamadi.");
        }else {
          if(isimAra > 0)
            printf("\ntoplam %d kayit bulundu.",isimAra);
          else
            printf("\nHATA: numara aranamadi!");
        }
        break;
      case '3':
        if (kayitEkle()==0){ 
          printf("\nKayit basariyla eklendi.");
        }else{
          printf("\nHATA:Kayýt eklenemedi!");
        }
        break;
      case '4':
     kayitSil();
	  break;
	  case '5':
	  kayitGuncellestir();
	  	break;
	  case '6':
       return 0;
        break;
      default:
        printf("\nlutfen 1-6 arasinda bir secim yapiniz.");
 
    }
  }
  while(secim!=6);

return 0;	
}




