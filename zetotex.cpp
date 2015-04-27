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
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "zetotex.hpp"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//              Useful Functions
//++++++++++++++++++++++++++++++++++++++++++++++++++
std::string array_to_str(std::vector<std::string> array,unsigned int index){
  if( index < array.size()){
    std::stringstream ss;
    ss.clear();
    ss << array[index];
    return ss.str(); 
  }
  else{
    return " ";
  };
};

std::string array_to_str(std::vector<float> array,unsigned int index){
  if( index < array.size()){
    std::stringstream ss;
    ss.clear();
    ss << array[index];
    return ss.str(); 
  }
  else{
    return " ";
  };
};


//++++++++++++++++++++++++++++++++++++++++++++++++++
//           tex_assistant and methods
//++++++++++++++++++++++++++++++++++++++++++++++++++



//+++++++++++++++++++Constructor++++++++++++++++++++
tex_assistant::tex_assistant(std::string tex_file_path){
  tex_file=tex_file_path;
  std::fstream myfile;
  
  std::time_t t = time(0);// get time now
  struct tm * now = localtime( & t );

  myfile.open(tex_file.c_str(), std::ofstream::out | std::ofstream::trunc);

  myfile << "%TexAssistant file written by Tex Assistant"<<"\n";
  myfile << "%Written on: "
	 << std::setw(2)<< std::setfill('0')<<now->tm_mday << "."
	 << std::setw(2)<< std::setfill('0')<<now->tm_mon + 1 << "."
	 << std::setw(4)<< std::setfill('0')<<now->tm_year + 1900 << " at "
	 << std::setw(2)<< std::setfill('0')<<now->tm_hour <<":"
	 << std::setw(2)<< std::setfill('0')<<now->tm_min
	 <<"\n"<<"\n"<<"\n";
    
  myfile.close();
    
};//end constructor


//+++++++++++++++++++Write to File++++++++++++++++++

void tex_assistant::write_to_file(std::string toAppend){
  std::fstream myfile;
  myfile.open (tex_file.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
  myfile << toAppend;
  myfile.close();
};


//++++++++++++++++++Command Methods+++++++++++++++++

void tex_assistant::ncmdValue(std::string name, float value){
  std::stringstream ss;
  ss<<value;
  ncmdStr(name,ss.str());
};

void tex_assistant::ncmdStr(std::string name, std::string value){
  std::ostringstream oss;
  oss << "\\newcommand{";
  oss << "\\"+name;
  oss << "}{";
  oss << value;
  oss << "}\n\n";
  write_to_file(oss.str());
};

void tex_assistant::ncmdArray(std::string name,
			      std::vector <std::string> header,
			      std::vector<std::vector< float> > data){

  if(not header.size() == data.size()){
    std::cout <<"Header and data not of compatible size! \n  appending empty spaces where necessary ";
  }  
  int ncols=std::max(header.size(),data[0].size());
  std::ostringstream oss;
  oss << "\n\t\\begin{tabular}{";
  for(int i=0;i<ncols-1;i++){
    oss<< "|c";
  }

  oss <<"|}\n" << "\t\\hline ";

  for(int  i=0;i<ncols-1;i++){
    oss <<array_to_str(header,i);
    if(!(i==ncols-2)) oss << " & ";
    else oss << " \\\\\n";
  }

  int nlines = (int) data.size();

  for(int  j=0;j< nlines-1;j++){
    oss <<"\t\\hline ";
    for(int  i=0;i<ncols-1;i++){
      if(!(i >(int) data[0].size())){
	oss << array_to_str(data[j],i);
      }
      if(!(i==ncols-2)) oss<< " & ";
      else oss << " \\\\\n";
    }
  }
  oss<<"\t\\hline\n \t\\end{tabular}\n";
  ncmdStr(name,oss.str());

}




