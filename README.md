# KBBI Qt

[![Build Status](https://travis-ci.org/bgli/kbbi-qt.svg?branch=master)](https://travis-ci.org/bgli/kbbi-qt)
[![Copr](https://copr.fedorainfracloud.org/coprs/alunux/kbbi-qt-git/package/KBBI-Qt/status_image/last_build.png)](https://copr.fedorainfracloud.org/coprs/alunux/kbbi-qt-git/)

KBBI Qt adalah aplikasi Kamus Besar Bahasa Indonesia berbasis _Graphical User Interface_ (GUI) yang dikembangkan menggunakan bahasa pemrograman C++ dan _Framework_ Qt. KBBI Qt memiliki antarmuka grafis yang dapat digunakan dengan mudah di desktop GNU/Linux. KBBI Qt merupakan perangkat lunak bebas _(free software)_ berlisensi GNU GPL v3.0. Saat ini KBBI Qt siap untuk dipasang pada distribusi GNU/Linux Fedora 23/24/25/Rawhide, CentOS 7/RHEL 7, Debian dan distro-distro turunan Debian serta sistem operasi Windows.

![Screenshot](screenshot.png)

# Ikut Terlibat
Kami sangat terbuka apabila Anda ingin bergabung dan terlibat dalam proyek ini. Segala bentuk kontribusi Anda akan sangat membantu kami dalam mengembangkan aplikasi ini.

Kontribusi dapat berupa penanganan/perbaikan _Bug (code)_, _Improvement (code)_, Dokumentasi, Publikasi, Pemaketan, dan lain sebagainya.

# Install

**[Centos/RHEL 7]**  

``` sh
$ sudo wget https://copr.fedorainfracloud.org/coprs/alunux/kbbi-qt-git/repo/epel-7/alunux-kbbi-qt-git-epel-7.repo -O /etc/yum.repos.d/kbbi-qt.repo
$ sudo yum install KBBI-Qt
```

**[Fedora 23/24/25/Rawhide]**  

``` sh
$ sudo dnf copr enable alunux/kbbi-qt-git
$ sudo dnf install KBBI-Qt
```

**[Debian dan Distro Turunan Debian]**  
Untuk 32-bit:
``` sh
$ wget https://github.com/bgli/kbbi-qt/releases/download/v1.0/kbbi-qt_1.0-1_i386.deb
$ sudo dpkg -i kbbi-qt_1.0-1_i386.deb
```

Untuk 64-bit:
``` sh
 $ wget https://github.com/bgli/kbbi-qt/releases/download/v1.0/kbbi-qt_1.0-1_amd64.deb
 $ sudo dpkg -i kbbi-qt_1.0-1_amd64.deb
 ```

**[BlankOn Linux]**
``` sh
$ sudo apt install kbbi-qt
```

**[Arch Linux]**
```sh
    $ yaourt -S kbbi-qt
```
atau
```sh
    $ git clone https://aur.archlinux.org/kbbi-qt.git
    $ cd kbbi-qt
    $ makepkg -si
```

**[Slackware dan Distro Turunannya]**
```sh
    $ git clone https://github.com/sasongko26/kbbi-qt-slackbuild.git
    $ cd kbbi-qt-slackbuild
    # chmod +x kbbi-qt.SlackBuild
    # ./kbbi-qt.SlackBuild
    # installpkg /tmp/kbbi-qt*.tgz
```

**[Pemasangan Melalui Source Code]** 
Untuk melakukan kompilasi, pastikan sistem operasi Anda sudah memiliki **GCC dengan dukungan C++**, **Qt5**, dan **qmake (qtchooser)**.
``` sh
$ git clone https://github.com/bgli/kbbi-qt.git
$ cd kbbi-qt
$ qmake KBBI-Qt.pro
$ make
$ sudo make clean install
```

**[Windows]**
Unduh dari https://github.com/bgli/kbbi-qt/releases/download/v1.0/kbbi-qt_1.0-1_win32.7z. Untuk menginstalnya, cukup ekstrak berkas **kbbi-qt\_1.0-1_win32..7z** lalu jalankan KBBI Qt dengan KBBI-Qt.exe.

# Kontribusi
Untuk berkontribusi silakan _fork_ repositori ini dan melakukan _pull request_ terhadap _branch **dev**_


# Diskusi
Silakan hubungi kami via Telegram jika Anda berminat untuk terlibat dalam pengembangan proyek KBBI Qt ini:
* [Belajar GNU/Linux Indonesia](http://s.id/BGLI)
* [SinauDev](https://telegram.me/sinaudev)

# Kontributor
* Ade Malsasa Akbar (https://github.com/malsasa)
* Anto Samalona (https://github.com/antosamalona)
* Azis Pratama (https://github.com/azispratama92)
* Billy (https://github.com/as3mbus)
* Christian Kurniawan (https://github.com/saa7go)
* Hanhan (https://github.com/hahn)
* La Ode Muh. Fadlun (https://github.com/alunux)
* Listya Adinugroho (ladinugroho@yahoo.co.id)
* Nadilah Nurtalia (nadhilahnurtalia@yahoo.co.id)
* Muhammad Irwan Andriawan (https://github.com/andriawan)
* Ramdziana Feri Yustitanto (https://github.com/rafeyu)
* Rania el-Amina (https://github.com/raniaamina)
* Rizky Tia Rifianty (rizkyciki@gmail.com)
* Sucipto (https://github.com/showcheap)
