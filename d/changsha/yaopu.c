// /d/zhuojun/yaopu.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��Զ��������ҩ�̣�ȫ�����ص�ҩ����������Ӧ�о��У���
�Ǽ۸�ȴ�Ƿǳ�����ֻ�и����˼Һ�������ʿ���˹�ˣ�����ҩ����
���������塣
LONG
	);
set("exits", ([
                "west"  :__DIR__"nandajie1",
	]));
	set("objects",([
	__DIR__"npc/song":1,
	]));
       setup();
	replace_program(ROOM);
}	
