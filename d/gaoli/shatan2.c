// Room in ����
inherit ROOM;
void create()	
{
	set("short", "ɳ̲");
	set("long", @LONG	
������ɳ̲֮�ϣ�����������ĺ�ɳ���ϱ���һ�Ҵ�ս������ͣ��
�������˵���Ǹ����ĺ��沿��֮һ���������ƻ��ң�������ս��Ҳ
���ϼӽ䱸��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northwest" : __DIR__"shatan1",
		"south":__DIR__"jiaban",
	]));
       setup();
	replace_program(ROOM);
}	
