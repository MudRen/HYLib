//cool 98.7.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
��������һ�����ʯ����ʯ����ŵĵط��������㿴����ʯ���������ˣ�
ֻ������ʼ��һ�������������ִ������ۣ�������ͬɫ��
LONG
	);
        set("outdoors", "����");
        set("objects", ([
	    __DIR__"npc/dyq": 1,
	]));
	setup();
}

void init()
{
      add_action("do_jump","tiao");
      add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me = this_player();
      if (arg !="down") 
        return notify_fail("��Ҫ����ȥ��\n");
      if( arg=="down"){
        write("��������������ʯ��\n");
        message("vision",me->name() + "һ������������ʯ��\n",environment(me), ({me}) );
        me->move(__DIR__"anbian");
        message("vision",me->name() + "���˹�����\n",environment(me), ({me}) );
        }
       return 0;
}
