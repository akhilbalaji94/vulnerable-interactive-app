#define OWNER_NAME "owner"
#define USER_NAME "user"

#define MOVIE1_NAME "IT"
#define MOVIE1_PRICE 12

#define MOVIE2_NAME "THOR"
#define MOVIE2_PRICE 10

#define MOVIE3_NAME "RUSH"
#define MOVIE3_PRICE 13

#define MOVIE_AVAIL "YES"
#define MOVIE_NOTAVAIL "NO"

struct movie {
	char name[5];
	int price;
	char avail[4];
};

struct account {
	char name[6];
	int dues;
};



