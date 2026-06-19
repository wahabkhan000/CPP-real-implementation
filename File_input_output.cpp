#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using std::cout,std::cin,std::string,std::endl;
int main() {

    std::vector<int>p;
    std::ifstream fin;
    fin.open("zoom.cpp");

    int c;
    fin>>c;
    while (!fin.eof()) {
        p.push_back(c);
        fin>>c;
    }
    fin.close();

    std::sort(p.begin(),p.end());

    std::ofstream fout;
    fout.open("zoom.cpp");

    for (int i=0;i<p.size();i++) {
        fout<<p[i];
        fout<<" ";
    }
    fout.close();

}
