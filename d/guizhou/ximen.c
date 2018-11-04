inherit ROOM;

void create()
{
	set("short", "贵阳西门");
	set("long", @LONG
此间是贵阳城的西门，是为贵州重镇。城墙由石块和土垒成，高二
丈五，厚达二丈。城下三两个盔甲鲜明的军士瞪大了眼睛观察着来来往
往的行人，偶尔盘问几个形迹可疑份子。
LONG );

	set("exits", ([
                          "east"      : __DIR__"xidajie",
                         "west"      : __DIR__"tulu1",
                         "north"      : __DIR__"guanlu1",
		
	]));
set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



