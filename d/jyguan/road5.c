// road5.c �ٵ�
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/14/1998 by Freeze

inherit ROOM;

void create()
{
	set("short", "�� ��");
	set("long", @LONG
����һ�������Ĵ�·���̶�������һȺ���ڼ��������ļ�
���°���שʯ��
    ������Ǿ���Ҫ����ǧ���۹ء��������ء�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"dongmen",
		"east" : __DIR__"road4",
               
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

