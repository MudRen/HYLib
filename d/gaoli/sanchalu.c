// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����·��");
	set("long", @LONG
	
����һ������·�ڣ������߲�Զ���Ǹ������ˣ����Ͼ��ǰټõؽ�
�ˣ������������޵ؽ磬��Ϊ���̵�ԭ�����������˷ǳ��١�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"dadao4",
		"south" : __DIR__"dadao5",
                "northeast" : __DIR__"shaoqia",
	]));
       setup();
	replace_program(ROOM);
}	
