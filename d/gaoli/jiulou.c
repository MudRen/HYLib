// /d/gaoli/jiulou
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
������Ǹ�������һָ�ľ�¥�������ˡ���һ¥�Ĵ����аڷ���ʮ
����Բ�����Ա������˿��ˡ�������С������ѩ�׵�ë���ڿ����д���
�ţ���һ��������¡�ľ���
LONG
);
set("exits", ([
                "west":__DIR__"zhuque-1", 
	]));
set("objects", ([
		"/d/gaoli/npc/han" : 1,
	]));
       setup();
	replace_program(ROOM);
}
