inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������D�D�����ˣ���Ϊ�������´��ң���·Ӣ���ӸͶ�
��ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ��
�ϸ񣬲�ʱ�п���ӳ���ɳ۶������򶫾��������ˡ�	
LONG );

	set("exits", ([
	        "west"      : __DIR__"xinxian",
		"southeast"      : __DIR__"dadao9",
		
	]));
	set("objects", ([
		__DIR__"npc/bing" : 1,
	]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



