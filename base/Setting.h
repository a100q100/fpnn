#ifndef SETTING_H_
#define SETTING_H_
#include <string>
#include <vector>
#include <unordered_map>
namespace fpnn {
class Setting
{
	public:
		typedef std::unordered_map<std::string, std::string> MapType;
	private:
		static const std::string* _find(const std::string& key, const MapType& map);
		static MapType _map;
		static std::string _config_file;
	public:
		struct EndpointST{
			std::string name;
			std::string proto;
			std::string host;
			int port;
			int timeout;
		};

		struct MysqlConnST{
			std::string proto;
			std::string user;
			std::string passwd;
			std::string host;
			int port;
			std::string db;
			int timeout;
		};

		static std::string getString(const std::string& name, const std::string& dft = std::string(), const MapType& map = _map);
		static intmax_t getInt(const std::string& name, intmax_t dft = 0, const MapType& map = _map);
		static bool getBool(const std::string& name, bool dft = false, const MapType& map = _map);
		static double getReal(const std::string& name, double dft = 0.0, const MapType& map = _map);
		static std::vector<std::string> getStringList(const std::string& name, const MapType& map = _map);

		static void set(const std::string& name, const std::string& value);
		static bool insert(const std::string& name, const std::string& value);
		static bool update(const std::string& name, const std::string& value);

		static bool load(const std::string& file);
		static MapType loadMap(const std::string& file);
		static std::string getFileMD5(const std::string& file);

		static bool setted(const std::string& name, const MapType& map = _map);

		static void printInfo();
		static std::string getConfigFile() { return _config_file; }

		/* name @tcp:localhost:11008^10 */
		bool parseEndpoint(const std::string& endpoint, EndpointST& st);
		/* mysql://dev:dev@127.0.0.1:3306/db^10 */
		bool parseDBSetting(const std::string& mysqlConn, MysqlConnST& st);

		static std::string getString(const std::vector<std::string>& priority, const std::string& dft = std::string(), const MapType& map = _map);
		static intmax_t getInt(const std::vector<std::string>& priority, intmax_t dft = 0, const MapType& map = _map);
		static bool getBool(const std::vector<std::string>& priority, bool dft = false, const MapType& map = _map);
		static double getReal(const std::vector<std::string>& priority, double dft = 0.0, const MapType& map = _map);
};
}

#endif
