// Launch configuration for a single Machine
// Author: Daniel Sahu <danielmohansahu@gmail.com>

#ifndef ROSMON_LAUNCH_MACHINE_H
#define ROSMON_LAUNCH_MACHINE_H

#include <string>
#include <memory>

namespace rosmon
{

namespace launch
{

class Machine
{
public:
	typedef std::shared_ptr<Machine> Ptr;
	typedef std::shared_ptr<const Machine> ConstPtr;

	Machine(std::string name, std::string address, std::string env_loader);

	void setTimeout(const std::string& timeout);
	void setUsername(const std::string& username);

	std::string name() const
	{ return m_name; }

	std::string address() const
	{ return m_address; }

	std::string env_loader() const
	{ return m_env_loader; }

	std::string username() const
	{ return m_username; }

	double timeout() const
	{ return m_timeout; }

private:
	std::string m_name;
	std::string m_address;
	std::string m_env_loader;

	std::string m_username;
	double m_timeout;

};

}

}

#endif
