// Room: /d/jingzhou/xidajie1.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣����ϡ�٣������ĵغ������塣
������һ�����ֵĹ㳡���ϱ��Ǿ��ݸ��á�������һ��������Ժ���Ǿ�������
���ˡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"south" : __DIR__"jzyamen",
		"west" : __DIR__"xidajie2",
		"north" : __DIR__"wanghouse",
	]));

	setup();
	replace_program(ROOM);
}

