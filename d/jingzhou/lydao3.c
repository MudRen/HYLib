// Room: /d/jingzhou/lydao3.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���������������������������ֹ�������ɫ��ʯ�ӣ�������ͷ���졣
������һ���������ֱͨ�ϴ�֡����ߺ�����һ����Ȫ��
LONG
	);
        set("outdoors", "jingzhou");
	set("exits", ([
		"out" : __DIR__"lydao2",
	]));

	set("objects", ([
	 __DIR__"npc/kid" :3,
	]));
        
	setup();
	replace_program(ROOM);
}

