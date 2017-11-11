//Name: Maze Game
//Author: Dillon Mills

#include <iostream>
using std::cout;
using std::endl;
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <sstream>
using std::istringstream;
#include <string>
using std::string;
#include <stdlib.h>

#define player      105
#define enemy       225
#define treasure    36
#define path        176
#define wall        219
#define exit        234

char makeUppercase(char a);
char getInput();
char getKey();
void printScreen(short a[][40], short lcount, short tcount);


int main(void)
{
	/**********Title Screen**************************************************************************************************************************************************************************/
	char start = 0;
    printf("################################################################################");
	printf("@i                                                                            %c#", 127);
	printf("#####     #################################      ###############################");
	printf("####  ###  ###############################   ##   ##############################");
	printf("###  #####################################  ####  ##############################");
	printf("###  ##########   ####  #  ####   ########  ##########   ####  #  # #####   ####");
	printf("###  #########  %c  ###  #  ###  %c  #######  #########  %c  ###        ###  %c  ###", 127, 127, 127, 127);
	printf("###  ############  ####   ####     #######  ###   ######  ###  #  #  ###     ###");
	printf("###  ##########    ####   ####  ##########  ####  ####    ###  #  #  ###  ######");
	printf("####  ###  ###  #  ##### #####  #  #######   ##   ###  #  ###  #  #  ###  #  ###");
	printf("#####     ####     ##### #####     ########      ####     ###  #  #  ###     ###");
	printf("#$                                                                             @");
	printf("################################################################################");
	printf("\n                                i IS THE HERO                                  \n");
	printf("\n\n\n\n\n\n\n\n                               * Press Enter *");
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                    Dillon Mills");

	//pauses until player hits enter
	while (true)
    {
        char key = getKey();
        if(key == 0x000D){break;} // Enter
        if(key == 0x001B){return 1;}  // ESC
    }
    system("cls");

	/**********Main Game**************************************************************************************************************************************************************************/
	short play=1, askPlay=0, goodAnswer, lCount=0;	//Game
	short tCount=0;					//Treasure
	short eCount=5;						//Enemy
	short mCount=0;						//Player

	/**********Level Start********************************************************************************/
	do{
		short a[40][40], mx, my, dirM, badMap, forced;		//Map
		short tx, ty, gotTreasure=0; 						//Treasure
		short ex[100], ey[100], eMove=1, eDir[100], eRand;	//Enemy
		short posX=0, posY=0, dead=0; char dirP=0;			//Player
		srand(time(NULL));

		/**********Map Generation****************************************/
		printf("LOADING");
		do{
            printf(".");
			/**********All Wall**********/
			for(int i=0; i<40; i++){
				for(int j=0; j<40; j++){
					a[i][j] = wall;}}

			/**********Walks Path**********/
			a[0][0] = path;	//makes a[0][0] a path
			mx=0; my=0; badMap=0; forced=0;

			while(a[39][39] == wall){//mx<39 && my<39){//} && badMap==0){
				dirM = rand()%4;	//determines direction to generate
				if((a[my+1][mx]!=wall || my==39) && (a[my-1][mx]!=wall || my==0) && (a[my][mx+1]!=wall || mx==39) && (a[my][mx-1]!=wall || mx==0)){
					//badMap = 1;
					forced = 1;
					dirM = rand()%4;}	//prevents dead ends from causing infinite loops
				if(dirM == 0){	//down
					if((a[my+1][mx]==wall || forced) && my<39){
						my++;
						a[my][mx] = path;}}
				else if(dirM == 1){	//right
					if((a[my][mx+1]==wall || forced) && mx<39){
						mx++;
						a[my][mx] = path;}}
				else if(dirM == 2){	//up
					if(a[my-1][mx]==wall && my>0){
						my--;
						a[my][mx] = path;}}
				else if(dirM == 3){	//left
					if(a[my][mx-1]==wall && mx>0){
						mx--;
						a[my][mx] = path;}}
			}
		}while(a[39][39] == wall);	//regenerates until a path goes from first coordinate to last coordinate
		//a[39][39] = path;	//makes last grid space the exit

		/**********Treasure Placement**********/
		do{
			tx = rand()%40; ty = rand()%40;
			if(a[ty][tx] == path){
				a[ty][tx] = treasure;}
		}while(a[ty][tx] != treasure);

		/**********Enemy Placement**********/
		for(int i=0; i<eCount; i++){
			do{
				ex[i] = rand()%40; ey[i] = rand()%40;
				if(a[ey[i]][ex[i]] == path){
					a[ey[i]][ex[i]] = enemy;}
			}while(a[ey[i]][ex[i]] != enemy);}

		//starts player at a[0][0]
		a[0][0] = player;

		/**********Game Mechanics****************************************/
		do{
			gotTreasure = 0;

			/**********Print Screen**********/
			printScreen(a, lCount, tCount);

			/**********Player Mechanics**********/
			/*****Input*****/
			printf("Enter direction (W/A/S/D): ");
			dirP = getKey();
			if(dirP == 0x001B){return 1;} // ESC
			dirP = makeUppercase(dirP);
			mCount++;

			/*****Movement*****/
			//W
			if(dirP == 87){	//W
				if(a[posY-1][posX]==treasure){	//collects treasure
					gotTreasure++;
					tCount++;}
				if(a[posY-1][posX]==path || a[posY-1][posX]==treasure){
					posY--;						//moves player
					a[posY][posX] = player;		//makes player appear in new spot
					a[posY+1][posX] = path;}	//makes old spot a path
				if(a[posY-1][posX]==enemy){
					a[posY-1][posX] = treasure;}}	//turns dead enemies into treasure}}
			//S
			if(dirP == 83){	//S
				if(a[posY+1][posX]==treasure){
					gotTreasure++;
					tCount++;}
				if(a[posY+1][posX]==path || a[posY+1][posX]==treasure){
					posY++;
					a[posY][posX] = player;
					a[posY-1][posX] = path;}
				if(a[posY+1][posX]==enemy){
					a[posY+1][posX] = treasure;}}
			//A
			if(dirP == 65){	//A
				if(a[posY][posX-1]==treasure){
					gotTreasure++;
					tCount++;}
				if(a[posY][posX-1]==path || a[posY][posX-1]==treasure){
					posX--;
					a[posY][posX] = player;
					a[posY][posX+1] = path;}
				if(a[posY][posX-1]==enemy){
					a[posY][posX-1] = treasure;}}
			//D
			if(dirP == 68){	//D
				if(a[posY][posX+1]==treasure){
					gotTreasure++;
					tCount++;}
				if(a[posY][posX+1]==path || a[posY][posX+1]==treasure){
					posX++;
					a[posY][posX] = player;
					a[posY][posX-1] = path;}
				if(a[posY][posX+1]==enemy){
					a[posY][posX+1] = treasure;}}


			/**********Enemy Mechanics**********/
			if(eMove == 1){
				for(int i=0;i<eCount;i++){
					/*****Enemy Dies*****/
					if(a[ey[i]][ex[i]]!=enemy){ey[i] = 0; ex[i] = 0;}	//kills enemy
					if(a[ey[i]][ex[i]]==treasure){ey[i] = 0; ex[i] = 0;}	//kills enemy
					if(a[ey[i]][ex[i]]==player){ey[i] = 0; ex[i] = 0;}	//kills enemy
					if(ey[i]==posY && ex[i]==posX){ey[i] = 0; ex[i] = 0;}	//kills enemy

						/*****Enemy Movement Determination*****/
					if(ey[i] != 0 || ex[i] != 0){	//makes sure the enemy isn't dead befor moving
						eDir[i] = 4;	//erases last movement's memory
						eRand = rand()%2;	//for use when enemy is not alligned with player

						if(ey[i]>posY && ex[i]>posX){
							if(eRand==0){
								if(a[ey[i]-1][ex[i]]==path || a[ey[i]-1][ex[i]]==player){eDir[i] = 0;}
								else if(a[ey[i]][ex[i]-1]==path || a[ey[i]][ex[i]-1]==player){eDir[i] = 2;}}
							if(eRand==1){
								if(a[ey[i]][ex[i]-1]==path || a[ey[i]][ex[i]-1]==player){eDir[i] = 2;}
								else if(a[ey[i]-1][ex[i]]==path || a[ey[i]-1][ex[i]]==player){eDir[i] = 0;}}}

						if(ey[i]>posY && ex[i]<posX){
							if(eRand==0){
								if(a[ey[i]-1][ex[i]]==path || a[ey[i]-1][ex[i]]==player){eDir[i] = 0;}
								else if(a[ey[i]][ex[i]+1]==path || a[ey[i]][ex[i]+1]==player){eDir[i] = 3;}}
							if(eRand==1){
								if(a[ey[i]][ex[i]+1]==path || a[ey[i]][ex[i]+1]==player){eDir[i] = 3;}
								else if(a[ey[i]-1][ex[i]]==path || a[ey[i]-1][ex[i]]==player){eDir[i] = 0;}}}

						if(ey[i]<posY && ex[i]>posX){
							if(eRand==0){
								if(a[ey[i]+1][ex[i]]==path || a[ey[i]+1][ex[i]]==player){eDir[i] = 1;}
								else if(a[ey[i]][ex[i]-1]==path || a[ey[i]][ex[i]-1]==player){eDir[i] = 2;}}
							if(eRand==1){
									if(a[ey[i]][ex[i]-1]==path || a[ey[i]][ex[i]-1]==player){eDir[i] = 2;}
								else if(a[ey[i]+1][ex[i]]==path || a[ey[i]+1][ex[i]]==player){eDir[i] = 1;}}}

						if(ey[i]<posY && ex[i]<posX){
							if(eRand==0){
								if(a[ey[i]+1][ex[i]]==path || a[ey[i]+1][ex[i]]==player){eDir[i] = 1;}
								else if(a[ey[i]][ex[i]+1]==path || a[ey[i]][ex[i]+1]==player){eDir[i] = 3;}}
							if(eRand==1){
								if(a[ey[i]][ex[i]+1]==path || a[ey[i]][ex[i]+1]==player){eDir[i] = 3;}
								else if(a[ey[i]+1][ex[i]]==path || a[ey[i]+1][ex[i]]==player){eDir[i] = 1;}}}

						if(ey[i]==posY){
							if(ex[i]>posX){
								if(a[ey[i]][ex[i]-1]==path || a[ey[i]][ex[i]-1]==player){eDir[i] = 2;}}
							if(ex[i]<posX){
								if(a[ey[i]][ex[i]+1]==path || a[ey[i]][ex[i]+1]==player){eDir[i] = 3;}}}

						if(ex[i]==posX){
							if(ey[i]>posY){
								if(a[ey[i]-1][ex[i]]==path || a[ey[i]-1][ex[i]]==player){eDir[i] = 0;}}
							if(ey[i]<posY){
									if(a[ey[i]+1][ex[i]]==path || a[ey[i]+1][ex[i]]==player){eDir[i] = 1;}}}



						/*****Enemy Movement*****/
						if(eDir[i]==0){	//up
							ey[i]--;					//moves enemy position
							if(a[ey[i]][ex[i]]!=player){
								a[ey[i]][ex[i]] = enemy;}		//makes enemy appear in new spot
							a[ey[i]+1][ex[i]] = path;}		//makes old spot a path
						if(eDir[i]==1){	//down
							ey[i]++;
							if(a[ey[i]][ex[i]]!=player){
								a[ey[i]][ex[i]] = enemy;}
							a[ey[i]-1][ex[i]] = path;}
						if(eDir[i]==2){	//left
							ex[i]--;
							if(a[ey[i]][ex[i]]!=player){
								a[ey[i]][ex[i]] = enemy;}
							a[ey[i]][ex[i]+1] = path;}
						if(eDir[i]==3){	//right
							ex[i]++;
							if(a[ey[i]][ex[i]]!=player){
								a[ey[i]][ex[i]] = enemy;}
							a[ey[i]][ex[i]-1] = path;}

						/*****Player Dies*****/
						if(ey[i]==posY && ex[i]==posX){dead = 1;}}}}	//kills player

			/**********Exit Level**********/
			if(gotTreasure>0){a[39][39] = path;}	//allows player to exit when treasure is collected
			if(dead == 1){a[39][39] = 1;}	//ends game when player is dead

		}while(a[39][39]==exit || a[39][39]==path);

		/**********Level End********************************************************************************/
		system("cls");

		/**********Death Screen****************************************/
		if(dead == 1){
			eCount=5;

			/**********Game Stats**********/
			printf("\n\n       YOU DIED!\n");
			printf("\n\n Stats\n");
			printf("----------------------\n");
			printf("|Treasure Collected: |\n");
			printf("|%-20d|\n", tCount);
			printf("|                    |\n");
			printf("|Level Reached:      |\n");
			printf("|%-20d|\n", lCount);
			printf("|                    |\n");
			printf("|Moves Taken:        |\n");
			printf("|%-20d|\n", mCount);
			printf("----------------------\n");
			printf("\n\nDo you want to play again?\n");
			lCount = 0;
			tCount = 0;
			mCount = 0;

			/**********Ask Replay**********/
			do{
				printf("(Y/N): ");

				/*****Takes Input*****/
				askPlay = getKey();
				if(askPlay == 0x001B){return 1;}
				askPlay = makeUppercase(askPlay);

				/*****Interprets Answer*****/
				if(askPlay==89){
					goodAnswer = 1;
					play = 1;}
				else if(askPlay==78){
					goodAnswer = 1;
					play = 0;}
				else{
					goodAnswer = 0;
					printf("Invalid input.\n");}
			}while(goodAnswer == 0);}	//requires valid input

		/**********Next Level****************************************/
		else{eCount++; lCount++;}
	}while(play==1);

	/**********Quit Game****************************************/
	printf("\nQUITTER!\n\n");
	return 0;
}

/**********Functions**************************************************************************************************************************************************************************/
char makeUppercase(char a)
{
	if(a>96 && a<123){	//converts to upper case
	a -= 32;}
	return a;
}


char getKey()
{
    char key = getch();
    if (key == 0x00 || key == 0xE0)
    {
        key *= 0x0100; // shift left by 8 bits to get extended code
        key += getch(); // retrieve second byte of extended code
    }
    return key;
}


void printScreen(short a[][40], short lCount, short tCount)
{
    system("cls");
    std::stringstream ss;
    ss << "Level: " << lCount << "  CAVE GAME  Treasure: " << tCount << endl;
    ss << string(42,(char)wall) << endl << (char)wall;
    if(a[0][0]==path){a[0][0] = exit;}
    for(int i=0;i<40;i++){
        for(int j=0;j<40;j++)
        {
            if(i+j==39+39)
            {
                ss << (char)exit;
            }
            else
            {
                ss << (char)a[i][j];
            }
        }
        ss << (char)wall << endl << (char)wall;
    }
    ss << string(41,(char)wall) << endl;
    cout << ss.str();
}
