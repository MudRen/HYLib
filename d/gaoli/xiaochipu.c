// /d/gaoli/xiaochipu
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "С�Ե�");
	set("long", @LONG
����һ�Һ��ƺܾɵ�С�ꡣֻ�����������������ҵİڷ��ţ�����
��ճ��һ������͹���ǽ�����ѱ�����Ѭȥ��ԭ���ı�ɫ�����ﲻ��
����ʳ�ֻ��һЩС�ԣ��۸������
LONG
	);
set("exits", ([
               "south":__DIR__"baihu-2", 
	]));
set("objects", ([
		"/d/gaoli/npc/li" : 1,
	]));
       setup();
	replace_program(ROOM);
}	
