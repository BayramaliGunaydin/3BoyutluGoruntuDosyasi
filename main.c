#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <math.h>
struct Nokta
{
    float x;
    float y;
    float z;
    int r;
    int g;
    int b;
    char hata1;
    char hata2;
};
int main()
{
    int secim;
    int q=0;
    DIR *d;
    struct dirent *dir;
    float eny=99999.0,enu=0.0,sonuc=0.0;
    int m,n,eny1,eny2,enu1,enu2;
    double tplmnktsys;
    int k=0;
    int dizi[k];
    int count = 0;
    int sayacc =0;
    int kalanyer = 0;
    while(1)
    {
        printf("\t MENU\n");
        printf("1-Dosyalari oku ve dogrula.\n");
        printf("2-En yakin ve en uzak noktalari bul.\n");
        printf("3-Tum noktalari icine alan en kucuk kupun noktalarini bul.\n");
        printf("4-Merkez koordinatlari ve yaricapi verilen kurenin icinde kalan noktalari bul.\n");
        printf("5-Tum noktalarin birbirine uzakliklarinin ortalamasini bul.\n");
        printf("Programi sonlandirmak icin 6 giriniz");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            d = opendir("C:\\prolab1\\");
            char adres_dizim[20][26];
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {
                    if(dir->d_name[strlen(dir->d_name)-1]=='t')
                    {
                        if(dir->d_name[strlen(dir->d_name)-2]=='k')
                        {
                            if(dir->d_name[strlen(dir->d_name)-3]=='n')
                            {
                                if(dir->d_name[strlen(dir->d_name)-4]=='.')
                                {
                                    if(dir->d_name[strlen(dir->d_name)-5]!='t'){

                                    strcpy(adres_dizim[k],dir->d_name);
                                    k++;}
                                }
                            }
                        }
                    }
                }
                closedir(d);
            }

            int sayac=0;
            char buf[100];
            int i=0;
            int l=0;
            int hata1=0,hata2=0;
            int bosluk=0;
            int satirsayisi=1;
            int ascii=0;
            int verkontrol=0;
            int alankontrol=0;
            int noktakontrol=0;
            struct Nokta *Noktalar;
            FILE *dosya;
            FILE *output;
            output=fopen("C:\\prolab1\\output.nkt","w+");
            Noktalar=malloc(1000000*sizeof(Noktalar));
            while(sayac<k)
            {
                printf("%s\n",adres_dizim[sayac]);
                char dosyayolu[]="C:\\prolab1\\";
                strcpy(dosyayolu,"C:\\prolab1\\");
                strcat(dosyayolu,adres_dizim[sayac]);
                dosya=fopen(dosyayolu,"r");
                if(dosya==NULL)
                {
                    printf("dosya yok");
                }
                else
                {
                    fgets(buf,100,dosya);
                    fscanf(dosya,"%s",buf);
//printf("%s",buf);
                    if(strcmp(buf,"VERSION")==0)
                    {
                        fgets(buf,100,dosya);
                        verkontrol++;
                    }
                    fscanf(dosya,"%s",buf);
                    if(strcmp("ALANLAR",buf)==0)
                    {
                        fgetc(dosya);
                        if(fgetc(dosya)=='x')
                        {
                            fgetc(dosya);
                            if(fgetc(dosya)=='y')
                            {
                                fgetc(dosya);
                                if(fgetc(dosya)=='z')
                                {
                                    alankontrol++;
                                    if(fgetc(dosya)!='\n')
                                    {
                                        if(fgetc(dosya)=='r')
                                        {
                                            fgetc(dosya);
                                            if(fgetc(dosya)=='g')
                                            {
                                                fgetc(dosya);
                                                if(fgetc(dosya)=='b')
                                                {
                                                    alankontrol++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    fscanf(dosya,"%s",buf);
                    if(strcmp(buf,"NOKTALAR")==0)
                    {
                        noktakontrol++;
                    }
                    fgets(buf,8,dosya);
                    fgets(buf,5,dosya);
                    if(strcmp(buf,"DATA")==0)
                    {
                        fgetc(dosya);
                        char d=fgetc(dosya);
                        if(d=='a')
                        {
                            ascii++;
                        }
                        if(d=='b')
                        {
                            ascii=ascii+2;
                        }
                    }
                    fgets(buf,100,dosya);
                    if(alankontrol==2&&ascii==1)
                    {
                        while(!feof(dosya))
                        {
                            if(satirsayisi>5)
                            {
                                if(bosluk==0)
                                {
                                    fscanf(dosya,"%9f",&Noktalar[i].x);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==1)
                                {
                                    fscanf(dosya,"%9f",&Noktalar[i].y);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==2)
                                {
                                    fscanf(dosya,"%9f",&Noktalar[i].z);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==3)
                                {
                                    fscanf(dosya,"%d",&Noktalar[i].r);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==4)
                                {
                                    fscanf(dosya,"%d",&Noktalar[i].g);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==5)
                                {
                                    fscanf(dosya,"%d",&Noktalar[i].b);
                                    bosluk++;
                                    bosluk=0;
                                    if(fgetc(dosya)!='\n' && fgetc(dosya)!=EOF)
                                    {
                                        fgets(buf,100,dosya);
                                        Noktalar[hata1].hata1=satirsayisi-5;
                                        hata1++;
                                        bosluk=0;
                                    }
                                }
                                i++;
                                satirsayisi++;
                            }
                            else
                            {
                                satirsayisi=6;
                                if(verkontrol==0 || noktakontrol==0 || alankontrol==0 || noktakontrol==0 || ascii==0)
                                {
                                    continue;
                                }
                            }
                        }
                    }
                    if(alankontrol==1&&ascii==1)
                    {
                        while(!feof(dosya))
                        {
                            if(satirsayisi>5)
                            {
                                if(bosluk==0)
                                {
                                    fscanf(dosya,"%9f",&Noktalar[i].x);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==1)
                                {
                                    fscanf(dosya,"%9f",&Noktalar[i].y);
                                    bosluk++;
                                    if(fgetc(dosya)=='\n')
                                    {
                                        Noktalar[hata2].hata2=satirsayisi-5;
                                        hata2++;
                                        bosluk=0;
                                    }
                                }
                                if(bosluk==2)
                                {
                                    fscanf(dosya,"%f",&Noktalar[i].z);
                                    bosluk++;
                                    bosluk=0;
                                    if(fgetc(dosya)!='\n' && fgetc(dosya)!=EOF)
                                    {
                                        fgets(buf,100,dosya);
                                        Noktalar[hata1].hata1=satirsayisi-5;
                                        hata1++;
                                        bosluk=0;
                                    }
                                }
                                i++;
                                satirsayisi++;
                            }
                            else
                            {
                                satirsayisi=6;
                                if(verkontrol==0 || noktakontrol==0 || alankontrol==0 || noktakontrol==0 || ascii==0)
                                {
                                continue;
                                }
                            }
                        }
                    }
                    if(alankontrol==2&&ascii==2)
                    {
                        while(!feof(dosya))
                        {
                            fread(&Noktalar[i].x,sizeof(float),1,dosya);
                            if(Noktalar[i].x==0.000000)
                            {
                                break;
                            }
                            fread(&Noktalar[i].y,sizeof(float),1,dosya);

                            fread(&Noktalar[i].z,sizeof(float),1,dosya);
                            fread(&Noktalar[i].r,sizeof(int),1,dosya);
                            fread(&Noktalar[i].g,sizeof(int),1,dosya);
                            fread(&Noktalar[i].b,sizeof(int),1,dosya);
                            i++;
                            satirsayisi++;
                        }
                    }
                    if(alankontrol==1&&ascii==2)
                    {
                        while(!feof(dosya))
                        {
                            fread(&Noktalar[i].x,sizeof(float),1,dosya);
                            if(Noktalar[i].x==0.000000)
                            {
                                break;
                            }
                            fread(&Noktalar[i].y,sizeof(float),1,dosya);
                            fread(&Noktalar[i].z,sizeof(float),1,dosya);
                            i++;
                            satirsayisi++;
                        }
                    }
                    if(verkontrol==1)
                    {
                        printf("Versiyon dogrulama basarili.\n",adres_dizim[sayac]);
                    }
                    else
                    {
                        fprintf(output,"%s Dosyasinda versiyon dogrulama basarisiz.\n",adres_dizim[sayac]);
                        printf("%s Dosyasinda versiyon dogrulama basarisiz.\n",adres_dizim[sayac]);

                    }
                    if(alankontrol==1)
                    {
                        printf("Alan dogrulama basarili. Alan x y z seklinde verilmis.\n");
                    }
                    else if(alankontrol==2)
                    {
                        printf("Alan dogrulama basarili. Alan x y z r g b seklinde verilmis.\n");
                    }
                    else
                    {
                        fprintf(output,"%s Dosyasinda alan dogrulama basarisiz.\n",adres_dizim[sayac]);
                        printf("%s Dosyasinda alan dogrulama basarisiz.\n",adres_dizim[sayac]);

                    }
                    if(noktakontrol==1)
                    {
                        printf("Nokta sayisi dogrulama basarili.\n");
                    }
                    else
                    {
                        fprintf(output,"%s Dosyasinda nokta sayisi dogrulama basarisiz.\n",adres_dizim[sayac]);
                        printf("%s Dosyasinda nokta sayisi dogrulama basarisiz.\n",adres_dizim[sayac]);
                    }
                    if(ascii==1)
                    {
                        printf("Data dogrulama basarili. Data ascii seklinde verilmis.\n\n");
                    }
                    else if(ascii==2)
                    {
                        printf("Data dogrulama basarili. Data binary seklinde verilmis.\n");
                    }
                    else
                    {
                        printf("%s Dosyasinda data dogrulama basarisiz.\nDosya okuma sonlandirildi.\n\n",adres_dizim[sayac]);
                        fprintf(output,"%s Dosyasinda data dogrulama basarisiz.\nDosya okuma sonlandirildi.\n\n",adres_dizim[sayac]);
                        for(q=sayac;q<k;q++){
                                            strcpy(adres_dizim[q],adres_dizim[q+1]); }k--;sayac--;
                                        }

                    if(hata1!=0)
                    {
                        for(l=0; l<hata1; l++)
                        {
                            fprintf(output,"%s dosyasinda %d. satirda fazladan bilgi vardir.\n",adres_dizim[sayac],Noktalar[l].hata1);
                        }
                    }
                    if(hata2!=0)
                    {
                        for(l=0; l<hata2; l++)
                        {
                            fprintf(output,"%s dosyasinda %d. satirda eksik bilgi vardir.\n",adres_dizim[sayac],Noktalar[l].hata2);
                        }
                    }
                    else
                    {
                        if(verkontrol==1&&noktakontrol==1&&(alankontrol==1||alankontrol==2))
                        {
                            fprintf(output,"%s dosya basariyla okundu.Toplam %d kadar nokta bilgisi okunup bellege kaydedilmistir.\n\n",adres_dizim[sayac],i);
                            dizi[count]=i;
                            count++;
                        }
                    }
                    sayac++;
                    hata1=0;
                    hata2=0;
                    satirsayisi=6;
                    verkontrol=0;
                    alankontrol=0;
                    noktakontrol=0;
                    ascii=0;
                    tplmnktsys = 100;
                }
            }
            fclose(dosya);
            break;
        case 2:
            fprintf(output,"\nSECIM2");
            for(sayacc=0; sayacc<k; sayacc++)
            {
                fprintf(output,"\n%s",adres_dizim[sayacc]);
                for(m=kalanyer; m<dizi[sayacc]; m++)
                {
                    for(n=m+1; n<dizi[sayacc]; n++)
                    {
                        sonuc=sqrt(pow(Noktalar[m].x-Noktalar[n].x,2)+pow(Noktalar[m].y-Noktalar[n].y,2)+pow(Noktalar[m].z-Noktalar[n].z,2));
                        if(sonuc<eny)
                        {
                            eny=sonuc;
                            eny1=m+1;
                            eny2=n+1;
                        }
                        if(sonuc>enu)
                        {
                            enu=sonuc;
                            enu1=m+1;
                            enu2=n+1;
                        }
                    }
                }
                fprintf(output,"\nEn yakin iki noktadan 1.sinin koordinatlari:%d-,%f,%f,%f,%d,%d,%d",eny1,Noktalar[eny1].x,Noktalar[eny1].y,Noktalar[eny1].z,Noktalar[eny1].r,Noktalar[eny1].g,Noktalar[eny1].b);
                fprintf(output,"\nEn yakin iki noktadan 2.sinin koordinatlari:%d-,%f,%f,%f,%d,%d,%d",eny2,Noktalar[eny2].x,Noktalar[eny2].y,Noktalar[eny2].z,Noktalar[eny2].r,Noktalar[eny2].g,Noktalar[eny2].b);
                fprintf(output,"\nEn uzak iki noktadan 1.sinin koordinatlari:%d-,%f,%f,%f,%d,%d,%d",enu1,Noktalar[enu1].x,Noktalar[enu1].y,Noktalar[enu1].z,Noktalar[enu1].r,Noktalar[enu1].g,Noktalar[enu1].b);
                fprintf(output,"\nEn uzak iki noktadan 2.sinin koordinatlari:%d-,%f,%f,%f,%d,%d,%d",enu2,Noktalar[enu2].x,Noktalar[enu2].y,Noktalar[enu2].z,Noktalar[enu1].r,Noktalar[enu1].g,Noktalar[enu1].b);
                kalanyer = dizi[sayacc]+1;
                sonuc = 0;
            }
            printf("\nSECIM2:Birbirine en yakin ve en uzak iki nokta bulundu.\n");
            break;
        case 3:
            fprintf(output,"\nSECIM3");
            kalanyer = 0;
            for(sayacc=0; sayacc<k; sayacc++)
            {
                fprintf(output,"\n%s",adres_dizim[sayacc]);
                int enb = 0,enk = 0;
                for(i=kalanyer; i<dizi[sayacc]; i++)
                {
                    if(Noktalar[i].x>Noktalar[enb].x)
                    {
                        enb=i;
                    }
                    if(Noktalar[i].x<Noktalar[enk].x)
                    {
                        enk=i;
                    }
                }
                for(i=kalanyer; i<dizi[sayacc]; i++)
                {
                    if(Noktalar[i].y>Noktalar[enb].y)
                    {
                        enb=i;
                    }

                    if(Noktalar[i].y<Noktalar[enk].y)
                    {
                        enk=i;
                    }
                }
                for(i=kalanyer; i<dizi[sayacc]; i++)
                {
                    if(Noktalar[i].z>Noktalar[enb].z)
                    {
                        enb=i;
                    }
                    if(Noktalar[i].z<Noktalar[enk].z)
                    {
                        enk=i;
                    }
                }
                /*
                fprintf(output,"\nEn buyuk x degeri: %f",Noktalar[enb].x);
                fprintf(output,"\nEn kucuk x degeri: %f",Noktalar[enk].x);
                fprintf(output,"\nEn buyuk y degeri: %f",Noktalar[enb].y);
                fprintf(output,"\nEn kucuk y degeri: %f",Noktalar[enk].y);
                fprintf(output,"\nEn buyuk z degeri: %f",Noktalar[enb].z);
                fprintf(output,"\nEn kucuk z degeri: %f",Noktalar[enk].z);
                */
                float enbxyz = 0, enkxyz = 9999;
                if (Noktalar[enb].x>Noktalar[enb].y && Noktalar[enb].x>Noktalar[enb].z)
                {
                    enbxyz = Noktalar[enb].x;
                }
                if (Noktalar[enb].y>Noktalar[enb].x && Noktalar[enb].y>Noktalar[enb].z)
                {
                    enbxyz = Noktalar[enb].y;
                }
                if (Noktalar[enb].z>Noktalar[enb].x && Noktalar[enb].z>Noktalar[enb].y)
                {
                    enbxyz = Noktalar[enb].z;
                }
                if (Noktalar[enk].x<Noktalar[enk].y && Noktalar[enk].x<Noktalar[enk].z)
                {
                    enkxyz = Noktalar[enk].x;
                }
                if (Noktalar[enk].y<Noktalar[enk].x && Noktalar[enk].y<Noktalar[enk].z)
                {
                    enkxyz = Noktalar[enk].y;
                }
                if (Noktalar[enk].z<Noktalar[enk].x && Noktalar[enk].z<Noktalar[enk].y)
                {
                    enkxyz = Noktalar[enk].z;
                }
                fprintf(dosya,"\nKupun noktalari: ");
                fprintf(output,"\n%f     %f     %f",enbxyz,enbxyz,enbxyz);
                fprintf(output,"\n%f     %f     %f",enkxyz,enbxyz,enbxyz);
                fprintf(output,"\n%f     %f     %f",enkxyz,enbxyz,enkxyz);
                fprintf(output,"\n%f     %f     %f",enbxyz,enbxyz,enkxyz);
                fprintf(output,"\n%f     %f     %f",enbxyz,enkxyz,enbxyz);
                fprintf(output,"\n%f     %f     %f",enkxyz,enkxyz,enbxyz);
                fprintf(output,"\n%f     %f     %f",enkxyz,enkxyz,enkxyz);
                fprintf(output,"\n%f     %f     %f",enbxyz,enkxyz,enkxyz);
                kalanyer = dizi[sayacc]+1;
            }
            printf("\nSECIM3:Tum noktalari icine alan en kucuk kupun noktalari bulundu\n");
            break;
        case 4:
            fprintf(output,"\nSECIM4\n");
            float cx,cy,cz,mesafe;
            float yaricap;
            printf("Kurenin merkezinin x koordinatini giriniz.");
            scanf("%f",&cx);
            printf("Kurenin merkezinin y koordinatini giriniz.");
            scanf("%f",&cy);
            printf("Kürenin merkezinin z koordinatini giriniz.");
            scanf("%f",&cz);
            printf("Kurenin yaricapini giriniz.");
            scanf("%f",&yaricap);
            fprintf(output,"Kurenin icinde kalan noktalar:");
            kalanyer = 0;
            for(sayacc=0; sayacc<k; sayacc++)
            {
                fprintf(output,"\n%s",adres_dizim[sayacc]);
                for (i=kalanyer; i<dizi[sayacc]; i++)
                {
                    mesafe=sqrt(pow(Noktalar[i].x-cx,2)+pow(Noktalar[i].y-cy,2)+pow(Noktalar[i].z-cz,2));
                    if(mesafe<yaricap||mesafe==yaricap)
                    {
                        fprintf(output,"\n%f     %f     %f     %d     %d     %d",Noktalar[i].x,Noktalar[i].y,Noktalar[i].z,Noktalar[i].r,Noktalar[i].g,Noktalar[i].b);
                    }
                }
                kalanyer = dizi[sayacc]+1;
            }
            printf("\nSECIM4:x,y,z ve r'si verilen kurenin icinde kalan noktalar bulundu\n");
            break;
        case 5:
            fprintf(output,"\nSECIM5\n");
            i = 0;
            int    j = 0;
            double toplam = 0,ortalama = 0;
            kalanyer = 0;
            float noktasayisi;
            float uzaklik = 0;
            double sayacbes = 0;
            for(sayacc=0; sayacc<k; sayacc++)
            {
                fprintf(output,"\n%s",adres_dizim[sayacc]);
                for(i=kalanyer; i<dizi[sayacc]; i++)
                {
                    for(j=i+1; j<dizi[sayacc]; j++)
                    {
                        uzaklik = sqrt(pow(Noktalar[i].x-Noktalar[j].x,2)+pow(Noktalar[i].y-Noktalar[j].y,2)+pow(Noktalar[i].z-Noktalar[j].z,2));
                        toplam = toplam + uzaklik;
                    noktasayisi=noktasayisi+1;
                    sayacbes++;
                    }
                }
                ortalama = toplam / sayacbes;
                fprintf(output,"Noktalarin birbirine gore uzakliklarinin ortalamalari:%f",ortalama);
                kalanyer = dizi[sayacc] +1;
                toplam = 0;
                ortalama = 0;
                sayacbes = 0;
            }
            printf("\nSECIM5:Tum noktalarin birbirine olan uzakliklarinin ortalamasi bulundu.\n");
            break;
        case 6:
            return 0;
        default:
            printf("Yanlis giris yaptiniz tekrar giris yapiniz.\n");
            break;
        }
    }
    return 0;
}
