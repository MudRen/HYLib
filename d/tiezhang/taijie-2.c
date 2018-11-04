// Room: /u/bobo/tiezhang/taijie-2.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ�׵��������û���ˣ�ͻȻ����һƬ��������Χʯ���ϵĻ��ȼ��������
�㿴����ǰ����ͭƤ���ŵĴ���(gate)�����š��
LONG
        );

        set("exits", ([ 
"eastup" : __DIR__"taijie-1",
]));
        set("objects", ([
        "/d/feihu/npc/corpse" : 4,
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_open", "tui");
}

int do_open(string arg)
{
      object me;
      me=this_player();
      
      if(!arg || arg != "gate")
          return notify_fail("��Ҫ��ʲô��\n");
	if (objectp(present("flash corpse", environment(me))))
	   return notify_fail("�������ණ�����㻹�п����������\n");

      if (arg == "gate")
      {
      if ((int)me->query_temp("marks/baowu")){
          write("������һ�ƴ��ţ�����һ���Ǻ�����˽�ȥ���������͹����ˡ�\n");
          me->move(__DIR__"dashishi");
          me->delete_temp("marks/baowu",1);
          return 1;
          }
       }
       return notify_fail("���þ�ȫ���ƴ��ţ�����˿�������������ε�ҡ��ҡͷ��\n");
}
