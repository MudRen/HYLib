// Room: /d/jingzhou/xidajie2.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣�������ﲻ���������ǵ���������
��ʥ��������һ�����ֵĹ㳡��
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"jzximen",
		"north" : __DIR__"guanmiao",
                "south" : __DIR__"lydao1",
	]));

	setup();
	replace_program(ROOM);
}

