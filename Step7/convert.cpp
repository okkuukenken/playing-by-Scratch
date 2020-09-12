#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
int main(){
    for(int i=1;i<=4;i++){
        ifstream ifs("music"+to_string(i)+".txt");
        ofstream ofs_pitch("pitch"+to_string(i)+".txt"),ofs_until_second("until_second"+to_string(i)+".txt");
        vector<int>pitch;
        vector<double>until_second;
        int bpm;
        ifs>>bpm;
        string p;
        double l,sum=0;
        map<string,int>p2num={{"低低ソ",43},{"低低ラ",45},{"低低シ",47},{"低ド",48},{"低レ",50},{"低ミ",52},{"低ファ",53},{"低ファ#",54},{"低ソ",55},{"低ソ#",56},{"低ラ",57},{"低シ",59},{"ド",60},{"レ",62},{"ミ",64},{"ファ",65},{"ファ#",66},{"ソ",67},{"ソ#",68},{"ラ",69},{"シ",71},{"高ド",72},{"休",0}};
        while(ifs>>p>>l){
            sum+=l*60/bpm;
            pitch.push_back(p2num[p]);
            until_second.push_back(sum);
        }
        int sz=pitch.size();
        for(int j=0;j<sz;j++){
            ofs_pitch<<pitch[j];
            ofs_until_second<<until_second[j];
            if(j!=sz-1){
                ofs_pitch<<endl;
                ofs_until_second<<endl;
            }
        }
    }
    return 0;
}
