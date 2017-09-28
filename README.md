ReOS
====

A new phone with new OS
-----------------------

I always dreamed about to make my own phone. No like just buying one and modifying, building almost from scratch. And some people had the idea: make a DIY phone! This is RePhone.
https://www.seeedstudio.com/RePhone-Kit-Create-p-2552.html

Sadly the stock OS has a lot of bugs and well, but buying the kit and flashing the stock OS is nothing like writing your very own OS!

The kit comes with a handy RTOS and a lot of libs: http://labs.mediatek.com/api/linkit-assist-2502/frames.html?frmname=topic&frmfile=vm_dcl_gpio_control_level_status_t.html

So, the goal?
-------------

Make a phone. Oh, almost forgot: native C++. Not LUA, not C, not Arduino. Hopefully it can be squeezed in a watch case. (and finally talk to KITT)

Call, SMS first and all things needed: phonebook, manager classes, GUI framework optimized for touch, MP3 ringtone, hardcoded.

Settings menu and add dynamic behavior, read-write configs from config files.

It has GPRS capabilities so maybe reading your mails? (Good luck on 1.5") But syncing would be good. Maybe syncing calendar.

And Bluetooth, but no idea how to use it correctly - you won't connect a headset to it.