// Room: /dream/huayuan1.c
// HEM 1998/11/1
inherit ROOM;
void create()
{
	set("short", "��԰");
	set("long", @LONG
	����һ��Ƭ��԰�����ŵش�����,ռ�ع������������˻����������������ŵ�
����֮�࣬��ϲ����Ū���ݣ�����������԰Ʒ�ַ��࣬���껨�Ž���,�ǳ�Ư��������
�кܶັ�����Ļ��ݣ�������������������ζ�����в������á�
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"east" : __DIR__ "liujiantang",
		"west" : __DIR__ "huayuan2",
        ]));
        set("objects", ([
		__DIR__"npc/yahuan" : 2,
			]));
	setup();
	replace_program(ROOM);
}

