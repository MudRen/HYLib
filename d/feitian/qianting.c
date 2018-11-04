// Room: dongwuchang.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

inherit ROOM;

void init();
int do_da(string);
int do_ci(string);

void create ()
{
  set ("short", "ǰͥ");
  set ("long", @LONG
����һ������ǰͥ������������������������Щ�����ݲݣ�����������
������ߣ�һ�����ΰ�С��������������ľ�ˡ�������ðѽ�����һ��
(ci)ľ������ϰ���ұ��и���ɳ�������������һȭ��(da)��ȥ����ǰ��
һ�����ȡ�
LONG);

  set("area", "����������");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"damen",
  "north" : __DIR__"zhongting",
  "east" : __DIR__"xiulianshi",
  "west" : __DIR__"kongdi",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miyan" : 1,
]));

  setup();

}
int valid_leave(object me, string dir)
{
        if ((!(string)me->query("family") || (string)me->query("family/family_name") != "����������") 
               && ( dir == "north")
              && (objectp(present("mi yan", environment(me)))
               || objectp(present("mi yan", environment(me))) ))
               {  if (objectp(present("mi yan", environment(me)))) 
               
                       return notify_fail("����˵�����㲻�ǵ������ӣ���ذɡ�\n");
        }

        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_da", "da");
        add_action("do_ci", "ci");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "shabao" ) )
                return notify_fail("�����ʲô��\n");
        me->add("qi",-10);

        if ( me->query("qi") <= (10) )
                return notify_fail("��̫ƣ���ˣ�û�о���ȥ�����ˡ�\n");

        message_vision("$N�ںü��ƣ�һȭ��ɳ����ȥ��\n", me);

        if ( me->query_skill("parry", 1) < 5 )  
        {
                message_vision("$N��������񶷣�����ֶ����ˡ�\n", me);
   		
        } else if ( me->query_skill("parry", 1) < 20 )
        {
                message_vision("$N��ɳ����û�����ȥ��\n", me);
        } else 
        {
                message_vision("�Ե�һ����ɳ����$N��÷���������\n", me);
        }
 
        if ( me->query_skill("parry", 1) < 30)
        {
                me->improve_skill("parry", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( me->query_skill("parry",1) >= 30 )
        { 
                write("��һ�¾Ͱ�ɳ�����ˣ�ɳ������������ǣ�\n");
        }
        return 1;
}

int do_ci(string arg)
{
        object me;
        int jing_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "muren" ) )
                return notify_fail("�����ʲô��\n");
        
        me->add("qi",-10);

        if ( me->query("qi") <= (10) )
                return notify_fail("��̫ƣ���ˣ�û�о���ȥ�����ˡ�\n");

        message_vision("$N���������һ����ľ�˴�ȥ��\n", me);

        if ( me->query_skill("sword", 1) < 5 )  
        {
                message_vision("$N�������ὣ��������ľ��ֻ��������һ�¡�\n", me);
   		
        } else if ( me->query_skill("sword", 1) < 20 )
        {
                message_vision("$N��׼ľ�˵��ƶ���һ������ľ�˵�ҪѨ�ϡ�\n", me);
        } else 
        {
                message_vision("$N����һ�����Ѿ�����ľ�˵�Ҫ���ˡ�\n", me);
        }
 
        if ( me->query_skill("sword", 1) < 30)
        {
                me->improve_skill("sword", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( me->query_skill("sword",1)>= 30 )
        { 
                write("��һ�¾Ͱ�ľ�˴̵��ˣ�������ľ�˶���ûʲô�����ˣ�\n");
        }
        return 1;
}



