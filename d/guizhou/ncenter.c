inherit ROOM;

void create()
{
	set("short", "�ڳ�");
	set("long", @LONG
���ǹ������ڳǵ�ʮ�ֽ�ͷ���ڶ�����һ��С�ϳ����㻹������ʿ
��������������������һ����ۡ��������һ��������ľ�����
LONG );

	set("exits", ([
                          "north"      : __DIR__"chengmen",		
	]));

          set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));
 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



