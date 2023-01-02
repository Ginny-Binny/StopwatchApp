#include <bits/stdc++.h>
using namespace std;

class CWH{
    protected:
    string title;
    float rating;
    public:
    CWH(string s, float r){
        title=s;
        rating = r;
    }
   virtual void display()=0; // pure virtual function
};

class CWHvideo: public CWH{
    float videolength;
    public:
    CWHvideo(string s, float r, float v): CWH(s,r){
        videolength=v;
    }
    void display(){
        cout<<"The title of the video is "<<title<<endl;
        cout<<"Rating of the video is "<<rating<<endl;
        cout<<"Length if the video is "<<videolength<<" minutes"<<endl;
    }
};

class CWHtext: public CWH{
    int wordcount;
    public:
    CWHtext(string s, float r, int wc): CWH(s,r){
        wordcount=wc;
    }
    void display(){
        cout<<"The title of the text tutorial is "<<title<<endl;
        cout<<"Rating of the text tutorial is "<<rating<<endl;
        cout<<"Length off the text is "<<wordcount<<endl;
    }
};

int main(){
    string title;
    float rating, vlen;
    int words;
    // for videos
    title="this is django tutorial";
    vlen=4.56;
    rating=4.65;
    CWHvideo djvideo(title,rating,vlen);
    //djvideo.display();

    // for text
    title="this is django tutorial text";
    words=456;
    rating=4.12;
    CWHtext djtext(title,rating,words);
    //djtext.display();

    CWH* tuts[2];
    tuts[0]=&djvideo;
    tuts[1]=&djtext;

    tuts[0]->display();
    tuts[1]->display();
return 0;
}