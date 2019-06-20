// Launch configuration for a single Machine
// Author: Daniel Sahu <danielmohansahu@gmail.com>

#include "machine.h"

#include "../package_registry.h"

#include <wordexp.h>
#include <glob.h>

#include <cstdarg>

#include <fmt/format.h>

template<typename... Args>
std::runtime_error error(const char* format, const Args& ... args)
{
	std::string msg = fmt::format(format, args...);
	return std::runtime_error(msg);
}

namespace rosmon
{

namespace launch
{

Machine::Machine(std::string name, std::string address, std::string env_loader)
 : m_name(std::move(name))
 , m_address(std::move(address))
 , m_env_loader(std::move(env_loader))
 , m_username()
 , m_timeout(10.0)
{
}

void Machine::setTimeout(const std::string& timeout)
{
	double numerical_timeout;
	try {
		numerical_timeout = std::stod(timeout);
		m_timeout = numerical_timeout;
	} catch(std::invalid_argument) {
		throw error("Invalid timeout parameter for machine tag {}: {}", m_name, timeout);
	}
}

void Machine::setUsername(const std::string& username)
{
	m_username = username;
}

} // namespace launch

} // namespace rosmon
