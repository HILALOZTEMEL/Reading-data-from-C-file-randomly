#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h> 
#include<unistd.h>

void oyun_kurallari();
void random_sayi_oyunbiricin(int array[3]);
void random_sayi_(int arrayx[2]);

int main(){
	 oyun_kurallari();
        system("COLOR b");//g�rsel g�r�n�m ad�na,t�m yaz�lar�n mavi olmas� i�in
        printf("\n\n\n*_*_*_*OYUNA BA�LAMAK ���N ENTER a BASINIZ*_*_*_*");
	    getch();
	    system("COLOR f");//g�rsel g�r�n�m ad�na,t�m yaz�lar�n parlak beyaz olmas� i�in
	
		int  k,result,totalPuan=0,say,dongu;
	    char harf_alma[5]={"harf"};
	    
	    float total_s;
	    char cevap[10];
	    int array[3],array1[4],array2[5],array3[6],array4[7],array5[8],array6[9],arrayx[2];
        //s�reyi ba�latt�m.
		clock_t t0 = clock();
	    FILE *oyun_bir,*oyun_bir_soru;
    	//dosyadan okunacak de�erler i�in dizi tan�mlad�m
	    char birinci_level[4];
	    char birinci_level_soru[106];
	    //dosyadan okuma yapt�m
	    
	    
	    dongu=0;
	    random_sayi_(arrayx);
	    
	    //4 harfli kelimelerden iki tanesini nin sorular� ve kelimelri ekrana getirmek i�in i�in for loop 
		for(int a=0;a<2;a++){
			oyun_bir = fopen("1.level.txt", "r"); 
	    oyun_bir_soru=fopen("1.level_sorulari.txt", "r");
	     //z=10 ��nk� dosyalar�n i�inde 10 ar tane eleman var
	    for(int z=0;z<10;z++){
	    //dosyadan veri z nin artmas�na ba�l� olarak dosyadan s�rayla okur
	    fscanf(oyun_bir,"%s ",&birinci_level);
	    fgets(birinci_level_soru,106,oyun_bir_soru);
		  //"void random_sayi_(int arrayx[2]);" fonksiyonunu dosyadan random veri okumak ad�na yazm��t�m.
		  //�retile random sayi z ye esit ise i�lem yap�lmaya devam eder b�ylece dosyadan veriyi random olarak okumu� oldum
	      if(arrayx[a]==z&&dongu!=2){
		  printf("a=%d array=%d z=%d",a,arrayx[a],z);
		  dongu++;
	    	int sayac=0;
	    	printf("\n\n");
	        //ilk kelimenin uzunlu�unu buldum
		    k=strlen(birinci_level);
		    char bulunan_harfler[k];
		    printf("______________________________________________________________________________________________________________________\n");
			printf("D�RT HARFL� %d.inci SORUNUZ         ",say);
		    printf("\n___________________________\n\nSORU:");
		    puts(birinci_level_soru);
		    printf("         ");
		    int point;
          for(int i=0;i<k;i++)
          {//ekrana kelimenin harflrini g�r�nmeyecek sekilde yazd�rd�m
          bulunan_harfler[i]= '_';
          printf("%c ",bulunan_harfler[i]);
		  }
		  point=0;
		  do{//cevap do�ru oalna kadar d�necek d�ng�
		  printf("\n\ncevab� giriniz= ");
		  gets(cevap);
		  //verilen cevab� do�rumu diye kars�la�t�rma yapt�m
		  if(cevap[0]=='p'){
		  	exit;
		  	system("cls");
		  	oyun_kurallari();
		    printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  }else{
		  random_sayi_oyunbiricin(array);
		  result=strcmp(birinci_level,cevap);
		  if(result==0)
		  {point+=400;//kelime 4 harfli ise 400 puan al�r.
		  totalPuan+=point;
		  printf("\nTEBR�KLER  %d  puan    ",point);
		  sleep(2);//2 saniye sonra system("cls"); ile ekran� temizler
		  system("cls");
		  oyun_kurallari();
		  printf("\n\n\n--------->Total Puan = %d     ",totalPuan);
		  
		  }
          else
		  { //yanl�� ise ve harf alamak istiyorsa 
		  int result1=strcmp(cevap,harf_alma);
		    if(result1!=0) {
		    	printf("\nYANLI� CEVAP YEN�DEN DENEY�N�Z");
              }else if(result1==0)
		           { 
			    if(sayac!=3){
	           //"array[sayac]" � "void random_sayi_oyunbiricin(int array[3]);" fonksiyonundan ald�m.
			   int c=array[sayac];
                sayac++;
	            point-=100; //yanl�� ise 4 harflik kelimenin al�nan her harfi i�in  -100 puan al�r
	           printf("         ");
				for(int i=0;i<k;i++){
			   if(i==c){ //verilen harfi gidip yerine yazar
	           	bulunan_harfler[i]=birinci_level[c];
			    }printf("%c ",bulunan_harfler[i]);  
			   } printf("    point %d",point);
			     if(sayac==3){
                printf("\nHARF ALMA HAKKINIZ B�TM�ST�R!");	
				}
			}	
		 } 	
		  }}
		  }while(result!=0);
}
} 
}	   
		    
			//oyun_bir ve oyun_bir_soru dosyas�n� kapatt�m
			fclose(oyun_bir);
			fclose(oyun_bir_soru);
			//1. oyun bitimindeki total s�reyi hesaplattim.
	    clock_t t1 = clock();
	    total_s=(420-((double)(t1 - t0)/CLOCKS_PER_SEC));
       printf("\n--------->Kalan S�re = %.0Lf saniye",total_s);
			
			  
	  return 0;
	   }
	   void oyun_kurallari(){
	   	setlocale(LC_ALL, "Turkish"); 
        printf("\n************************************************\n");
        printf("*.*.*.*.*.*KEL�ME OYUNUNA HOSGELD�N�Z*.*.*.*.*.*\n");
        printf("************************************************\n");
        printf("    OYUN KURALLARI\n\n");
        printf("  1]D�rt harfli kelimeler 400 puan\n  2]Be� harfli kelimeler 500 puan\n  3]Alt� harfli kelimeler 600 puan\n  4]Yedi harfli kelimeler 700 puan\n  5]Sekiz harfli kelimeler 800 puan\n  6]Dokuz harfli kelimeler 900 puan\n  7]On harfli kelimeler 1000 puan d�r.\n  8]Harf almak i�in ----> harf <---- yaz�n�z\n  9]Her harf -100 puand�r. ");
	    printf(" \n \nS�REN�Z 4 DK'd�r  ");
	   	return ;
	   }
	   
void random_sayi_(int arrayx[2]){
int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<2;count++){
arrayx[count]=rand()%10;
printf("arrayx1=%d",arrayx[count]);
}

while(i<2){
    int r=rand()%10;
    
    for (x = 0; x < i; x++)
    {
        if(arrayx[x]==r){
            break;
        }
    }
    if(x==i){
        arrayx[i++]=r;
    }
    
}
for(int i=0;i<2;i++)
printf("%d ",arrayx[i]);
	   	return;	
}
void random_sayi_oyunbiricin(int array[3]){
	   	

int x, p;
int count;
int i=0;

srand(time(NULL));

for(count=0;count<3;count++){
array[count]=rand()%4;
}

while(i<3){
    int r=rand()%4;
    
    for (x = 0; x < i; x++)
    {
        if(array[x]==r){
            break;
        }
    }
    if(x==i){
        array[i++]=r;
    }
    
}

	   	return;
	   }
	  
	   


