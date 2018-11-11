#include <iostream>
#include <fstream>
#include "conDB.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

const string ENV[ 24 ] = {
   "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
   "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
   "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
   "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
   "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
   "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
   "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
   "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
   "SERVER_SIGNATURE","SERVER_SOFTWARE" };

int main () {

    ofstream testPageOne;
    testPageOne.open ("G:/My Drive/ITCS 3112 Term Project/UI_Docs(HTML, CSS, Javascript files)/HTML/testPageOne.html");

    //add some html content
   testPageOne << "Content-type:text/html\r\n\r\n";
   testPageOne << "<html>\n";
   testPageOne << "<head>\n";
   testPageOne << "<title>CGI Environment Variables</title>\n";
   testPageOne << "</head>\n";
   testPageOne << "<body>\n";
   testPageOne << "<table border = \"0\" cellspacing = \"2\">";

   for ( int i = 0; i < 24; i++ ) {
      testPageOne << "<tr><td>" << ENV[ i ] << "</td><td>";

      // attempt to retrieve value of environment variable
      char *value = getenv( ENV[ i ].c_str() );
      if ( value != 0 ) {
         testPageOne << value;
      } else {
         testPageOne << "Environment variable does not exist.";
      }
      testPageOne << "</td></tr>\n";
   }

   testPageOne << "</table><\n";
   testPageOne << "</body>\n";
   testPageOne << "</html>\n";

   //ending html
    testPageOne << "</body></html>";
    testPageOne.close();

   return 0;
}
