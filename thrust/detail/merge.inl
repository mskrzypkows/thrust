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

/*! \file merge.inl
 *  \brief Inline file for merge.h.
 */

#include <thrust/merge.h>
#include <thrust/detail/backend/generic/select_system.h>
#include <thrust/detail/backend/generic/merge.h>
#include <thrust/iterator/iterator_traits.h>

// XXX make the backend-specific versions of reduce available
// XXX try to eliminate the need for these
#include <thrust/detail/backend/cpp/merge.h>
#include <thrust/detail/backend/cuda/merge.h>

namespace thrust
{

template<typename InputIterator1,
         typename InputIterator2,
         typename OutputIterator,
         typename StrictWeakOrdering>
  OutputIterator merge(InputIterator1 first1,
                       InputIterator1 last1,
                       InputIterator2 first2,
                       InputIterator2 last2,
                       OutputIterator result,
                       StrictWeakOrdering comp)
{
  using thrust::detail::backend::generic::select_system;
  using thrust::detail::backend::generic::merge;

  typedef typename thrust::iterator_space<InputIterator1>::type space1;
  typedef typename thrust::iterator_space<InputIterator2>::type space2;
  typedef typename thrust::iterator_space<OutputIterator>::type space3;

  return merge(select_system(space1(),space2(),space3()), first1, last1, first2, last2, result, comp);
} // end set_intersection()

template<typename InputIterator1,
         typename InputIterator2,
         typename OutputIterator>
  OutputIterator merge(InputIterator1 first1,
                       InputIterator1 last1,
                       InputIterator2 first2,
                       InputIterator2 last2,
                       OutputIterator result)
{
  using thrust::detail::backend::generic::select_system;
  using thrust::detail::backend::generic::merge;

  typedef typename thrust::iterator_space<InputIterator1>::type space1;
  typedef typename thrust::iterator_space<InputIterator2>::type space2;
  typedef typename thrust::iterator_space<OutputIterator>::type space3;

  return merge(select_system(space1(),space2(),space3()), first1, last1, first2, last2, result);
} // end merge()

} // end thrust

