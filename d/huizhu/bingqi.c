// Room: /d/huijiang/bingqi.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@LONG
�����Ǻ컨��ı����⣬һ�����ı����ѵú��ˡ�����Ŵν�����
������սƵ�ԣ�����ܶ���������������������ԭ�鷳��������ġ�
LONG );
        set("objects", ([
		"/clone/weapon/gangjian"     : random(2)+1,
		"/clone/weapon/gangzhang"     : random(2)+1,
		"/clone/weapon/gangdao" : random(2)+1,
		__DIR__"obj/feidao"     : random(2)+1,
        ]));
	set("exits", ([
		"west" : __DIR__"wuchang",
	]));
	set("coor/x", -50030);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}