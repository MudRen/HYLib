// "suiye"/nandajie2
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
�����·��խ��������һƥ�������������ĵ�·�ᴩ�ϱ���һ��
С�������ĵĽ����š�������һ�Ҽ�Ժ������Ư����Ů�����űߺ���ʿ
�������Σ�����ȴ�����ĵģ�ԭ����һ����ꡣ
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"nanchengmen",
		"north" :  __DIR__"nandajie1",
                "east"  : __DIR__"jiyuan",
                "west"  :__DIR__"shudian",
	]));
 set("objects",([ __DIR__"npc/jianke":1,]));
       setup();
	replace_program(ROOM);
}	
