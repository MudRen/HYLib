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
		"south"      : __DIR__"dadao2",
		"east"      :  "/d/jinan/gate",
		
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



