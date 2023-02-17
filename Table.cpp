#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

ofstream myfile;
ifstream fin;
string sort;
string Time = " ";
string info;
string sizes;
int runs = 0;
int size = 10;
if (argc != 3) {
    printf("Usage: %s (inputfile) (outputfile)\n", argv[0]);
    return 1;
}
//opens file
fin.open(argv[1]);
if (!(fin)){
    perror("Error");
    return 1;
}
    
    
myfile.open("Table.txt"); 
myfile << "| Mode   | Size | Elapsed Time  |\n";  
//clears flags and seeks back to beginning
fin.clear();
fin.seekg(0);

while(getline(fin, info)){
    
    if(info[0] == 'r'){
        //cout << info[6] << endl;
        for(int i = 4; i < info.length(); i++){
            
                    cout << info[i] << endl;
                    Time = Time + info[i];
                
        }
        
            
        
        
        //strings for sizes
        if(size == 10){
            sizes = "1E1";
        }else if(size == 100){
            sizes = "1E2";
        }else if(size == 1000){
            sizes = "1E3";
        }else if(size == 10000){
            sizes = "1E4";
        }else if(size == 100000){
            sizes = "1E5";
        }else if(size == 1000000){
            sizes = "1E6";
        }else{
            sizes = "1E7";
        }

        if(runs < 29){
            myfile << "| STL    | " << sizes << "  |" << Time << "  |" << endl;
        }else if(runs < 57){
            myfile << "| Qsort  | " << sizes << "  |" << Time << "  |" << endl;
        }else if(runs < 85){
            myfile << "| Merge  | " << sizes << "  |" << Time << "  |" << endl;
        }else{
            myfile << "| Quick  | " << sizes << "  |" << Time << "  |" << endl;
        }
        size = size * 10;
        if(size > 10000000){
            size = 10;
        }
        Time.clear();
    }
    
    
runs++;  
}

}