// Room: /dream/huayuan2.c
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
		"eastup" : __DIR__ "jiaolou2",
		"west" : __DIR__ "huayuan7",
		"south" :__DIR__ "changlang22",
        ]));
	setup();
	replace_program(ROOM);
}

