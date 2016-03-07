/* -*- c++ -*- */

#define CPPTUTORIAL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "cpptutorial_swig_doc.i"

%{
#include "cpptutorial/myqpskdemod_cb.h"
#include "cpptutorial/cpptest1.h"
#include "cpptutorial/cppderivative.h"
#include "cpptutorial/derivative_ff.h"
#include "cpptutorial/wil_polyclock1.h"
%}


%include "cpptutorial/myqpskdemod_cb.h"
GR_SWIG_BLOCK_MAGIC2(cpptutorial, myqpskdemod_cb);
%include "cpptutorial/cpptest1.h"
GR_SWIG_BLOCK_MAGIC2(cpptutorial, cpptest1);
%include "cpptutorial/cppderivative.h"
GR_SWIG_BLOCK_MAGIC2(cpptutorial, cppderivative);
%include "cpptutorial/derivative_ff.h"
GR_SWIG_BLOCK_MAGIC2(cpptutorial, derivative_ff);

%include "cpptutorial/wil_polyclock1.h"
GR_SWIG_BLOCK_MAGIC2(cpptutorial, wil_polyclock1);
