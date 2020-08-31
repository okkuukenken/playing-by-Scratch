#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
int main(){
    std::ifstream ifs("music.txt");
    std::vector<double>pitches[4],until_seconds[4];
    int bpm;
    ifs>>bpm;
    for(int i=0;i<4;i++){
        std::string pitch;
        double length,sum=0;
        std::map<std::string,int>pitch2num={{"低低ソ",43},{"低低ラ",45},{"低低シ",47},{"低ド",48},{"低レ",50},{"低ミ",52},{"低ファ",53},{"低ファ#",54},{"低ソ",55},{"低ソ#",56},{"低ラ",57},{"低シ",59},{"ド",60},{"レ",62},{"ミ",64},{"ファ",65},{"ファ#",66},{"ソ",67},{"ソ#",68},{"ラ",69},{"シ",71},{"高ド",72},{"休",0}};
        while(ifs>>pitch){
            if(pitch=="~~~")
                break;
            ifs>>length;
            sum+=length*60/bpm;
            pitches[i].push_back(pitch2num[pitch]);
            until_seconds[i].push_back(sum);
        }
    }
    int max_size=0;
    for(int i=0;i<4;i++)
        max_size=std::max(max_size,(int)pitches[i].size());
    std::ofstream ofs("info.txt");
    for(int i=0;i<max_size;i++){
        for(int j=0;j<4;j++){
            if(i<pitches[j].size()){
                ofs<<pitches[j][i]<<std::endl;
                ofs<<until_seconds[j][i]<<std::endl;
            }else{
                ofs<<0<<std::endl;
                ofs<<0<<std::endl;
            }
        }
    }
    return 0;
}
