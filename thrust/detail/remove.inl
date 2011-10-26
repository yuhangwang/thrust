/*
 *  Copyright 2008-2011 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


/*! \file remove.inl
 *  \brief Inline file for remove.h.
 */

#include <thrust/remove.h>
#include <thrust/system/detail/generic/select_system.h>
#include <thrust/system/detail/generic/remove.h>
#include <thrust/iterator/iterator_traits.h>

namespace thrust
{

template<typename ForwardIterator,
         typename T>
  ForwardIterator remove(ForwardIterator first,
                         ForwardIterator last,
                         const T &value)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::remove;

  typedef typename thrust::iterator_space<ForwardIterator>::type space;

  return remove(select_system(space()), first, last, value);
} // end remove()

template<typename InputIterator,
         typename OutputIterator,
         typename T>
  OutputIterator remove_copy(InputIterator first,
                             InputIterator last,
                             OutputIterator result,
                             const T &value)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::remove_copy;

  typedef typename thrust::iterator_space<InputIterator>::type  space1;
  typedef typename thrust::iterator_space<OutputIterator>::type space2;

  return remove_copy(select_system(space1(),space2()), first, last, result, value);
} // end remove_copy()

template<typename ForwardIterator,
         typename Predicate>
  ForwardIterator remove_if(ForwardIterator first,
                            ForwardIterator last,
                            Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::remove_if;

  typedef typename thrust::iterator_space<ForwardIterator>::type space;

  return remove_if(select_system(space()), first, last, pred);
} // end remove_if()

template<typename ForwardIterator,
         typename InputIterator,
         typename Predicate>
  ForwardIterator remove_if(ForwardIterator first,
                            ForwardIterator last,
                            InputIterator stencil,
                            Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::remove_if;

  typedef typename thrust::iterator_space<ForwardIterator>::type space1;
  typedef typename thrust::iterator_space<InputIterator>::type   space2;

  return remove_if(select_system(space1(),space2()), first, last, stencil, pred);
} // end remove_if()

template<typename InputIterator,
         typename OutputIterator,
         typename Predicate>
  OutputIterator remove_copy_if(InputIterator first,
                                InputIterator last,
                                OutputIterator result,
                                Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::remove_copy_if;

  typedef typename thrust::iterator_space<InputIterator>::type  space1;
  typedef typename thrust::iterator_space<OutputIterator>::type space2;

  return remove_copy_if(select_system(space1(),space2()), first, last, result, pred);
} // end remove_copy_if()

template<typename InputIterator1,
         typename InputIterator2,
         typename OutputIterator,
         typename Predicate>
  OutputIterator remove_copy_if(InputIterator1 first,
                                InputIterator1 last,
                                InputIterator2 stencil,
                                OutputIterator result,
                                Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::remove_copy_if;

  typedef typename thrust::iterator_space<InputIterator1>::type space1;
  typedef typename thrust::iterator_space<InputIterator2>::type space2;
  typedef typename thrust::iterator_space<OutputIterator>::type space3;

  return remove_copy_if(select_system(space1(),space2(),space3()), first, last, stencil, result, pred);
} // end remove_copy_if()

} // end namespace thrust

