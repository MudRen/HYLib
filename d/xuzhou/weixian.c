inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ݵ���������ˣ������Թ��Ǳ���Ҫ�أ������ǿ�
����ԭ�Ĺؼ��ص�֮һ���������´��ң���·Ӣ���ӸͶ���ս
�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ����
�񣬲�ʱ�п���ӳ���ɳ۶�����	
LONG );

	set("exits", ([
	        "east"      : __DIR__"shanlu",
		"southwest"      : __DIR__"edao",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



