// Room: /jyguan/longwangmiao.c
// Shark 10/08/1998

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����İ���Ϊ���������콵������������Ҳ��ˮ��Ȫӿ���������ݽߣ����޽�
������������������������ˡ�
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);
	set("objects", ([
		"/d/city/obj/box" : 1,
	]));
	
	set("exits", ([
		"north" : __DIR__"townroad1",
	]));

	setup();
	replace_program(ROOM);
}

