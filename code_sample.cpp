
//++++++++++++++++++++++++++++++++++++++++++++++++++
//            ZetoTex Latex Assistant
//                 Version 1.0
//            Written by: Carl Schaffer
//           Mail: cfmschaffer@hotmail.de

// ZetoTex is free software: you can redistribute it
// and/or modify it under the terms of the GNU
// General Public License as published by the Free
// Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it
// will be useful, but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General
// Public License along with this program.  If not,
// see <http://www.gnu.org/licenses/>.

//++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <sstream>
#include "zetotex.cpp"

using namespace std;

void code_sample(void){

  cout << endl << "Starting testing process..."<<endl;

  cout << "Creating instance of tex_assistant..."<<endl;
  tex_assistant ta = tex_assistant("./output/tex_sample.tex");
  cout << "Writing test command to file..."<<endl;

  // for(int i = 0; i<20;i++){
  //   ta.write_to_file("TEST\n");
  // }

  ta.ncmdValue("commandWithFloat",1.0002);
  ta.ncmdValue("commandWithInteger",1);

  cout <<"Generating array test data..."<<endl;

  
  std::vector <string> header;
  std::vector <std::vector <float> > data;
  std::vector <float> datline;

  int datsize =4;
  int headsize =datsize+3;
  int nlines = 5 ;



  //fill data
  for(int i=0;i<nlines;i++){
    datline.clear();
    for(int j =0;j<datsize;j++){
      datline.push_back(j);
    };
    data.push_back(datline);
  };

  //fill header
  stringstream ss;
  for(int j =0;j<headsize;j++){
    ss.clear();
    ss.str("");
    ss<< "Column "<<j;
    header.push_back(ss.str());
  }
  cout <<"Writing test array command...\n";
  ta.ncmdArray("SampleArray",header,data);

  cout <<"\nTesting finished!\n";
};


int main(void){
  code_sample();
  return 0;
}
