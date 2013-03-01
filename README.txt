## onigmo

cd onigmo
git clone https://github.com/k-takata/Onigmo src
cd src
./configure --prefix=`pwd`/../prefix
make
make install


## posix
(use libc)


## pcre

cd pcre
svn co svn://vcs.exim.org/pcre/code/trunk src
cd src
./configure --prefix=`pwd`/../prefix
make
make install
