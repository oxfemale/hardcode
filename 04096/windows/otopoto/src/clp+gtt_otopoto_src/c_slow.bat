crinkler.exe /OUT:release\4k_euskal09.exe /TRUNCATEFLOATS /PRINT:LABELS /ORDERTRIES:10000 /REPORT:reports\compressReportSlow.html /UNSAFEIMPORT /TRANSFORM:CALLS /HASHTRIES:1000 /COMPMODE:SLOW /SUBSYSTEM:WINDOWS /RANGE:opengl32 /RANGE:glu32 lib\dsound.lib lib\msvcrt.lib kernel32.lib user32.lib gdi32.lib opengl32.lib glu32.lib release\mainWin32.obj release\synth.obj release\intro.obj release\play.obj release\thesong.obj