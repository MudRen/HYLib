inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
�˴��Ǹ���·��������Զ�������������ɵ����ݣ�����ͨ
��������ɽ����������˳������·��ɽ��ȥ��
LONG);
        set("exits", ([
                "west" : "/d/luoyang/road9",
  		"east" : __DIR__"wroad2",
	]));
        set("outdoors", "zhongzhou");

        set("coor/x", -310);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
