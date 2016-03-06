#!/usr/bin/env python
##################################################
# Gnuradio Python Flow Graph
# Title: Derivative Test2
# Generated: Sun Mar  6 23:07:45 2016
##################################################

from PyQt4 import Qt
from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import cpptutorial
import sys

from distutils.version import StrictVersion
class derivative_test2(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Derivative Test2")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Derivative Test2")
        try:
             self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except:
             pass
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "derivative_test2")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())


        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 32000

        ##################################################
        # Blocks
        ##################################################
        self.cpptutorial_derivative_ff_0 = cpptutorial.derivative_ff(2)
        self.blocks_vector_source_x_0 = blocks.vector_source_f((0, 1, 2, 3, 4, 4, 4, 4, 2, 0), True, 1, [])
        self.blocks_vector_sink_x_0 = blocks.vector_sink_f(1)
        self.blocks_throttle_0 = blocks.throttle(gr.sizeof_float*1, samp_rate,True)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_throttle_0, 0), (self.cpptutorial_derivative_ff_0, 0))    
        self.connect((self.blocks_vector_source_x_0, 0), (self.blocks_throttle_0, 0))    
        self.connect((self.cpptutorial_derivative_ff_0, 0), (self.blocks_vector_sink_x_0, 0))    

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "derivative_test2")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.blocks_throttle_0.set_sample_rate(self.samp_rate)

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"
    parser = OptionParser(option_class=eng_option, usage="%prog: [options]")
    (options, args) = parser.parse_args()
    if(StrictVersion(Qt.qVersion()) >= StrictVersion("4.5.0")):
        Qt.QApplication.setGraphicsSystem(gr.prefs().get_string('qtgui','style','raster'))
    qapp = Qt.QApplication(sys.argv)
    tb = derivative_test2()
    tb.start()
    tb.show()
    print tb.blocks_vector_sink_x_0.data()
    def quitting():
        tb.stop()
        tb.wait()
    qapp.connect(qapp, Qt.SIGNAL("aboutToQuit()"), quitting)
    qapp.exec_()
    tb = None #to clean up Qt widgets
