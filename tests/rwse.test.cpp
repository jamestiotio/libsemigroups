//
// libsemigroups - C++ library for semigroups and monoids
// Copyright (C) 2017 James D. Mitchell
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

#include "catch.hpp"
#include "rwse.hpp"

#define RWSE_REPORT false

using namespace libsemigroups;

template <class TElementType>
void delete_gens(std::vector<TElementType>& gens) {
  for (auto& x : gens) {
    delete x;
  }
}

TEST_CASE("RWSE 01:", "[quick][rwse][01]") {
  std::vector<Element*> gens
      = {new Transformation<u_int16_t>({1, 0}),
         new Transformation<u_int16_t>(std::vector<u_int16_t>({0, 0}))};
  FroidurePin<> S = FroidurePin<>(gens);
  REPORTER.set_report(RWSE_REPORT);
  delete_gens(gens);

  REQUIRE(S.size() == 4);
  REQUIRE(S.degree() == 2);
  REQUIRE(S.nr_rules() == 4);
  std::vector<relation_type> extra;
  Congruence                 cong("twosided", &S, extra);

  RWS rws;
  rws.add_rules(cong.relations());
  rws.add_rules(cong.extra());

  REQUIRE(rws.confluent());

  gens          = {new RWSE(rws, 0), new RWSE(rws, 1)};
  FroidurePin<> T = FroidurePin<>(gens);
  REPORTER.set_report(RWSE_REPORT);
  REQUIRE(T.size() == 4);
  delete_gens(gens);

  RWSE ab(rws, word_type({0, 1}));
  RWSE b(rws, 1);
  REQUIRE(!(b < ab));
  REQUIRE(b == ab);
  REQUIRE(!(ab < b));
  REQUIRE(!(ab < b));

  RWSE aba(rws, word_type({0, 1, 0}));
  REQUIRE(b < aba);
}

TEST_CASE("RWSE 02: factorisation", "[quick][rwse][02]") {
  std::vector<Element*> gens
      = {new Transformation<u_int16_t>({1, 0}),
         new Transformation<u_int16_t>(std::vector<u_int16_t>({0, 0}))};
  FroidurePin<> S = FroidurePin<>(gens);
  REPORTER.set_report(RWSE_REPORT);
  delete_gens(gens);

  std::vector<relation_type> extra;
  Congruence                 cong("twosided", &S, extra);
  RWS                        rws;
  rws.add_rules(cong.relations());
  rws.add_rules(cong.extra());

  REQUIRE(rws.confluent());

  gens          = {new RWSE(rws, 0), new RWSE(rws, 1)};
  FroidurePin<> T = FroidurePin<>(gens);
  REPORTER.set_report(RWSE_REPORT);
  delete_gens(gens);

  RWSE ab(rws, word_type({0, 1}));
  REQUIRE(T.factorisation(&ab) == word_type({1}));

  RWSE aaa(rws, word_type({0, 0, 0}));
  REQUIRE(T.factorisation(&aaa) == word_type({0}));
}
