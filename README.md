Budgie CpuPower Applet
-----------------------

Monitor and manage your Intel CPU PStates from Budgie panel (via intel_pstate kernel module).

The UI design was heavily inspired by the great [Gnome Shell extension equivalent](https://github.com/martin31821/cpupower) (kudos to martin31821).

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