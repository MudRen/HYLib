// "suiye"/dongdajie1
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
·���˺ö࣬��Ҳ��������������˧�����ˣ����ڼ���æ�Ľ���
�������˧����������������ĵ�����ȥ��
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"west" : __DIR__"zhongxinguanchang",
		"north" :  __DIR__"dangpu",
                "east"  : __DIR__"dongdajie2",
                "south"  :__DIR__"shuaifu",
	]));
 set("objects",([ __DIR__"npc/nongmin":1,]));
       setup();
	replace_program(ROOM);
}	
