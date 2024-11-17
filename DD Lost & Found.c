printf("Username: ");gets(l.user);
 	printf("\nPassword: ");gets(l.pass);
 	while(fread(in,sizeof(in),1,in)==1)
 {
  		if(strcmp(r.user,l.user)==0 && strcmp(r.user,l.user)==0)
  		{
  		 printf("\nSelamat datang! %s",user.uname);
   		ada=1;
  		}
 }#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void daskom(){
	printf("        	        DDDDDD    AAA    SSSSS  KK   KK   0000    MMM  MMM                          \n\
                    	DD   DD AA   AA SS      KK  KK   00  00  MM  MM  MM                         \n\
                    	DD   DD AAaaaAA  SSS    KK KK   00    00 MM  MM  MM                         \n\
                    	DD   DD AA   AA    SSS  KK KK   00    00 MM  MM  MM                         \n\
                    	DD   DD AA   AA      SS KK  KK   00  00  MM  MM  MM                         \n\
                    	DDDDDD  AA   AA  SSSSS  KK   KK   0000   MM  MM  MM                         \n\n\
		===================================================================\n\n");
}
struct login {
	char user[100],pass[100], kontak[100],acc[100];
}r,l;

struct barang{
	char nm_barang[100], tgl[100], p_barang[100], k_barang[100], status[100]; 
}b_lost,b_found,temp,slost[100],sfound[100];

int pil,login3x=3,i,j;

void menadmin();
void menpelan();
void admin();
void pelanggan();
void inlost();
void lihatlost();
void claimlost();//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
void hapuslost();
void infound();
void lihatfound();
void claimfound();//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
void listacc();
void hapusfound();
void login();//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
void regis();
void accakun();

FILE *out;
FILE *in;
FILE *lost;
FILE *lost2;
FILE *found;
FILE *found2;

main(){
	system("cls");
	daskom();
	printf("1. Admin\n2. Pelanggan\n");
	printf("Pilihan : ");scanf("%d",&pil);getchar();
	switch(pil){
		case 1 : admin();break;
		case 2 : pelanggan();break;
		default : printf("Pilihan tidak ada \n"); main();
	}
}
void admin(){
	system("cls");
	daskom();
	printf("== LOGIN ADMIN ==\n");
	printf("Username	: ");gets(l.user);
	printf("Password	: ");gets(l.pass);
	if(strcmp(l.user,"admin")==0&&strcmp(l.pass,"admin")==0){
		menadmin();
	}
	else {
		printf("Password Salah\n"); system("pause");main();
	}
	
}
void pelanggan(){
	system("cls");
	daskom();
	printf("1. Registrasi\n2. Login\n3. Kembali\n");
	printf("Pilihan	: ");scanf("%d",&pil); getchar();
	switch(pil){
		case 1 : regis();break;
		case 2 : login3x=3;login();break;
		case 3 : main();break;
		default : printf("Pilihan tidak ada \n"); pelanggan();
	}
}
void regis(){
	in=fopen("Data Pelanggan.dat","wb");
	system("cls");
	printf("== REGISTRASI ==\n");
	printf("Username :");gets(r.user);
	printf("Password :");gets(r.pass);
	printf("Kontak :");gets(r.kontak);
	printf("== REGIS BERHASIL ==\n");
	system("pause");pelanggan();
}

void login(){/////INI BELOM////
	in=fopen("Data Pelanggan.dat","rb");
	printf("== LOG IN ==\n");
	if (login3x > 3) 
	{
		while(fread(in,sizeof(in),1,in)==1){
		if ((strcmp(r.user,l.user)==0) && (strcmp(r.pass,l.pass)==0) && (strcmp(r.acc,l.acc)==0)){
			printf("== LOGIN BERHASIL ==");
			printf ("\t\t Anda bisa memulai mencari list lowongan kerja\n\n");
			fclose(in);
			system ("pause");
			menpelan();
		}
		else if(strcmp(r.acc,"acc")!=0){
			printf("Akun anda belum aktif\n");
			printf("== LOGIN GAGAL ==");
			system("pause");
			if (login3x<=3) {
				printf("\n\tSisa kesempatan untuk login = %d \n",login3x-1);
				system("pause");
				printf("\nApakah anda ingin mencoba login lagi? (y/n)\t: : ");scanf("%c",&pil);getchar();
				if (pil=='y'||pil=='Y'){
					login3x--;
					system("cls");
					login();
				}
				else {
				printf("\nTekan enter untuk balik ke menu utama!\n");
				fclose(in);
				system("cls");
				main();
				}	
		}
		else 
		{
			printf("Username/Password yang Anda masukkan salah\n");
			printf("== LOGIN GAGAL ==");
			system("pause");
			if (login3x<=3) {
				printf("\n\tSisa kesempatan untuk login = %d \n",login3x-1);
				system("pause");
				printf("\nApakah anda ingin mencoba login lagi? (y/n)\t: : ");scanf("%c",&pil);getchar();
				if(pil=='y'||pil=='Y'){
					login3x--;
					system("cls");
					login();
				}
			else {
				printf("\nTekan enter untuk balik ke menu utama!\n");
				fclose(in);
				system("cls");
				main();
			}	
			}
		}
	}
	}
		
 	}
 	else {
 		printf("\nKesempatan anda telah habis!\n");
 		system("pause");
 		fclose(in);
 		pelanggan();
	 }

	

void menpelan(){
	system("cls");daskom();
	printf("1. Lihat lost \n\
2. Input lost\n\
3. Lihat found\n\
4. Input found\n\
5. Menu Utama\n");
	printf("Pilihan	: ");scanf("%d",&pil); getchar();
	switch(pil){
		case 1 : lihatlost();claimlost();break;
		case 2 : inlost();break;
		case 3 : lihatfound();claimfound();break;
		case 4 : infound();break;
		case 5 : main();break;
		default : printf("pilihan tidak ada pada menu\npilih ulang!!!\n"); system("pause"); menadmin();break;
	}
}
void menadmin(){
	system("cls");daskom();
	printf("1. Lihat lost\n\
2. Hapus lost\n\
3. Lihat found\n\
4. Hapus found\n\
5. Acc Akun Pelanggan\n\
6. Menu utama\n");
	printf("Pilihan	: ");scanf("%d",&pil); getchar();
	switch(pil){
		case 1 : lihatlost();menadmin();break;
		case 2 : lihatlost();hapuslost();break;
		case 3 : lihatfound();menadmin();break;
		case 4 : lihatfound();hapusfound();break;
		case 5 : accakun();break;
		case 6 : main(); break;
		default : printf("pilihan tidak ada pada menu\npilih ulang!!!\n"); system("pause"); menadmin();break;
	}
}
void accakun(){
	system("cls");
	daskom();
	int no=1;
	out=fopen("Data Pelanggan.dat","rb");
	while(fread(&r,sizeof(r),1,out)==1){
		printf("\n%d. Username		: %s\n",no++,r.user);
		printf("   Password		: %s\n",r.pass);
		printf("   Kontak		: %s\n",r.kontak);
		printf("   Status ACC		: %s\n",r.acc);
	}
	fclose(out);
	char cari[100];
	printf("Masukkan Username Akun Yang Akan Di ACC	: ");gets(cari);
	out=fopen("Data pelanggan.dat","rb+");
	while(fread(&r,sizeof(r),1,out)==1){
		if(strcmp(r.user,cari)==0){
			fseek(out,(long)-sizeof(r),SEEK_CUR);
			strcpy(r.acc,"acc");
			fwrite(&r, sizeof(r), 1, out);
			printf("== TEKAN ENTER UNTUK ACC ==");getchar();
			break;
		}
	}
	printf("== ACC BERHASIL ==\n");system("pause");
	fclose(out);
	menadmin();
}

void inlost(){
	lost=fopen("Lost.dat","ab+");
	printf("Nama barang		: "); gets(b_lost.nm_barang);
	printf("Tanggal hilang (bb/hh)  : "); gets(b_lost.tgl);
	strcpy(b_lost.p_barang,r.user);
	strcpy(b_lost.k_barang,r.kontak);
	strcpy(b_lost.status,"Masih hilang");
	fwrite(&b_lost,sizeof(b_lost),1,lost);
	fclose(lost);
	menpelan();
}

void lihatlost(){
	lost=fopen("Lost.dat","rb+");
	i=0;
	int x=0;
	while(fread(&b_lost,sizeof(b_lost),1,lost)==1){
		 slost[i]=b_lost;
		 i++;x++;
	}
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if(strcmp(slost[j-1].tgl,slost[j].tgl)>0){ 
			temp=slost[j-1];
			slost[j-1]=slost[j];
			slost[j]=temp;
			}
	}
	for(i=0;i<x;i++){
		printf("\nBarang %d\n",i+1);
		printf("Nama barang 		: %s\n",slost[i].nm_barang);
		printf("Tanggal hilang (bb/hh) 	: %s\n",slost[i].tgl);
		printf("Nama pemilik 		: %s\n",slost[i].p_barang);
		printf("Kontak pemilik 		: %s\n",slost[i].k_barang);
		if(strcmp(slost[i].status,"Masih hilang")==0)
		printf("Status 			: %s\n",slost[i].status);
		else 
		printf("Status 			: Ditemukan %s\n",slost[i].status);
	}	
	fclose(lost);
	printf("\n");	
	system("pause");
}
	
void claimlost(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	
}

void infound(){
	found=fopen("Found.dat","ab+");
	printf("Nama Barang :");gets(b_found.nm_barang);
	printf(" Tanggal hilang (bb/hh) :");gets(b_found.tgl);
	system("pause");
	menpelan();
}

void lihatfound(){
	found=fopen("Found.dat","rb+");
	i=0;
	int x=0;
	while(fread(&b_found,sizeof(b_found),1,found)==1){
		 sfound[i]=b_found;
		 i++;x++;
	}
	for(i=x-1;i>=1;i--)
		for(j=1;j<=i;j++){
			if(strcmp(sfound[j-1].tgl,sfound[j].tgl)>0){ 
			temp=sfound[j-1];
			sfound[j-1]=sfound[j];
			sfound[j]=temp;
			}
	}
	for(i=0;i<x;i++){
		printf("\nBarang %d\n",i+1);
		printf("Nama barang 		: %s\n",sfound[i].nm_barang);
		printf("Tanggal hilang (bb/hh) 	: %s\n",sfound[i].tgl);
		printf("Nama pemilik 		: %s\n",sfound[i].p_barang);
		printf("Kontak pemilik 		: %s\n",sfound[i].k_barang);
		if(strcmp(sfound[i].status,"Masih hilang")==0)
		printf("Status 			: %s\n",sfound[i].status);
		else 
		printf("Status 			: Ditemukan %s\n",sfound[i].status);
	}	
	fclose(found);
	printf("\n");	
	system("pause");
}

void claimfound(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	
}

void listacc(){
	found=fopen("Found.dat","rb+");
	while(fread(&b_found,sizeof(b_found),1,found)==1){
		 if(strcmp(b_found.status,"acc")!=0&&strcmp(b_found.status,"Belum ada pemilik")!=0){
		 	printf("\nNama barang 		  : %s\n",b_found.nm_barang);
			printf("Tanggal ditemukan (bb/hh) : %s\n",b_found.tgl);
			printf("Nama penemu 		  : %s\n",b_found.p_barang);
			printf("Kontak penemu 		  : %s\n",b_found.k_barang);
			printf("Peng-claim 		  : %s\n",b_found.status);
		 }
	}
	fclose(found);
}

void hapuslost(){
	int i,offset_byte;
	char hps[100], kfr;
	lost = fopen("Found.dat", "rb");
	printf("\nMasukkan nama barang yang akan anda hapus : "); gets(hps);
	printf("\nData barang yang ingin anda hapus : ");
	while (fread(&b_lost,sizeof(b_lost),1, lost)==1){
		if (strcmp(b_lost.nm_barang,hps)==0){
			offset_byte=i*sizeof(b_lost);
		}else i++;
	}
	fseek(lost, offset_byte, SEEK_SET);
	if (fread(&b_lost, sizeof (b_lost), 1, lost) != 0){
		printf("\nNama barang 		  : %s\n",b_lost.nm_barang);
		printf("Tanggal ditemukan (bb/hh) : %s\n",b_lost.tgl);
		printf("Nama penemu 		  : %s\n",b_lost.p_barang);
		printf("Kontak penemu 		  : %s\n",b_lost.k_barang);
		printf("Peng-claim 		  : %s\n",b_lost.status);
	} 
	fclose(lost);
	printf("Apakah anda yakin ingin menghapus barang? [y/n] : "); scanf("%c",&kfr);
	if (kfr=='Y'||kfr=='y'){
		lost = fopen("Lost.dat", "rb");
		lost2 = fopen("Lost2.dat","wb");
		while (fread(&b_lost,sizeof (b_lost),1, lost)==1){
		if (strcmp(b_lost.nm_barang,hps)!=0){
			fwrite(&b_lost, sizeof(b_lost), 1, lost2);
			}
		}
		fclose(lost);
		fclose(lost2);
		remove("Lost.dat");
		rename("Lost2.dat","Lost.dat");
		menadmin();
	}else {
		menadmin();
	}
}
	
}

void hapusfound(){
	int i,offset_byte;
	char hps[100], kfr;
	found = fopen("Found.dat", "rb");
	printf("\nMasukkan nama barang yang akan anda hapus : "); gets(hps);
	printf("\nData barang yang ingin anda hapus : ");
	while (fread(&b_found,sizeof(b_found),1, found)==1){
		if (strcmp(b_found.nm_barang,hps)==0){
			offset_byte=i*sizeof(b_found);
		}else i++;
	}
	fseek(found, offset_byte, SEEK_SET);
	if (fread(&b_found, sizeof (b_found), 1, found) != 0){
		printf("\nNama barang 		  : %s\n",b_found.nm_barang);
		printf("Tanggal ditemukan (bb/hh) : %s\n",b_found.tgl);
		printf("Nama penemu 		  : %s\n",b_found.p_barang);
		printf("Kontak penemu 		  : %s\n",b_found.k_barang);
		printf("Peng-claim 		  : %s\n",b_found.status);
	} 
	fclose(found);
	printf("Apakah anda yakin ingin menghapus barang? [y/n] : "); scanf("%c",&kfr);
	if (kfr=='Y'||kfr=='y'){
		found = fopen("Found.dat", "rb");
		found2 = fopen("Found2.dat","wb");
		while (fread(&b_found,sizeof (b_found),1, found)==1){
		if (strcmp(b_found.nm_barang,hps)!=0){
			fwrite(&b_found, sizeof(b_found), 1, found2);
			}
		}
		fclose(found);
		fclose(found2);
		remove("Found.dat");
		rename("Found2.dat","Found.dat");
		menadmin();
	}else {
		menadmin();
	}
}
 	fclose(in);
 	 
 	return main();
	}
}
