#include "Podify.h"

Podify::~Podify(){
    for(int i=0;i<podcasts.getSize();++i){
        delete podcasts[i];
    }
}

void Podify::addPodcast(Podcast* p){
    podcasts.add(p);
}

void Podify::addEpisode(Episode* ep,const string& podcastTitle){
    Podcast* pod = getPodcast(podcastTitle);
    pod->add(ep);
}

const Array<Podcast*>&  Podify::getPodcasts(){
    return podcasts;
}

Podcast* Podify::getPodcast(int index){
    return podcasts[index];
}

Podcast* Podify::getPodcast(const string& podcastTitle){
    for(int i=0;i<podcasts.getSize();++i){
        Podcast* podcast = podcasts[i];
        if(podcast->getTitle()==podcastTitle){
            return podcast;
        }
    }
    cerr<<"Podcast does not exist."<<endl;
	exit(1);
}

void Podify::getEpisodes(Search& search, Array<Episode*> &array){
    cout<<"Updating the playlist with this search: "<<search<<endl;
    for(int i=0;i<podcasts.getSize();++i){
        Podcast* pd = podcasts[i];
        for (int j=0;j<pd->getSize();++j){
            Episode* ep = pd->get(j);
            if(search.matches(ep)){
                array.add(ep);
            } 
        }
    }
    cout<<"Current Elements in the array:";
    for(int i=0;i<array.getSize();++i){
        cout<<*array[i]<<endl;
    }
}