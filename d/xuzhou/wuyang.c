inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������������������ˣ���Ϊ�������´��ң���·Ӣ���ӸͶ�
��ս�𲻶ϣ������פ�����������࣬���ҶԹ����Ŀ����̲��ʮ��
�ϸ񣬲�ʱ�п���ӳ���ɳ۶�����	
LONG );

	set("exits", ([
	        "north"      : __DIR__"edao1",
		"northeast"      : __DIR__"edao6",
		"southwest"      : __DIR__"edao7",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



