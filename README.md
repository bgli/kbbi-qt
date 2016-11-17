# KBBI Qt

[![Build Status](https://travis-ci.org/bgli/kbbi-qt.svg?branch=master)](https://travis-ci.org/bgli/kbbi-qt)
[![Copr](https://copr.fedorainfracloud.org/coprs/alunux/kbbi-qt-git/package/KBBI-Qt/status_image/last_build.png)](https://copr.fedorainfracloud.org/coprs/alunux/kbbi-qt-git/)

KBBI Qt adalah aplikasi Kamus Besar Bahasa Indonesia berbasis _Graphical User Interface_ (GUI) yang dikembangkan menggunakan bahasa pemrograman C++ dan _Framework_ Qt. KBBI Qt memiliki antarmuka grafis yang dapat digunakan dengan mudah di desktop GNU/Linux. KBBI Qt merupakan perangkat lunak bebas _(free software)_ berlisensi GNU GPL v3.0. Saat ini KBBI Qt siap untuk dipasang pada distribusi GNU/Linux Fedora 23/24/25/Rawhide, CentOS 7/RHEL 7, Debian dan distro-distro turunan Debian serta sistem operasi Windows.

![Screenshot](screenshot.png ""Screenshot"")

# Ikut Terlibat
Kami sangat terbuka apabila Anda ingin bergabung dan terlibat dalam proyek ini. Segala bentuk kontribusi Anda akan sangat membantu kami dalam mengembangkan aplikasi ini.

Kontribusi dapat berupa penangan/perbaikan _Bug (code)_, _Improvement (code)_, Dokumentasi, Publikasi, Pemaketan, dan lain sebagainya.

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

``` sh
$ wget https://github.com/bgli/kbbi-qt/releases/download/v1.0-alpha/kbbi-qt_1.0.0-alpha-1_amd64.1.deb
$ sudo dpkg -i kbbi-qt_1.0.0-alpha-1_amd64.deb
```

**[Pemasangan Melalui Source Code]**  
``` sh
$ git clone https://github.com/bgli/kbbi-qt.git
$ cd kbbi-qt
$ qmake -project
$ make
```

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
* Ramdziana Feri Yustitanto (https://github.com/rafeyu)
* Rania el-Amina (https://github.com/raniaamina)
* Rizky Tia Rifianty (rizkyciki@gmail.com)
* Sucipto (https://github.com/showcheap)
