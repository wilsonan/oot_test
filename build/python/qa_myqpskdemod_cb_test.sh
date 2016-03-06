#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/wilsonan/Software/gr-cpptutorial/python
export PATH=/home/wilsonan/Software/gr-cpptutorial/build/python:$PATH
export LD_LIBRARY_PATH=/home/wilsonan/Software/gr-cpptutorial/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/wilsonan/Software/gr-cpptutorial/build/swig:$PYTHONPATH
/usr/bin/python2 /home/wilsonan/Software/gr-cpptutorial/python/qa_myqpskdemod_cb.py 
