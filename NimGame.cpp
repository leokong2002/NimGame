#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int A=0;//Menu selecter
	int AA=0;
	int AAA=0;
	int AC=0;
	int ACA=0;
	int ss=0;//set selecter
	int ps=0;//no. of pebbles selecter
	int chanceNUM = 1;//number of chance
	int chance=chanceNUM;//chance for type in again
	int i=0;
	int j=0;
	int m=0;//i value storer
	int e=1;//indicator of pebbles(there are sones remain or not.)
	char playerA[25];
	char playerB[25];
	char player[25];
	char RR[99];
	char ER[99];
	char CP[25] = "COMPUTER";
	int wantset;
	int saveset[21] = {3, 4, 5};
	int set[21] ; 
	int eset[21];
	int ep[21];
	int temp=0;
	int rangemax=10;
	int rangemin=1;
	int setsize = rangemax - rangemin + 1;
	int pebblesum=0;//total no. of pebbles
	int setsum=0;//total no. of sets
	int maxset=0;
	int maxpebble=0;
	int to=0;
	int from=0;
	int recordlinecount=0;
	int sr;//save record selection
	FILE* Record;
	srand(time(NULL));

	Record = fopen("D:\\Record_1.DAT", "a");
	fclose(Record);
	/*start of menu*/
do{	for (i=0; i<22; i++)
		set[i] = saveset[i];
											
	i=0;//set[]

	printf("                                        MENU       \n\n");
	printf("                                   1) PLAY GAME    \n");
	printf("                                   2) LOAD GAME    \n");
	printf("                                   3) SETTINGS     \n");
	printf("                                   4) HOW TO PLAY  \n");
	printf("                                   0) EXIT         \n");
	printf("                 Your Choice :");
	scanf(" %d", &A);
	/*end of menu*/

	printf("\n");
	printf("\n");
	printf("\n");

																				switch(A)
	{

																				case 1://play game
	printf("                                   1) 1 Player\n");
	printf("                                   2) 2 Players\n");
	printf("                 Your Choice :");
	scanf(" %d", &AA);

	printf("\n");
	printf("\n");
	printf("\n");
	
																				switch(AA)
	{
																				case 1://1 player
	printf("                                      1 PLAYER       \n\n");
	printf("                                      1) Easy    \n");
	printf("                                      2) Hard    \n");
	printf("     What is the computer difficulty you want? :");
	scanf(" %d", &AAA);

	printf("\n");
	printf("\n");
	printf("\n");
																				switch(AAA)
	{
																				case 1://easy
/*start of asking name*/
	printf("		 What is your name? :");
	scanf(" %s", playerA);
/*end of asking name*/

	strncpy(playerB, CP, sizeof(player));

	strncpy(player, playerA, sizeof(player));

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
}while (set[i] !=0);//print the table till value 0 found in set
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");

	m=i;//store the number of set printed
	/*start of the player selection*/	
do{
	printf("         Do you want to save?(1=Y/2=N)?");
	scanf(" %d", &sr);

			if(sr==1)
			{	
				recordlinecount=0;
				
				
				Record = fopen("D:\\Record_1.DAT", "r");
				do
				{
					RR[0]='\0';
					fscanf(Record, " %[^\n]\n", RR);
					
					recordlinecount++;
				}while (!feof(Record));
				printf("%d", recordlinecount);
				fclose(Record);

				if (recordlinecount<20)
				{
					Record = fopen("D:\\Record_1.DAT", "a");
					fprintf(Record, "%s\n", playerA);
					fprintf(Record, "%d\n", m+1);
					fprintf(Record, "%d\n", AAA);
					for(i=0; i<=m; i++)
						fprintf(Record, "%d ", set[i]);
					fprintf(Record, "\n");
					fclose(Record);
					
				}

				else if (recordlinecount>=20)
				{
					ER[0]='\0';
					Record = fopen("D:\\Record_1.DAT", "r");
					for(i=0; i<4; i++)
						fscanf(Record, " [^\n]\n", RR);
					fscanf(Record, " [^feof(Record)]", ER);
						

					fclose(Record);
				}
			}
				
				printf("        Which set you want to choose? %s:", player);
				scanf(" %d", &ss);
				printf("     How many pebble(s) you want to take? %s:", player);
				scanf(" %d", &ps);
				
	

	/*start of checking the value of k can be a possible answer or not.
	  if yes, cal. the no. of pebbles remain in the set
	  if not, ask for type in again*/
			if(ps <= set[ss-1] && ps != 0)
{				set[ss-1] -= ps;
			chance = -1;	}

			else
{	printf("\n");
	printf("\n");
	printf("                 Hey! You can not take more than the set contains!\n");
	printf("                      Or take 0 pebble from the set\n");
	printf("                      You have %d chance(s) to choose again!\n\n", chance);
			chance--;	}
			/*end of checking the value of k can be a possible answer or not.*/

}while(chance != -1);
			/*end of the player selection*/
			


		
do{		e=1;//reset pebbles indicator
		i=0;//reset the set[] to set[0] 
		pebblesum=0;
		chance=chanceNUM;//reset the chance
	
	printf("\n");
	printf("\n");
	printf("\n");

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				pebblesum += set[i];//total no. of pebbles
				i++;//change of set[]
				m--;//set print counter
}while(m != 0);
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");
	
	/*start of changing the turn the player*/
	if (strcmp(player, playerA) == 0)
			strncpy(player, playerB, sizeof(player));
	else
			strncpy(player, playerA, sizeof(player));
			/*end of changing the turn of player*/

	/*start of the player selection*/

	if (strcmp(player, playerA) == 0)
	{
do{
	printf("        Which set you want to choose? %s:", player);
			scanf(" %d", &ss);
	printf("     How many pebble(s) you want to take? %s:", player);
			scanf(" %d", &ps);
			
	/*start of checking the value of k can be a possible answer or not.
	  if yes, cal. the no. of pebbles remain in the set
	  if not, ask for type in again*/
			if(ps <= set[ss-1] && ps != 0)
{				set[ss-1] -= ps;
			chance = -1;	}

			else
{	printf("\n");
	printf("\n");
	printf("                 Hey! You can not take more than the set contains!\n");
	printf("                      Or take 0 pebble from the set\n");
	printf("                      You have %d chance(s) to choose again!\n\n", chance);
			chance--;	}
			/*end of checking the value of k can be a possible answer or not.*/
}while(chance != -1);}
	/*end of the player selection*/
	/*start of COMPUTER selection*/
	else
{	i+1;
	printf("        Which set you want to choose? %s:", player);
			
	ss = rand() % i + 1;	
	
	while(set[ss-1] == 0)
			ss = rand() % i + 1;
	
	printf("%d", ss);
	
	printf("     How many pebble(s) you want to take? %s:", player);

				//easy computer logic
				if (pebblesum == set[ss-1])
					ps = set[ss-1];
				else if (set[ss-1] == 1)
					ps = set[ss-1];
				else 
					ps = set[ss-1] - 1;
			
	printf("%d", ps);

			
				set[ss-1] -= ps;
				i-1;
	}
			/*end of the COMPUTER selection*/

			m=i;//store the number of set printed
			
	/*start of checking there are pebbles remain or not*/ 
do{
				if (set[i] == 0)
					i--;
				else
					e=0;
}while(i != -1 && e !=0);
			/*end of checking there are pebbles remain or not*/

}while(i != -1);
			/*end of taking the pebbles*/

	printf("\n");
	printf("\n");
	printf("\n");

	i=0;//reset the set[] to set[0]

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
				m--;//set print counter
}while(m != 0);
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");

	printf("                              %s win this game\n", player);
																					break;//easy
																				case 2://hard
	/*start of asking name*/
	printf("		 What is your name? :");
	scanf(" %s", playerA);
/*end of asking name*/

	printf("\n");
	printf("\n");
	printf("\n");

	strncpy(playerB, CP, sizeof(player));

	strncpy(player, playerA, sizeof(player));

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
}while (set[i] !=0);//print the table till value 0 found in set
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");

	/*start of the player selection*/	
do{
	printf("        Which set you want to choose? %s:", player);
			scanf(" %d", &ss);
	printf("     How many pebble(s) you want to take? %s:", player);
			scanf(" %d", &ps);

	

	/*start of checking the value of k can be a possible answer or not.
	  if yes, cal. the no. of pebbles remain in the set
	  if not, ask for type in again*/
			if(ps <= set[ss-1] && ps != 0)
{				set[ss-1] -= ps;
			chance = -1;	}

			else
{	printf("\n");
	printf("\n");
	printf("                 Hey! You can not take more than the set contains!\n");
	printf("                      Or take 0 pebble from the set\n");
	printf("                      You have %d chance(s) to choose again!\n\n", chance);
			chance--;	}
			/*end of checking the value of k can be a possible answer or not.*/

}while(chance != -1);
			/*end of the player selection*/
			
		m=i;//store the number of set printed


		
do{		e=1;//reset pebbles indicator
		i=0;//reset the set[] to set[0] 
		j=0;
		pebblesum=0;
		setsum=0;
		maxpebble=0;
		chance=chanceNUM;//reset the chance
	
	printf("\n");
	printf("\n");
	printf("\n");

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				pebblesum += set[i];//total no. of pebbles
				if (set[i] !=0)//total no. of possible sets
				{	setsum++;
					ep[j] = set[i];
					eset[j] = i+1;	}
				if (set[i] > maxpebble)//find the set have max no. of pebble
				{	maxpebble = set[i];
					maxset = i+1;	}

				i++;//change of set[]
				m--;//set print counter
				j++;
				
}while(m != 0);
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("			setsum = %d\n", setsum);
	printf("			pebblesum = %d\n", pebblesum);
	printf("			maxset = %d\n", maxset);
	printf("			maxpebble = %d\n", maxpebble);
	
	/*start of changing the turn the player*/
	if (strcmp(player, playerA) == 0)
			strncpy(player, playerB, sizeof(player));
	else
			strncpy(player, playerA, sizeof(player));
			/*end of changing the turn of player*/

	/*start of the player selection*/

	if (strcmp(player, playerA) == 0)
	{
do{
	printf("        Which set you want to choose? %s:", player);
			scanf(" %d", &ss);
	printf("     How many pebble(s) you want to take? %s:", player);
			scanf(" %d", &ps);
			
	/*start of checking the value of k can be a possible answer or not.
	  if yes, cal. the no. of pebbles remain in the set
	  if not, ask for type in again*/
			if(ps <= set[ss-1] && ps != 0)
{				set[ss-1] -= ps;
			chance = -1;	}

			else
{	printf("\n");
	printf("\n");
	printf("                 Hey! You can not take more than the set contains!\n");
	printf("                      Or take 0 pebble from the set\n");
	printf("                      You have %d chance(s) to choose again!\n\n", chance);
			chance--;	}
			/*end of checking the value of k can be a possible answer or not.*/
}while(chance != -1);	}
	/*end of the player selection*/
	/*start of COMPUTER selection*/
	else
{	i+1;
	printf("        Which set you want to choose? %s:", player);

	//hard computer choose line
			
	if(setsum > 3)
	{	ss = rand() % i + 1;	
		while(set[ss-1] == 0)
		ss = rand() % i + 1;	}

	else if (setsum == 3)
	{	if(ep[0] == ep[1])
			ss = eset[2];
		else if(ep[1] == ep[2])
			ss = eset[0];
		else if(ep[0] == ep[2])
			ss = eset[1];	}
		
		else
			ss = maxset;
	
	printf("%d\n", ss);
	
	printf("     How many pebble(s) you want to take? %s:", player);

				//hard computer logic

				if (setsum == 3 && ss == eset[0] && ep[1] == ep[2])
					ps = ep[0];

				else if (setsum == 3 && ss == eset[1] && ep[0] == ep[2])
					ps = ep[1];

				else if (setsum == 3 && ss == eset[2] && ep[1] == ep[0])
					ps = ep[2];

				else if (pebblesum == set[ss-1])
					ps = set[ss-1];

				else if (setsum%2 !=0 && setsum>3 && set[ss-1] != 0)
					ps = set[ss-1];

				else if (set[ss-1] == 1)
					ps = 1;

				else if (pebblesum == set[ss-1] + 1)
					ps = set[ss-1] - 1;

				else if (pebblesum == set[ss-1] + 2 && setsum == 3)
					ps = set[ss-1];

				else if (pebblesum%2 != 0)
					ps = 1;

				else if (pebblesum%2 == 0)
					ps = 2;
			
	printf("%d", ps);


				set[ss-1] -= ps;
				i-1;
	}
			/*end of the COMPUTER selection*/

			m=i;//store the number of set printed
			
	/*start of checking there are pebbles remain or not*/ 
do{
				if (set[i] == 0)
					i--;
				else
					e=0;
}while(i != -1 && e !=0);
			/*end of checking there are pebbles remain or not*/

} while(i != -1);
			/*end of taking the pebbles*/

	printf("\n");
	printf("\n");
	printf("\n");

	i=0;//reset the set[] to set[0]

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
				m--;//set print counter
}while(m != 0);
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");

	printf("                              %s win this game\n", player);

																					break;//hard
		}//end of switch(AAA)
																					break;//1 player
																				case 2://2 player
/*ask name*/
	printf("What is the first player's name?");
	scanf(" %s", playerA);
	printf("What is the second player's name?");
	scanf(" %s", playerB);

	strncpy(player, playerA, sizeof(player));

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
}while (set[i] !=0);//print the table till value 0 found in set
	/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");

	/*start of the player selection*/
do{
	printf("        Which set you want to choose? %s:", player);
			scanf(" %d", &ss);
	printf("     How many pebble(s) you want to take? %s:", player);
			scanf(" %d", &ps);



	/*start of checking the value of k can be a possible answer or not.
	  if yes, cal. the no. of pebbles remain in the set
	  if not, ask for type in again*/
			if(ps <= set[ss-1] && ps != 0)
{				set[ss-1] -= ps;
			chance = -1;	}

			else
{	printf("\n");
	printf("\n");
	printf("                 Hey! You can not take more than the set contains!\n");
	printf("                      Or take 0 pebble from the set\n");
	printf("                      You have %d chance(s) to choose again!\n\n", chance);
			chance--;	}
			/*end of checking the value of k can be a possible answer or not.*/

}while(chance != -1);
			/*end of the player selection*/
			
		m=i;//store the number of set printed

do{		e=1;//reset pebbles indicator
		i=0;//reset the set[] to set[0] 
		chance=chanceNUM;//reset the chance
	
	printf("\n");
	printf("\n");
	printf("\n");

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
				m--;//set print counter
}while(m != 0);
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");
	
	/*start of changing the turn the player*/
	if (strcmp(player, playerA) == 0)
			strncpy(player, playerB, sizeof(player));
	else
			strncpy(player, playerA, sizeof(player));
			/*end of changing the turn of player*/

	/*start of the player selection*/
do{
	printf("        Which set you want to choose? %s:", player);
			scanf(" %d", &ss);
	printf("     How many pebble(s) you want to take? %s:", player);
			scanf(" %d", &ps);
			
	/*start of checking the value of k can be a possible answer or not.
	  if yes, cal. the no. of pebbles remain in the set
	  if not, ask for type in again*/
			if(ps <= set[ss-1] && ps != 0)
{				set[ss-1] -= ps;
			chance = -1;	}

			else
{	printf("\n");
	printf("\n");
	printf("                 Hey! You can not take more than the set contains!\n");
	printf("                      Or take 0 pebble from the set\n");
	printf("                      You have %d chance(s) to choose again!\n\n", chance);
			chance--;	}
			/*end of checking the value of k can be a possible answer or not.*/
}while(chance != -1);
			/*end of the player selection*/

			m=i;//store the number of set printed
			
	/*start of checking there are pebbles remain or not*/ 
do{
				if (set[i] == 0)
					i--;
				else
					e=0;
}while(i != -1 && e !=0);
			/*end of checking there are pebbles remain or not*/

} while(i != -1);
			/*end of taking the pebbles*/

	printf("\n");
	printf("\n");
	printf("\n");

	i=0;//reset the set[] to set[0]

	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, set[i]);
				i++;//change of set[]
				m--;//set print counter
}while(m != 0);
			/*end of printing the table*/

	printf("\n");
	printf("\n");
	printf("\n");

	printf("                              %s win this game\n", player);

																				break;//2 Players break
			}//end of switch (AA)

																				case 2://Load game
																					break;//Load game break
																				
																				
																				case 3://settings
	printf("                                     SETTINGS		\n\n");
	printf("                                  1) Play Mode		\n");
	printf("                                  0) Back to MENU	\n");
	printf("                 Your Choice :");
	scanf(" %d", &AC);

	printf("\n");
	printf("\n");

	switch(AC)//settings switch
																				case 1://settings/playmode
	printf("                                    Play Mode		\n\n");
	printf("                               1) Standard game		\n");
	printf("                               2) Ascending game	\n");
	printf("                               3) Random game		\n");
	printf("                               0) Back to MENU		\n");
	printf("                 Your Choice :");
	scanf(" %d", &ACA);

	printf("\n");
	printf("\n");

	switch(ACA)//play mode switch
		{
																				case 1://Standard game
saveset[0] = 3;
saveset[1] = 4;
saveset[2] = 5;
saveset[3] = 0;

/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, saveset[i]);
				i++;//change of set[]
}while (saveset[i] !=0);//print the table till value 0 found in set
	/*end of printing the table*/

																			break;//break of Standard game
																				case 2://setings/playmode/Ascending game
	printf("     How many sets you want?(At most 20 sets):");
	scanf(" %d", &wantset);

	printf("\n");
	printf("\n");

	temp = wantset;

	for(i=wantset-1; i>=0; i--)
	{	saveset[i] = temp;
			temp--;	}

	i=0;




	/*start of printing the table*/
	printf("                         set                 number of pebbles\n");
do{
	printf("                          %d                        %d\n", i+1, saveset[i]);
				i++;//change of set[]
			}while (saveset[i] !=0);//print the table till value 0 found in set
	/*end of printing the table*/
																					break;//break of Ascending game
																				case 3://seetings/playmode/Random game
	printf("             How many sets do you want?");
	scanf(" %d", &wantset);
	printf("             What is the range do you prefer?");
do{
	printf("\n");
	printf("                                        from?");
		scanf(" %d", &from);
		if (from == 0)
			printf("Hey! You can not set 0 pebble in each line\n\n");
}while(from = 0);
	printf("                                         to?");
		scanf(" %d", &to);
	printf("\n");
	printf("\n");


	/*start of printing the table*/
	printf("                         line                 number of pebbles\n");
do{
	printf("                          %d                          ", i+1);
		saveset[i] = rand() % to - from + 1 + from;
	printf("%d", saveset[i]);
	printf("\n");

		if (saveset[i] <= 0)
			printf("Hey! You can not set 0 pebble in each line\n\n");
		else
		{	i++;//change of line[]
				wantset--;		}

}while (wantset != 0);//print the table till value 0 found in line
	/*end of printing the table*/
																					break;//Random game break

																					break;//settings 1 break																
			
	}	
																					break;//Settings break
																				case 0://exit
	printf("                                   Bye Bye!");
																					break;//exit break
	}//end of switch (A)
			
}while(A != 0);
			
			
			return 0;
}