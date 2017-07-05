
#include <iostream>

using namespace std;

//CLASS DECLARATION
class File {
public:
    File(string name);
     virtual ~File();
    
    virtual string name() const; //every file has a name
    virtual void open() const = 0;
    virtual void redisplay() const;
    
private:
    string m_name;
};

//TextMsg
class TextMsg: public File {
public:
    TextMsg(string name): File(name){};
    virtual ~TextMsg();
    
    virtual void open() const;
    virtual void redisplay() const;
    
    
};

//Video
class Video: public File {
public:
    Video(string name, int times): File(name), time(times){};
     virtual ~Video();
    
    virtual void open() const;
    virtual void redisplay() const;
    
private:
    int time;
    
};

//Picture
class Picture: public File {
public:
    Picture(string name): File(name){};
    virtual ~Picture();
    
    
    virtual void open() const;
    virtual void redisplay() const;
    
    
};


//CLASS IMPLIMENTATION


//File
File::File(string name) {
    m_name = name;
}

string File::name() const {
    return m_name;
}

void File::redisplay() const {
    cout <<"refresh the screen";
}

File::~File() {
}

//TextMsg
void TextMsg::open() const {
    cout << "open text message ";
}

void TextMsg::redisplay() const {
    File::redisplay();
}

TextMsg::~TextMsg() {
    cout << "Destroying "  << File::name()<< ", a text message" << endl;
}

//Video

void Video::open() const {
    cout << "play " << time << " second video ";
}

void Video::redisplay() const {
    File::redisplay();
}

Video::~Video() {
    cout << "Destroying " << File::name() << ", a video" << endl;
}

//Picture
void Picture::open() const {
    cout << "show picture " ;
}

void Picture::redisplay() const {
    cout << "refresh the screen";
}

Picture::~Picture() {
    cout << "Destroying the picture " << File::name() << endl;
}


void openAndRedisplay(const File* f)
{
    cout << f->name() << ": ";
    f->open();
    cout << endl << "Redisplay: ";
    f->redisplay();
    cout << endl;
}
















