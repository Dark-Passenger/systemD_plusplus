#include "systemd.hxx"


void login1::Manager_proxy::PowerOff(const bool& argin0)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    call.member("PowerOff");
    DBus::Message ret = invoke_method (call);
}

void login1::Manager_proxy::Reboot(const bool& argin0)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    call.member("Reboot");
    DBus::Message ret = invoke_method (call);
}

const std::string systemd1::Unit_proxy::LoadState() {
    DBus::CallMessage call ;
    call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
    DBus::MessageIter wi = call.writer();
    const std::string interface_name = "org.freedesktop.systemd1.Unit";
    const std::string property_name  = "LoadState";
    wi << interface_name;
    wi << property_name;
    DBus::Message ret = this->invoke_method (call);
    DBus::MessageIter ri = ret.reader ();
    DBus::Variant argout;
    ri >> argout;
    return argout;
};

const std::string systemd1::Unit_proxy::ActiveState() {
    DBus::CallMessage call ;
    call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
    DBus::MessageIter wi = call.writer();
    const std::string interface_name = "org.freedesktop.systemd1.Unit";
    const std::string property_name  = "ActiveState";
    wi << interface_name;
    wi << property_name;
    DBus::Message ret = this->invoke_method (call);
    DBus::MessageIter ri = ret.reader ();
    DBus::Variant argout;
    ri >> argout;
    return argout;
};

const std::string systemd1::Unit_proxy::SubState() {
    DBus::CallMessage call ;
    call.member("Get"); call.interface("org.freedesktop.DBus.Properties");
    DBus::MessageIter wi = call.writer();
    const std::string interface_name = "org.freedesktop.systemd1.Unit";
    const std::string property_name  = "SubState";
    wi << interface_name;
    wi << property_name;
    DBus::Message ret = this->invoke_method (call);
    DBus::MessageIter ri = ret.reader ();
    DBus::Variant argout;
    ri >> argout;
    return argout;
};

DBus::Path systemd1::Manager_proxy::GetUnit(const std::string& argin0)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    call.member("GetUnit");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

DBus::Path systemd1::Manager_proxy::GetUnitByPID(const uint32_t& argin0)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    call.member("GetUnitByPID");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

DBus::Path systemd1::Manager_proxy::LoadUnit(const std::string& argin0)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    call.member("LoadUnit");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

DBus::Path systemd1::Manager_proxy::StartUnit(const std::string& argin0, const std::string& argin1)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    wi << argin1;
    call.member("StartUnit");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

void systemd1::Manager_proxy::EnableUnitFiles(const std::vector< std::string >& argin0, const bool& argin1, const bool& argin2, bool& argout0, std::vector< DBus::Struct< std::string, std::string, std::string > >& argout1)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    wi << argin1;
    wi << argin2;
    call.member("EnableUnitFiles");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    ri >> argout0;
    ri >> argout1;
}

void systemd1::Manager_proxy::DisableUnitFiles(const std::vector< std::string >& argin0, const bool& argin1, std::vector< DBus::Struct< std::string, std::string, std::string > >& argout0)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    wi << argin1;
    call.member("DisableUnitFiles");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    ri >> argout0;
}

DBus::Path systemd1::Manager_proxy::StopUnit(const std::string& argin0, const std::string& argin1)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    wi << argin1;
    call.member("StopUnit");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

DBus::Path systemd1::Manager_proxy::ReloadUnit(const std::string& argin0, const std::string& argin1)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    wi << argin1;
    call.member("ReloadUnit");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

DBus::Path systemd1::Manager_proxy::RestartUnit(const std::string& argin0, const std::string& argin1)
{
    DBus::CallMessage call;
    DBus::MessageIter wi = call.writer();

    wi << argin0;
    wi << argin1;
    call.member("RestartUnit");
    DBus::Message ret = invoke_method (call);
    DBus::MessageIter ri = ret.reader();

    DBus::Path argout;
    ri >> argout;
    return argout;
}

void systemd1::Manager_proxy::Reload()
{
    DBus::CallMessage call;
    call.member("Reload");
    DBus::Message ret = invoke_method (call);
}

DBus::Connection systemd::login_manager::SetDispatcher(DBus::BusDispatcher &dispatcher)
{
    DBus::default_dispatcher = &dispatcher;
    return DBus::Connection::SystemBus();
}


void systemd::login_manager::PowerOff()
{
    logind.PowerOff(false);
}

void systemd::login_manager::Reboot()
{
    logind.Reboot(false);
}

DBus::Connection systemd::manager::SetDispatcher(DBus::BusDispatcher &dispatcher)
{
    DBus::default_dispatcher = &dispatcher;
    return DBus::Connection::SystemBus();
}

systemd::unit systemd::manager::GetUnit(const std::string &service_name)
{
    return unit(con, systemd.GetUnit(service_name).c_str(), name);
}

systemd::unit systemd::manager::LoadUnit(const std::string &service_name)
{
    return unit(con, systemd.LoadUnit(service_name).c_str(), name);
}

bool systemd::manager::StartUnit(const std::string &service_name, const std::string &mode)
{
    if(systemd.StartUnit(service_name, mode).size() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool systemd::manager::StopUnit(const std::string &service_name, const std::string &mode)
{
    if(systemd.StopUnit(service_name, mode).size() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool systemd::manager::RestartUnit(const std::string &service_name, const std::string &mode)
{
    if(systemd.RestartUnit(service_name, mode).size() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool systemd::manager::ReloadUnit(const std::string &service_name, const std::string &mode)
{
    if(systemd.ReloadUnit(service_name, mode).size() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool systemd::manager::EnableUnit(const std::string &service_name)
{
    std::vector<std::string> services{service_name};
    bool retval;
    std::vector< DBus::Struct< std::string, std::string, std::string > > retvector;

    systemd.EnableUnitFiles(services, false, false, retval, retvector);

    return retval;
}

bool systemd::manager::DisableUnit(const std::string &service_name)
{
    std::vector<std::string> services{service_name};

    std::vector< DBus::Struct< std::string, std::string, std::string > > retvector;

    systemd.DisableUnitFiles(services, false, retvector);

    if(retvector.size() != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void systemd::manager::DaemonReload()
{
    systemd.Reload();
}
