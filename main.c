#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

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


    noecho();
    keypad(stdscr, TRUE);

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

    endwin();

	printf("%s", string);


    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
return 0;	
}
