// /d/gaoli/zhuquedajie1
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��ʤ���");
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�����ʹ��ˡ������Կ�
���ʹ���Χǽ�������Ǹ��������ŵ�ʤ�ţ������Ǹ������ľ�¥����
����һ���鱦�꣬ר����ʽ���������Ρ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"zhuque-2",
		"north" : __DIR__"yudao1",
                "east":__DIR__"jiulou",
                "west":__DIR__"zhubaodian",    
	]));
       setup();
	replace_program(ROOM);
}	
