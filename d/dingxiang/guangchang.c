// /d/yazhang/guangchang.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����㳡");
	set("long", @LONG
����������ʵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ����¥��
����ǰ��������Щ���ơ�ÿ���峿�����������������ŵ�����������
���ʵĴ��С�·�ڳ�ˮ�����������˳����ϡ�
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"beidajie2",  
                  "south" : __DIR__"nandajie2",  
                  "east" : __DIR__"dongdajie2",  
                  "west" : __DIR__"xidajie2",    
	]));
set("objects",(["/clone/npc/man":3,]));	
       setup();
	replace_program(ROOM);
}	
