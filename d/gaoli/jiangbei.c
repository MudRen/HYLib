// /d/gaoli/xuanwumen
// Room in ����
#include <ansi.h>
inherit ROOM;



void create()

{
set("short", "Ѽ�̽�����");

	set("long", @LONG
������Ѽ�̽��ı�����������˴����£��Ϳ��Ե������ˡ������
�˱Ƚ϶࣬����ͣ���ż���С������Զ������С��Ҫ����������
LONG
	);
	
	set("objects", ([
	"quest/skills2/wunon/yu/yutan" : 2	,   
	
	]));
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"milin1",
"south" : __DIR__"jiangnan",
		               
	]));
       setup();
	
}
