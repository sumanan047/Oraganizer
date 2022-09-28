#include <stdio.h>
#include <sqlite3.h> 
#include <stdlib.h>

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;                                                              
   rc = sqlite3_open("credentials.db", &db);                                   // instance object to open the database

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   sqlite3_close(db);
}



/*
Notes: In case you forget next time, this code is compiled with a -l flag like shown below
$g++ test.c -l sqlite3
returns an a.out
run the a.out to get the "credentials.db" named databse
*/