#include <iostream>
#include <memory>
#include "textQuery.hpp"

using namespace std;
TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
    string text;
    while(getline(is,text)){

        file->push_back(text);
        int n = file->size()-1;
        string word;
        istringstream line(text);
        while (line>>word){

            shared_ptr<set<TextQuery::line_no>> &lines = wm[word];
            if(!lines)        
                lines.reset(new set<TextQuery::line_no>);
            lines->insert(n);
        }

    }
}