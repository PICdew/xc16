
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_io_ObjectOutput__
#define __java_io_ObjectOutput__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>


class java::io::ObjectOutput : public ::java::lang::Object
{

public:
  virtual void write(jint) = 0;
  virtual void write(JArray< jbyte > *) = 0;
  virtual void write(JArray< jbyte > *, jint, jint) = 0;
  virtual void writeObject(::java::lang::Object *) = 0;
  virtual void flush() = 0;
  virtual void close() = 0;
  virtual void writeBoolean(jboolean) = 0;
  virtual void writeByte(jint) = 0;
  virtual void writeChar(jint) = 0;
  virtual void writeShort(jint) = 0;
  virtual void writeInt(jint) = 0;
  virtual void writeLong(jlong) = 0;
  virtual void writeFloat(jfloat) = 0;
  virtual void writeDouble(jdouble) = 0;
  virtual void writeBytes(::java::lang::String *) = 0;
  virtual void writeChars(::java::lang::String *) = 0;
  virtual void writeUTF(::java::lang::String *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_io_ObjectOutput__