// /d/taiyuan/duchang.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ĳ�");
	set("long", @LONG
��ν�Ķĳ��������Ǽ��ŷ��������ĵ�ֻ��������Ǯ���������Ե�
�˵����ӣ������ڶĽ�ɽ��ɽ�����۳�죬վ�����Բ�ס�ĺȡ���������
��ô��������
LONG
	);
set("exits", ([
                "north" : __DIR__"dongdajie2", 
	]));
       setup();
	replace_program(ROOM);
}	
