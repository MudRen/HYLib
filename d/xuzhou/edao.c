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
		"west"      : "/d/hefei/dongmen",
		"southeast"      : __DIR__"dadao",
		"northeast"      : __DIR__"weixian",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



