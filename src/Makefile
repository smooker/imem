DEPENDENCIES := -lpthread -I../release/include/ -L ../release/build/
UNAME := $(shell uname)
# Assume target is Mac OS if build host is Mac OS; any other host targets Linux
ifeq ($(UNAME), Darwin)
	DEPENDENCIES := -lobjc -framework IOKit -framework CoreFoundation
else
	DYNAMIC_LIBS += -pthread -lrt -I../release/include/ -L ../release/build/
endif

CFLAGS = -Wall -Wextra
COMMON_FLAGS = -ffunction-sections -fmerge-all-constants 

APP = M269
#STATIC_APP = $(APP)-static
DYNAMIC_APP = $(APP)-dynamic

all: $(STATIC_APP) $(DYNAMIC_APP)

#$(STATIC_APP): main.c
#	$(CC) main.c -o $(STATIC_APP) -lmpsse $(CFLAGS) $(DEPENDENCIES)

$(DYNAMIC_APP): main.c
	$(CC) $(COMMON_FLAGS) main.c -o $(DYNAMIC_APP) -lmpsse $(CFLAGS) $(DYNAMIC_LIBS)

clean:
	-rm -f *.o $(STATIC_APP) $(DYNAMIC_APP)
