// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������
������ҴҶ��������������һЩС��̯���ƺ���һ�����С�
����������ݳ��ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"beimen",
		"southwest" : __DIR__"huqiu",
		//"north" : "/d/guiyun/shanlu2",
	"north" : "/d/wuxi/road4",
	]));
	setup();
	replace_program(ROOM);
}

