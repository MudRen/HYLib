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
		"southup"      : __DIR__"dadao8",
                "north"      : __DIR__"nanmen",	
                "northwest"      : __DIR__"wushui",		
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



