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
		"northwest"      : __DIR__"henan",
		///"east"      : "/d/pengliang/fuqiao",
				"south"      : "/d/wuxi/paotai",
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



