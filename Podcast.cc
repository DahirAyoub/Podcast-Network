#include "Podcast.h"

Podcast::Podcast(const string& title,const string& host):title(title),host(host){}

Podcast::~Podcast(){
    for(int i=0;i<episodes.getSize();++i){
        delete episodes[i];
    }
}

bool Podcast::equals(const string& title) const{
    return this->title==title;
}

Episode* Podcast::get(int index) const{
    if(index>=getSize()||index<0) exit(1);
    return episodes.get(index);
}

int Podcast::getSize() const{
    return episodes.getSize();
}

void Podcast::add(Episode* ep){
    episodes.add(ep);
}
string Podcast::getTitle() const{
    return title;
}

void Podcast::print(ostream& ost) const{
    ost<<"Podcast Title: "<<title<<" Host: "<<host<<endl;
}

void Podcast::printWithEpisodes(ostream& ost)const{
    print(ost);
    for(int i=0;i<episodes.getSize();++i){
        episodes[i]->print(ost);
    }
}

ostream& operator<<(ostream& ost,Podcast& podcast){
    podcast.print(ost);
    return ost;
}