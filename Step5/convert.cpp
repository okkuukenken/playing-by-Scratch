#include<iostream>
#include<string>
#include<map>
#include<fstream>
int main(){
    std::ifstream ifs("music.txt");
    std::ofstream ofs_pitch("pitch.txt"),ofs_until_second("until_second.txt");
    int bpm;
    ifs>>bpm;
    std::string pitch;
    double length,sum=0;
    std::map<std::string,int>pitch2num={{"ド",60},{"レ",62},{"ミ",64},{"ファ",65},{"ソ",67},{"ラ",69},{"休",0}};
    while(ifs>>pitch>>length){
        sum+=length*60/bpm;
        ofs_pitch<<pitch2num[pitch]<<std::endl;
        ofs_until_second<<sum<<std::endl;
    }
    return 0;
}
