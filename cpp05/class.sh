#! /bin/sh

# CPP --------------------------------------------------------------------------
cpp() {
	# VARIABLES ----------------------------------------------------------------
	local CLASS=$1
	local UPPERCASE=$(echo $CLASS | tr a-z A-Z)

	# CLASS DEFINITION ---------------------------------------------------------
	cat <<EOF >${CLASS}.cpp
#include "${CLASS}.hpp"
#include <iostream>

${CLASS}::${CLASS}(void) {
	//std::cout << "${CLASS} default constructor called" << std::endl;
}

${CLASS}::${CLASS}(${CLASS} const &src) {
	//std::cout << "${CLASS} copy constructor called" << std::endl;
	*this = src;
	return;
}

${CLASS}::~${CLASS}(void) {
	//std::cout << "${CLASS} destructor called" << std::endl;
	return;
}

${CLASS} &${CLASS}::operator=(${CLASS} const &rhs) {
	//std::cout << "${CLASS} copy constructor called" << std::endl;
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

EOF
}

# HPP --------------------------------------------------------------------------
hpp() {
	# VARIABLES ----------------------------------------------------------------
	local CLASS=$1
	local UPPERCASE=$(echo $CLASS | tr a-z A-Z)

	# COLORS -------------------------------------------------------------------
	cat <<EOF >${CLASS}.hpp
EOF

	# CLASS DECLARATION --------------------------------------------------------
	cat <<EOF >>${CLASS}.hpp
#ifndef ${UPPERCASE}_HPP
# define ${UPPERCASE}_HPP

class ${CLASS} {
	public:
		${CLASS}(void);
		${CLASS}(${CLASS} const &src);
		${CLASS} &operator=(${CLASS} const &rhs);
		~${CLASS}(void);
};

#endif
EOF
}

# MAIN -------------------------------------------------------------------------
main() {
	for CLASS in "$@"; do
		cpp $CLASS
		hpp $CLASS
	done
}

main "$@"
