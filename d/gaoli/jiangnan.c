// /d/gaoli/xuanwumen
// Room in ����
#include <ansi.h>
inherit ROOM;


void create()

{
set("short", "Ѽ�̽��ϰ�");

	set("long", @LONG
������Ѽ�̽����ϰ���������˴����ϣ��Ϳ��Ե���ԭ�ı����ˡ�
����ͣ���ż���С������Զ������С��Ҫ����������
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : "/d/changbaishan/shanlu5",
"north" : __DIR__"jiangbei",

		               
	]));
       setup();
	
}
