// Room in ����
inherit ROOM;
void create()	
{
	set("short", "С·");
	set("long", @LONG
������һ��С·֮�ϡ����������߾��Ǹ�����һ�����̨�ˡ����
̨�������ݾ��顣��ʱ�м����ٱ��������߹�����������������ˡ���
�ߴ󺣵Ĳ��������������˼�����׳�ķ�Χ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northeast" : __DIR__"xiaolu1",
		"westup":__DIR__"fenghuotai",
		"northdown":__DIR__"zhuangjiadi",
	]));
       setup();
	replace_program(ROOM);
}	
