# systemD++

## W.I.P.

A header only simplification of the systemD's dbus api for c++ developers.
based on dbuscplusplus for dbus action.
RAII is used for simplification of the startup process and to give it a more oops feel.

to compile dbuscxx package needs to be present and linking to dbus-c++-1, dbus-1 is required.

NOTE: sometimes the changes are not reflected by the systemd daemon(eg for enable and disable) it has occured successfully
but to check reload the daemon using systemd-daemon-reload or by using the reload function).

NOTE2: reboot and poweroff are performed by logind now, Its the correct way as it performs graceful shutdown rather than just instaniously shuttingdown.
