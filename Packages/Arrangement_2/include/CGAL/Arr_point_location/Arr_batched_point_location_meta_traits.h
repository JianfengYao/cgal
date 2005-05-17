// Copyright (c) 1997  Tel-Aviv University (Israel).
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
// $Source$
// $Revision$ $Date$
// $Name$
//
// Author(s)     : Baruch Zukerman <baruchzu@post.tau.ac.il>

#ifndef ARR_BATCHED_POIN_LOCATION_META_TRAITS_H
#define ARR_BATCHED_POIN_LOCATION_META_TRAITS_H


CGAL_BEGIN_NAMESPACE



template <class Traits, class _Halfedge_const_handle>
class Arr_batched_point_location_meta_traits : public Traits
{

  typedef _Halfedge_const_handle  Halfedge_const_handle;
  // nested class My_X_monotone_curve_2
  class My_X_monotone_curve_2 : public Traits::X_monotone_curve_2 
  {
  public:
    typedef typename Traits::X_monotone_curve_2 Base;
    typedef typename Traits::Point_2            Point_2;

    friend class Arr_batched_point_location_meta_traits<Traits,
                                                        Halfedge_const_handle>;

    My_X_monotone_curve_2():Base(),
                            m_he_handle(NULL)
    {}

    My_X_monotone_curve_2(const Base& cv):Base(cv),
                                          m_he_handle(NULL)
    {}

    My_X_monotone_curve_2(const Base&cv, Halfedge_const_handle he):Base(cv),
                                                                   m_he_handle(he)
    {}


    Halfedge_const_handle get_halfedge_handle() const
    {
      return m_he_handle;
    }

   
    protected:
    Halfedge_const_handle m_he_handle;
  }; // nested class My_X_monotone_curve_2 - END


public:

  typedef typename Traits::X_monotone_curve_2       Base_X_monotone_curve_2;
  typedef typename Traits::Point_2                  Point_2;
  typedef My_X_monotone_curve_2                     X_monotone_curve_2;

  class Intersect_2
  {
  public:
   
    template<class OutputIterator>
    OutputIterator operator() (const X_monotone_curve_2& cv1,
                               const X_monotone_curve_2& cv2,
                               OutputIterator oi) const
    {
      return (oi);
    }
  };

  /*! Get an Intersect_2 functor object. */
  Intersect_2 intersect_2_object () const
  {
    return Intersect_2();
  }
};


CGAL_END_NAMESPACE

#endif

