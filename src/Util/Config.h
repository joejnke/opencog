/*
 * src/Util/Config.h
 *
 * Copyright (C) 2008 by Singularity Institute for Artificial Intelligence
 * All Rights Reserved
 *
 * Written by Gustavo Gama <gama@vettalabs.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef UTIL_CONFIG_H
#define UTIL_CONFIG_H

#include <string>
#include <map>

namespace opencog
{

static const std::string DEFAULT_CONFIG[] = {
    "SERVER_PORT",                "17001",
    "LOG_FILE",                   "opencog_server.log",
    "LOG_LEVEL",                  "info",
    "LOG_TO_STDOUT",              "true",
    "SERVER_CYCLE_DURATION",      "100",     // in milliseconds
    "IDLE_CYCLES_PER_TICK",       "3",
    "STARTING_STI_FUNDS",         "10000",
    "STARTING_LTI_FUNDS",         "10000",
    "STI_FUNDS_BUFFER",           "10000",
    "LTI_FUNDS_BUFFER",           "10000",
    "MIN_STI",                    "-400",
    "",                           ""
};

class Config
{

protected:

    std::string emptyString;
    std::map<std::string, std::string> table;

public:
    // constructor and destructor
    ~Config();
    Config();

    // reset configuration to default
    void reset();

    // Load passed file and redefines values for parameters.
    void load(const char* config_file);

    // Return current value of a given parameter.
    const std::string& get(const std::string &parameter_name) const;
    const std::string& operator[](const std::string &name) const;

    // Return current value of a given parameter as an integer
    int get_int(const std::string &parameter_name) const;

    // Return current value of a given parameter as a double
    double get_double(const std::string &parameter_name) const;
    //
    // Return current value of a given parameter as a boolean
    bool get_bool(const std::string &parameter_name) const;

    // Dump all configuration parameters to a string
    std::string to_string() const;
};

// singleton instance (following meyer's design pattern)
Config& config();

} // namespace opencog

#endif
