// /kaifeng/tonanyang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������ӿ��⸮�����ݵĹٵ�����������·�ΰ��Ϻ�
����Ҳ���١�����ͨ�򿪷⣬����ͨ�����ݡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"tokaifeng",
		"east" : "/d/ruzhou/ximen",
	]));
	set("outdoors", "kaifeng");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
