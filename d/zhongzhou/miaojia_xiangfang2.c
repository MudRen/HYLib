inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
��������������Ե�һ���᷿���ǹ���Զ���Ŀ��˺����
��������ס�ġ��᷿������ż��Ŵ󴲣��������ӡ����й���
��ͣ�ʹ�˸���˯�⡣
LONG);
	set("exits", ([
  		"north" : __DIR__"miaojia_zhengting",
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
        set("no_clean_up", 0);
        set("coor/x", -200);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
