# KBBI Qt is KBBI Qt is a GUI based C++/Qt Framework program for The Big Indonesian Language Dictionary.
# Copyright (C) 2016 KBBI Qt Team <https://github.com/bgli/kbbi-qt>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# This file is a part of KBBI Qt source code. 
# This file is written by Sucipto <admin@sucipto.net> and Rania el-Amina <reaamina@gmail.com>.
# 
#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T00:03:13
#
#-------------------------------------------------

QT       += core gui sql network webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KBBI-Qt
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/tentang.cpp \
    src/puebi.cpp

HEADERS  += src/mainwindow.h \
    src/tentang.h \
    src/puebi.h

FORMS    += src/mainwindow.ui \
    src/tentang.ui \
    src/puebi.ui

RESOURCES += \
    src/resource.qrc

# hanya dicoba di output 32bit
win32 {
    RC_FILE += src/kbbi-qt.rc
    DB_FILE = KBBI.db
    PWD_SOURCE = $${PWD}
    PWD_SOURCE ~= s,/,\\,g
    PWD_DEST = $${OUT_PWD}
    PWD_DEST ~= s,/,\\,g

    CONFIG(release, debug|release) {
        QMAKE_POST_LINK += $$quote(${COPY} $${PWD_SOURCE}\\src\\data\\$${DB_FILE} $${PWD_DEST}\\release\\)
#        QMAKE_CLEAN += $$quote(release\\$${DB_FILE})
    }

    CONFIG(debug, debug|release) {
        QMAKE_POST_LINK += $$quote(${COPY} $${PWD_SOURCE}\\src\\data\\$${DB_FILE} $${PWD_DEST}\\debug\\)
#        QMAKE_CLEAN += $$quote(debug\\$${DB_FILE})
    }

}

unix {
	INSTALLBASE = /usr
	target.path = $$INSTALLBASE/bin
	dbtarget.path = $$INSTALLBASE/share/$$TARGET/data
	dbtarget.files = src/data/KBBI.db
	icons.path = $$INSTALLBASE/share/pixmaps
	icons.files = src/KBBI-qt.png
        docs.path = $$INSTALLBASE/share/doc/$$TARGET/
        docs.files += AUTHORS LICENSE README.md
        manuals.path = $$INSTALLBASE/share/doc/$$TARGET/manual/
        manuals.files += doc/dokumentasi.md
        manuals_img.path = $$INSTALLBASE/share/doc/$$TARGET/manual/gbr
        manuals_img.files += doc/gbr/*
	desktop.path = $$INSTALLBASE/share/applications/
	desktop.files = KBBI-Qt.desktop
	INSTALLS += target  dbtarget icons docs manuals manuals_img desktop
}

DISTFILES += \
    src/data/uB5I0d8t/excanvas-compiled.js \
    src/data/uB5I0d8t/uB5I0d8t.js \
    src/data/uB5I0d8t/Times_New_Roman_Type1_29.otf \
    src/data/uB5I0d8t/Arial_Type0_23.otf \
    src/data/uB5I0d8t/Arial_Type0_24.otf \
    src/data/uB5I0d8t/Arial_Unicode_MS_TrueType_8.ttf \
    src/data/uB5I0d8t/Arial_Unicode_MS_Type0_17.otf \
    src/data/uB5I0d8t/Bookman_Old_Style_TrueType_1.ttf \
    src/data/uB5I0d8t/Bookman_Old_Style_TrueType_13.ttf \
    src/data/uB5I0d8t/Bookman_Old_Style_TrueType_2.ttf \
    src/data/uB5I0d8t/Bookman_Old_Style_TrueType_3.ttf \
    src/data/uB5I0d8t/Bookman_Old_Style_Type0_22.otf \
    src/data/uB5I0d8t/Bookman_Old_Style_Type0_28.otf \
    src/data/uB5I0d8t/Bookman_Old_Style_Type0_4.otf \
    src/data/uB5I0d8t/Calibri_TrueType_15.ttf \
    src/data/uB5I0d8t/Calibri_TrueType_5.ttf \
    src/data/uB5I0d8t/Calibri_TrueType_7.ttf \
    src/data/uB5I0d8t/Calibri_Type0_16.otf \
    src/data/uB5I0d8t/Cambria_Math_Type0_18.otf \
    src/data/uB5I0d8t/Courier_New_Type0_19.otf \
    src/data/uB5I0d8t/Palatino_Linotype_TrueType_0.ttf \
    src/data/uB5I0d8t/Palatino_Linotype_TrueType_30.ttf \
    src/data/uB5I0d8t/Palatino_Linotype_TrueType_6.ttf \
    src/data/uB5I0d8t/Simplified_Arabic_Fixed_TrueType_27.ttf \
    src/data/uB5I0d8t/Simplified_Arabic_Fixed_Type0_26.otf \
    src/data/uB5I0d8t/Symbol_Type0_14.otf \
    src/data/uB5I0d8t/Times_New_Roman_TrueType_10.ttf \
    src/data/uB5I0d8t/Times_New_Roman_TrueType_12.ttf \
    src/data/uB5I0d8t/Times_New_Roman_TrueType_9.ttf \
    src/data/uB5I0d8t/Times_New_Roman_Type0_11.otf \
    src/data/uB5I0d8t/Times_New_Roman_Type0_20.otf \
    src/data/uB5I0d8t/Times_New_Roman_Type0_21.otf \
    src/data/uB5I0d8t/Times_New_Roman_Type0_25.otf \
    src/data/uB5I0d8t/02c1f2551b6290538b47738725538c6b.png \
    src/data/uB5I0d8t/0436767ac91ff22b49cde30b7712241b.png \
    src/data/uB5I0d8t/05299aaf541bfdb9a9ceaa52de613738.png \
    src/data/uB5I0d8t/05fcc3643baa6f13d63ee9d13a60bf63.png \
    src/data/uB5I0d8t/06afc499ef5a1eb6f225d8c66fdabd26.png \
    src/data/uB5I0d8t/0767ed9a6ee4e4ad8836d38f2246b47d.png \
    src/data/uB5I0d8t/0907c7824d88389b6dbccc62a2609020.png \
    src/data/uB5I0d8t/0a704abd551070a75fca6d150e06d4b9.png \
    src/data/uB5I0d8t/0ce292727380be5eeb23578f588ee0d9.png \
    src/data/uB5I0d8t/0f0da56a31a7e52a8c04114dcfc525db.png \
    src/data/uB5I0d8t/10bfbbe3ffa4e92ddf585a03f59839cf.png \
    src/data/uB5I0d8t/1249bbc55d7029f76ece27122670b11a.png \
    src/data/uB5I0d8t/12d71723c5f616ab4cf23e31f9d95f12.png \
    src/data/uB5I0d8t/12dac98ee15d5ff53e9d2728633dd310.png \
    src/data/uB5I0d8t/136b7446327657bec358b67b5f107ed6.png \
    src/data/uB5I0d8t/15a103da72b5b73dea8946729410c89e.png \
    src/data/uB5I0d8t/1629257247a15bbc0fc0593ada830e53.png \
    src/data/uB5I0d8t/16945781561f1c8b4e05246791d05539.png \
    src/data/uB5I0d8t/16af7aa36a0743d4da4200b0f95698f4.png \
    src/data/uB5I0d8t/18b8f6c12f28a7f41296152f293e6690.png \
    src/data/uB5I0d8t/1a787191d4085b3645b6cdb9b3fd2bee.png \
    src/data/uB5I0d8t/1bbb91800ef88fb814fa38d23633e143.png \
    src/data/uB5I0d8t/1c9f7511cbe81d12a3a83cba162e682a.png \
    src/data/uB5I0d8t/1cf8ede16b1404dbd4efc7552a7b0872.png \
    src/data/uB5I0d8t/1d18edcbb5ffc543ea684fc867828474.png \
    src/data/uB5I0d8t/1d9c4f50ae4f94c378b50a73ff85e16f.png \
    src/data/uB5I0d8t/1e88f8d6e22a50811f61f3edefad7653.png \
    src/data/uB5I0d8t/22c34522d1a4805e9ac502c550383d91.png \
    src/data/uB5I0d8t/27bc634a64f63f44f116ae6007db6855.png \
    src/data/uB5I0d8t/2988b31381a528ca0a21a3a1000a53f8.png \
    src/data/uB5I0d8t/29a63fe00cb9368d555a6bba96ae6ee4.png \
    src/data/uB5I0d8t/2a87b694138693ac694b8508e2ea91ac.png \
    src/data/uB5I0d8t/2b50195a684f76b013d552c4cc5eb726.png \
    src/data/uB5I0d8t/2b78236cf49016dc7f9182b5dae3383a.png \
    src/data/uB5I0d8t/2d1f51e0b4a42e0a209761c4bae205a3.png \
    src/data/uB5I0d8t/2d6d5d32de12c5ac5202dc03859f9ce5.png \
    src/data/uB5I0d8t/32a4aca67e422c50b36a1112255a1d98.png \
    src/data/uB5I0d8t/32b54d00f41689ff6cd1274062619b7e.png \
    src/data/uB5I0d8t/332563c6510778c2f7e14129348bae94.png \
    src/data/uB5I0d8t/33b4f1a0992b40ad56c744a26f633ebc.png \
    src/data/uB5I0d8t/34e2455c49a75a898e259e28006c1867.png \
    src/data/uB5I0d8t/353ec90977b8eced9ac79bbd3bc98aef.png \
    src/data/uB5I0d8t/374aa04a0d5f109e4979423dc6f57b12.png \
    src/data/uB5I0d8t/39669827c860ef742282796cee0c10d0.png \
    src/data/uB5I0d8t/3afce3e3279d0bb24b7944c6ec3da794.png \
    src/data/uB5I0d8t/3cf235c667970d1c90dc10acfe6bd94d.png \
    src/data/uB5I0d8t/3d465d56c66f6317464d472c00b2d598.png \
    src/data/uB5I0d8t/3df4d8326c1d0c14e59ae34be7bd74b5.png \
    src/data/uB5I0d8t/3ea711a885b684d68d163fa8710c788f.png \
    src/data/uB5I0d8t/3f41772319a5b9b895c39dc286c8d4da.png \
    src/data/uB5I0d8t/3f825b8765a450da24bd8350c271a655.png \
    src/data/uB5I0d8t/3fc79ada01f52fcbdca69756885f6eb3.png \
    src/data/uB5I0d8t/403c37820d1e01d296897cf9811fee49.png \
    src/data/uB5I0d8t/407c68a98fe0cf0082f0e9e41fbfcfc1.png \
    src/data/uB5I0d8t/4082a86e894e4f499d007984610000e9.png \
    src/data/uB5I0d8t/41a0da3b5a29e53c8da15a2965b8f8d4.png \
    src/data/uB5I0d8t/426a84e11c4dba7ba5d538ad9ee73d27.png \
    src/data/uB5I0d8t/435c4c58854097d211219fb3b2722e56.png \
    src/data/uB5I0d8t/455f4441305769390f7feb70ff8ff1f6.png \
    src/data/uB5I0d8t/45aa638822a64d9c9dbccc43d5d21b21.png \
    src/data/uB5I0d8t/45fcfa0577e0c3d2ee7a37e28bb47fa6.png \
    src/data/uB5I0d8t/4667fa1c8c5ea93505ff7cd534b1ad6d.png \
    src/data/uB5I0d8t/4b3fd2532c767055b030642a5419e48b.png \
    src/data/uB5I0d8t/4b41db8331ffffd71739163f18858052.png \
    src/data/uB5I0d8t/4de060dc52c11710df51829353eae142.png \
    src/data/uB5I0d8t/50364b3fa879481511e878ab1d3ad1eb.png \
    src/data/uB5I0d8t/537870fd6cf9a133b9a5adeff0d8eeb1.png \
    src/data/uB5I0d8t/542c02ebcee196d9bf4771bccee04276.png \
    src/data/uB5I0d8t/55279565095b2f6099122ff1bbc449cc.png \
    src/data/uB5I0d8t/5a69b7decc10ee7e1ca545f1af9a586c.png \
    src/data/uB5I0d8t/5c1d08845bd20e6fcb0d9300cc267233.png \
    src/data/uB5I0d8t/5c63ca26cb471c560178b5a8d5fa0a79.png \
    src/data/uB5I0d8t/5d7862adf928505b883baaba877a19a4.png \
    src/data/uB5I0d8t/5db2c4c67673c96a50e424aff6f45f5e.png \
    src/data/uB5I0d8t/5deaafccd5810f5f9a25912cd96d1930.png \
    src/data/uB5I0d8t/5e31c6531498a5addbea57b1406bd1e7.png \
    src/data/uB5I0d8t/5fbee60b5052aa442fecc2ec453acaa2.png \
    src/data/uB5I0d8t/6319f05bcd531b47553134a44d2beb8d.png \
    src/data/uB5I0d8t/63451bb46d91c84490c153ec06887ff8.png \
    src/data/uB5I0d8t/6437f15195cf8efe83f89e2e8a0a5623.png \
    src/data/uB5I0d8t/66738f013847d329e260fe9b3585cba8.png \
    src/data/uB5I0d8t/682e40dd08b617ddc1532be610f46100.png \
    src/data/uB5I0d8t/687728f3f914d6ed5985792329f2579a.png \
    src/data/uB5I0d8t/692f2a75459bc811dbd4f2559f7aa574.png \
    src/data/uB5I0d8t/69c88788849b2f3813eacc69a8c31a69.png \
    src/data/uB5I0d8t/69d2e141ff2d0930a0d6e7289899ab22.png \
    src/data/uB5I0d8t/69fdf704aa3629db88276c2b223fd0b1.png \
    src/data/uB5I0d8t/6d66de530c8a146260bf2aa9e753f5fb.png \
    src/data/uB5I0d8t/6e6db43029bc982bedafd8ef4284c8cb.png \
    src/data/uB5I0d8t/6f30fe5b483bfda736769aea0b45aee0.png \
    src/data/uB5I0d8t/6fc223cf15cd806159154c240a6a0ce7.png \
    src/data/uB5I0d8t/70f6d5fff0109a1c5bf4f172b08710bb.png \
    src/data/uB5I0d8t/7141e4cf084632d63d29a9a5779963d4.png \
    src/data/uB5I0d8t/749177c588afdfa0f6fcf7692018610b.png \
    src/data/uB5I0d8t/783bc6c1013e43ea0117c392cd9a40b6.png \
    src/data/uB5I0d8t/79156086a68e10a4ee3b19007c00a0e1.png \
    src/data/uB5I0d8t/7b3c38ff84cdbe8cc10741ceaf0f35d4.png \
    src/data/uB5I0d8t/7b480e0516290978f634d51deeacafbe.png \
    src/data/uB5I0d8t/7bcd2f32f9a7e8df2f01bc332d9a2748.png \
    src/data/uB5I0d8t/7c14ca855b5d2c215ef5947fd9645942.png \
    src/data/uB5I0d8t/7c4b50f1ce1347cfafa23409f360aedb.png \
    src/data/uB5I0d8t/7cdda9ac263f6c6a796fa4e09ffe8a95.png \
    src/data/uB5I0d8t/7cfb73e3ff1e3ff0da82fc9df84a6222.png \
    src/data/uB5I0d8t/7d8afc3c7d8af24336306ba1d828c35a.png \
    src/data/uB5I0d8t/7fc2208dcfc9dc905e611c9c3d55c69b.png \
    src/data/uB5I0d8t/82c00c1eadae4d877f019b307e21403b.png \
    src/data/uB5I0d8t/83574d20a1e5a0d8924b8436fe87656d.png \
    src/data/uB5I0d8t/83ba0953f9e17235251b4a8ec3b160aa.png \
    src/data/uB5I0d8t/887dacef264ea9931f2abbaf77de4fd5.png \
    src/data/uB5I0d8t/8c6439e3bee23aba8511bdd240d7722a.png \
    src/data/uB5I0d8t/8cff420d7fc7b7c6c3c59239dbc9803b.png \
    src/data/uB5I0d8t/911165532acbc036011154c4b7e5d246.png \
    src/data/uB5I0d8t/92a19e9e77bb6bbf5068e3eb3efe7de0.png \
    src/data/uB5I0d8t/943358e91e7142dbc5090c5e74b38a59.png \
    src/data/uB5I0d8t/9534a2ce18451fad4c72386a492ea7d7.png \
    src/data/uB5I0d8t/9840e78c851569724c0a7a7fcb456fb5.png \
    src/data/uB5I0d8t/9849f7db50e5a83c119e66e1521b6db7.png \
    src/data/uB5I0d8t/988994b464b5f13b4b17c610ed7579fc.png \
    src/data/uB5I0d8t/98e86c2f3d52b4858ae0081211429cb8.png \
    src/data/uB5I0d8t/9b033793ea0a000aa0a69965259b1ffe.png \
    src/data/uB5I0d8t/9d68fd41d9bc4e6ce1baaf2a1a4c7bea.png \
    src/data/uB5I0d8t/9e818621ad837e7fc19dc3d4147f2c29.png \
    src/data/uB5I0d8t/9f6c261fe891a92f9aa4db3cf96f4d4e.png \
    src/data/uB5I0d8t/a005d435354f7f527f2e81b04347ee00.png \
    src/data/uB5I0d8t/a11401704839b2159b2fd0cf72a9f3a5.png \
    src/data/uB5I0d8t/a1a5c5f1904ebf03f446fa01a7e33e30.png \
    src/data/uB5I0d8t/a265027dd725e0345e03ddd588670af9.png \
    src/data/uB5I0d8t/a3bc85dc7c47e7a1c0a7651eb629bea8.png \
    src/data/uB5I0d8t/a52c33d8b7cf4ea47e6e853dfb4efd09.png \
    src/data/uB5I0d8t/a662f5ba7bade52fac72e713800dc279.png \
    src/data/uB5I0d8t/a66eb82294ed82fc6d665ef3a2c4328b.png \
    src/data/uB5I0d8t/a734bccf48a41ac5dc270ca47b30fa07.png \
    src/data/uB5I0d8t/a8843b554dadbc2680fe5ff111557562.png \
    src/data/uB5I0d8t/a8a708cd5f8eb661df3dd23ea2fc9832.png \
    src/data/uB5I0d8t/a96f1fab351c7e478a107f844beddd7b.png \
    src/data/uB5I0d8t/a98a07dfc4593f59f8e2d5755cbcf360.png \
    src/data/uB5I0d8t/a9e08d53a071db0d3fb811fddce3f807.png \
    src/data/uB5I0d8t/aa495e3b4d3d49815a67134d6eabc0ef.png \
    src/data/uB5I0d8t/ab1e0d4342fbe09b0a74907e49fd7927.png \
    src/data/uB5I0d8t/ad7b47fbc59f22f53aea6bcb853f89c9.png \
    src/data/uB5I0d8t/af5e0ed457667e740c975b91605b7c64.png \
    src/data/uB5I0d8t/b07eda17442af66fa77bb93f8445bd83.png \
    src/data/uB5I0d8t/b0b3b2c1276191d8000fcc788935d0b3.png \
    src/data/uB5I0d8t/b244d14b3f8ee93209b680dfbf58cb74.png \
    src/data/uB5I0d8t/b267c4dddb925b5aa5e51181660b88c1.png \
    src/data/uB5I0d8t/b3dd3b45851b7bbef1e037302fe55fad.png \
    src/data/uB5I0d8t/b602142caa4a9f253348a9c9e009a44b.png \
    src/data/uB5I0d8t/b7f7d4054779fbf1c7a8219bf43ab892.png \
    src/data/uB5I0d8t/ba109bb8f71407a9f9dcadcc71c0d554.png \
    src/data/uB5I0d8t/bad46d52f4a81e5244a59dd179eedcc7.png \
    src/data/uB5I0d8t/be7120bde2661fabdaa2286b4af7cfbb.png \
    src/data/uB5I0d8t/be79d68701edd8dd7efd5c9fc328a2b0.png \
    src/data/uB5I0d8t/c185f633c574f0f6bd17621cd1a586b2.png \
    src/data/uB5I0d8t/c20f0232c50820595b9f229556119ba4.png \
    src/data/uB5I0d8t/c29276475df5f6cd717a71279f291804.png \
    src/data/uB5I0d8t/c4c4c5fc09b846d64e7b4d856cb47520.png \
    src/data/uB5I0d8t/c4e296aa1e06969723a914ffe079233d.png \
    src/data/uB5I0d8t/c6cacd692a9dd5f03484568c6fec8d39.png \
    src/data/uB5I0d8t/ce50ec55d4eecc5a9e3e4e6e70819cf0.png \
    src/data/uB5I0d8t/ce6dcbb65ebc3056daf7d7d277318d4b.png \
    src/data/uB5I0d8t/ced91502e8d1c630a328ad226e501961.png \
    src/data/uB5I0d8t/d009adccf7be033a2eabb1fd8365494c.png \
    src/data/uB5I0d8t/d0a3039774d450c9ee91d1e9d7ad3541.png \
    src/data/uB5I0d8t/d110199229a1c2ec38d5b82ad6f8d92b.png \
    src/data/uB5I0d8t/d180b2dd80d809625a7f3dc61160c97d.png \
    src/data/uB5I0d8t/d426311e7da3766d344cf5eb454a5076.png \
    src/data/uB5I0d8t/d5d173f03b233d0d146cd743161155e8.png \
    src/data/uB5I0d8t/d656ae59612b1fba98f1a524c0d5e5a4.png \
    src/data/uB5I0d8t/d65e8b808f319d0132ccaa69f4477a3c.png \
    src/data/uB5I0d8t/d7c3a811cb7521e87f8d04bb7914c797.png \
    src/data/uB5I0d8t/d83b770c0795bccac9836d635579e439.png \
    src/data/uB5I0d8t/d91f198fe83460b4e49715e783151a56.png \
    src/data/uB5I0d8t/daaae3701ba2bc84e1a62840381b27a8.png \
    src/data/uB5I0d8t/db732199b1984017e446feca73bc4f5a.png \
    src/data/uB5I0d8t/ddd8a21c7997e8c2c5ce10f68b7275a7.png \
    src/data/uB5I0d8t/e023b6a166b7577f4c22a3393ae9af19.png \
    src/data/uB5I0d8t/e260a712b9b380f9237444208f0b9b88.png \
    src/data/uB5I0d8t/e289362d6baf3f9765af6065c238d674.png \
    src/data/uB5I0d8t/e4824d92ff3a70379f8aaaa4ab5fd50d.png \
    src/data/uB5I0d8t/e6a7280960cf8a06fe6fa4c6c5b214c5.png \
    src/data/uB5I0d8t/e72eb20a0f0a8b342ed624d95a59eeb2.png \
    src/data/uB5I0d8t/e7ccca2df4e08840e2251de8ccc0832b.png \
    src/data/uB5I0d8t/e849565698add600b4d9382ae809c455.png \
    src/data/uB5I0d8t/e86abbf77c7857e51b3a7f053d0edae2.png \
    src/data/uB5I0d8t/e88a74f231ffbeabc6009d0b840ab281.png \
    src/data/uB5I0d8t/e98ee1ae687e6d5b7730e5e53eb0aa74.png \
    src/data/uB5I0d8t/e9b6e9155bc403230746008b4ce1762a.png \
    src/data/uB5I0d8t/eeeab1e12ef5f291dc23a0915ee967ae.png \
    src/data/uB5I0d8t/f043630fbf4b0c4d5cd9f36116b006b1.png \
    src/data/uB5I0d8t/f10a397b64f89e74d7593a865057a80b.png \
    src/data/uB5I0d8t/f1ef2bcb557d6b2862687f60646ac2d3.png \
    src/data/uB5I0d8t/f20710ed166535cdeb228e1ea3766e83.png \
    src/data/uB5I0d8t/f5e2f2728c259b991381428a0a534bf8.png \
    src/data/uB5I0d8t/f712a3aa28abf5251b47754b5891bbe6.png \
    src/data/uB5I0d8t/f79c837d65500b221ca9428b135d5e1e.png \
    src/data/uB5I0d8t/f83906156bcf5cfb2e5153e9caebfd01.png \
    src/data/uB5I0d8t/faed66cfdfe5abaee6b1f065ce2f9c29.png \
    src/data/uB5I0d8t/uB5I0d8t.css \
    src/data/puebi.html


