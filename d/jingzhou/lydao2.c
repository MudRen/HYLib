// Room: /d/jingzhou/lydao2.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���������������������������ֹ�������ɫ��ʯ�ӣ����ϱ���ͷ���졣��
���Ǹߴ�ľ��ݳ�ǽ���ϱߺ�����һ����Ȫ��
LONG
	);
        set("outdoors", "jingzhou");
	set("objects", ([
	 __DIR__"npc/kid" :3,
	]));
        
	set("exits", ([
		"north" : __DIR__"lydao1",
		"southdown" : __DIR__"wenquan",
	]));

	setup();
	replace_program(ROOM);
}

