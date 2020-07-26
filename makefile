CUR_DIR := $(shell pwd)
PY_EXE := $(shell which python3)
LAUNCHER := ${CUR_DIR}/bin/pas
MAIN := ${CUR_DIR}/UIControl/main.py
FRONTEND := $(shell pwd)/UIControl
BACKEND := $(shell pwd)/pasLib

run: setup
	${LAUNCHER}

setup: frontend backend
	-mkdir -p ${CUR_DIR}/bin
	@echo "export PAS_BASE=${CUR_DIR}" > ${LAUNCHER}
	@echo "${PY_EXE} ${MAIN}" >> ${LAUNCHER}
	chmod +x ${LAUNCHER}

backend:
	${MAKE} -C ${BACKEND} -f makefile.backend

frontend:
	${MAKE} -C ${FRONTEND} -f makefile.frontend
