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
		"northwest"      : __DIR__"edao4",
		"south"      : __DIR__"edao2",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



