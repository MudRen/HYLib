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
		"northeast"      : __DIR__"dadao11",
		"southwest"      : __DIR__"shanlu",
		"south"      : __DIR__"beimen",
		///"north":"/d/taiyuan/road7-2",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



