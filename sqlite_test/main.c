#include "sqlite3.h"
#include <stdio.h>

//check sqlite library version
// int main(void){
//     printf("%s\n", sqlite3_libversion());

//     return 0;
// }

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//test sqlite3 library
// int main(void){

//     sqlite3* db;
//     sqlite3_stmt* res;

//     //sqlite3_open : open and connect database
//     //in-memory database
//     int rc = sqlite3_open(":memory:", &db);

//     // we need to invoke sqlite3_close() whatever error or not.
//     if(rc != SQLITE_OK){
//         fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return 1;
//     }
//     //sqlite3_prepare_v2 == compiler
//     //parameter: db=handle, second=sql query to compile, -1=length of sql query(unit:byte, -1->until \0), res=sql query handle, last:
//     rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);

//     if(rc != SQLITE_OK){
//         fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);

//         return 1;
//     }

//     rc = sqlite3_step(res);
//     //SQLITE_ROW : result of query is one
//     if(rc == SQLITE_ROW){
//         printf("%s\n", sqlite3_column_text(res,0));
//     }

//     sqlite3_finalize(res);
//     sqlite3_close(db);

//     return 0;

// }

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// INSERT TEST
// int main(){
//     sqlite3* db;
//     char* err_msg = 0;

//     int rc = sqlite3_open("test.db", &db);

//     if(rc != SQLITE_OK){
//         fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return 1;
//     }

//     char* sql = "DROP TABLE IF EXISTS Cars;"
//                 "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);"
//                 "INSERT INTO Cars VALUES(1, 'Audi', 52642);"
//                 "INSERT INTO Cars VALUES(2, 'Mercedes', 57127);"
//                 "INSERT INTO Cars VALUES(3, 'Skoda', 9000);"
//                 "INSERT INTO Cars VALUES(4, 'Volvo', 29000);"
//                 "INSERT INTO Cars VALUES(5, 'Bentley', 350000);"
//                 "INSERT INTO Cars VALUES(6, 'Citroen', 21000);"
//                 "INSERT INTO Cars VALUES(7, 'Hummer', 41400);"
//                 "INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);";
       //execute query
       //sqlite3_prepare_v2() + sqlite3_step() + sqlite3_finalize()
//     rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//     if(rc != SQLITE_OK){
//         fprintf(stderr, "SQL error: %s\n", err_msg);

//         sqlite3_free(err_msg);
//         sqlite3_close(db);

//         return 1;
//     }

//     sqlite3_close(db);
//     return 0;


// }


// int main(void){

//     sqlite3* db;
//     char *err_msg = 0;

//     int rc = sqlite3_open(":memory:", &db);

//     if(rc!=SQLITE_OK){
//         fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return 1;
//     }

//     char *sql = "CREATE TABLE Friends(Id INTEGER PRIMARY KEY, Name TEXT);"
//                 "INSERT INTO Friends(Name) VALUES('TOM');"
//                 "INSERT INTO Friends(Name) VALUES('Rebecca');"
//                 "INSERT INTO Friends(Name) VALUES ('Jim');"
//                 "INSERT INTO Friends(Name) VALUES ('Roger');"
//                 "INSERT INTO Friends(Name) VALUES ('Robert');";

//     rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

//     if(rc != SQLITE_OK){
//         fprintf(stderr, "Failed to create table\n");
//         fprintf(stderr, "SQL error: %s\n", err_msg);
//         sqlite3_free(err_msg);
//     }
//     else{
//         fprintf(stdout, "Table Friends created successfully\n");
//     }
//     //가장 최근에 성공적으로 추가한 행의 Id를 반환
//     int last_id = sqlite3_last_insert_rowid(db);
//     printf("The last Id of the inserted row is %d\n", last_id);

//     sqlite3_close(db);
// }


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// int callback(void *, int, char **, char **);

// int main(void){
//     sqlite3  *db;
//     char *err_msg = 0;
//     int rc = sqlite3_open("test.db", &db);

//     if(rc != SQLITE_OK){
//         fprintf(stderr, "Cannot open database : %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);

//         return 1;
//     }

//     char *sql = "SELECT * FROM Cars";

//     rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

//     if(rc != SQLITE_OK){
//         fprintf(stderr, "Failed to select data\n");
//         fprintf(stderr, "SQL error: %s\n", err_msg);

//         sqlite3_free(err_msg);
//         sqlite3_close(db);

//         return 1;
//     }

//     sqlite3_close(db);

//     return 0;
// }

// int callback(void *NotUsed, int argc, char ** argv, char **azColName){
//     NotUsed = 0;

//     for(int i=0; i<argc; i++){
//         printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//     }
//     printf("\n");

//     return 0;
// }

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// int main(void){

//        sqlite3 *db;
//        char *err_msg = 0;
//        sqlite3_stmt *res;

//        int rc = sqlite3_open("test.db", &db);
//        if(rc != SQLITE_OK){

//               fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//               sqlite3_close(db);

//               return 1;
//        }

//        char *sql = "SELECT Id, Name FROM Cars WHERE Id = ?";
//        rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

//        if (rc == SQLITE_OK){
//               sqlite3_bind_int(res, 1, 3);
//        }
//        else{
//               fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
//        }

//        int step = sqlite3_step(res);

//        if(step == SQLITE_ROW){
//               printf("%s: ", sqlite3_column_text(res, 0));
//               printf("%s\n", sqlite3_column_text(res, 1));
//        }

//        sqlite3_finalize(res);
//        sqlite3_close(db);

//        return 0;
// }


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(void){

       sqlite3 *db;
       char *err_msg = 0;
       sqlite3_stmt *res;

       int rc = sqlite3_open("test.db", &db);
       if(rc != SQLITE_OK){

              fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
              sqlite3_close(db);

              return 1;
       }
       // @ or :
       char *sql = "SELECT Id, Name FROM Cars WHERE Id = @id";
       rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

       if (rc == SQLITE_OK){
              int idx = sqlite3_bind_parameter_index(res, "@id");
              int value = 4;
              sqlite3_bind_int(res, idx, value);
       }
       else{
              fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
       }

       int step = sqlite3_step(res);

       if(step == SQLITE_ROW){
              printf("%s: ", sqlite3_column_text(res, 0));
              printf("%s\n", sqlite3_column_text(res, 1));
       }

       sqlite3_finalize(res);
       sqlite3_close(db);

       return 0;
}

