#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <iostream>
#include "Podcast.h"
#include <fstream>
using namespace std;

class PodcastPlayer{
    public:
        virtual void play(const Episode& m,ostream& ost) = 0;
};

class AudioPlayer: public PodcastPlayer{
    public:
        virtual void play(const Episode& m,ostream& ost);
};

class VideoPlayer: public AudioPlayer{
    public:
        virtual void play(const Episode& m,ostream& ost);
};

#endif