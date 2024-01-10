#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Episode.h"
using namespace std;

class Episode;


class Search {
    public:
        virtual ~Search() {}
        virtual bool matches(const Episode* episode) const = 0;
        virtual void print(ostream& ost) const = 0;
};


ostream& operator<<(ostream& ost, const Search& search);

    
class H_Search : virtual public Search {
    public:
        H_Search(const string& host);
        virtual bool matches(const Episode* episode) const;
        virtual void print(ostream& ost) const;
        const string& getHost() const { return host; }
    private:
        string host;
};


class C_Search : virtual public Search {
    public:
        C_Search(const string& category);
        virtual bool matches(const Episode* episode) const;
        virtual void print(ostream& ost) const;
        const string& getCategory() const { return category; }
    private:
        string category;

};


class HorC_Search : public H_Search, public C_Search {
    public:
        HorC_Search(const string& host, const string& category);
        virtual bool matches(const Episode* episode) const;
        virtual void print(ostream& ost) const;
};
#endif 