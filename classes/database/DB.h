//
// Created by Administrateur on 05/12/2022.
//

#ifndef BIM_CLIENT_DB_H
#define BIM_CLIENT_DB_H

#include <string>
#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <map>

class DB {
private:

    sqlite3* db;
    int rc;
    char* zErrMsg;

    static int callbackSelect(void * data, int argc, char **argv, char **azColName) {
        auto * vector = (std::vector<std::map<std::string, std::string>> *) data;
        std::map<std::string, std::string> line;
        for (int i = 0; i < argc; ++i) {
            line[azColName[i]] = argv[i];
        }
        (*vector).push_back(line);

        return 0;
    }

public:
    DB(std::string database)
    {
        zErrMsg = 0;
        rc = sqlite3_open(database.c_str(), &db);

        if( rc ) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        } else {
            fprintf(stderr, "Opened database successfully\n");
        }
    }

    ~DB()
    {
        sqlite3_close(db);
    }

    std::vector<std::map<std::string, std::string>> select(std::string request)
    {
        std::vector<std::map<std::string, std::string>> result;
        std::string data = "Callback function called";

        rc = sqlite3_exec(db, request.c_str(), callbackSelect, &result, &zErrMsg);

        if( rc != SQLITE_OK ) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
            return {};
        } else {
            return result;
        }
    }
};


#endif //BIM_CLIENT_DB_H
