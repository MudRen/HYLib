inherit ROOM;

void create()
{
        set("short", "Ѳ����");
        set("long", @LONG
һ�߽��谵��Ѳ������һʱ��ɶ�����������;����е���
ɭ���¡���ɿ�������Լ���û����ʲô���캦����¡�
LONG);
        set("objects", ([
  		"/d/city/npc/xunbu" : 2,
	]));
        set("no_clean_up", 0);
        set("exits", ([
  		"east" : __DIR__"laofang",
  		"west" : __DIR__"wendingbei3",
	]));

        set("coor/x", -220);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
