TEMPLATE = subdirs

CONFIG += debug_and_release
#QMAKE_MAC_SDK = macosx10.12

SUBDIRS += \
    KFVerifier \
    RUC1 \
	libiconv \
	libxml2 \
	ATCore \
	ATProject \
	ATLinker \
	ATGUI \
	EDFDEditor \
	UCore \
	EDFDCover \
	ATPlanner \
	DSFEditor \
	ATTextEditor \
	KBEditor \
        ATVerifier \
	KMPZ \
	ATWorkbench \
        KnowledgeField \
        DataMining \
        Merger \
        Protocols \
        Tests/EDFDCoverTest

SOURCES += \
    ../../src/plugins/KMPZ/forms/common/setup_script.cpp

