// road2.c �ٵ�
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
		"southeast" : __DIR__"road1",
		"southwest" : __DIR__"road3",
//		"eastup" : "d/xingxiu/xxroad3",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

