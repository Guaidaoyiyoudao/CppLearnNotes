#include<iostream>
using namespace std;
class  Point
{
public:
    Point(float  x=0.0):_x(x){}
    float x(){ return _x; }
    void x(float val){ _x = val; }
    virtual void draw()
    {
        cout<<"This is point class!~"<<endl;
    }
    virtual ~Point(){}
private:
   float  _x; 
};
class Point2d:public Point
{
public:
    Point2d(float x,float y):Point(x),_y(y){}
    float y(){return _y;}
    void y(float val){ _y = val; }
    virtual void draw()
    {
        cout<<"This is point2d class!"<<endl;
    }
    virtual ~Point2d(){}
private:
    float _y;
};

class Point3d:
    public Point2d
{
public:
    Point3d(float x,float y,float z):Point2d(x,y),_z(z){}
    
    float z(){ return _z; }
    void z(float val){ _z = val; }

    void draw()
    {
        cout<<"this is point3d class"<<endl;
    }
private:
    float _z;

};

int main()
{

    Point* p1 = new Point(1.0);
    Point* p2 = new Point2d(1.0,2.0);
    Point* p3 = new Point3d(1.0,2.0,3.0); 
    p1->draw();
    p2->draw();
    p3->draw();
    return 0;
}
