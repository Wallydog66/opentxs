/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_Otapi_WRAP_H_
#define SWIG_Otapi_WRAP_H_

namespace Swig {
  class Director;
}


class SwigDirector_OTCallback : public OTCallback, public Swig::Director {

public:
    SwigDirector_OTCallback(VALUE self);
    virtual ~SwigDirector_OTCallback();
    virtual void runOne(char const *szDisplay, OTPassword &theOutput);
    virtual void runTwo(char const *szDisplay, OTPassword &theOutput);
};


#endif
