#include<iostream>
#include<string>
#include<map>
#include<fstream>
int main(){
    for(int i=1;i<=4;i++){
        std::ifstream ifs("music"+std::to_string(i)+".txt");
        std::ofstream ofs_pitch("pitch"+std::to_string(i)+".txt"),ofs_until_second("until_second"+std::to_string(i)+".txt");
        int bpm;
        ifs>>bpm;
        std::string pitch;
        double length,sum=0;
        std::map<std::string,int>pitch2num={{"低低ソ",43},{"低低ラ",45},{"低低シ",47},{"低ド",48},{"低レ",50},{"低ミ",52},{"低ファ",53},{"低ファ#",54},{"低ソ",55},{"低ソ#",56},{"低ラ",57},{"低シ",59},{"ド",60},{"レ",62},{"ミ",64},{"ファ",65},{"ファ#",66},{"ソ",67},{"ソ#",68},{"ラ",69},{"シ",71},{"高ド",72},{"休",0}};
        while(ifs>>pitch>>length){
            sum+=length*60/bpm;
            ofs_pitch<<pitch2num[pitch]<<std::endl;
            ofs_until_second<<sum<<std::endl;
        }
    }
    return 0;
}
