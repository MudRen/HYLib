// /d/yazhang/nandajie1.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
�����Ǹ�ԭ�Ƽ�֮�����Ե���������������һ�һ��۵꣬ר����һ
ЩŮ�����õ���֬���ۣ��������Ρ�������һ�Ҳ÷�ꡣ
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"nandajie2",  
                  "south" : __DIR__"nanmen",  
                  "east" : __DIR__"huafendian",  
                  "west" : __DIR__"chaifengdian",    
	]));
       set("objects",([
         __DIR__"npc/jiesheshuai":1,
         ]));
       setup();
	replace_program(ROOM);
}	
