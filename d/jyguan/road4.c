// road4.c �ٵ�
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/14/1998 by Freeze

inherit ROOM;

void create()
{
	set("short", "�� ��");
	set("long", @LONG
����һ�������Ĵ�·���̶������������˿��֮·��������
�˴���ɴ˽�����ݣ�����Ҫ��ͨ��������
    �ɴ˵�������ȥ����ɳ�������ų�¥���һȺ����
���������ļ࿴������������שʯ����ʱ����������������
���µ�������ʹ����İ��տ಻���ԡ�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"road5",
		"southeast" : __DIR__"road3",
                "northwest" : __DIR__"wall",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

