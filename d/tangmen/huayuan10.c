// Room: /dream/huayuan10.c
// xws 1998/11/05
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
		"north" : __DIR__ "kuixinlou",
		"south" : __DIR__ "huayuan11",
        ]));
	setup();
	replace_program(ROOM);
}

