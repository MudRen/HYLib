// Room: xting
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������򸮵����������������һ�����ӣ��Լ�һ����ܣ�����Ϸ��źܶ��鼮��
�����ŵ��Ӷ���ĵط���
LONG
	);

	set("exits", ([
		"east" : __DIR__"dayuan",
		
	]));

	setup();
	replace_program(ROOM);
}

