// Room: /lanzhou/caisicang.c
// xws 1998/10/15 
inherit ROOM;
void create()
{
	set("short", "���г�");
	set("long", @LONG
���������ݳ��������߲������г�����Բ�����ũ�񶼽��Լ���ֲ���߲�
�͵���������ۡ�������߲����࣬�۱��ˣ��ܶ����߲�����ķ��Ӷ��������
�ɹ���
LONG
	);
        set("outdoors", "lanzhou");
	set("exits", ([
		"west" : __DIR__"beidajie1",
		"south" : __DIR__"dongdajie1",
		]));
	set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/cainong" : 2,
	__DIR__"npc/boy" : 1,
	__DIR__"npc/girl" : 1,
	]));
	setup();
	replace_program(ROOM);
}

