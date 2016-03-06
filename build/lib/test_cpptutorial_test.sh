#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/wilsonan/Software/gr-cpptutorial/lib
export PATH=/home/wilsonan/Software/gr-cpptutorial/build/lib:$PATH
export LD_LIBRARY_PATH=/home/wilsonan/Software/gr-cpptutorial/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-cpptutorial 
