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
		"southwest"      : __DIR__"edao8",
		"northeast"      : __DIR__"wuyang",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



