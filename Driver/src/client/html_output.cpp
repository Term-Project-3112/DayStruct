#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "html_output.h"

using namespace std;

const string ENV[ 24 ] = {
   "Test", "Test", "Test",
   "Test", "Test",
   "Test", "Test",
   "Test", "Test", "Test",
   "Test", "Test", "Test",
   "Test", "Test", "Test",
   "Test", "Test", "Test",
   "Test","Test","Test",
   "Test","Test" };

html_output::html_output()
{

}

html_output::createTestPage()
{
    ofstream testPageOne;
// *******This currently outputs the file into the output folder of the project******
    testPageOne.open ("./output/HTML/testPageOne.html");

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
}

html_output::~html_output()
{
    //dtor
}
