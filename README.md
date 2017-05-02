Budgie CpuPower Applet
-----------------------

Monitor and manage your Intel CPU PStates from Budgie panel (via intel_pstate kernel module).

Building from sources
----------------------
```bash
sh autogen.sh
make
sudo make install
```

Getting the applet listed on Raven Sidebar
---------------------
After installation you can either logout/login to Budgie or issue the following command
```bash
nohup budgie-panel --replace &
```

Screenshot
----------
Applet embedded in panel with popover displayed:

![alt text][applet]

[applet]: https://raw.githubusercontent.com/ImperiumMaximus/budgie-cpupower-applet/master/screenshots/applet.png