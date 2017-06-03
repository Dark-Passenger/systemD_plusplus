#ifndef __SYSTEMD_HXX__
#define __SYSTEMD_HXX__

#include <dbus-c++-1/dbus-c++/dbus.h>
#include <cassert>

namespace login1
{
    class Manager_proxy
        : public ::DBus::InterfaceProxy
    {
        public:

            Manager_proxy()
                : ::DBus::InterfaceProxy("org.freedesktop.login1.Manager"){}

            /* properties exported by this interface */
            void PowerOff(const bool& argin0);

            void Reboot(const bool& argin0);
    };
}

namespace systemd1
{
    class Unit_proxy
        : public ::DBus::InterfaceProxy
    {
        public:

            Unit_proxy()
                : ::DBus::InterfaceProxy("org.freedesktop.systemd1.Unit"){}

        public:

            /* properties exported by this interface */
            const std::string LoadState();
            const std::string ActiveState();
            const std::string SubState();
    };

    class Manager_proxy
        : public ::DBus::InterfaceProxy
    {
        public:

            Manager_proxy()
                : ::DBus::InterfaceProxy("org.freedesktop.systemd1.Manager"){}

            ::DBus::Path GetUnit(const std::string& argin0);

            ::DBus::Path GetUnitByPID(const uint32_t& argin0);

            ::DBus::Path LoadUnit(const std::string& argin0);

            ::DBus::Path StartUnit(const std::string& argin0, const std::string& argin1);

            void EnableUnitFiles(const std::vector< std::string >& argin0, const bool& argin1, const bool& argin2, bool& argout0, std::vector< ::DBus::Struct< std::string, std::string, std::string > >& argout1);

            void DisableUnitFiles(const std::vector< std::string >& argin0, const bool& argin1, std::vector< ::DBus::Struct< std::string, std::string, std::string > >& argout0);

            ::DBus::Path StopUnit(const std::string& argin0, const std::string& argin1);

            ::DBus::Path ReloadUnit(const std::string& argin0, const std::string& argin1);

            ::DBus::Path RestartUnit(const std::string& argin0, const std::string& argin1);

            void Reload();
    };
}


class SystemD : public systemd1::Manager_proxy,
    public DBus::IntrospectableProxy,
    public DBus::ObjectProxy
{
    public:
        SystemD(DBus::Connection con, const char *path, const char *name) : DBus::ObjectProxy(con, path, name) {};

};

class LoginD : public login1::Manager_proxy,
    public DBus::IntrospectableProxy,
    public DBus::ObjectProxy
{
    public:
        LoginD(DBus::Connection con, const char *path, const char *name) : DBus::ObjectProxy(con, path, name) {};

};

namespace systemd
{
    class unit : public systemd1::Unit_proxy,
    public DBus::IntrospectableProxy,
    public DBus::ObjectProxy
    {
        public:
            unit(DBus::Connection con, const char *path, const char *name) : DBus::ObjectProxy(con, path, name) {};
    };

    class login_manager
    {
        private:
            const char *path = "org/freedesktop/login1";
            const char *name = "org.freedesktop.login1";
            DBus::BusDispatcher dispatcher;
            DBus::Connection con;
            LoginD logind;

            DBus::Connection SetDispatcher(DBus::BusDispatcher &dispatcher);

        public:
            login_manager(): con(SetDispatcher(dispatcher)), logind(con, path, name) {};

            void PowerOff();

            void Reboot();

    };

    class manager
    {
        private:
            const char *path = "/org/freedesktop/systemd1";
            const char *name = "org.freedesktop.systemd1";
            DBus::BusDispatcher dispatcher;
            DBus::Connection con;
            SystemD systemd;

            DBus::Connection SetDispatcher(DBus::BusDispatcher &dispatcher);

        public:
            manager(): con(SetDispatcher(dispatcher)), systemd(con, path, name) {};

            unit GetUnit(const std::string &service_name);

            unit LoadUnit(const std::string &service_name);

            bool StartUnit(const std::string &service_name, const std::string &mode = "fail");

            bool StopUnit(const std::string &service_name, const std::string &mode = "fail");

            bool RestartUnit(const std::string &service_name, const std::string &mode = "fail");

            bool ReloadUnit(const std::string &service_name, const std::string &mode = "fail");

            bool EnableUnit(const std::string &service_name);

            bool DisableUnit(const std::string &service_name);

            void DaemonReload();
    };
}


#endif //__SYSTEMD__
