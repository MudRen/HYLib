// "suiye"/zhongxinguanchang
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��Ҷ�㳡");
	set("long", @LONG
���������Ҷ�ǵ����ģ�������ֽ����ڴˡ������䲻��Ư������
�����Ļ��Ǻ�������һ������������ʯ�����ڳ����ģ������������ǵ�
����
LONG);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"nandajie1",
		"north" :  __DIR__"beidajie2",
                "east"  : __DIR__"dongdajie1",
                "west"  :__DIR__"xidajie1",
	]));
 set("objects",([
  __DIR__"npc/xiaofan2":1,
"/clone/npc/man":2,
  	]));

       setup();
	replace_program(ROOM);
}	
