%global _hardened_build 1
%global debug_package %{nil}
%define build_timestamp %(date +"%Y%m%d").git
%define install_dir /opt/KBBI-Qt

Summary: KBBI Qt: KBBI Qt adalah aplikasi Kamus Besar Bahasa Indonesia
Name: KBBI-Qt
Version: %{build_timestamp}
Release: 1%{?dist}
License: GPLv3
Group: Applications/Productivity
URL: https://github.com/bgli/kbbi-qt
Source0: https://github.com/bgli/kbbi-qt/archive/master.zip
BuildRequires: qt5-qtbase-devel ImageMagick
Requires: qt5-qtbase

%if 0%{?mga}
BuildRequires: locales
%endif

%description
KBBI Qt adalah aplikasi Kamus Besar Bahasa Indonesia yang dikembangkan
menggunakan bahasa pemrograman C++ dan Framework Qt

%prep
%autosetup -n kbbi-qt-master
patch -p1 < db_location.patch
cd src
for i in 256 128 64 48 32 24 16; do
    mkdir -p icons/${i}
    convert kbbi-qt.png -resize ${i}x${i} icons/${i}/kbbi-qt.png
done

%build
cd src
qmake-qt5
make %{?_smp_mflags}

%install
cd src

install -d %{buildroot}%{_bindir}
install -d %{buildroot}%{install_dir}
install -d %{buildroot}%{_datadir}/applications

install -m 755 %{name} %{buildroot}%{install_dir}
install -m 644 data/KBBI.db %{buildroot}%{install_dir}
ln -sf %{install_dir}/%{name} %{buildroot}%{_bindir}

cat >> %{name}.desktop << FOE
[Desktop Entry]
Version=0.1
Name=KBBI Qt
Comment=Aplikasi Kamus Besar Bahasa Indonesia
Exec=%{name} %u
Icon=%{name}
Terminal=false
Type=Application
Categories=Utility;
FOE

install -m 644 %{name}.desktop \
        %{buildroot}%{_datadir}/applications/%{name}.desktop

for i in 128 64 48 32 24 16; do
    install -D -m 0644 icons/${i}/kbbi-qt.png \
            %{buildroot}%{_datadir}/icons/hicolor/${i}x${i}/apps/%{name}.png
done

%post
/bin/touch --no-create %{_datadir}/icons/hicolor &>/dev/null ||:
/usr/bin/update-desktop-database &>/dev/null ||:
/usr/bin/gtk-update-icon-cache %{_datadir}/icons/hicolor &>/dev/null || :

%postun
if [ $1 -eq 0 ]; then
    /bin/touch --no-create %{_datadir}/icons/hicolor &>/dev/null ||:
    /usr/bin/gtk-update-icon-cache -f -t -q %{_datadir}/icons/hicolor ||:
fi
/usr/bin/update-desktop-database &>/dev/null ||:

%posttrans
/usr/bin/gtk-update-icon-cache -f -t -q %{_datadir}/icons/hicolor ||:

%clean
rm -rf %{buildroot} %{_builddir}/kbbi-qt-master

%files
%defattr(-,root,root,-)
%doc README.md LICENSE
%license LICENSE
%{_bindir}/%{name}
%dir %{install_dir}
%{install_dir}/*
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png

%changelog
* Mon Oct 31 2016 La Ode Muh. Fadlun Akbar <fadlun.net@gmail.com> - 20161031.git
- Create RPM SPEC for kbbi-qt
- Patch KBBI-Qt db location
- Other changelog at https://github.com/bgli/kbbi-qt/commits/master
