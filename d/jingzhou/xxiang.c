// Room: /jingzhou/xxiang.c
// congw 98/08/30

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ�������ֺڵ����ӣ�ɢ����һ������ˮ��ζ����ʳ�﷢ù��ζ����
�����ֳ���

LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"south" : __DIR__"xxend",
		"north" : __DIR__"dongdajie2",
	]));

	setup();
	replace_program(ROOM);
}

