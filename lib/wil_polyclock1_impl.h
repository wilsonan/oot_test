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

#ifndef INCLUDED_CPPTUTORIAL_WIL_POLYCLOCK1_IMPL_H
#define INCLUDED_CPPTUTORIAL_WIL_POLYCLOCK1_IMPL_H

#include <cpptutorial/wil_polyclock1.h>
#include <gnuradio/filter/fir_filter.h>

namespace gr {
  namespace cpptutorial {

    class wil_polyclock1_impl : public wil_polyclock1
    {
     private:
      // Nothing to declare in this block.
	int d_nfilt; 

	gr::filter::kernel::fir_filter_ccf *test_filter;

	// Creating taps for the polyphase matched filter- it is made as a two dimensional dynamic array
	std::vector< std::vector<float> >	d_taps;

	//test_filter = new gr::filter::kernel::fir_filter_ccf(1);

     public:
      wil_polyclock1_impl(double sps, float lpbw, const std::vector<float> &taps, unsigned int filter_size, float ini_phase, float max_rdev, int outsps);
      ~wil_polyclock1_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace cpptutorial
} // namespace gr

#endif /* INCLUDED_CPPTUTORIAL_WIL_POLYCLOCK1_IMPL_H */
