// /d/zhuojun/road1.c
// Room in �ÿ�
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡����߾��ǳ�ɳ���š�
LONG );

	set("exits", ([
		"east"      : __DIR__"ximen",
		"west"      : __DIR__"road2",
		
	]));


 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



