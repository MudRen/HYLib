inherit ROOM;

void create()
{
        set("short", "�ɿ�·");
        set("long", @LONG
����������ͨ�����ݳǵĴ�������Ƕɿڡ�ͨ���ɿڿ�
�Ե��ｭ�������ݣ����������ϱ���Ҫ����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"to_zhongzhou",
  		"north" : __DIR__"zhongzhoudu",
	]));
        set("outdoors", "zhongzhou");
        set("objects", ([
  		__DIR__"npc/boy1" : 1,
  		__DIR__"npc/girl2" : 1,
	]));
        set("no_sleep_room", 1);

        set("coor/x", -230);
	set("coor/y", 80);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
