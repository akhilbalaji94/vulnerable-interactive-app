#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_rental.h"

int authorize(char* username){
   int auth = 0;
   char userinput[11];
   printf("\nEnter username: ");
   scanf ("%s", userinput);

   if (strcmp(userinput,username)==0){
      auth = 1;
   }
   else{
      printf("\nIncorrect login information");
   }
   return auth;
}

void makeavail_movie(struct movie* movies, int num_movies){
   int i;
   char movie_name[5];

   printf("\nEnter the movie name: ");

   scanf("%s", movie_name);

	for(i=0;i<num_movies;i++){
		if(strcmp(movie_name,movies[i].name) == 0 && strcmp(MOVIE_NOTAVAIL,movies[i].avail)==0){
		   strcpy(movies[i].avail,MOVIE_AVAIL);
         printf("\nMovie is now available");
         return;
      }
   }
	printf("\nError! Wrong input");
   return;
}

int rentavail_movie(struct movie* movies, int num_movies){
   int i,checkout=0;
   char movie_name[5];
   
   printf("\nEnter the movie name: ");

   scanf("%s", movie_name);

	for(i=0;i<num_movies;i++){
		if(strcmp(movie_name,movies[i].name) == 0 && strcmp(MOVIE_AVAIL,movies[i].avail)==0){
         strcpy(movies[i].avail,MOVIE_NOTAVAIL);
         checkout=movies[i].price;
	      printf("\nSuccess! Enjoy your movie!");
         return checkout;
		}
   }
   printf("\nMovie not available");
   return checkout;

}

void list_movies(struct movie* movies, int num_movies){
   int i;
   for(i=0;i<num_movies;i++){
		printf("\n%s:$%d %s",movies[i].name, movies[i].price, movies[i].avail);
      }
}




int main(){
	int i,inp1=0, inp2=0, num_movies=3, checkout = 0;
	
   char owner_name[6] = OWNER_NAME;
	char user_name[5] = USER_NAME;

	struct account owner_account;
	struct account user_account;
	struct movie movies[3];
	
   strcpy(owner_account.name,OWNER_NAME);
	owner_account.dues = 0;
	
	strcpy(user_account.name,USER_NAME);
	user_account.dues = 0;
	
	strcpy(movies[0].name,MOVIE1_NAME);
	movies[0].price = MOVIE1_PRICE;
	strcpy(movies[0].avail,MOVIE_AVAIL);

   strcpy(movies[1].name,MOVIE2_NAME);
	movies[1].price = MOVIE2_PRICE;
	strcpy(movies[1].avail,MOVIE_AVAIL);

   strcpy(movies[2].name,MOVIE3_NAME);
	movies[2].price = MOVIE3_PRICE;
	strcpy(movies[2].avail,MOVIE_AVAIL);

	do{
		printf("\nWELCOME TO UTA MOVIE RENTALS ! FLAT RATES.\n");
		printf("\n1. Login as owner");
      printf("\n2. Login as user");
		printf("\n3. Exit");
		printf("\nEnter the corresponding number: ");
   		scanf("%i", &inp1);
		switch(inp1){
			case 1:
            if(authorize(OWNER_NAME) == 1){
   					do{
   						printf("\n1. List movies with availability");
   						printf("\n2. Set movie as available Usage: <name>");
   						printf("\n3. Logout");
						printf("\nEnter the corresponding number: ");
   						scanf("%i", &inp2);
						switch(inp2){
							case 1:
							   list_movies(movies,num_movies);
								break;
							case 2:
                        makeavail_movie(movies, num_movies);
                        break;
                     case 3:
								printf("\nLogging out!");
								break;
							default:
								printf("\nInvalid input");
								break;
						}
					}while(inp2!=3);
				}
            break;
         case 2:
               if(authorize(user_name) == 1) {
   			  	do{
   					printf("\n1. List movies with availability");
   					printf("\n2. Rent movie Usage: <name>");
						printf("\n3. Total dues");
						printf("\n4. Logout");
						printf("\nEnter the corresponding number: ");
   						scanf("%i", &inp2);
						switch(inp2){
							case 1:
								list_movies(movies, num_movies);
								break;
							case 2:
								checkout = rentavail_movie(movies,num_movies);
                        if(checkout > 0){
                              user_account.dues+=checkout;
									}
								break;
							case 3:
								printf("\nTotal dues:$%d",user_account.dues);
								break;
							case 4:
								printf("\nLogging out!");
								break;
							default:
								printf("\nInvalid input");
								break;
					   	}
				   	}while(inp2!=4);
                }
            break;
			case 3:
				printf("\nThank you! Come again\n");
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
	}while(inp1 != 3);
}
