#include "PodcastPlayer.h"


void AudioPlayer::play(const Episode& m,ostream& ost){
    ost<<m.getAudio()<<endl;
}

void VideoPlayer::play(const Episode& m,ostream& ost){
    AudioPlayer::play(m,ost);
    
    ifstream infile(m.getVideoFile());
    if(!infile){
        cout<<"Error: Couldn't open the file."<<endl;
        exit(1);
    }
    string line;
    while (getline(infile,line)){
        ost<<line<<endl;
    }

    infile.close();
}