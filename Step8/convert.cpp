#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;
int main(){
    ifstream ifs("music.txt");
    ofstream ofs_pitches("pitches.txt"),ofs_until_seconds("until_seconds.txt");
    vector<vector<int>>pitch;
    vector<vector<double>>until_second;
    int bpm;
    ifs>>bpm;
    string p;
    double l,sum=0;
    map<string,int>p2num={{"低低ソ",43},{"低低ラ",45},{"低低シ",47},{"低ド",48},{"低レ",50},{"低ミ",52},{"低ファ",53},{"低ファ#",54},{"低ソ",55},{"低ソ#",56},{"低ラ",57},{"低シ",59},{"ド",60},{"レ",62},{"ミ",64},{"ファ",65},{"ファ#",66},{"ソ",67},{"ソ#",68},{"ラ",69},{"シ",71},{"高ド",72},{"休",0}};
    while(ifs>>p){
        if(p=="開始"){
            pitch.emplace_back();
            until_second.emplace_back();
            continue;
        }
        if(p=="終了")
            continue;
        ifs>>l;
        sum+=l*60/bpm;
        pitch.back().push_back(p2num[p]);
        until_second.back().push_back(sum);
    }
    int n=pitch.size();
    int max_sz=0;
    for(int i=0;i<n;i++)
        max_sz=max(max_sz,(int)pitch[i].size());
    for(int i=0;i<max_sz;i++){
        for(int j=0;j<n;j++){
            if(i<pitch[j].size()){
                ofs_pitches<<pitch[j][i];
                ofs_until_seconds<<until_second[j][i];
            }else{
                ofs_pitches<<0;
                ofs_until_seconds<<0;
            }
            if(i!=max_sz-1||j!=n-1){
                ofs_pitches<<endl;
                ofs_until_seconds<<endl;
            }
        }
    }
    return 0;
}
