#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}

run "nm-applet"
# run "pamac-tray"
# run "megasync"
# run "xfce4-power-manager"
# run "blueberry-tray"
# run "/usr/lib/xfce4/notifyd/xfce4-notifyd"
run "/usr/bin/dunst"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
picom -b  --config ~/.dwm/picom.conf &
run "volumeicon"
run sxhkd -c ~/.dwm/sxhkd/sxhkdrc &
run kbar &
~/.screenlayout/layout.sh
# Launch KRT - Pomodoro
/home/jicg/Personal/KrtPomodoro/server_start.sh &
nitrogen --restore
