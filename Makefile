all:: onigmo posix

onigmo::
	(cd onigmo && make)

posix::
	(cd posix && make)

pcre::
	(cd pcre && make)
