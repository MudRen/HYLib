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
		///"northeast"      : "/d/taiyuan/road7",
		"southwest"      : __DIR__"dadao11",
		"southeast"      : __DIR__"xiaolu1",
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



