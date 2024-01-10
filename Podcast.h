#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Episode.h"
#include "Array.h"


using namespace std;

class Podcast{
    friend ostream& operator<<(ostream&,Podcast&);
    public:
        Podcast(const string& title,const string& host);
        ~Podcast();
        
        bool equals(const string& title)const;
        Episode* get(int index)const;
        int getSize() const;
        void print(ostream&) const;
        void printWithEpisodes(ostream&) const;
        void add(Episode*);
        string getTitle() const;



    private:
        Array<Episode*> episodes;
        string title;
        string host;

};

#endif