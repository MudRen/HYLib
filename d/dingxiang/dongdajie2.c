// /d/yazhang/dongdajie2.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�����·�൱�Ŀ����ݺü�ƥ�����У������ĵ�·�ᴩ������
������һ�һ��ꡣ�ϱ������ʵ���˾���������Ĺ㳡���������Կ�����
���š�
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"huadian",  
                  "south" : __DIR__"yansi",  
                  "east" : __DIR__"dongdajie1",  
                  "west" : __DIR__"guangchang",    
	]));
	set("objects",([
	__DIR__"npc/ke":1,
	]));
       setup();
	replace_program(ROOM);
}	
