#****************************************
#      Library for Latex from Data
# V1.0
#
#
# Written by Carl Schaffer
#****************************************





class tex_assistant():

    def __init__(self,tex_file):
        self.tex_file = tex_file
        f=open(self.tex_file,"w+")
        f.write("%This tex file is generated automatically from analysis code!\n")
        f.write("%Include it in your document to access the defined commands.\n")       
        f.write(" \n\n\n")

        f.close();


    def __repr__():
        outstring  = "Tex-Assistant, saving to: "
        outstring +=self.tex_file;
        return outstring;
    def appendString(self,toAppend):
        f = open(self.tex_file,"a+");
        f.write(toAppend)
        f.close()
        
        

    def writeValue(self,name,value):
        outstring = "\\newcommand{"
        outstring += "\\"+name
        outstring += "}{"+(string)value+"}\n"
        return outstring;

    def writeTable(self,name,header,data):
        
        #help functions
        def array_to_str(array,index):
            if index < len(array):
                return str(array[index])
            else:
                return " "


        if(not len(header) == len(data)):
            print "Header and data not of compatible size! \n  appending empty spaces where necessary "
            ncols=max(len(header),len(data[0]));
            
            outstring="\\begin{tabular}{"
            for i in range(0,ncols-1):
                outstring+= "|c"
            outstring+="|}"
            
            outstring+= "\\hline"
            for i in range(0,ncols-1):
                outstring += array_to_str(header,i)
                if not i==ncols-2:
                    outstring+= " & ";
                else:
                    outstring += "\\\\\n"
            nlines = len(data)
            for j in range(0, nlines-1):
                outstring +="\\hline"
                for i in range(0,ncols-1):
                    if  not i > len(data[0]):
                        outstring += array_to_str(data[j],i)
                    
                    elif not i==ncols-2:
                        outstring+= " & ";
                    else:
                        outstring += "\\\\\n"
                        


            outstring+="\\end{tabular}";
            return outstring



        
ta = tex_assistant("test.tex")
print ta.writeValue("Answer",42)
ta.appendString(ta.writeValue("Answer",42))


header= ["a","a","a","a","a","a"];
data  = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
ta.appendString(ta.writeTable("thetable",header,data))

print "done"
