#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



typedef union{
	char formula[40];
	char text[50];
	float num;

}blocks;
typedef struct spec{
	blocks m[9];
}spec;
spec cell[9];/* lines 9 - 18. 2 dimensional array used for storing cell info*/


char l[9];
char n[9];

typedef struct sr{
	char dply[15];
}sr;

typedef struct sc{
	sr l[9];
}sc;
  sc c[9]; /* lines 23-30. 2 dimensional array used for displaying cell info*/



void iload(){/*displays empty spredsheet*/

	strcpy(l,"ABCDEFGHI");
    strcpy(n,"123456789");
	int y,x; /*used to control the for loops*/
	char hl[10]; /*horizontal line*/
	char vl[10]; /*vertical line*/
	strcpy(hl," --------");
	strcpy(vl,"|       ");
	
    
    for (x=0; x<9; x++){
		printf("     %c   ",l[x]);
	}
	printf("\n");
	for(y=0; y<9; y++){
		for (x=0; x<9; x++){
			
			printf("%s",hl);
		}
		printf("\n");
		for(x=0; x<9; x++){
			printf(" %s",vl);
			if(x==8){
				printf("|");

			}

		}
		printf("%c\n",n[y]);
		if(y == 8){
			for(x=0; x<9; x++){
				printf("%s",hl);
			}
		}
	}
	printf("\n");
}
void load(int c1,int c2){/*function to diplay new iterations of the spreadsheet when modified*/

	strcpy(l,"ABCDEFGHI");
    strcpy(n,"123456789");
	int y,x; /*used to control the for loops7*/
	char hl[10]; /*horizontal line*/
	char vl[10]; /*vertical line*/
	strcpy(hl," --------");
	strcpy(vl,"|");

    for (x=0; x<9; x++){
		printf("     %c   ",l[x]);
	}
	printf("\n");
	for(y=0; y<9; y++){
		for (x=0; x<9; x++){
			
			printf("%s",hl);
		}
		printf("\n");
		for(x=0; x<9; x++){
			printf(" %s",vl);
			
				if(c[x].l[y].dply[0] != ' '){
					for(int v =0; v<=7; v++){
						printf("%c",c[x].l[y].dply[v]);
					}
				}else{
					printf("       ");
				}
				if(x==8){
					printf("|");

				}
		}
		printf("%c\n",n[y]);
		if(y == 8){
			for(x=0; x<9; x++){
				printf("%s",hl);
			}
		}
	}
	printf("\n");
}


float average(int x, int z,int a, int b){/*function used for calculating averge*/
	float sum;
	float result;
	sum = 0;
	for(int h=0; h==(b - z); h++){
		sum = sum + cell[x].m[z + h].num;
	}
	result = sum/(b - z);
	return result;
	
}

float range(int x, int z, int a, int b){/*function used for calculating range*/
	float lnum,snum;
	float result;
	lnum = cell[x].m[z].num;
	snum = cell[x].m[z].num;
	for(int h=0; h==(b - z); h++){
		if(lnum < cell[x].m[z + x].num){
			lnum = cell[x].m[z + x].num;
		}
		if(snum < cell[x].m[z + x].num){
			snum = cell[x].m[z + x].num;
		}
		result = lnum - snum;
		
	}
	return result;
}

float sum(int x, int z, int a, int b){ /*function used for calculating sum*/
	float sum;
	sum = 0;
	if(x == a){
		for(int h=0; h==(b - z); h++){
			sum = sum + cell[x].m[z + h].num;
		}
	}else if(z == b){
		for(int h=0; h==(a - x); h++){
			sum = sum + cell[x + h].m[z].num;
		}
	}
	return sum;
}

int main(){
	char input[20];
	int x,z,c1,c2;
	int cn,cx;
	char quit[3];
	for(int i=0; i<9; i++){
		for (int p = 0; p<9; p++)
		{
			strcpy(c[p].l[i].dply,"        ");
		}
	}

	
	iload();/*Displays new empty spreadsheet*/
	strcpy(l,"ABCDEFGHI");
    strcpy(n,"123456789");
    strcpy(quit,"no");
    while(strcmp(quit,"yes")!=0){
		printf("Which cells would you like to enter data into:\n");
		scanf("%s",input);

		for(x=0;x<9;x++){
			if (toupper(input[0]) == l[x]){
				for(z=0;z<9;z++){
					if(input[1] == n[z]){

						c1 = x;
						c2 = z;
					}


				}
			}
			
		}

		printf("The cell you have selected is %c%c\n",l[c1],n[c2]);
		printf("Input:\n ");
		scanf("%s",input);

		if(atof(input)!=0){
			cell[c1].m[c2].num = atof(input);
			strcpy(c[c1].l[c2].dply,"       ");                    /* line 203 - 210 evaluates it input to see if string or number*/
			sprintf(c[c1].l[c2].dply,"%0.2f",cell[c1].m[c2].num);
		}else{
			strcpy(c[c1].l[c2].dply,"       "); 
			strcpy(cell[c1].m[c2].text,input);
			strcpy(c[c1].l[c2].dply,cell[c1].m[c2].text);
		}
		if(input[0] == 'A'){
			if(input[1] == 'V'){
				if(input[2] == 'E'){
					if(input[3] == 'R'){
						if(input[4] == 'A'){
							if(input[5] == 'G'){
								if(input[6] == 'E'){
									if(input[7] == '(' ){
										if(input[10] == ','){
											if(input[13] == ')'){
												for(x=0; x<8; x++){
													if(input[8] == l[x]){
														for(z=0; z<8; z++){
															if(input[9] == n[z]){
																
																for(int a; a<8; a++){
																	if(input[11] == l[a]){
																		for(int b=0; b<8; b++){
																			if(input[12] == n[b]){
																				cell[c1].m[c2].num = average(x,z,a,b);           /*line 211 - 250 Used to evluate string and call average() if required*/
																				strcpy(c[c1].l[c2].dply,"       ");
																				sprintf(c[c1].l[c2].dply,"%0.2f",cell[c1].m[c2].num);
																			}
																		}
																	}
																}	
															}
														}
													}	
												}
											}
										}
									}
								}
							}
						}
					}
				}	
			}
		}

		
		if(input[0] == 'S'){
			if(input[1] == 'U'){
				if(input[2] == 'M'){
					if(input[3] == '('){
						if(input[6] == ','){
							if(input[9] == ')'){
								for(x=0; x<9; x++){
									if(input[4] == l[x]){
										for(z=0; z<8; z++){
											if(input[5] == n[z]){				
												for(int a; a<8; a++){
													if(input[7] == l[a]){
														for(int b=0; b<8;b++){
															if(input[8] == n[b]){
																cell[c1].m[c2].num = sum(x,z,a,b);           /*line 255 - 285 Used to evluate string and call sum() if required*/
																strcpy(c[c1].l[c2].dply,"       ");
																sprintf(c[c1].l[c2].dply,"%0.2f",cell[c1].m[c2].num);
															}
														}
													}
												}	
											}
										}
									}	
							    }
							}
						}
					}
				}
			}
		}
		if(input[0] == 'R'){
			if(input[1] == 'A'){
				if(input[2] == 'N'){
					if(input[3] == 'G'){
						if(input[4] == 'E'){
							if(input[5] == '('){
								if(input[8] == ','){
									if(input[11] == ')'){
										for(x=0; x<8; x++){
											if(input[6] == l[x]){
												for(z=0; z<8; z++){
													if(input[7] == n[z]){		
														for(int a=0; a<8; a++){
															if(input[9] == l[a]){
																for(int b=0; b<8;b++){
																	if(input[10] == n[b]){
																		cell[c1].m[c2].num = range(x,z,a,b);   /*line 286 - 320 Used to evluate string and call sum() if required*/																			
																		strcpy(c[c1].l[c2].dply,"       ");
																		sprintf(c[c1].l[c2].dply,"%0.f",cell[c1].m[c2].num);
																	}

																}
															}
														}	
													}
												}
											}	
							    		}
									}
								}
							}
						}
					}
				}
			}
		}
		load(c1,c2); /*re displays modified spreadsheet*/
		printf("Do you wish to quit 'yes' or 'no'\n");
		scanf("%s",quit); /*used for termination*/
	}	
}