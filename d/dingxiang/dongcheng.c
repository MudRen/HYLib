// /guanwai/dongcheng.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������û����̾͵Ľֵ������ϵ����˲��࣬�����������塣ż��
�м�������������ε������߹��������������壬����ľ������洫
�����ӵĽ�������
LONG );
	set("exits", ([
                //"west"     : __DIR__"puyuer",
		"south"     : __DIR__"dadao1",
		"northeast" : __DIR__"huandi1",
	]));
	set("outdoors", "dingxiang");
	setup();
}

