#include <iostream>
#include "systemd.hxx"

int main()
{
    systemd::manager system;
    systemd::unit crond = system.GetUnit("crond.service");
    std::cout << crond.ActiveState() << std::endl;
}
