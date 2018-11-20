/* Copyright 2008, 2010, Oracle and/or its affiliates. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include <mysql.h>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "jdbc/mysql_connection.h"

#include "jdbc/mysql_driver.h"
#include "jdbc/cppconn/exception.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/prepared_statement.h"

using namespace std;

#include "conDB.h"

conDB::conDB()
{

}

void conDB::connect(){

    cout << "DATABASE CONNECTOR TEST" << endl;
    try {

      string dbDataTestOne;
      string dbDataTestTwo;

      MYSQL *con;
      mysql_init(con);

      /* Create a connection */
      //driver = get_driver_instance();
      cout << "connecting::::" << endl;
      //con = driver->connect("tcp://127.0.0.1:3306", "root", "112211");
      con = mysql_real_connect(con,"localhost","root","112211","DAYSTRUCT_DATABASE",0,0,0);
      cout << "Connected using tcp://127.0.0.1:3306, root, root" << endl;

      mysql_query(con, "SELECT user_name FROM users WHERE users.ID = 1");
      MYSQL_RES *res = mysql_store_result(con);
      int totalRows = mysql_num_rows(res);
      int numFields = mysql_num_fields(res);
      MYSQL_FIELD *mfield;
      char** row;
      while((row = mysql_fetch_row(res))){
        for(int i = 0; i < numFields; i++){
            char *val = row[i];
            cout <<val<< endl;
        }
      }

/** **********A query that gets the username of the user with the ID 1**********
      // execute a query to get the username of user with the ID 1
      res = mysql_stmt_result_metadata("SELECT user_name FROM users WHERE users.ID = 1");
      //res = stmt->result();
      // run while loop for each value returned by the query
      while(res->next()){
        // test data equals the string of the value. In this case the username.
        dbDataTestOne = res->getString("user_name");
        cout << dbDataTestOne << endl;
      }
 ***************************************************************************** **/

/** **********A query that gets the password of the user with the ID 1**********
      // prepare a query to get the password of user with the ID
      stmt = mysql_stmt_init("SELECT password_s FROM logins WHERE logins.ID = 1");
      res = stmt->result();
      // run while loop for each value returned by the query
      while(res->next()){
        // test data equals the string of the value. In this case the password.
        dbDataTestTwo = res->getString("password_s");
        cout << dbDataTestTwo << endl;
      }
***************************************************************************** **/

      // delete the connection
      delete con;

    } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;
}

conDB::~conDB()
{
    //dtor
}
