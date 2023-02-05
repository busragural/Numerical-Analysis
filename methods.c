#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main(){
	
	printf("*******SAYISAL ANALIZ DONEM PROJESI*******\n\n");
	
	int quit=1, menu;
	int i, j, k;
	int derece, iterasyon=1, secim, satir, denklem, n;
	int katsayilar[25];
	double alt, ust, epsilon, f_alt, f_ust, hata=100, kok, f_kok=0, baslangic, f_alt_turev, r,c, delta, f_baslangic, f_onceki, f_sonraki, ileri, geri, merkezi, tek, cift, sonuc, toplam=0;
	double matris[25][25], birim[25][25];
	double x[25], alt_x[25], f_alt_x[25];
	
	while(quit){
		
		printf("1.Bisection Yontemi\n2.Regula Falsi Yontemi\n3.Newton Raphson Yontemi\n4.Kare Matrisin Tersini Bulma\n5.Gauss Eleminasyon Yontemi\n");
		printf("6.Gauss Seidal Yontemi\n7.Sayisal Turev\n8.Simpson Yontemi\n9.Trapez Yontemi\n10.Degisken Donusumsuz Newton Enterpolasyonu\n");
		
		
		printf("\n\nBir islem seciniz:");
		scanf("%d", &menu);
		
		if(menu == 1){
			printf("\n\n********  BISECTION YONTEMI  ********\n\n\n");
						
			printf("Denklemin maksimum derecesini giriniz: ");
			scanf("%d", &derece);
						
			printf("Denklemin katsayilarini en buyuk dereceden baslayarak sirasiyla giriniz:\n");
						
			for(i=derece; i>=0; i--){
				scanf("%d", &katsayilar[i]);
			}
			
			printf("\nDENKLEM:");
					
			for(i=derece; i>0; i--){ //EKRANA DENKLEMÝ YAZDIRMA
							
				if(i == 1 && katsayilar[i] !=0 ){
					printf("(%d)(x)+", katsayilar[i]);
				}
				else{
					if(katsayilar[i] != 1 &&  katsayilar[i] != 0 ){
						printf("(%d)(x)^%d+", katsayilar[i],i);
					}
					else if(katsayilar[i] == 1){
						printf("(x)^%d+",i);
					}	
				}	
			}
			
			if(katsayilar[0] != 0){ //EKRANA DENKLEMÝ YAZDIRMA
				printf("(%d)=0\n", katsayilar[0]);
			}
					
			printf("\nKokunu hesaplamak istediginiz araligin alt sinirini giriniz:");
			scanf("%lf", &alt);
							
			printf("\nKokunu hesaplamak istediginiz araligin ust sinirini giriniz:");
			scanf("%lf", &ust);
						
			printf("\nHata(Epsilon):");
			scanf("%lf", &epsilon);	
						
			for(i=derece; i>=0; i--){
				f_alt += katsayilar[i] * pow(alt,i); 
			}
							
			printf("f(%lf) = %lf\n", alt, f_alt);
						
			for(i=derece; i>=0; i--){
				f_ust += katsayilar[i] * pow(ust,i); 
			}
							
			printf("f(%lf) = %lf\n", ust, f_ust);
						
			while(hata > epsilon){
					
				if(f_alt * f_ust < 0){
								
					kok = (alt + ust) / 2;	
					printf("\nKOK: %lf\n", kok);
								
					f_kok = 0;
								
					hata =  (ust - alt) / pow(2,iterasyon+1);
					printf("HATA: %lf\n", hata);
								
					for(i=derece; i>=0; i--){
									
						f_kok += katsayilar[i] * pow(kok,i); 
					}
					printf("f(%lf): %lf\n", kok, f_kok);
								
					if(f_kok * f_alt < 0){
									
						printf("Kok %lf ile %lf arasindadir.\n", alt , kok);
						ust = kok;
						f_ust = f_kok;
					}
					if(f_kok * f_ust < 0 ){
											
						printf("Kok %lf ile %lf arasindadir.\n", kok, ust);
						alt = kok;
						f_alt = f_kok;
									
					}		
								iterasyon++;
				}
			}	
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);		
			
		}
		
		else if(menu == 2){
			
			printf("\n\n********  REGULA FALSI YONTEMI  ********\n\n\n");
			printf("Denklemin maksimum derecesini giriniz: ");
			scanf("%d", &derece);
						
			printf("Denklemin katsayilarini en buyuk dereceden baslayarak sirasiyla giriniz:\n");
						
			for(i=derece; i>=0; i--){
				scanf("%d", &katsayilar[i]);
			}
				
			printf("\nDENKLEM:");
					
			for(i=derece; i>0; i--){ //EKRANA DENKLEMÝ YAZDIRMA
							
				if(i == 1 && katsayilar[i] !=0 ){
					printf("(%d)(x)+", katsayilar[i]);
				}
				else{
					if(katsayilar[i] != 1 &&  katsayilar[i] != 0 ){
						printf("(%d)(x)^%d+", katsayilar[i],i);
					}
					else if(katsayilar[i] == 1){
						printf("(x)^%d+",i);
					}	
				}	
			}
			
			
			if(katsayilar[0] != 0){ //EKRANA DENKLEMÝ YAZDIRMA
				printf("(%d)=0\n", katsayilar[0]);
			}
					
			printf("\nKokunu hesaplamak istediginiz araligin alt sinirini giriniz:");
			scanf("%lf", &alt);
							
			printf("\nKokunu hesaplamak istediginiz araligin ust sinirini giriniz:");
			scanf("%lf", &ust);
						
			printf("\nHata(Epsilon):");
			scanf("%lf", &epsilon);	
						
			for(i=derece; i>=0; i--){
				f_alt += katsayilar[i] * pow(alt,i); 
			}
							
			printf("f(%lf) = %lf\n", alt, f_alt);
						
			for(i=derece; i>=0; i--){
				f_ust += katsayilar[i] * pow(ust,i); 
			}
							
			printf("f(%lf) = %lf\n", ust, f_ust);
			
			while(hata > epsilon){

				if(f_alt * f_ust < 0){
			
					kok = (alt * f_ust - ust * f_alt) / (f_ust - f_alt);
					printf("\n\nKOK: %lf\n", kok);
					
					f_kok = 0;
					
					for(i=derece; i>=0; i--){
						f_kok += katsayilar[i] * pow(kok,i); 
					}
					printf("f(%lf): %lf", kok, f_kok);
					
					
					
					if(f_kok * f_alt < 0){
						
						printf("\nKok %lf ile %lf arasindadir.", alt , kok);
						ust = kok;
						f_ust = f_kok;
						
						
					}
					if(f_kok * f_ust < 0 ){
								
						printf("\nKok %lf ile %lf arasindadir.", kok, ust);
						alt = kok;
						f_alt = f_kok;
						
					}
					
					hata =  (ust - alt) / pow(2,iterasyon+1);
					printf("\tHATA: %lf\n", hata);
						
					iterasyon++;
				}
			}	
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);	
		}
		
		else if(menu == 3){
			printf("\n\n********  NEWTON RAPHSON YONTEMI  ********\n\n\n");
			printf("Denklemin maksimum derecesini giriniz: ");
			scanf("%d", &derece);
						
			printf("Denklemin katsayilarini en buyuk dereceden baslayarak sirasiyla giriniz:\n");
						
			for(i=derece; i>=0; i--){
				scanf("%d", &katsayilar[i]);
			}
				
			printf("\nDENKLEM:");
					
			for(i=derece; i>0; i--){ //EKRANA DENKLEMÝ YAZDIRMA
							
				if(i == 1 && katsayilar[i] !=0 ){
					printf("(%d)(x)+", katsayilar[i]);
				}
				else{
					if(katsayilar[i] != 1 &&  katsayilar[i] != 0 ){
						printf("(%d)(x)^%d+", katsayilar[i],i);
					}
					else if(katsayilar[i] == 1){
						printf("(x)^%d+",i);
					}	
				}	
			}
			
			
			if(katsayilar[0] != 0){ //EKRANA DENKLEMÝ YAZDIRMA
				printf("(%d)=0\n", katsayilar[0]);
			}
					
			printf("\nKokunu hesaplamak istediginiz araligin alt sinirini giriniz:");
			scanf("%lf", &alt);
							
			printf("\nKokunu hesaplamak istediginiz araligin ust sinirini giriniz:");
			scanf("%lf", &ust);
						
			printf("\nHata(Epsilon):");
			scanf("%lf", &epsilon);	
			
			printf("\nBaslangic degeri varsa 1'i, yoksa 0'i seciniz.");
			scanf("%d", &secim);
			
			while (hata > epsilon){
		
				if(secim == 1){
					printf("\nBaslangic degerini giriniz:");
					scanf("%lf", &baslangic);
					alt = baslangic;
					secim = 0;			
				}
		
				f_alt = 0;
				f_alt_turev = 0;
				
				for(i=derece; i>=0; i--){
					f_alt += katsayilar[i] * pow(alt,i); 
				}
				
				for(i=derece; i>1; i--){
					f_alt_turev += i * katsayilar[i] * pow(alt,(i-1));
				}
				f_alt_turev += katsayilar[1];
				
				kok = alt - (f_alt / f_alt_turev);
				printf("\nKOK: %lf\t", kok);
				
				if(alt > kok){
					hata = alt- kok;
				}
				else{
					hata = kok - alt;
				}
				printf("HATA: %lf", hata);
				alt = kok;
				
			}
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);	
		}
		
		else if(menu == 4){
			printf("\n\n********  KARE MATRISIN TERSINI BULMA  ********\n\n\n");
			
			printf("Matrisin satir sayisini giriniz:");
			scanf("%d", &satir);
			
			for(i=0; i<satir; i++){
				for(j=0; j<satir; j++){
					printf("[%d][%d]. eleman: ", i+1, j+1);
					scanf("%lf", &matris[i][j]);
				}
			}
			
			printf("\n\n");
			
			printf("***MATRIS:\n\n");
			for(i=0; i<satir; i++){
				for(j=0; j<satir; j++){
					printf("%lf\t", matris[i][j]);	
				}
				printf("\n");
			}
			
			printf("\n\n***MATRISIN INVERSI:\n\n");
			
			for(i=0; i<satir; i++){
				for(j=0; j<satir; j++){
					
					if(i==j){
						birim[i][j] = 1;
					}
					else{
						birim[i][j] = 0;
					}
				}
			}
			
			for(i=0; i<satir; i++){
				
				r = matris[i][i];
				
				for(j=0; j<satir; j++){
					
					matris[i][j] = matris[i][j] / r;
					birim[i][j] = birim[i][j] / r;
				}
				
				for(k=0; k<satir; k++){
					if(k != i){
						 c = matris[k][i];
						for(j=0; j<satir; j++){
							matris[k][j] -= matris[i][j] * c;
							birim[k][j] -= birim[i][j] * c;
						}
					}
				}
			}
			
			for(i=0; i<satir; i++){
				for(j=0; j<satir; j++){
					printf("%lf\t", birim[i][j]);
					
				}
				printf("\n");
			}
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);	
		}
		
		else if(menu == 5){
			printf("\n\n********  GAUSS ELIMINASYON YONTEMI  ********\n\n\n");
			
			printf("Denklem sayisini giriniz:");
			scanf("%d",&denklem);
			
			printf("\n");
			
			for(i=1;i<=denklem;i++){
        		for(j=1;j<=denklem+1;j++){
        			if(j!=denklem+1){
						printf("%d.denklemin x%d katsayisi : ",i,j);
            			scanf("%lf",&matris[i][j]);
        			}
        			else{
        				printf("%d.denklemin sonucu : ",i);
            			scanf("%lf",&matris[i][j]);
					}
				}
				printf("\n");
    		}
    		
			printf("\nDENKLEMLER:\n\n");
			
			for(i=1;i<=denklem;i++){
				printf("%d.denklem : ",i);
				for(j=1;j<=denklem+1;j++){
					if(j==denklem+1){
						printf("= %lf  ",matris[i][j]);
					}
					else{
						printf("%lfx%d ",matris[i][j],j);
					}
				}
				printf("\n");
			}
			
			for(j=1; j<=denklem; j++){
        		for(i=1; i<=denklem; i++){
            		if(i>j){
                		r=matris[i][j]/matris[j][j];
                		for(k=1; k<=denklem+1; k++){
                    		matris[i][k]-=r*matris[j][k];
               			}
            		}
        		}
    		}
    		
    		x[denklem]=matris[denklem][denklem+1]/matris[denklem][denklem];
    		
    		for(i=denklem-1; i>=1; i--){
        		c=0;
        		for(j=i+1; j<=denklem; j++){
            		c+=matris[i][j]*x[j];
       	 		}
       	 		
        		x[i]=(matris[i][denklem+1]-c)/matris[i][i];
    		}
    		
   			printf("\nBULUNAN DEGERLER: \n");
   			
    		for(i=1;i<=denklem;i++){
        		printf("\nx%d=%lf\t",i,x[i]);
			}
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);	
			
		}
		
		else if(menu == 6){
			printf("\n\n********  GAUSS SEIDAL YONTEMI  ********\n\n\n");
			
		}
		
		else if(menu == 7){
			printf("\n\n********  SAYISAL TUREV  ********\n\n\n");
			
			printf("Denklemin maksimum derecesini giriniz: ");
			scanf("%d", &derece);
						
			printf("Denklemin katsayilarini en buyuk dereceden baslayarak sirasiyla giriniz:\n");
						
			for(i=derece; i>=0; i--){
				scanf("%d", &katsayilar[i]);
			}
				
			printf("\nDENKLEM:");
					
			for(i=derece; i>0; i--){ //EKRANA DENKLEMÝ YAZDIRMA
							
				if(i == 1 && katsayilar[i] !=0 ){
					printf("(%d)(x)+", katsayilar[i]);
				}
				else{
					if(katsayilar[i] != 1 &&  katsayilar[i] != 0 ){
						printf("(%d)(x)^%d+", katsayilar[i],i);
					}
					else if(katsayilar[i] == 1){
						printf("(x)^%d+",i);
					}	
				}	
			}
			
			
			if(katsayilar[0] != 0){ //EKRANA DENKLEMÝ YAZDIRMA
				printf("(%d)=0\n", katsayilar[0]);
			}
			
			printf("\nBaslangic degerini giriniz:");
			scanf("%lf", &baslangic);
			
			printf("\nDeltayi giriniz:");
			scanf("%lf", &delta);
			
			for(i=derece; i>=0; i--){
				f_baslangic += katsayilar[i] * pow(baslangic,i); 
			}
			
			printf("\nf(%lf) = %lf\n", baslangic, f_baslangic);
			
			for(i=derece; i>=0; i--){
				f_onceki += katsayilar[i] * pow((baslangic-delta),i); 
			}
			
			printf("\nf(%lf) = %lf\n", (baslangic-delta), f_onceki);
			
			for(i=derece; i>=0; i--){
				f_sonraki += katsayilar[i] * pow((baslangic+delta),i); 
			}
			
			printf("\nf(%lf) = %lf\n", (baslangic+delta), f_sonraki);
			
			
			ileri = (float) (f_sonraki - f_baslangic) / delta;
			geri = (float) (f_baslangic - f_onceki) / delta;
			merkezi = (float) (ileri + geri) / 2;
			
			printf("\nIleri Fark ile Turev   : %lf", ileri);
			printf("\nGeri Fark ile Turev    : %lf", geri);
			printf("\nMerkezi Fark ile Turev : %lf", merkezi);
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);			
		
		}
		
		else if(menu == 8){
			printf("\n\n********  SIMPSON YONTEMI  ********\n\n\n");
			
			printf("Denklemin maksimum derecesini giriniz: ");
			scanf("%d", &derece);
						
			printf("Denklemin katsayilarini en buyuk dereceden baslayarak sirasiyla giriniz:\n");
						
			for(i=derece; i>=0; i--){
				scanf("%d", &katsayilar[i]);
			}
			
			printf("\nDENKLEM:");
					
			for(i=derece; i>0; i--){ //EKRANA DENKLEMÝ YAZDIRMA
							
				if(i == 1 && katsayilar[i] !=0 ){
					printf("(%d)(x)+", katsayilar[i]);
				}
				else{
					if(katsayilar[i] != 1 &&  katsayilar[i] != 0 ){
						printf("(%d)(x)^%d+", katsayilar[i],i);
					}
					else if(katsayilar[i] == 1){
						printf("(x)^%d+",i);
					}	
				}	
			}
			
			if(katsayilar[0] != 0){ //EKRANA DENKLEMÝ YAZDIRMA
				printf("(%d)=0\n", katsayilar[0]);
			}
					
			printf("\nIntegralin alt sinirini giriniz:");
			scanf("%lf", &alt);
							
			printf("\nIntegralin ust sinirini giriniz:");
			scanf("%lf", &ust);
			
			printf("\nKac esit parcaya bolmek istediginizi yaziniz:");
			scanf("%d", &n);
			
			delta = (ust - alt) / n;
			
			for(i=0; i<n; i++){
				if(i == 0){
					alt_x[0] = alt;
				}
				else{
					alt_x[i] = alt_x[i-1] + delta;
				}
			}	
			
			printf("     x                f(x)\n");
			
			for(i=0; i<=n; i++){
		        alt_x[i] = alt + i * delta;
		       	for(k=0; k<=derece; k++){
					f_alt_x[i] += katsayilar[k] * (pow(alt_x[i],k)) ;
				}
				printf("\n%lf...........%lf\n", alt_x[i], f_alt_x[i]);
			}
			
			for(i=0; i<n-1; i++){
		        if((i+1) % 2 == 1){
					tek += f_alt_x[i+1];
				}
				else{
					cift += f_alt_x[i+1];
				}
			}
			
			sonuc = delta / 3 * ((f_alt_x[0] + f_alt_x[n] + 4 * tek + 2 * cift));
			printf("\nSONUC: %lf",sonuc);
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);	
			
		}
		
		else if(menu == 9){
			printf("\n\n********  TRAPEZ YONTEMI  ********\n\n\n");	
			
			printf("Denklemin maksimum derecesini giriniz: ");
			scanf("%d", &derece);
						
			printf("Denklemin katsayilarini en buyuk dereceden baslayarak sirasiyla giriniz:\n");
						
			for(i=derece; i>=0; i--){
				scanf("%d", &katsayilar[i]);
			}
			
			printf("\nDENKLEM:");
					
			for(i=derece; i>0; i--){ //EKRANA DENKLEMÝ YAZDIRMA
							
				if(i == 1 && katsayilar[i] !=0 ){
					printf("(%d)(x)+", katsayilar[i]);
				}
				else{
					if(katsayilar[i] != 1 &&  katsayilar[i] != 0 ){
						printf("(%d)(x)^%d+", katsayilar[i],i);
					}
					else if(katsayilar[i] == 1){
						printf("(x)^%d+",i);
					}	
				}	
			}
			
			if(katsayilar[0] != 0){ //EKRANA DENKLEMÝ YAZDIRMA
				printf("(%d)=0\n", katsayilar[0]);
			}
					
			printf("\nIntegralin alt sinirini giriniz:");
			scanf("%lf", &alt);
							
			printf("\nIntegralin ust sinirini giriniz:");
			scanf("%lf", &ust);
			
			printf("\nKac esit parcaya bolmek istediginizi yaziniz:");
			scanf("%d", &n);
			
			delta = (ust - alt) / n;
			
			for(i=0; i<n; i++){
				if(i == 0){
					alt_x[0] = alt;
				}
				else{
					alt_x[i] = alt_x[i-1] + delta;
				}
			}	
			
			printf("     x                f(x)\n");
			
			for(i=0; i<=n; i++){
        		alt_x[i] = alt + i * delta;
        			for(k=0; k<=derece; k++){
						f_alt_x[i] += katsayilar[k] * (pow(alt_x[i], k)) ;
					}
					printf("\n%lf...........%lf\n", alt_x[i], f_alt_x[i]);
			}
			
			for(i=1; i<n; i++){
					toplam += f_alt_x[i];
			}
			
			sonuc = delta * ((f_alt_x[0] + f_alt_x[n]) / 2 + toplam);
            printf("\nSONUC: %lf", sonuc);
			
			printf("\n\nProjeyi sonlandirmak icin 0'i, ana menuye donmek icin 1'i seciniz:");
			scanf("%d", &quit);	
			
		}
		
		else if(menu == 10){
			
			
		}
		
		else{
			printf("\nHatali secenek! Yeniden seciniz:");
			scanf("%d", &menu);
			
		}

	}
	
	return 0;
}

