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
#include "wil_polyclock1_impl.h"
#include <gnuradio/filter/fir_filter.h>


namespace gr {
  namespace cpptutorial {

    wil_polyclock1::sptr
    wil_polyclock1::make(double sps, float lpbw, const std::vector<float> &taps, unsigned int filter_size, float ini_phase, float max_rdev, int outsps)
    {
      return gnuradio::get_initial_sptr
        (new wil_polyclock1_impl(sps, lpbw, taps, filter_size, ini_phase, max_rdev, outsps));
    }


    static int ios[] = {sizeof(gr_complex),sizeof(float),sizeof(float),sizeof(float)};
    static std::vector<int> iosig(ios, ios+sizeof(ios)/sizeof(int));
    
 	
     /*
     * The private constructor
     */
    wil_polyclock1_impl::wil_polyclock1_impl(double sps, float lpbw, const std::vector<float> &taps, unsigned int filter_size, float ini_phase, float max_rdev, int outsps)
      : gr::block("wil_polyclock1",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::makev(1, 4, iosig)),d_nfilt(filter_size)
    {
	// Checking if the tap size is 0 or not. If 0 then a runtime error is invoked.
	if(taps.size() == 0)
	  throw std::runtime_error("Tap Size cannot be zero. Please specify a filter.\n");
	
	// Let scheduler adjust our relative_rate
	//enable_update_rate(true);
	//d_nfilt = filter_size;	
	std::cout<<"The filter taps are:";
	for(int i = 0; i < taps.size(); i++)
		std::cout<<" "<<taps[i]<<" ";
	
	// Creating a fir filter using the gnuradio libraries
   	test_filter = new gr::filter::kernel::fir_filter_ccf(1,taps);	
	//test_filter->set_taps(taps);
	set_history(taps.size());

	}


    /*
     * Our virtual destructor.
     */
    wil_polyclock1_impl::~wil_polyclock1_impl()
    {
    }

    void
    wil_polyclock1_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
        /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    wil_polyclock1_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        gr_complex *out = (gr_complex *) output_items[0];

	for(int i = 0; i < noutput_items; i++) {

		//out[i] = in[i]*(float)d_nfilt;
		out[i] = test_filter->filter(&in[i]);
		
	}

	//test_filter->filterN(out, in, noutput_items);	
	//std::cout<<" "<<iosig[0]<<" "<<iosig[1]<<" "<<iosig[2]<<" "<<iosig[3];
       	//std::cout<<" "<<d_nfilt<<" ";
	// Do <+signal processing+>
        // Tell runtime system how many input items we consumed on
        // each input stream.
        consume_each (noutput_items);

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace cpptutorial */
} /* namespace gr */

