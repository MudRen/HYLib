// Room: /lanzhou/nandajie2.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������˶�����
����ȥ��������һ�����ֵĹ㳡��
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"south" : __DIR__"nanmen",
		"north" : __DIR__"nandajie1",
	]));
	setup();
	replace_program(ROOM);
}
