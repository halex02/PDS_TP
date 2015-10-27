enum flag_e {NIHIL=-1, AND = 1, OR = 2, KILL = 4, CC = 8} ;
typedef enum flag_e flag_t ;

int isAShortOption(char *opt) ;

int isALongOption(char *opt) ;

int isAnOption(char *opt)
