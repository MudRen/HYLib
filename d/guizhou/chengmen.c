inherit ROOM;

void create()
{
	set("short", "�ڳǳ���");
	set("long", @LONG
�˼��ǹ������ڳǵĳ��ţ�����Ϊ���������ڳǳ�ǽ��ʯ�����
�ݳɣ������壬������ࡣ�������������������ľ�ʿ�����Ͼ��ǹ���
���ڳ��ˡ�
LONG );

	set("exits", ([
                          "north"      : __DIR__"center",
                         "south"      : __DIR__"ncenter",
                         
		
	]));
    set("objects",([
     __DIR__"npc/bing":2,
 __DIR__"npc/wujiang":2,
     
     ]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



