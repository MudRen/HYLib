// /d/zhoujun/xiaochidian.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "С�Ե�");
	set("long", @LONG
��С�Ե��������������Լ۸���ˣ�ʳ�÷���Ϊ����������С��
����ˣ��󲿷ֶ���ƶ���ˣ�Ҳ��Щ����������ʿΪ��ͼ���㵽������
�͡�
LONG
	);
set("exits", ([
                "west"  :__DIR__"nandajie2",
	]));
	set("objects",([
	 __DIR__"npc/xiaoer":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
