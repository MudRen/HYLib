// "suiye"/dongdajie2
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
·�����ˣ��������������ǳ����ž�¥������һЩ�������ʹӶ���
���������ö��������µ���Ҳ����ҡ���ߣ���������һ����լ��
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"west" : __DIR__"dongdajie1",
		"north" :  __DIR__"jiulou",
                "east"  : __DIR__"dongchengmen",
                "south"  :__DIR__"minzhai",
	]));
set("objects",(["/clone/npc/man":1,]));
       setup();
	replace_program(ROOM);
}	
