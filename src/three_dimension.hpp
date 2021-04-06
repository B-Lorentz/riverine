
#ifndef THREED_H
#define THREED_H

#include <ostream>
#include <math.h>
namespace thd{
constexpr double EQUAL_EPS = 1e-8;
bool AreEqual(double a, double b){
    return abs(a-b) < EQUAL_EPS;
}
bool EqualsZero(double a){
    return AreEqual(a ,0.0);
}
class PVector
{
public:
    
    PVector ();
   
    PVector (double x, double y, double z);
   
    PVector (const PVector &v);
   
    friend std::ostream &operator << (std::ostream &os, const PVector &v);
  
    friend bool operator == (const PVector &v1, const PVector &v2);
  
    friend bool operator != (const PVector &v1, const PVector &v2);
   
    friend PVector operator + (const PVector &v1, const PVector &v2);
   
    friend PVector operator - (const PVector &v1, const PVector &v2);
   
    friend PVector operator * (const PVector &v, double scalar);
    friend PVector operator * (double scalar, const PVector &v);
    
    friend PVector operator / (const PVector &v, double scalar);
   
    friend double operator * (const PVector &v1, const PVector &v2);
  
    friend PVector CrossProduct (const PVector &v1, const PVector &v2);

    friend double DistanceBetween (const PVector &v1, const PVector &v2);
    
    friend double DistanceBetweenSquared (const PVector &v1, const PVector &v2);
    
    PVector &operator = (const PVector &v);
   
    PVector &operator += (const PVector &v);
    
    PVector &operator -= (const PVector &v);
  
    PVector &operator *= (double scalar);
  
    PVector &operator /= (double scalar);
   
    PVector &operator - ();
   
    void MakeZero ();
    
    bool IsZero ();
  
    double LengthSquared ();
   
    double Length ();
    
    void Normalize ();
  
    bool IsNormalized ();
    
    double x;
  
    double y;
  
    double z;

};

PVector::PVector() : x(0.0), y(0.0), z(0.0) {}

PVector::PVector(double x, double y, double z) : x(x), y(y), z(z) {}

PVector::PVector(const PVector &v) : x(v.x), y(v.y), z(v.z) {}

std::ostream &operator<<(std::ostream &os, const PVector &v)
{
    os << ' ' << v.x << ' ' << v.y << ' ' << v.z << ' ';
    return os;
}

bool operator==(const PVector &v1, const PVector &v2)
{
    return (AreEqual(v1.x, v2.x) &&
            AreEqual(v1.y, v2.y) &&
            AreEqual(v1.z, v2.z));
}

bool operator!=(const PVector &v1, const PVector &v2)
{
    return !(v1==v2);
}

PVector operator+(const PVector &v1, const PVector &v2)
{
    return PVector(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
}

PVector operator-(const PVector &v1, const PVector &v2)
{
    return PVector(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}

PVector operator*(const PVector &v, double scalar)
{
    return PVector(v.x*scalar, v.y*scalar, v.z*scalar);
}

PVector operator*(double scalar, const PVector &v)
{
    return PVector(v.x*scalar, v.y*scalar, v.z*scalar);
}

PVector operator/(const PVector &v, double scalar)
{
    scalar = 1.0 / scalar;
    return PVector(v.x*scalar, v.y*scalar, v.z*scalar);
}

double DotProduct (const PVector &v1, const PVector &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

PVector CrossProduct(const PVector &v1, const PVector &v2)
{
    return PVector(v1.y*v2.z - v1.z*v2.y,
                  v1.z*v2.x - v1.x*v2.z,
                  v1.x*v2.y - v1.y*v2.x);
}

double DistanceBetween(const PVector &v1, const PVector &v2)
{
    PVector distance = v1 - v2;
    return distance.Length();
}

double DistanceBetweenSquared (const PVector &v1, const PVector &v2)
{
    PVector distance = v1 - v2;
    return distance.LengthSquared();
}

PVector &PVector::operator=(const PVector &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
} 

PVector &PVector::operator+=(const PVector &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

PVector &PVector::operator-=(const PVector &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

 PVector &PVector::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

 PVector &PVector::operator/=(double scalar)
{
    scalar = 1.0 / scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

 PVector &PVector::operator-()
{
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

 void PVector::MakeZero()
{
    x = y = z = 0.0;
}

 bool PVector::IsZero()
{
    return EqualsZero(x) &&
           EqualsZero(y) &&
           EqualsZero(z);
}

 double PVector::LengthSquared()
{
    return x*x + y*y + z*z;
}

 double PVector::Length()
{
    return sqrt(LengthSquared());
}

 void PVector::Normalize()
{
    double magnitude = Length();
    
    magnitude = 1.0 / magnitude;

    x *= magnitude;
    y *= magnitude;
    z *= magnitude;
}

 bool PVector::IsNormalized()
{
    return AreEqual(Length(), 1.0);
}
}
#endif