// Room: /d/fuzhou/fzroad1.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
    ������խխ������ɽС���ϣ�ɽ·��᫣�����ɭɭ�����г�
��Ұ�޳�û����ν��������������ѡ����ϲ����ۡ�������ų�
��Ϫ������������ڶ��ϵ�����ɽ�ˡ�
LONG );
	set("exits", ([
		"northdown" : "/d/quanzhou/qzroad4",
		"south"     : __DIR__"erbapu",
	]));
        set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

