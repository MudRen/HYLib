// /d/taiyuan/jiuguan.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "С�ƹ�");
	set("long", @LONG
����һ���Ѳ�����С��С�ƹݣ�С�ƹ���ֻ�м��ŷ����������Ĳ�
���Ƕ���ͷ�������ף�������֮¦�������ȾƵ�Ҳ���������ˣ���һ��
�Ƽ���С�ˣ�����һ�¹�������Ȥ��
LONG
	);
set("exits", ([
                "south" : __DIR__"dongdajie2", 
	]));
	set("objects",([
	__DIR__"npc/xiaoer2":1,
	]));
       setup();
	replace_program(ROOM);
}	
