// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
������һ����̡��Ա߾�����ӿ�Ĵ󺣣������紵���������Ĵ�
�ŵ̰������������϶��Ǻ�ˮ���ϱ߾��Ǹۿ��ˣ���������������ۿ�
���ӵ�������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northwest" : __DIR__"dadi5",
        	"south":__DIR__"gangkou",
	]));
       setup();
	
}
