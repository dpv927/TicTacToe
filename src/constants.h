/* general settings */
static const int PLAYER_1  = 1;
static const int PLAYER_2  = 2;
static const int PLAYER_N  = 0;
static const int COND_DRAW = 0;
static const int COND_KEEP = 1;
static const unsigned int BOARD_LEN = 9;

/* appearance */
static const char P1_NAME[] = "Player1";
static const char P2_NAME[] = "Player2";

static const char P1_ALIAS = 'x';
static const char P2_ALIAS = 'o'; 

static const char BOARD_COLOR[]    = "\033[1;31m";
static const char ANSI_RESET[]   = "\033[1;37m";

/* search settings */
static const unsigned int DEF_DEPTH = 9;