// "suiye"/beidajie2
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
·������ôխ�����˽�������������һ�����յ�����Ŭ��ߺߺ���š�
�����Ǵ����̡�������һ���ӻ��̡�
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"zhongxinguanchang",
		"north" :  __DIR__"beidajie1",
                "east"  : __DIR__"datiepu",
                "west"  :__DIR__"zahuopuu",
	]));
 set("objects",([ __DIR__"npc/yiren":1,]));
       setup();
	replace_program(ROOM);
}	
