#include <iostream>
#include "systemd.hxx"

int main()
{
    systemd::manager system;
    systemd::unit crond = system.GetUnit("sshd.service");
    std::cout << crond.ActiveState() << std::endl;

    if(system.DisableUnit("crond.service"))
    {
        std::cout << "disabled crond" << std::endl;
    }

}
