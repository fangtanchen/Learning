#!/bin/bash
# ubuntu 16.10 configure

#update the mirrors and softwares
sudo  apt-get -y update
sudo  apt-get -y upgrade
               
sudo  apt-get -y install git
sudo  apt-get -y install git-core
sudo  apt-get -y install octave

# spf-13
sudo apt-get -y  install vim
sudo apt-get -y install curl
sudo curl https://j.mp/spf13-vim3 -L > spf13-vim.sh && sh spf13-vim.sh

# configure python environment
sudo apt-get -y install python2.7 python2.7-dev python3.2 python3.2-dev
# 安装 pip
sudo apt-get -y install python-pip
# 安装 virtualenv
sudo pip install virtualenv



# configure undistract-me
sudo apt-get install undistract-me
echo >> ~/.bashrc
echo >> ~/.bashrc
echo >> ~/.bashrc
echo "#configure undistract-me" >> ~/.bashrc
echo ". /usr/share/undistract-me/long-running.bash" >>~/.bashrc 
echo "notify_when_long_running_commands_finish_install" >> ~/.bashrc
echo >> ~/.bashrc
echo >> ~/.bashrc
echo >> ~/.bashrc


