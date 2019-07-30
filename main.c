#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
char* readString(void);

int main(int argc, char ** argv) {

    initscr();

    int h,w;
    getmaxyx(stdscr, h, w);

	/* // DB STUFF */
	/* sqlite3 *db; */
	/* int rc; */
	/* rc = sqlite3_open("db", &db); */
	/* char *err; */
	/* char *sql = "INSERT INTO words(word,word2) VALUES ('tset', 'test2')"; */
	/* sqlite3_exec(db,sql,callback, 0, &err); */
	/* sqlite3_close(db); */
    
    WINDOW *win = newwin(h,w,0,0);

	char * word1=NULL;
	char * word2=NULL;


    noecho();
    keypad(stdscr, TRUE);

	word1 = readString();
	word2 = readString();

    endwin();

	printf("%s\n%s", word1, word2);


    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
return 0;	
}

char* readString(void){
	char *string = NULL, *tmp = NULL;
	size_t size = 0, index = 0;

	for(;;){
		int c = getch();
		if(c != 10){
			size += 1;	
			tmp = realloc(string,size);
			if(!tmp){
				free(string);
				string = NULL;
				break;
			}
			string = tmp;
		}else{
			break;	
		}
		string[index++] = c;
	}
	return string;
}


