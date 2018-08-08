#include "json.h"
#include "jsonValue.h"
#include "jsonException.h"

namespace pain {

	void Json::parse(const std::string &content, std::string &status) noexcept 
	{
		try{
			parse(content);
			status = "parse ok";
		} catch (const json::Exception &msg) {
			status = msg.what();
		} catch (...) {
		}
	}

	void Json::parse(const std::string &content)
	{
		v->parse(content);
	}

	Json::Json() noexcept : v(new json::Value) { }
	Json::~Json() noexcept { }
	Json::Json(const Json &rhs) noexcept
	{
		v.reset(new json::Value(*(rhs.v)));
	}
	Json& Json::operator=(const Json &rhs) noexcept
	{
		v.reset(new json::Value(*(rhs.v)));
	}

	int Json::get_type() const noexcept

	{
		return v-> get_type();
	}
	void Json::set_type(json::type t) noexcept
	{
		v-> set_type(t);
	}
	double Json::get_number() const noexcept
	{
		return v-> get_number();
	}
	void Json::set_number(double d) noexcept
	{
		v-> set_number(d);
	}
	const std::string Json::get_string() const noexcept
	{
		return v-> get_string();
	}
	void Json::set_string(const std::string &str) noexcept
	{
		v-> set_string(str);
	}

}
