// /d/gaoli/xuanwumen
// Room in ����
inherit ROOM;

void create()

{
set("short", "����");

	set("long", @LONG
��������һï�ܵĴ���֮�С����ܶ��ǲ���Ĺ�������ס��ͷ�ϵ�
���⡣��ʱ�м�ֻҰ�ô���������ܹ�������֮�У������˺ܶ����޶�
�ߣ��㲻��С��������
LONG
	);
	

set("outdoors", "/d/gaoli");
set("exits", ([
		"southeast" : __DIR__"shanlu2",
		"south" : __DIR__"jiangbei",
               
	]));
	set("objects", ([

   "quest/skills2/wunon/dalie/dalie" : 2,
  
	
	]));	
       setup();
	replace_program(ROOM);
}
