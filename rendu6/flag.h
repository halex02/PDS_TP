enum flag_e{
  NIHIL=0, AND = 1, OR = 2, KILL = 4, CC = 8
} ;
typedef enum flag_e flag_t ;

int isAShortOption(char *opt) ;

int isALongOption(char *opt) ;

int isAnOption(char *opt) ;

int getCtrlValue(int argc, char *argv[], char *optList, int *check) ;

void checkInvalidCtrlValue(int check) ;
