
REM https://multipass.run/

multipass launch -n ubuntu-cpp
multipass mount "%~dp0..\.." ubuntu-cpp:/mnt/repo_sources
multipass exec ubuntu-cpp -- mkdir -p /home/ubuntu/DEV
multipass exec ubuntu-cpp -- cp /mnt/repo_sources/scripts/multipass/provision-software.sh /home/ubuntu/DEV/provision-software.sh
multipass exec ubuntu-cpp -- chmod 700 /home/ubuntu/DEV/provision-software.sh
multipass exec ubuntu-cpp -- sudo apt install -y dos2unix
multipass exec ubuntu-cpp -- dos2unix /home/ubuntu/DEV/provision-software.sh
multipass exec ubuntu-cpp -- /home/ubuntu/DEV/provision-software.sh
multipass info ubuntu-cpp

REM log in via shh (password=ubuntu-cpp): ssh ubuntu@<ip>
REM or: multipass shell ubuntu-cpp
