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
#include "cpptest1_impl.h"

namespace gr {
  namespace cpptutorial {

    cpptest1::sptr
    cpptest1::make()
    {
      return gnuradio::get_initial_sptr
        (new cpptest1_impl());
    }

    /*
     * The private constructor
     */
    cpptest1_impl::cpptest1_impl()
      : gr::sync_block("cpptest1",
              gr::io_signature::make(1,1, sizeof(gr_complex)),
              gr::io_signature::make(1,1, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    cpptest1_impl::~cpptest1_impl()
    {
    }

    int
    cpptest1_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        gr_complex *out = (gr_complex *) output_items[0];

        // Do <+signal processing+>
	std::cout<<in[0];
        std::cout<<"It is working here";
	for(int i = 0;i < noutput_items; i++)
	{
	
	std::cout<<in[i];
	}
	// Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace cpptutorial */
} /* namespace gr */

