// /d/zhuojun/eroad3.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡�����Զ�����Ѿ��ܿ�����ɳ�ˡ�
LONG );

	set("exits", ([
		"west" : __DIR__"eroad2",
                "northeast" : __DIR__"shulin1",
		
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



