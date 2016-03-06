/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "myqpskdemod_cb_impl.h"

namespace gr {
  namespace cpptutorial {

    myqpskdemod_cb::sptr
    myqpskdemod_cb::make(bool gray_code)
    {
      return gnuradio::get_initial_sptr
        (new myqpskdemod_cb_impl(gray_code));
    }

    /*
     * The private constructor
     */
    myqpskdemod_cb_impl::myqpskdemod_cb_impl(bool gray_code)
      : gr::sync_block("myqpskdemod_cb",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(char))),
	d_gray_code(gray_code)
    {}

    /*
     * Our virtual destructor.
     */
    myqpskdemod_cb_impl::~myqpskdemod_cb_impl()
    {
    }

    /*
     * The minimum distance decoder function
     */ 
    unsigned char
    myqpskdemod_cb_impl::get_minimum_distances(const gr_complex &sample)
    { 
	if (d_gray_code) {
		unsigned char bit0 = 0;
		unsigned char bit1 = 0;
		// The two left quadrants (quadrature component < 0) have this bit set to 1
		if (sample.real() < 0)	{
			bit0 = 0x01;
		}
	        // The two lower quadrants (in-phase component < 0) have this bit set to 1
                if (sample.imag() < 0)  {
                        bit1 = 0x01 << 1;
                }
		return bit0|bit1;
	} else {
		// For non-gray code, we can't simply decide on signs, so we check every single quadra			nt.
	  if (sample.imag() >= 0 and sample.real() >= 0) {
          	return 0x00;
          }
          else if (sample.imag() >= 0 and sample.real() < 0) {
          	return 0x01;
          }
          else if (sample.imag() < 0 and sample.real() < 0) {
          	return 0x02;
          }
          else if (sample.imag() < 0 and sample.real() >= 0) {
          	return 0x03;
          }
	}
    }



    int
    myqpskdemod_cb_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        unsigned char *out = (unsigned char *) output_items[0];
	gr_complex origin = gr_complex(0,0);

	// Perform ML decoding over the input iq data to generate alphabets	
	for(int i = 0; i < noutput_items; i++)
	{
		// ML decoder, determine the minimum distance from all constellation points 
		out[i] = get_minimum_distances(in[i]);
	}
        // Do <+signal processing+>

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace cpptutorial */
} /* namespace gr */

