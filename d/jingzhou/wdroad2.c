// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ��ϱ���Լ�ɼ������ݳǵĳ�ǽ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : "/d/jingzhou/jzbeimen",
		"north" : __DIR__"wdroad3",
	]));

	setup();
	replace_program(ROOM);
}

