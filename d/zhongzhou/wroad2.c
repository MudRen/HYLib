inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
���������ӿ��⸮�����ݸ��Ĺٵ�����������·�ΰ��Ϻ�
����Ҳ���١�����ͨ�򿪷⣬���������ݸ��������Ǹ���·�ڡ�
LONG);
        set("exits", ([
  		"west" : __DIR__"wroad3",
  		"east":__DIR__"wroad1",
	]));
        set("outdoors", "zhongzhou");
        set("no_clean_up", 0);

        set("coor/x", -300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
