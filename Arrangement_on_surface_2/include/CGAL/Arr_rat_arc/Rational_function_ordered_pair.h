// Copyright (c) 2011 Tel-Aviv University (Israel), INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Oren Salzman <orenzalz@post.tau.ac.il >
//                 Michael Hemmer <Michael.Hemmer@sophia.inria.fr>

#ifndef CGAL_RATIONAL_FUNCTION_ORDERED_PAIR_H
#define CGAL_RATIONAL_FUNCTION_ORDERED_PAIR_H


#include <CGAL/Arr_rat_arc/Base_rational_arc_ds_1.h>
#include <CGAL/Arr_rat_arc/Rational_function.h>
#include <CGAL/Arr_rat_arc/Rational_function_pair.h>

namespace CGAL {
namespace Arr_rational_arc
{
template <typename AlgebraicKernel_d_1>
class Rational_function_ordered_pair:
    public Base_rational_arc_ds_1<AlgebraicKernel_d_1>
{
public:
  typedef AlgebraicKernel_d_1                          Algebraic_kernel_d_1;
  typedef Base_rational_arc_ds_1<Algebraic_kernel_d_1> Base;
  typedef CGAL::Arr_rational_arc::Rational_function_pair<Algebraic_kernel_d_1>
                                                       Rational_function_pair;
  typedef CGAL::Arr_rational_arc::Rational_function<Algebraic_kernel_d_1>
                                                       Rational_function;

  typedef typename Base::Polynomial_1                  Polynomial_1;
  typedef typename Base::Algebraic_real_1              Algebraic_real_1;
  typedef typename Base::Algebraic_vector              Algebraic_vector;
  typedef typename Base::Multiplicity                  Multiplicity;
  typedef typename Base::Multiplicity_vector           Multiplicity_vector;
  typedef typename Base::Root_multiplicity_vector      Root_multiplicity_vector;
 
public:
  Rational_function_ordered_pair(const Rational_function_pair& rat_pair,
                                 bool is_opposite = false) :
    _rat_pair(rat_pair), _is_opposite(is_opposite)
  {}
       
  Comparison_result compare_f_g_at(const Algebraic_real_1& x,
                                   CGAL::Sign epsilon = CGAL::ZERO)
  {
    Comparison_result cr =  _rat_pair.compare_f_g_at(x,epsilon);
    if (_is_opposite == false)
      return cr;
    return (cr == CGAL:: LARGER ) ? CGAL:: SMALLER  :
      (cr == CGAL:: SMALLER ) ? CGAL:: LARGER  :
      /* (cr == CGAL::EQUAL)*/   CGAL:: EQUAL;
  }

  Comparison_result compare_f_g_at(Arr_parameter_space boundary)
  {
    Comparison_result cr =  _rat_pair.compare_f_g_at(boundary);
    if (_is_opposite == false)
      return cr;
    return (cr == CGAL:: LARGER ) ? CGAL:: SMALLER  :
      (cr == CGAL:: SMALLER ) ? CGAL:: LARGER  :
      /* (cr == CGAL::EQUAL)*/ CGAL::EQUAL;
  }

  bool is_intersecting_in_range(const Arr_parameter_space left_parameter_space,
                                const Algebraic_real_1 left,
                                const Arr_parameter_space right_parameter_space,
                                const Algebraic_real_1 right)
  {
    return _rat_pair.is_intersecting_in_range(left_parameter_space, left,
                                              right_parameter_space, right);
  }

  const Algebraic_vector & roots() const
  {
    return _rat_pair.roots();
  }

  const Multiplicity_vector & multiplicities() const
  {
    return _rat_pair.multiplicities();
  }

private:   
  const Rational_function_pair& _rat_pair;
  bool       _is_opposite;
}; // Rational_function_ordered_pair


}   //namespace Arr_rational_arc
}   //namespace CGAL {   

#endif //CGAL_RATIONAL_FUNCTION_ORDERED_PAIR_H