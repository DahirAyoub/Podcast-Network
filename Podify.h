#ifndef PODIFY_H
#define PODIFY_H

#include <iostream>
#include "Podcast.h"
#include "Search.h"

using namespace std;

class Podify{
    public:
        ~Podify();
        void addPodcast(Podcast*);
        void addEpisode(Episode*,const string& podcastTitle);
        const Array<Podcast*>& getPodcasts();
        Podcast* getPodcast(int index);
        Podcast* getPodcast(const string& title);
        void getEpisodes(Search& search, Array<Episode*> &array);

    private:
        Array<Podcast*> podcasts;
};

#endif