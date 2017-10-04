// Class_String.cpp
#include "Class_String.h"
#include<iostream>
#include<cstdlib>

//以下为构造函数定义
String::String()
{
    num=0;
    pc=nullptr;
}

String::String(const char* chr)
{
    if(!chr)
    {
        num=0;
        pc=nullptr;
    }
    else
    {
        unsigned i=0,_count=0;
        while(chr[i])
        {
            _count++;i++;
        }
        num=_count;
        pc=new char[num];
        for(i=0;i<num;++i)
        {
            pc[i]=chr[i];
        }
    }
}

String::String(unsigned n,const char c)
{
    num=n;
    pc=new char[num];
    for(unsigned i=0;i<num;++i)
    {
        pc[i]=c;
    }
}

String::String(const String &s)
{
    num=s.num;
    pc=new char[num];
    for(unsigned i=0;i<num;++i)
    {
        pc[i]=s[i];
    }
}

//以下为重载运算符
char& String::operator[](unsigned index) const
{
    if(index>=num)
    {
        std::cerr<<"index too large";
        exit(-1);
    }
    else
    {
        return pc[index];
    }
}

String& String::operator=(const String& s)
{
    num=s.num;
    pc=new char[num];
    for(unsigned i=0;i<num;++i)
    {
        pc[i]=s[i];
    }
    return *this;
}

String& String::operator+(const String& s) const
{
    String temp(*this);
    temp.num=this->num+s.num;
    for(unsigned i=this->num;i<temp.num;++i)
    {
        temp[i]=s[i-this->num];
    }
    return temp;
}

bool String::operator==(const String &s) const
{
    if(this->num==s.num)
    {
        unsigned i;
        for(i=0;i<s.num;++i)
        {
            if((*this)[i]!=s[i]) break;
        }
        if(i==s.num) return 1;
        else return 0;
    }
    else return 0;
}

bool String::operator!=(const String &s) const
{
    if(*this==s) return 0;
    else return 1;
}

bool String::operator<(const String& s) const
{
    if(*this==s) return 0;
    else if(this->num==0&&s.num!=0) return 1;
    else if(this->num!=0&&s.num==0) return 0;
    else
    {
        unsigned _min=(this->num>s.num)?s.num:this->num;
        unsigned i;
        for(i=0;i<_min;++i)
        {
            if((*this)[i]>s[i]) break;
        }
        if(i==_min) return 1;
        else return 0;
    }
}

bool String::operator>(const String& s) const
{
    if(*this==s) return 0;
    else if(this->num==0&&s.num!=0) return 0;
    else if(this->num!=0&&s.num==0) return 1;
    else
    {
        unsigned _min=(this->num>s.num)?s.num:this->num;
        unsigned i;
        for(i=0;i<_min;++i)
        {
            if((*this)[i]<s[i]) break;
        }
        if(i==_min) return 1;
        else return 0;
    }
}

bool String::operator<=(const String& s) const
{
    if(*this<s||*this==s) return 1;
    else return 0;
}

bool String::operator>=(const String& s) const
{
    if(*this>s||*this==s) return 1;
    else return 0;
}

ostream& operator<<(ostream& out,const String& s)
{
    for(unsigned i=0;i<s.num;++i)
    {
        out<<s[i];
    }
    return out;
}

istream& operator>>(istream& in,String& s)//有问题！
{
    s.num=0;
    s.pc=new char[1024];
    char c,*p=s.pc;
    while(in>>c)
    {
        if(c!=' '&&c!='\n')
        {
            s.num++;
            *p=c;
            p++;
        }
        else break;
    }
    return in;
}
