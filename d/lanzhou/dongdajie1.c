// Room: /lanzhou/dongdajie1.c
// xws 1998/10/14 
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ���Ƚ�����Ľֵ��ϣ����߾������ݳǵ�����㳡�����Զ��
������㳡�����֣��ϱ���һ��������
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"north" : __DIR__"caisicang",
		"west" : __DIR__"guangchang",
		"east" : __DIR__"dongmen",
		"south" : __DIR__"tudimiao",
	]));
	setup();
	replace_program(ROOM);
}

