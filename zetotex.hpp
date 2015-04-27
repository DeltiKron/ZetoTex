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
#include <string.h>
#include <cstring>
#include <vector>

std::string array_to_str(std::vector<float> array,unsigned int index);

class tex_assistant{
public:
  std::string tex_file;
  tex_assistant(std::string tex_file_path);
  void write_to_file(std::string toAppend);
  void ncmdValue(std::string name, float value);
  void ncmdStr(std::string name, std::string value);
  void ncmdArray(std::string name, std::vector <std::string> header,std::vector<std::vector< float> > data);
};

