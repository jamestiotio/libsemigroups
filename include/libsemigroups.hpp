//
// libsemigroups - C++ library for semigroups and monoids
// Copyright (C) 2018 James D. Mitchell
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

//! \file
//! This file includes all the headers in libsemigroups, for convenience.

#ifndef LIBSEMIGROUPS_INCLUDE_LIBSEMIGROUPS_HPP_
#define LIBSEMIGROUPS_INCLUDE_LIBSEMIGROUPS_HPP_

#include "blocks.hpp"
#include "bmat8.hpp"
#include "cong-base.hpp"
#include "cong-pair.hpp"
#include "cong.hpp"
#include "constants.hpp"
#include "containers.hpp"
#include "fpsemi-base.hpp"
#include "fpsemi.hpp"
#include "froidure-pin-base.hpp"
#include "knuth-bendix.hpp"
#include "libsemigroups-config.hpp"
#include "libsemigroups-debug.hpp"
#include "libsemigroups-exception.hpp"
#include "obvinf.hpp"
#include "race.hpp"
#include "range.hpp"
#include "reduct.hpp"
#include "report.hpp"
#include "runner.hpp"
#include "schreier-sims.hpp"
#include "semiring.hpp"
#include "stl.hpp"
#include "tce.hpp"
#include "timer.hpp"
#include "todd-coxeter.hpp"
#include "traits.hpp"
#include "types.hpp"
#include "uf.hpp"
#include "wrap.hpp"

#ifdef LIBSEMIGROUPS_DENSEHASHMAP
#include "extern/sparsehash-c11/sparsehash/dense_hash_map"
#endif

#endif  // LIBSEMIGROUPS_INCLUDE_LIBSEMIGROUPS_HPP_
