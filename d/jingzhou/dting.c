// Room: dting
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������򸮵Ķ������������һ�����ӣ��Լ�һ����ܣ�����Ϸ��źܶ��鼮��
ǽ�Ϲ��ż����ֻ�����������������ŵ��������ĵط���
LONG
	);

	set("exits", ([
		"west" : __DIR__"dayuan",
		
	]));
	set("objects", ([
		__DIR__"npc/kongxincai" : 1,
		__DIR__"npc/qifang" : 1,		
	]));


	setup();
	replace_program(ROOM);
}

