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


#ifndef INCLUDED_CPPTUTORIAL_WIL_POLYCLOCK1_H
#define INCLUDED_CPPTUTORIAL_WIL_POLYCLOCK1_H

#include <cpptutorial/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace cpptutorial {

    /*!
     * \brief <+description of block+>
     * \ingroup cpptutorial
     *
     */
    class CPPTUTORIAL_API wil_polyclock1 : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<wil_polyclock1> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of cpptutorial::wil_polyclock1.
       *
       * To avoid accidental use of raw pointers, cpptutorial::wil_polyclock1's
       * constructor is in a private implementation
       * class. cpptutorial::wil_polyclock1::make is the public interface for
       * creating new instances.
       */
      static sptr make(double sps, float lpbw, const std::vector<float> &taps, unsigned int filter_size, float ini_phase, float max_rdev, int outsps);
    };

  } // namespace cpptutorial
} // namespace gr

#endif /* INCLUDED_CPPTUTORIAL_WIL_POLYCLOCK1_H */

