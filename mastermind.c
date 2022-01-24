
#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 

 
    /* FUNCTIONS DECLARATION */

    void showGuide(void); /* All guiding instructions  */ 
    void chooseLevel(void);/* prompt user for level .*/
    void takeArray(void);/*Takes the code from player one */
    void beginnerLevel(void); /*manage all beginner level*/
    void expertLevel(void);/* Manage all expert level*/
    int  showJokerHint(void); /* Gives player two a hint for a digit  */
    void showFinalResult(void); /*Displays final result */
	int  startAgain(void); /* Restarts the game */ 
	void RESET(void); /* reinitialize variables to start point*/
 
 
    /* Arrays declaration*/

    int  beginnerMainCode[5];    /* Stores beginner main Code*/ 
    int beginnerSecondaryCode[5];/*Stores player two guesiing code in level one*/
  
    char expertMainCode[6];      /* Stores expert main Code*/
    char expertSecondaryCode[6]; /* Stores expert guessing code*/
    
/* Variables declaration*/

     int i,j;
     int cases=5; 
     int once=0;
     int LEVEL; /* Stores current level : if one, its beginner, if two, then its expert */
     int iterationNumber=1;  /*Stores current iteration in the game  */
     int Mal_Place,Bien_Place;/*indique Bien placé de joker*/
     int isJokerUsed=0;/* Stores if the player has used Joker hint or not*/
     char p;
     char touch;
     FILE *fic=NULL ;
     
   
     
     
   
   
     void RESET(void){
     	
	isJokerUsed=0; 

	iterationNumber=1; 
	Mal_Place=0,Bien_Place=0;
}

     
int main(){ 
  if (once==0) 
	{
		showGuide();
	}
	   RESET();
      chooseLevel();
  if ( LEVEL==1 )
   {  
        takeArray();
        puts(" ");
        beginnerLevel();
        showFinalResult();
        startAgain();
        getch();    
}


  if ( LEVEL==2 )
   {
       takeArray();
       puts(" ");
       expertLevel();
       showFinalResult();
       startAgain();
       getch();
}

    return 0;
}


         /*showGuide function*/
         
  
void showGuide(void){
	system("COLOR 2f");
		printf("\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",200,200,200,205,205,205,205,205,205,205,205,205,205,205,205,200,200,200);
    printf ("\t\t\t\t\t\t\t%c   MASTERMIND   %c \n",186,186);
    printf("\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",200,200,200,205,205,205,205,205,205,205,205,205,205,205,205,200,200,200);;
    puts(" ");
    puts(" ");
    fic = fopen("Jouer.save","w");
	char p[20];
	printf(" ENTER YOUR NAME : ");
	gets(p);
   if (fic == NULL){
         exit(1);
		 }
		 else{
    fputs(p,fic);
    fclose(fic);
     }
	printf("   Welcome  %s  \n",p);
	puts("   Click any key for game guides  ");
getch();
system("cls");
puts(" ");
puts(" "); 
printf(" \t\t\t\%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,201,201);;
printf(" \t\t\t\%c MasterMind is a game of concentration and possibilities               %c\n",186,186);
printf(" \t\t\t\%c The goal in MasterMind is to correctly guess the code entered by the  %c\n",186,186);
printf(" \t\t\t\%c Oponnent. The First player Should enter a code of 5 digits            %c\n",186,186);
printf(" \t\t\t\%c The other Should guess The code.                                      %c\n",186,186);
printf(" \t\t\t\%c Your have the choice to of two levels.                                %c\n",186,186);
printf(" \t\t\t\%c                                                                       %c\n",186,186);
printf(" \t\t\t\%c                                                                       %c\n",186,186);
printf(" \t\t\t\%c%c%cBIGINNER LEVEL%c%c:You Should guess The code composed                  %c\n",186,186,186,186,186,186);
printf(" \t\t\t\%c                       of 5 distinct in 20 tries                       %c\n",186,186);
printf(" \t\t\t\%c                                                                       %c\n",186,186);
printf(" \t\t\t\%c                                                                       %c\n",186,186);
printf(" \t\t\t\%c%c%cEXPER LEVEL   %c%c:You Should guess The code composed De 5 ??          %c\n",186,186,186,186,186,186);
printf(" \t\t\t\%c                       Lettrs numbers ,on even a spaces                %c\n",186,186);
printf(" \t\t\t\%c                       The digist can be repeted.                      %c\n",186,186);
printf(" \t\t\t\%c                                                                       %c\n",186,186);
printf(" \t\t\t\%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,201,201);;
puts(" ");
puts("                                       Click any key for CONTINUIE ");
getch();
system("cls");
system("COLOR 2f");
puts(" ");
puts(" ");
printf(" \t\t\t\%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);;
printf("\t\t\t\t\t\t\t%c   JOKER   %c \n",186,186);
printf(" \t\t\t\%c                                                                                    %c\n",186,186);
printf(" \t\t\t\%c You have the right to use it the JOKER.                                            %c\n",186,186);
printf(" \t\t\t\%c The JOKER is offered from The 10th try and beyond.                                 %c\n",186,186);
printf(" \t\t\t\%c                So what is JOKER ?                                                  %c\n",186,186);
printf(" \t\t\t\%c When You use it it alows you to see whats in a certain digit                       %c\n",186,186);
printf(" \t\t\t\%c You chosed , and this digit Will no longer be a secret.                            %c\n",186,186);
printf(" \t\t\t\%c BUT BE CAUTIOUS!!: because When you use JOKER You Lose 3 tries.                    %c\n",186,186);
printf(" \t\t\t\%c For example When you use it at the 10th try.                                       %c\n",186,186);                                                                           
printf(" \t\t\t\%c You Pass directly to the 13th.                                                     %c\n",186,186);
printf(" \t\t\t\%c And When used at 17th try you finish the game.                                     %c\n",186,186);                                              
printf(" \t\t\t\%c                                                                                    %c\n",186,186);
printf(" \t\t\t\%c                     call JOKER ?                                                   %c\n",186,186);
printf(" \t\t\t\%c                                                                                    %c\n",186,186);
printf(" \t\t\t\%c When you reach 10th try you Will be prompted to use the Joker.                     %c\n",186,186);
printf(" \t\t\t\%c Have a good play.                                                                  %c\n",186,186);
printf(" \t\t\t\%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);;
once=1;
puts("                                         Click any key for CONTINUIE        ");
getch();
system("cls");
}

     
      
      /* chooseLevel Function */
      

void chooseLevel(void){ 
   
   
    char X;
    system("COLOR 2f");
    printf(" \n");
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf ("\t%c BIGINNER LEVEL %c \n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf ("\t%c EXPER LEVEL    %c\n",186,186);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

    printf(" D: For BIGINNER LEVEL     ******      E:For EXPER LEVEL     ******      Q:For QUITE:");

        do
        { 
        X=getch();
        }
        while (X!='D'&& X!='d'&& X!='E'&& X!='e' && X!='Q'&& X!='q');
  if(X=='Q'|| X=='q')
  exit(0);
  if (X=='D'|| X=='d')
   {
   	puts(" ");
    puts(" ");
    puts(" You have chosen  The BIGINNER LEVEL      ");
	puts(" Click any key To CONTINUIE ...          ");
		getch();
		system("cls");
    printf("\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        system("COLOR 03");
    printf ("\t\t\t\t\t\t\t  BIGINNER LEVEL \n");
    printf("\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);;
    puts(" ");
    puts(" ");
	puts(" THE CODE CAN NOT CONTAIN OTHER Than Positif Number ");
	puts(" The digit must be distinct case                    ");
	puts(" Chaque Should only contain one gigit               ");
	puts(" Enter Your Secret Code :                           ");
	puts(" ");
	LEVEL=1;
    
 }

 if (X=='E'|| X=='e')
   {   
    puts(" ");
    puts(" ");
    puts(" You have chosen The EXPER LEVEL          ");
	puts(" Click any key To CONTINUIE ...          ");
		getch();
		system("cls");
    printf("\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    system("COLOR 03");
    printf ("\t\t\t\t\t\t\t   EXPER LEVEL \n");
    printf("\t\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    puts(" ");
    puts(" ");
	puts(" The Secret code can contain anything (Numbers , Lettres , Spaces ! )");
	puts(" The digits can be repeted                                           ");
	puts(" Enter Your Secret Code :                                            ");
    LEVEL=2;

  } 
  }
  
    
                  /*beginnerLevel Function*/


void beginnerLevel(void){
	
	
	puts(" THE CODE CAN NOT CONTAIN OTHER Than Positif Number ");
	puts(" The digit must be distinct case                    ");
	puts(" Chaque Should only contain one gigit               ");
	puts(" Enter Your Secret Code :                           ");
    int erreur=0;
    while( iterationNumber<=20 && Bien_Place!=cases)
   {     printf("%deme Intantitive \n", iterationNumber);
    Bien_Place=0;
    Mal_Place=0;
    for(i=0;i<cases;i++)
    {   
        printf(" case %d : ",i);
        scanf("%d",&beginnerSecondaryCode[i]);
    }
    for (i=0;i<cases;i++)
    {
	for (j=i+1;j<cases;j++) {
	if (beginnerSecondaryCode[i]==beginnerSecondaryCode[j]) {
	erreur=1; break;
	 }
	}
  }
    if (erreur==1){ 
	printf(" You entred identical digits, try again   \n");
	beginnerLevel();
	}
    if (erreur==0)
    {
        for (i=0;i<cases;i++)
          {
            if ( beginnerMainCode[i]==beginnerSecondaryCode[i] ) {
			Bien_Place++;
			}
            for(j=0;j<cases;j++){
			if(beginnerSecondaryCode[i]==beginnerMainCode[j] && i!=j){
			Mal_Place++;
			} 
		   }
         }
      }

    if ( Bien_Place!=0 ) {
	printf(" %d Bien placs\n",Bien_Place);
	
	}
    if ( Mal_Place!=0 ) {
	printf(" %d Mal placs\n",Mal_Place);  
	}
    if ( Bien_Place==0 && Mal_Place==0)puts(" There is no Connespondance !! \n");
    if ( Bien_Place==cases) break;
    puts(" ");
    iterationNumber++;
    if ( iterationNumber>=10 && iterationNumber<18 && isJokerUsed==0 )
    { if (iterationNumber==10)
     {
        printf(" The Joker is available ,tap one of The following keys:\n");
        printf(" tap 'Y' To use JOKER , 'N' to not  use               \n");
     }
        showJokerHint();
    }
    
}
}


         
		  
	  /* expertLevel function*/
           
           

void expertLevel(void){
	
	char T[20];
    int null=0;
    
    system("COLOR 3");
	puts(" The Secret code can contain anything (Numbers , Lettres , Spaces ! )");
	puts(" The digits can be repeted                                           ");
	puts(" Enter Your Secret Code :                                            ");
	
    while( iterationNumber<=20 && Bien_Place!=cases){
	printf("%deme Intantitive \n",iterationNumber);
    Bien_Place=0;
    Mal_Place=0;
    for (i=0;i<cases;i++)
	{
	 T[i]= expertMainCode[i]; 
	}
    puts(" ");
    for(i=0;i<cases;i++)
    {
        printf(" case %d : ",i);
        expertSecondaryCode[i] = getchar();
       while(getchar()!='\n');
    }


     for (i=0;i<cases;i++)
     {
	  if( T[i]==expertSecondaryCode[i] )
	 { 
	    Bien_Place++; T[i]='*'; expertSecondaryCode[i]='.';
	 }
	   
     }   
        for(i=0;i<cases;i++)
        {
		 for(j=0;j<cases;j++)
        { 
		if (T[i]==expertSecondaryCode[j] && i!=j)
		{ 
		Mal_Place++; T[i]='-'; expertSecondaryCode[j]='/';
		
		}
	 }
	}

    if ( Bien_Place!=0 ) 
	{
	printf(" %d Bien places\n",Bien_Place);
	}
    if ( Mal_Place!=0 ) 
	{
	printf(" %d Mal places\n",Mal_Place);   
	}
    if ( Bien_Place==0 && Mal_Place==0)puts(" There is no Connespondance !! \n");
    if ( Bien_Place==cases) break;
    puts(" ");
    iterationNumber++;
    if ( iterationNumber>=10 && iterationNumber<18 && isJokerUsed==0 )
    {
	 if (iterationNumber==10)
     {
        printf(" The Joker is available ,tap one of The following keys:\n");
        printf(" tap 'Y' To use JOKER , 'N' to not  use               \n");
     }
        showJokerHint();
    }
    
}

}

      
	  
	  
	   /*takeArray Function */           
               
               
void  takeArray(void){  


    int null=0 /*la premiere erreur est de retourner l un des nombres saisis*/;
	int null1=0 /*La deuxième erreur est la saisie d'un nombre à deux chiffres ou la saisie d'un nombre négatif*/; 

    if(LEVEL==2 )
    {
        for(i=0;i<cases;i++)
		{ 
		printf(" case %d : ",i); 
		expertMainCode[i] = getchar();
		 while(getchar()!='\n'); 
		 }

    }
    else
    {
            for(i=0;i<cases;i++)
			{ 
			printf(" case %d : ",i);  
			scanf("%d",&beginnerMainCode[i]);

			}
    
    if (LEVEL==1)
    {
        for (i=0;i<cases;i++)
        {
        for (j=i+1;j<cases;j++)
		 {
		   if (beginnerMainCode[i]==beginnerMainCode[j]) {
		   null=1; break;
		   }
		}
        
    if ( beginnerMainCode[i]<0 || beginnerMainCode[i]>9 ) 
	{
        null1=1; 
          break;
    }
	}
    
    if (null==1)
	{ 
	  printf(" You entred identical digits, try again   \n");
	  takeArray();
	}
    if (null1==1)
	{  
	  printf("Negative Numbers / OR Greater Than 9 are not Supponted!\n");
	   takeArray();
	   
	} 
    }
    }
puts("                 Click any key for Go to main Player interface ");
    getch();
    system("cls");
}

        
         /* jokerHint Function */
         
        
int showJokerHint(void){  
  
   int v; /*la case que joueur a choisie pour voir ce qu'elle contient*/
   
   printf(" Using ? (Y/N) : \n");

        do
        { 
        p=getch();
        }
        while (p !='y'&& p!='Y'&& p!='n'&& p!='N');
    if (p=='y' || p=='Y') 
    {
    	puts(" ");
        printf(" Which Case you Chose to see ? : \n");
        printf(" Enter Case number : ");
        scanf("%d",&v);
        if ( v>=cases) 
        {
        printf(" This case number %d does not exist,Try again ? (Y/N) !\n",v);
            return showJokerHint();
        }
        if ( v>=0 && v<cases )
        {
         puts(" ");
         if(LEVEL==2)
         if(expertMainCode[v]==' ')
         {printf(" This case %d Contains ESPACE \n",v);
         }
         else
         {
          printf(" This case %d Contains the character %c \n",v,expertMainCode[v]);

         }
    else
          printf(" This case %d Contains the number    %d\n",v,beginnerMainCode[v]);
          puts(" ");
          puts(" You sow a case , You lost 3 tries ! \n");
          puts(" ");
          iterationNumber=iterationNumber+3;
          
          isJokerUsed=1;
        }
        
    }
    else if ((p=='n' || p=='N' )  && LEVEL==1) beginnerLevel();
    else if ((p=='n' || p=='N' ) && LEVEL==2) expertLevel();
    return 0;
}
      
        
    
	 /*showFinalResult Function */ 

void showFinalResult(void){   

         fic = fopen("Jouer.save","a");
         int g=5;
         
         if ( Bien_Place == cases  )
         {    system("color 0c");
              puts("Congrats ! You Succeded ");
         printf("\n"); 
         if( 1<=iterationNumber && iterationNumber<5 )
         {     puts("YOUR SCORE : * * * * * ( 5 Stare  )");
	     
	     }
      if( 5<=iterationNumber && iterationNumber<9 )
       {       puts("YOUR SCORE : * * * * (4 Stare  )");
	                 g--;
	    }
      if( 9<=iterationNumber && iterationNumber<13 )
       {       puts("YOUR SCORE : * * * (3 Stare )");
	                 g=g-2;
	    }
      if( 13<=iterationNumber && iterationNumber<17 )
       {     puts("YOUR SCORE : * * ( 2 Stare  )");
	                 g=g-3;
	    }
      if( 17<=iterationNumber && iterationNumber<=20 )
       {     puts("YOUR SCORE : * ( 1 Stare  )"); 
	                 g=g-4;
	   }

	    fic = fopen("Jouer.save","a");
        if (fic == NULL){
  
         exit(1);
      }   
	  else{
	 fprintf(fic," SCORE:%d Stare",g);
     fclose(fic);
     puts(" ");
	  } 
   
   fic = fopen("Jouer.save","r");
	int letter=0;
   if (fic == NULL){
   	  exit(1);
   }
     else{
           printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,177);
        system("COLOR B5");
    printf ("   %cNAME:",186);	
     	while(1){
     		letter=fgetc(fic);
     		if(feof(fic))
     		     break;
              printf("%c",letter);
		 }
		
		
		  printf("\n   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",186,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,177);
	 }

	 fclose(fic);  
	 
	 }
      
    if ( Bien_Place != cases )
      {     
	  system("color 7c");
      printf(" Sorry You Lost \n"); 
      printf(" The Secret Code  : \n");
      
    if(LEVEL==1){
   	for(i=0;i<cases;i++){
   		 printf("case %d:%d \n",i,beginnerMainCode[i]);
	   }
   }
   
   if(LEVEL==2){
   	
   	for(i=0;i<cases;i++){
   		 printf("case %d:%c \n",i,expertMainCode[i]);
	   }
    }
   }
 }




         /*startAgain Function*/
       
int startAgain(void){
	
	
     	if (Bien_Place==cases ){
		puts(" ");
		puts(" ");
		puts(" ");
        puts("                 Click any key for Go to main interface ");
		getch();
		system("cls");
		main();
		return 0;
     	}
		
		if (Bien_Place!=cases ){
		  puts(" ");
		  puts(" Try Again ? ( Y / N) ");
	      touch=getch();

		  if (touch=='Y' || touch=='y') { 
		  printf(" You Will Start Again  \n");
		  puts("   Click any key To Continue ");
		  getch();
		  system("cls");
		  main(); 
		  return 0;
		  
	}
	else if (touch=='N' || touch=='n') {
	  puts("Thank you For playing"); 
	  getch(); 
	   return 0;
	   
	   }
	   	
	   
	   else {
	   	printf(" Invalid touch , Try again \n");
	   	startAgain(); 
		}
	   	
     	return 0;

}
}
