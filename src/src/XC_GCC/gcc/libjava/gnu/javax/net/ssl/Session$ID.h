
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_Session$ID__
#define __gnu_javax_net_ssl_Session$ID__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace net
      {
        namespace ssl
        {
            class Session$ID;
        }
      }
    }
  }
}

class gnu::javax::net::ssl::Session$ID : public ::java::lang::Object
{

public:
  Session$ID(JArray< jbyte > *);
  JArray< jbyte > * id();
  jboolean equals(::java::lang::Object *);
  jint hashCode();
  jint compareTo(::java::lang::Object *);
  ::java::lang::String * toString();
public: // actually package-private
  static const jlong serialVersionUID = 7887036954666565936LL;
private:
  JArray< jbyte > * __attribute__((aligned(__alignof__( ::java::lang::Object)))) id__;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_Session$ID__