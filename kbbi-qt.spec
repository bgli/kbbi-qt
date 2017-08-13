%global _hardened_build 1
%global debug_package %{nil}
%define build_timestamp %(date +"%Y%m%d")

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

%package docs
Summary: KBBI Qt -- Berkas-berkas Dokumentasi
Group: Documentation/HTML

%description docs
KBBI Qt -- Berkas-berkas Dokumentasi
Paket ini berisi dokumentasi perkenalan dan penggunaan KBBI Qt

%prep
%autosetup -n kbbi-qt-master
cd src
for i in 256 128 64 48 32 24 16; do
    mkdir -p icons/${i}
    convert kbbi-qt.png -resize ${i}x${i} icons/${i}/kbbi-qt.png
done

%build
qmake-qt5 -makefile
make %{?_smp_mflags}

%install
install -d %{buildroot}%{_bindir}
install -d %{buildroot}%{_datadir}/applications
install -d %{buildroot}%{_datadir}/%{name}/
install -d %{buildroot}%{_datadir}/%{name}/data/
install -d %{buildroot}%{_datadir}/%{name}/data/puebi

install -m 755 %{name} %{buildroot}%{_bindir}

cd src
cp -vr data/ %{buildroot}%{_datadir}/%{name}

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
%license LICENSE
%attr(755,root,root) %{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png
%dir %{_datadir}/%{name}
%{_datadir}/%{name}/*

%files docs
%defattr(-,root,root,-)
%doc AUTHORS README.md doc/pdf/dokumentasi.pdf

%changelog
* Mon Oct 31 2016 La Ode Muh. Fadlun Akbar <fadlun.net@gmail.com> - 20161123
- Remove db_location.patch
- PUEBI support
- Add documentation package

* Mon Oct 31 2016 La Ode Muh. Fadlun Akbar <fadlun.net@gmail.com> - 20161031.git
- Create RPM SPEC for kbbi-qt
- Patch KBBI-Qt db location
- Other changelog at https://github.com/bgli/kbbi-qt/commits/master
