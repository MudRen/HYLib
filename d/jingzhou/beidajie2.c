// Room: beidajie2.c
// congw 1998/08/29 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ���
�⡣�ϱ��Եúܷ�æ��������һ��С���ݣ��Ŷ���д�š����Ϸ�ׯ����
���֣����������������㴹�����Ρ�������һ��ҩ�ꡣ
LONG
	);
        set("outdoors", "city");

	set("exits", ([
                "east" : __DIR__"libailou",
		"south" : __DIR__"beidajie1",
                "west" : __DIR__"yaopu",
                "north" : __DIR__"jzbeimen",
	]));

	setup();
	replace_program(ROOM);
}

