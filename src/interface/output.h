/* Copyright 2013-2015 Marcel Bollmann, Florian Petran
 *
 * This file is part of Norma.
 *
 * Norma is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * Norma is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with Norma.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef INTERFACE_OUTPUT_H_
#define INTERFACE_OUTPUT_H_
#include<string>
#include<iosfwd>
#include"iobase.h"
#include"normalizer/result.h"

namespace Norma {
/// Basic Output class. Not pure virtual since it's essentially
/// non-interactive output already.
class Output : public IOBase {
 public:
     Output();
     virtual ~Output() = default;
     /// put a line on the output device and record it in the history
     virtual void put_line(Normalizer::Result* result,
                           bool print_prob,
                           Normalizer::LogLevel max_level);
     bool thread_suitable() {
         return true;
     }

 protected:
     virtual void store_line(const string_impl& line) {
         _training->add_target(line);
     }
     virtual void log_messages(Normalizer::Result* result,
                               Normalizer::LogLevel max_level);
     std::ostream *_output;
};

}  // namespace Norma
#endif  // INTERFACE_OUTPUT_H_

