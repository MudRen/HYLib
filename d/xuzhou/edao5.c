inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ɽ��λ�ڹ����ϲ���ɫ�����ķ羰������Ϊ����
��ʤ֮�ڡ�����ɽ����142�ף�����3���������������
��ɽ�ı��ϡ�
LONG );

	set("exits", ([
		"northeast"      : __DIR__"xinxian",
		"south"      : __DIR__"yuancheng",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



