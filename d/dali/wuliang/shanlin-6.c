// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ɭ��");
	set("long", @LONG
����˾�ţ����֮�����������������������������ȴ������ǰ��û
����ȥ·,ǰ��һ����������༷��һ�𣬱���һ�´�ǽ��wall)���ƣ���Ҳ��
����ǰ��һ���ˡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
             "south" : __DIR__"shanlin-5",
	]));

	setup();
}

void init()
{       
       add_action("do_jump", "jump");
       add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
       object me;
       me = this_player();
       if (!arg || arg !="wall") 
           return notify_fail("��Ҫ������ȥ��\n");
       if (random(me->query_skill("dodge",1)) < 60){ 
           write("����������һ���������������ã�û������ǽ��ˤ��������\n");
           write("�����˵���!\n");
	   me->add("qi", -100);
           me->add("jingli", -80);
           me->receive_wound("qi", 50);
	   return 1;
           }
       else {
           write("��һ�������������ɵ������˴���ǽ��\n");
           message("vision",me->name() + "һ������������ǽ��\n",environment(me), ({me}) );            
           me->move(__DIR__"muwu1");
           me->start_busy(1);
           message("vision",me->name() + "����ǽ�������˹�����\n",environment(me), ({me}) );
           return 1;
           }
}
