default:
	cd src && qmake -qt5 lde.pro && make

install:
	install -d $(DESTDIR)/usr/
	install -d $(DESTDIR)/usr/bin/
	install -d $(DESTDIR)/usr/share/
	install -d $(DESTDIR)/usr/share/applications/
	install -d $(DESTDIR)/usr/share/xsessions/
	install -d $(DESTDIR)/usr/share/wallpapers/
	install -d $(DESTDIR)/usr/share/apps/kdm/sessions/
	install usr/bin/* $(DESTDIR)/usr/bin/
	install share/*.desktop $(DESTDIR)/usr/share/applications/
	install shell/startlde $(DESTDIR)/usr/bin/
	install xsessions/LDE.desktop $(DESTDIR)/usr/share/xsessions/
	install wallpapers/lde-default.png $(DESTDIR)/usr/share/wallpapers/
	install xsessions/LDE.desktop $(DESTDIR)/usr/share/apps/kdm/sessions/
