#include<iostream>
using namespace std;
class shape
{
  private:
  string position,color,borderthickness;
  public:
  shape(string position,string color,string thickness):position(position),
  color(color),borderthickness(thickness){}
  virtual void draw()
  {
    cout << "Drawing in the Parent class" << endl;
  }
  virtual void calculateArea()
  {
    cout << "Calculating the area" << endl;
  }
  virtual void calculatePerimeter()
  {
    cout << "Calculating the Perimeter" << endl;
  }

};
class Circle: public shape
{
  private:
  float radius,center_position;
  public:
  Circle(float r,float c,string positon,string color,string border):radius(r),center_position(c),shape(positon,color,border){}
  void draw(){cout <<"Drawing the Circle " << endl;}
  void calculateArea(){cout <<"Area of Circle : "<< 3.14*(radius*radius) << endl;}
  void calculatePerimeter(){cout <<"Perimeter of Circle : "<< 2*3.14*radius << endl;}

};
class Rectangle: public shape
{
  public:
  float width,height,topleft_corner_position;
  public:
    Rectangle(float width, float height, float p, string positon, string color, string border) :
     width(width), height(height), topleft_corner_position(p),shape(positon,color,border) 
    {}
    void draw() { cout << "Drawing the Rectangle " << endl; }
    void calculateArea() { cout << "Area of Rectangle : " << width*height << endl; }
    void calculatePerimeter() { cout << "Perimeter of Rectanlge :  " << 2*(width+height)<< endl; }
};
class triangle: public shape
{
  private:
  float s,a,b,c;
  public:
    triangle(float a,float b,float c,string positon, string color, string border):
    a(a),b(b),c(c),shape(positon,color,border){s=(a+b+c)/2;}
    void draw() { cout << "Drawing the Triangle " << endl; }
    void calculateArea() { cout << "Area of Triangle : " << s*(s-a)*(s-b)*(s-c) << endl; }
    void calculatePerimeter() { cout << "Perimter of traingle :  "<< a+b+c << endl; }
};
class polygon: public shape
{
  private:
  float sides,lengthofeachside,distanceFromCentre;
  public:
    polygon(float s, float l , float d,string positon, string color, string border):
    sides(s),lengthofeachside(l),distanceFromCentre(d),shape(positon,color,border){}
    void draw() { cout << "Drawing the Polygon " << endl; }
    void calculateArea() { cout << "Area of polygon : " << 0.5*sides*distanceFromCentre*lengthofeachside << endl; }
    void calculatePerimeter() { cout << "Perimter of Polygon :  " << sides*distanceFromCentre<< endl; }
};
int main()
{
  Circle c(5,3,"same","white","black");
  shape *s = &c;
  s->calculateArea();
  s->calculatePerimeter();
  s->draw();
}
