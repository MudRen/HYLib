// roadjyg.c �ٵ�
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/14/1998 by Freeze

inherit ROOM;

void create()
{
	set("short", "�� ��");
	set("long", @LONG
����һ�������Ĵ�·����ʱ�����̶Ӵ��������߹��������˿��֮·��������
�˴���ɴ˽�����ݣ�����Ҫ��ͨ��������
    ��·���Ӽ����غ����ݡ�
LONG
	);
        set("outdoors", "jyguan");

	set("exits", ([
		"northwest" : __DIR__"road1",
		"south" : "/d/lanzhou/river-bei",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

