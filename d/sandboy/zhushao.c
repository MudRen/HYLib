// Room: /d/sandboy/zhushao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�㱻������һ�������ϣ�������һ�ѿ��õ����ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/sandboy");

	setup();
	replace_program(ROOM);
}
