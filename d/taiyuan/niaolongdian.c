// /d/taiyuan/niaolongdian.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
����һ��ר���������ĵ��̣���ģ�С�ģ���ģ�ľ�ĸ�ʽ������
����Ӧ�о��У�ǽ�Ϲ�������ʽ���������������Ĺ��ߣ�ǽ�Ƿ���ë��
ľ�ϵ�����������ԭ�ϣ�һ�����������ר�ĵĸɻ
LONG
	);
set("exits", ([
                "east" : __DIR__"beidajie1", 
	]));
 set("objects",([ __DIR__"npc/lidianzhu":1,]));
       setup();
	replace_program(ROOM);
}	
