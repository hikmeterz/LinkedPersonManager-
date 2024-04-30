#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct person{

	char *name;
	int numbers;
	int rank;
	struct person* next;


};
typedef struct person Person;


Person *headMale = NULL; 
Person *tailMale = NULL;

Person *headFemale = NULL; 
Person *tailFemale = NULL;


void islem_yap(char *first_flag, char *target_name ,char *dosya_isimleri[10],char *extra_flags);

Person *makePerson(int rank,char * name,int numbers);
void appendMale(Person *p);
void appendFemale(Person *p);

Person *searchMale(char *name);
Person *searchFemale(char *name);
void printMale(); 
void printFemale();

void clearMale();
void clearFemale();

Person *searchMaleContain(char *target_name);
Person *searchFemaleContain(char *name);
int flag_mi(char *c);


Person *searchMaleContain(char *name) {
  Person *tmp;
  for (tmp = headMale; tmp != NULL; tmp = tmp->next) 
    if (strstr(tmp->name,name)==0 )
      return tmp;
  return NULL;
}
Person *searchFemaleContain(char *name) {
  Person *tmp;
  for (tmp = headFemale; tmp != NULL; tmp = tmp->next) 
    if (strstr(tmp->name,name)==0 )
      return tmp;
  return NULL;
}


void printMale() {
	printf("Males\n");
	Person *tmp;
	for (tmp = headMale; tmp != NULL; tmp = tmp->next)
		printf("%d %s %d\n", tmp->rank,tmp->name,tmp->numbers);
	
}

void printFemale() {
  printf("Females\n");
  Person *tmp;
  for (tmp = headFemale; tmp != NULL; tmp = tmp->next)
    printf("%d %s %d\n", tmp->rank,tmp->name,tmp->numbers);
}



Person *makePerson(int rank,char *name,int numbers) {
  Person *new;
  
	

  if ( (new = (Person *) malloc( sizeof(Person) ) )!= NULL) {
	new->name=(char*)malloc(sizeof(char) *50 );

	new->rank =  rank;
	strcpy(new->name,name);
	new ->numbers=numbers;
    new -> next = NULL;
  }
  else {
    printf("Out of memory!\n");
    exit(0);
  }

  return new;
}


void appendMale(Person *p) {

  if (headMale == NULL) {
    headMale = p;
    tailMale = p;
  }
  else {
    tailMale->next = p;
    tailMale = p;
  }
}

void appendFemale(Person *p) {

  if (headFemale == NULL) {
    headFemale = p;
    tailFemale = p;
  }
  else {
    tailFemale->next = p;
    tailFemale = p;
  }
}
Person *searchMale(char *name) {
  Person *tmp;
  for (tmp = headMale; tmp != NULL; tmp = tmp->next) 
    if (strcmp(tmp->name,name)==0 )
      return tmp;
  return NULL;
}

Person *searchFemale(char *name) {
  Person *tmp;
  for (tmp = headFemale; tmp != NULL; tmp = tmp->next) 
    if (strcmp(tmp->name,name) ==0)
      return tmp;
  return NULL;
}
void clearMale() {
  Person *tmp, *tmp2;
  for (tmp = headMale; tmp != NULL; tmp = tmp2) {
    tmp2 = tmp->next;
	//printf("Burada\n");
	free(tmp->name);
    free(tmp);
  }
  headMale= tailMale = NULL;
}

void clearFemale() {
  Person *tmp, *tmp2;
  for (tmp = headFemale; tmp != NULL; tmp = tmp2) {
    tmp2 = tmp->next;
	free(tmp->name);
    free(tmp);
  }
  headFemale= tailFemale = NULL;
}

int flag_mi(char *c){

	if(c[0]=='-')
		return 0;
	else

		return 1;


}

void islem_yap(char *first_flag, char *target_name ,char *dosya_isimleri[10],char *extra_flags){

	
	int total_numbers=0;
	/*
	for(int i=0;i<3;i++){
		printf("dosya isimleri:%s\n",dosya_isimleri[i] );

	}*/

	printf("target_name:%s\n",target_name);
	printf("Extra flags:%s\n",extra_flags);

	printf("First flag:%s\n",first_flag);
	//char *dosyalar[3];
	printf("************************************\n");

	//dosyalar[0]="hikmet.txt";
	//dosyalar[1]="ahmet.txt";
	//dosyalar[2]="sinem.txt";

	int size=0;

	FILE *file;
	
	for(int i=0;i<3;i++){

		//printf("dosya isim:%s\n" , dosya_isimleri[i]);
		if(strcmp(dosya_isimleri[i],"") !=0){ 
			file=fopen(dosya_isimleri[i], "r");
			if(file==NULL){  
				printf("Dosya acmada hata.\n");
				exit(1);
			}	
		}else
		{
			exit(1);
		}
		printf("file name:%s\n" , dosya_isimleri[i]);
				
		
		Person *male;
		Person *female;	

		int rankFile1=0;
		int numbersFile1=0;		
		int numbersFile2=0;
		
		char *nameFile1=(char *)malloc(sizeof(char)*50);
		char *nameFile2= (char *)malloc(sizeof(char)*50);
	
	 	while(1)
		{
				
			if( fscanf(file , "%d %s %d %s %d" ,  &rankFile1,  nameFile1,  &numbersFile1, nameFile2,&numbersFile2 ) == EOF )
				break;

				male=makePerson(rankFile1,nameFile1,numbersFile1);
				//printf("%d %s %d ",male->rank,male->name,male->numbers);
				
				appendMale(male);
				female=makePerson(rankFile1,nameFile2,numbersFile2);
				appendFemale(female);
				
				
				
		}
		//if (strstr(request, "favicon") != NULL) {
    // contains
		Person *as;
		int extra_flags_sayac=1;

		// -r iceriyosa x2
		// -n iceriyosa x3
		// -p iceriyosa x5

		if(strcmp(first_flag,"-s")==0){

			if(strstr(extra_flags,"r")!=NULL)

				extra_flags_sayac*=2;

			if(strstr(extra_flags,"n")!=NULL)	
				
				extra_flags_sayac*=3;
			
			if(strstr(extra_flags,"p")!=NULL)	
				
				extra_flags_sayac*=5;




			if(extra_flags_sayac%2==0){

				as=searchMale(target_name);
				if (as!= NULL){
					printf("rank of target_name:%d\n",as->rank);
					
				}
				else
				{
					as=searchFemale(target_name);
					if (as!= NULL){
						printf("rank of target_name:%d\n",as->rank);
					
					}else
					{
						printf("There is not a target_name in this file.\n");
						continue;
					}
					
				}

			}

			as=NULL;
			if(extra_flags_sayac%3==0){

				as=searchMale(target_name);
				if (as!= NULL){
					printf("number of target_name:%d\n",as->numbers);
					
				}
				else
				{
					as=searchFemale(target_name);
					if (as!= NULL){
						printf("number of target_name:%d\n",as->numbers);
					
					}else
					{
						printf("There is not this target_name in this file.\n");
						continue;
					}
					
				}

			}
			as=NULL;
			double number=0;
			double percentage=0;
			Person *as1;
			
			if(extra_flags_sayac%5==0){

				as=searchMale(target_name);
				if (as!= NULL){

					number=as->numbers;
					for(as1 = headMale; as1 != NULL; as1 = as1->next)
   						total_numbers+= as1->numbers;

					for (as1 = headFemale; as1 != NULL; as1 = as1->next) 
   						total_numbers+= as1->numbers;  
					

					percentage=(number/total_numbers)*100;
					printf("percentages of target_name:%f\n",percentage);
					
				}
				else
				{
					
					as=searchFemale(target_name);
					if (as!= NULL){

						number=as->numbers;
						for(as1 = headMale; as1 != NULL; as1 = as1->next)
							total_numbers+= as1->numbers;

						for (as1 = headFemale; as1 != NULL; as1 = as1->next) 
							total_numbers+= as1->numbers;  
						

						percentage=(number/total_numbers)*100;
						printf("percentage of target_name:%f\n",percentage );
					}
					else
					{
						printf("There is not this target_name in this file\n");
						continue;
					}
						
				
				}

			}	






		}else{
			
			if(strstr(extra_flags,"r")!=NULL)

				extra_flags_sayac*=2;

			if(strstr(extra_flags,"n")!=NULL)	
				
				extra_flags_sayac*=3;
			
			if(strstr(extra_flags,"p")!=NULL)	
				
				extra_flags_sayac*=5;




			if(extra_flags_sayac%2==0){

				as=searchMaleContain(target_name);
				if (as!= NULL){
					printf("rank of target_name:%d\n",as->rank);
					
				}
				else
				{
					as=searchFemaleContain(target_name);
					if (as!= NULL){
						printf("rank of target_name:%d\n",as->rank);
					
					}else
					{
						printf("There is not a target_name in this file.\n");
						continue;
					}
					
				}

			}

			as=NULL;
			if(extra_flags_sayac%3==0){

				as=searchMaleContain(target_name);
				if (as!= NULL){
					printf("number of target_name:%d\n",as->numbers);
					
				}
				else
				{
					as=searchFemaleContain(target_name);
					if (as!= NULL){
						printf("number of target_name:%d\n",as->numbers);
					
					}else
					{
						printf("There is not this target_name in this file.\n");
						continue;
					}
					
				}

			}
			as=NULL;
			double number=0;
			double percentage=0;
			Person *as1;
			
			if(extra_flags_sayac%5==0){

				as=searchMaleContain(target_name);
				if (as!= NULL){

					number=as->numbers;
					for(as1 = headMale; as1 != NULL; as1 = as1->next)
   						total_numbers+= as1->numbers;

					for (as1 = headFemale; as1 != NULL; as1 = as1->next) 
   						total_numbers+= as1->numbers;  
					

					percentage=(number/total_numbers)*100;
					printf("percentage of target_name:%f\n",percentage );
					
				}
				else
				{
					
					as=searchFemaleContain(target_name);
					if (as!= NULL){

						number=as->numbers;
						for(as1 = headMale; as1 != NULL; as1 = as1->next)
							total_numbers+= as1->numbers;

						for (as1 = headFemale; as1 != NULL; as1 = as1->next) 
							total_numbers+= as1->numbers;  
						

						percentage=(number/total_numbers)*100;
						printf("percentage of target_name:%f\n",percentage );
					}
					else
					{
						printf("There is not this target_name in this file\n");
						continue;
					}
						
				
				}

			}	


			


			
		}
		
		//printMale();
		//printFemale();
		
		fclose(file);

		
		
		clearMale();
		
		clearFemale();
		free(nameFile1);
		free(nameFile2);
			


		total_numbers+=100;
	}
	printf("%d\n",total_numbers);







}



int main(int argc, char *argv[]){


    int dosya_sayac=0;
    char *a;
	a=(char *)malloc(sizeof(char)*5);
    char *first_flag;
	first_flag=(char *)malloc(sizeof(char)*5);//first flag
    char *b;
	b=(char *)malloc(sizeof(char)*5);// second check argument.
	
    char *c;
    c=(char *)malloc(sizeof(char)*5);	//third check argument  extra flags


    char *extraflags;
    extraflags=(char *)malloc(sizeof(char)*5);
    char *dosya_isimleri[10];
	for(int i=0;i<10;i++){
		dosya_isimleri[i]=(char *)malloc(sizeof(char)*30);
	}
    char *target_name;
	target_name=(char *)malloc(sizeof(char)*5);

    char *extra_seperated_flags[3];
	
	for(int i=0;i<10;i++){
		extra_seperated_flags[i]=(char *)malloc(sizeof(char)*5);
	}

    char *birlestirilmis;
	birlestirilmis=(char *)malloc(sizeof(char)*5);
    char *birlestirilmis1;
	birlestirilmis1=(char *)malloc(sizeof(char)*5);
    int i=0;


    if(argc==1){
	printf("There is no argument on command line\n");
	exit(1);

    }else{
	first_flag=argv[1];

	if(strcmp(first_flag,"-s")==0){
	

		if(argc>2){
			b=argv[2];

			if(b[0]=='-'){
				printf("You should enter a target_name not a flag.\n");
				exit(1);			

			}else{
			
				target_name=argv[2];
				if(argc>3){
				
					c=argv[3];
					   if(flag_mi(c)==0){
						if(strcmp(c,"-npr")==0||strcmp(c,"-nrp")==0||strcmp(c,"-prn")==0||strcmp(c,"-pnr")==0||strcmp(c,"-rpn")==0||strcmp(c,"-rn")==0||strcmp(c,"-nr")==0
									||strcmp(c,"-rp")==0||strcmp(c,"-pr")==0||strcmp(c,"-pn")==0||strcmp(c,"-np")==0 ){
			
							strcpy(extraflags,c);//burada dosya isimlerinini alınması lazım.
							int sayac=0;
							for(int i=4;i<argc;i++){
								c=argv[i];								
										
								strcpy(dosya_isimleri[dosya_sayac],argv[i]);
								dosya_sayac++;
								
									


							}	
							islem_yap(first_flag,target_name,dosya_isimleri,extraflags);					
							

						}else{
							int sayac=0;
							for(int i=3;i<argc;i++){
								c=argv[i];								
								if(flag_mi(c)==0){
									extra_seperated_flags[sayac]=c;//bunlardan sonra eger flags yoksa hep dosya ismi olacagını varsayıyoruz.
									sayac++;			//yani araya bir daha flag giremez..		

								}else{
									if(sayac==1){
										strcpy(extraflags,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										//islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
									}else if(sayac==2){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]);
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										//islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis);	
									}else if(sayac==3){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]); 
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcat(birlestirilmis,extra_seperated_flags[2]);
										strcpy(birlestirilmis1,birlestirilmis);										
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;	
										//islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis1);	
									}


								}



							}

							if(sayac==1)
								islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
							else if(sayac==2)
								islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis);
							else if(sayac==3)
								islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis1);

						}					
					
					
					   }else{
						strcpy(extraflags,"-rnp");//default
						//dosya isimleri burada arancak. 4ten baslancak
						for(int i=3;i<argc;i++){
							strcpy(dosya_isimleri[dosya_sayac],argv[i]);
							dosya_sayac++;
						}	
						
						
						islem_yap(first_flag,target_name,dosya_isimleri,"-rnp");
			
					   }	


				}else{
					printf("Wrong.You should enter a file name or extra flags -r -n -p \n");
					exit(1);				

				}
	
			}

		}else{
			printf("you should enter a target_name\n");
			exit(1);


		}


	
	
	}else if(strcmp(first_flag,"-v")==0){
		//printf("Esit\n");
		if(argc>2){
			b=argv[2];

			if(b[0]=='-'){
				printf("You should enter a target_name not a flag.\n");
				exit(1);			

			}else{
			
				target_name=argv[2];
				if(argc>3){
				
					c=argv[3];
					   if(flag_mi(c)==0){
						if(strcmp(c,"-npr")==0||strcmp(c,"-nrp")==0||strcmp(c,"-prn")==0||strcmp(c,"-pnr")==0||strcmp(c,"-rpn")==0||strcmp(c,"-rn")==0||strcmp(c,"-nr")==0
									||strcmp(c,"-rp")==0||strcmp(c,"-pr")==0||strcmp(c,"-pn")==0||strcmp(c,"-np")==0 ){
			
							strcpy(extraflags,c);//burada dosya isimlerinini alınması lazım.
							int sayac=0;
							for(int i=4;i<argc;i++){
								c=argv[i];								
										
								strcpy(dosya_isimleri[dosya_sayac],argv[i]);
								dosya_sayac++;

							}
							islem_yap(first_flag,target_name,dosya_isimleri,extraflags);						
							

						}else{
							int sayac=0;
							for(int i=3;i<argc;i++){
								c=argv[i];								
								if(flag_mi(c)==0){
									extra_seperated_flags[sayac]=c;//bunlardan sonra eger flags yoksa hep dosya ismi olacagını varsayıyoruz.
									sayac++;			//yani araya bir daha flag giremez..		

								}else{
									if(sayac==1){
										strcpy(extraflags,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										
									}else if(sayac==2){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]);
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;
										//islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis);	
									}else if(sayac==3){
										strcat(extra_seperated_flags[0],extra_seperated_flags[1]); 
										strcpy(birlestirilmis,extra_seperated_flags[0]);
										strcat(birlestirilmis,extra_seperated_flags[2]);
										strcpy(birlestirilmis1,birlestirilmis);										
										strcpy(dosya_isimleri[dosya_sayac],argv[i]);
										dosya_sayac++;	
										//islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis1);	
									}


								}


							}
							if(sayac==1)
								islem_yap(first_flag,target_name,dosya_isimleri,extraflags);
							else if(sayac==2)
								islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis);
							else if(sayac==3)
								islem_yap(first_flag,target_name,dosya_isimleri,birlestirilmis1);
						}					
					
					
					   }else{
						strcpy(extraflags,"-rnp");//default
						//dosya isimleri burada arancak. 4ten baslancak
						for(int i=3;i<argc;i++){
							strcpy(dosya_isimleri[dosya_sayac],argv[i]);
							
			
							dosya_sayac++;
						}
						islem_yap(first_flag,target_name,dosya_isimleri,"-rnp");
				
					   }	


				}else{
					printf("Wrong.You should enter a file name or extra flags -r -n -p \n");
					exit(1);
				}
	
			}

		}else{
			printf("you should enter a target_name\n");
			exit(1);


		}


	}else{
		printf("Wrong.You should start  with -s or -v.\n");
		exit(1);
	

	}


   }

	/*
	printf("%s\n",target_name);
	printf("%s\n",extraflags);
	printf("%s\n",first_flag);
	for(int i=0;i<10;i++)
		printf("%s\n",dosya_isimleri[i]);


	printf("%s\n",birlestirilmis);
	printf("%s\n",birlestirilmis1);
	*/

	return 0;
}



