inherit ROOM;

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
�����ǹ�������ͷ�����˺���������Ͻ������������ｻ�㣬�Ǵ�
ֻת���ĵص㣬������ж�������������������������ϴ������ת�˴���	
LONG );

	set("exits", ([
               "southeast"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



