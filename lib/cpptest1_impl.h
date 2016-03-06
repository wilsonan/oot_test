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

#ifndef INCLUDED_CPPTUTORIAL_CPPTEST1_IMPL_H
#define INCLUDED_CPPTUTORIAL_CPPTEST1_IMPL_H

#include <cpptutorial/cpptest1.h>

namespace gr {
  namespace cpptutorial {

    class cpptest1_impl : public cpptest1
    {
     private:
      // Nothing to declare in this block.

     public:
      cpptest1_impl();
      ~cpptest1_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace cpptutorial
} // namespace gr

#endif /* INCLUDED_CPPTUTORIAL_CPPTEST1_IMPL_H */

