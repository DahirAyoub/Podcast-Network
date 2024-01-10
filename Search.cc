#include "Search.h"
H_Search::H_Search(const string& host){
    this->host=host;
}

bool H_Search::matches(const Episode* episode) const {
    return episode&& episode->getHost() == host;
}

void H_Search::print(ostream& ost) const {
    ost << "Searching for episodes with host named: " << host << endl;
}

C_Search::C_Search(const string& category) {
    this->category=category;
}

bool C_Search::matches(const Episode* episode) const {
    return episode&& episode->getCategory() == category;
}

void C_Search::print(ostream& ost) const {
    ost << "Searching for episodes in the category: " << category << endl;
}

HorC_Search::HorC_Search(const string& host, const string& category) : H_Search(host), C_Search(category) {}

bool HorC_Search::matches(const Episode* episode) const {
    return episode&& (episode->getHost() == H_Search::getHost() || episode->getCategory() == C_Search::getCategory());
}

void HorC_Search::print(ostream& ost) const {
    ost << "Searching for episodes with either host named: " <<  H_Search::getHost()<< " or in the category: " << C_Search::getCategory() << endl;
}

ostream& operator<<(ostream& ost, const Search& search) {
    search.print(ost);
    return ost;
}