// /d/zhuojun/eroad1.c
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
		"east"      : __DIR__"eroad2",
		"west"      : __DIR__"dongmen",
		
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



