inherit ROOM;

void create()
{
        set("short", "���԰��¥");
        set("long", @LONG
���԰��¥�����ݳ�����ָ�����Ĵ��¥�����ǲ�¥��ȴ
û�����ˡ���������и�¥�����£�΢΢������͸����ζ����
������ͷ�е㷢�衣
LONG);
        set("exits", ([
  		"east" : __DIR__"wendingnan2",
  		"down" : __DIR__"yanguan",
	]));
        set("no_clean_up", 0);

        set("coor/x", -240);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
