// Room: mochi.c
// HEM 1998/11/1
inherit ROOM;
void create()
{
	set("outdoors","tangmen");
	set("short", "ī��");
	set("long", @LONG
	һ����ɫ�ĳ�ˮ����û�߽����ŵ�һ��ŨŨ��ī�㡣���������˳����ڴ���
ϴ���⣬�ջ����ۣ����صı�ˮ�ͱ����һ��īˮ��
LONG
	);
       	set("exits", ([
		"north" : __DIR__ "danqingge",
	        ]));
	setup();
	replace_program(ROOM);
}

