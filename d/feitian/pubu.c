#include <room.h>
inherit ROOM;
#include <ansi.h>  
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
�㴩�����־�Ȼ�������ٲ��ߣ����������ˮ���Ӹ��ߵ�ɽ���������£�
һ����������������ʯ�����𴮴�ˮ�飬������������£����������ˡ�
��˵���ĳ�������������
LONG);
        set("exits", ([
		"west" : __DIR__"shulin2",
        ]));
        set("outdoors","feitian");
        setup();
}

void init()
{
        add_action("do_jump","jump");
    add_action("do_enter", "enter");
}

int do_jump(string arg)
{
          object ob;
        object me;

          me=this_player();
          if (!arg || arg!="pubu")
              return notify_fail("��Ҫ��������ȥ��\n");
          message_vision("ֻ��$Nʩչ���ж��е�ˮ�ݣ�����һ���������ٶ�����\n",me);
          if ((me->query_skill("dodge",1)<101) || (me->query_skill("wuxing-dun",1)<101))
             {
          message_vision("ֻ��$Nʩչ�Ṧ��Ҫ�ɹ�ȥʱ�����ٲ�ǿ��ĳ����������ȥ��\n",me);
                 message_vision("$N��ɫ�԰�ʧ���������.............................\n",me);
          this_player()->unconcious();
          return 0;
        }
          me->move(__DIR__"pingtai");
          message_vision("ֻ��$N��һ��أ����˽�����\n",me);
          return 1;
}

int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="midao" ) 
       {
         tell_object(this_player() , "��Ҫȥ�Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "����������")
{
     message_vision("$N���Ƿ������������ܵ�,�㲻��ʶ·!\n",  ob);
    return 1;
}

    if(!ob->query_temp("shirenok"))
{
     message_vision("$N����ȥ̽һ�������е������!!\n",  ob);
    return 1;
}

    ob->move("/d/feitian/jiedao3") ;
    tell_object(ob, BLU "�㿴����С·��ֱ���߳�������!\n" NOR ) ;
    return 1 ;
}