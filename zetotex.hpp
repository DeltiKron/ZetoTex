//****************************************
//      Library for Latex from Data
// V1.0
//
//****************************************

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <iomanip>

string array_to_str(std::vector<float> array,unsigned int index);
string array_to_str(std::vector<string> array,unsigned int index){
  if( index < array.size()){
    stringstream ss;
    ss.clear();
    ss << array[index];
    return ss.str(); 
  }
  else{
    return " ";
  };
};
string array_to_str(std::vector<float> array,unsigned int index){
  if( index < array.size()){
    stringstream ss;
    ss.clear();
    ss << array[index];
    return ss.str(); 
  }
  else{
    return " ";
  };
};


class tex_assistant{
 public:
  string tex_file;
  tex_assistant(string tex_file_path);

  void write_to_file(string toAppend){
    fstream myfile;
    myfile.open (tex_file.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
    myfile << toAppend;
    myfile.close();
  };

  
  void ncmdValue(string name, float value){
    stringstream ss;
    ss<<value;
    ncmdStr(name,ss.str());
  };
  
  void ncmdStr(string name, string value){
    ostringstream oss;
    oss << "\\newcommand{";
    oss << "\\"+name;
    oss << "}{";
    oss << value;
    oss << "}\n\n";
    write_to_file(oss.str());
  };
  
  
  void ncmdArray(string name, std::vector <string> header,std::vector<std::vector< float> > data){

    if(not header.size() == data.size()){
      cout <<"Header and data not of compatible size! \n  appending empty spaces where necessary ";
    }  
    int ncols=max(header.size(),data[0].size());
    ostringstream oss;
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



};


//constructor
tex_assistant::tex_assistant(string tex_file_path){
  tex_file=tex_file_path;
  fstream myfile;
  
  time_t t = time(0);// get time now
  struct tm * now = localtime( & t );

  myfile.open(tex_file.c_str(), std::ofstream::out | std::ofstream::trunc);
  myfile << "%TexAssistant file written by Tex Assistant"<<endl;
  myfile << "%Written on: "
	 << std::setw(2)<< std::setfill('0')<<now->tm_mday << "."
	 << std::setw(2)<< std::setfill('0')<<now->tm_mon + 1 << "."
	 << std::setw(4)<< std::setfill('0')<<now->tm_year + 1900 << " at "
	 << std::setw(2)<< std::setfill('0')<<now->tm_hour <<":"
	 << std::setw(2)<< std::setfill('0')<<now->tm_min
	 <<endl<<endl<<endl;
    
  myfile.close();
    
};


