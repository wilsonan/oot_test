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
#include "cppderivative_impl.h"

namespace gr {
  namespace cpptutorial {

    cppderivative::sptr
    cppderivative::make()
    {
      return gnuradio::get_initial_sptr
        (new cppderivative_impl());
    }

    /*
     * The private constructor
     */
    cppderivative_impl::cppderivative_impl()
      : gr::sync_block("cppderivative",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {
	std::vector<float> taps;
	taps.push_back(1);
	taps.push_back(-1);
	d_fir = new gr::filter::kernel::fir_filter_fff(1,taps);
	set_history(2);


    }

    /*
     * Our virtual destructor.
     */
    cppderivative_impl::~cppderivative_impl()
    {
   
	delete d_fir;

    }

    int
    cppderivative_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const float *in = (const float *) input_items[0];
        float *out = (float *) output_items[0];

        // Do <+signal processing+>
	
	d_fir->filterN(out, in, noutput_items);
	
        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace cpptutorial */
} /* namespace gr */

