inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ���Ȼ�ֽ����´��ң��������ܻ�
�����������������ӵġ����̵ġ����Ŵ󳵵���������������ǳ���
�֡���ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�
LONG );

	set("exits", ([
		"east"      : __DIR__"dadao2",
		"southwest"      : __DIR__"dadao4",
		"west"      : __DIR__"tiandi",
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



