inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����������ݵ���������ˣ���Ϊ�������´��ң���·Ӣ���ӸͶ�
��ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ��
�ϸ񣬲�ʱ�п���ӳ���ɳ۶�����	
LONG );

	set("exits", ([
	        "north"      : __DIR__"edao5",
		"west"      : __DIR__"edao6",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



