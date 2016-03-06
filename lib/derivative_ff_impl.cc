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
#include "derivative_ff_impl.h"

namespace gr {
  namespace cpptutorial {

    derivative_ff::sptr
    derivative_ff::make(int nfilt)
    {
      return gnuradio::get_initial_sptr
        (new derivative_ff_impl(nfilt));
    }

    /*
     * The private constructor
     */
    derivative_ff_impl::derivative_ff_impl(int nfilt)
      : gr::sync_block("derivative_ff",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {
	std::vector<float> taps;
	taps.push_back(1);
	taps.push_back(-1);
	d_fir = new gr::filter::kernel::fir_filter_fff(1,taps);
	set_history(2);
	//std::cout<<nfilt*2;
	filter_size = nfilt*2;
	}

    /*
     * Our virtual destructor.
     */
    derivative_ff_impl::~derivative_ff_impl()
    {
	delete d_fir;
    }

    int
    derivative_ff_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const float *in = (const float *) input_items[0];
        float *out = (float *) output_items[0];
	std::cout<<filter_size;
	d_fir->filterN(out,in,noutput_items);
        // Do <+signal processing+>
	
        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace cpptutorial */
} /* namespace gr */

