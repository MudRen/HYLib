inherit ROOM;

void create()
{
	set("short", "ͭɽ��");
	set("long", @LONG
����������ݵķ羰��ͭɽ���ˣ���Ϊ�������´��ң���·Ӣ����
�Ͷ���ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲�
��ʮ���ϸ񣬲�ʱ�п���ӳ���ɳ۶��������ڹ������ؾ�������
�ˡ�	
LONG );

	set("exits", ([
	        "east"      : __DIR__"wushui",
		"southwest"      : __DIR__"edao5",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



